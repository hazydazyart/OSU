// conleyme
// API backend written in Javascript using NodeJS with Express, Dynasty, body-parser and multer libraries

var credentials = {
	accessKeyId: 'AKIAILSCI2WZ2PN33VWA', 
	secretAccessKey: '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',
	region: 'us-west-2'
};

var dynasty = require('dynasty')(credentials); // For interactions with DynamoDB
var express = require('express'); // For HTTP action handling
var bodyParser = require('body-parser'); // For POST requests
var multer = require('multer'); // For POST requests
var AWS = require('aws-sdk');  // For interactions with DynamoDB
AWS.config.update({accessKeyId: 'AKIAIL5BJLEZF3EAQ37A', secretAccessKey: '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'});
AWS.config.region = 'us-west-2';	
var dynamodb = new AWS.DynamoDB();
var app = express();

app.use(bodyParser.json()); // for parsing application/json
app.use(bodyParser.urlencoded({ extended: true })); // for parsing application/x-www-form-urlencoded
app.use(multer()); // for parsing multipart/form-data


// GET request for specific user returns entire row
// Example: host/users/msmarvel
app.get('/users/:name', function (req, res) {
        var users = dynasty.table('users'); // load table
        users
                .find(req.params.name) // find user in table
                .then(function(data) { 
			if(data) { // if exists
                        	res.send(data); // send row as JSON
			} else {
				res.send('user not found');
			}
                });
});

// GET request for all rows from users table
// Example: host/users
app.get('/users', function (req, res) {
	var params = {
		TableName: 'users'
	};
	dynamodb.scan(params, function(err, data) {
		if(err) { console.log(err); }
		else { res.send(JSON.stringify(data, undefined, 2)); }
	}); 
});

// GET request for all rows from the scores table
// Example: host/scores
app.get('/scores', function (req, res) {
        var params = {
                TableName: 'highscores'
        };
        dynamodb.scan(params, function(err, data) {
                if(err) { console.log(err); }
                else { res.send(JSON.stringify(data, undefined, 2)); }
        });
});

// GET request for specific user's score for specific game
// Example: host/socres/msmarvel?game=Tetris
app.get('/scores/:name', function (req, res) {
	var scores = dynasty.table('highscores');
	if(!req.query.game) { // if required parameter is not included
		res.send('error');
	} else { // find and return row if exists
		scores
			.find({hash: req.params.name, range: req.query.game})
			.then(function(data) {
				if(data) {
					res.send(data);
				} else {
					res.send('not found');
				}
			});
	}
});

// PUT request to either a) add new user or b) update already existing row;
//     Dynamo automatically handles either case with the same action.
// Example: host/users/greenlatern?location=New York&date=20140404
app.put('/users/:name', function (req, res) {
	var users = dynasty.table('users');
	if(!req.query.location || !req.query.date) { // if either required parameter is missing
		res.send('error');
	} else { // insert new row or update already existing row with given key
	users
		.update({name: req.params.name, location: req.query.location, date_joined: req.query.date})
		.then(function(data) {
			res.send('success');
		});
	}
});

// PUT request to either a) add new score or b) update already existing row;
//     Dynamo automatically handles either case with the same action.
// Example: host/scores/greenlatern?game=Tetris&score=203984&date=20140404
app.put('/scores/:name', function (req, res) {
        var users = dynasty.table('users');
	if(!req.query.game || !req.query.date || !req.query.score) { // if any parameters are missing
		res.send('error');
	} else { // if user exists, update score
	users
		.find(req.params.name)
		.then(function(data) {
			if(data) {
				var scores = dynasty.table('highscores');
				scores
					.update({name: req.params.name, game: req.query.game, date: req.query.date, score: req.query.score})
					.then(function(data) {
						res.send('success');
					});
			} else { // cannot add row for user not in 'users' table
				res.send('user not found');
			}
		});
	}
});

// POST request for specific row from user table
// Because there are no other parameters, this is the same as the GET request
app.post('/users/:name', function(req, res) {
        var users = dynasty.table('users');
        users
                .find(req.params.name)
                .then(function(data) {
			if(data) {
                        	res.send(data);
			} else {
				res.send('user not found');
			}
                });
});

// POST request for all users
// Because there are no other parameters, this is the same as the GET request
app.post('/users', function (req, res) {
        var params = {
                TableName: 'users'
        };
        dynamodb.scan(params, function(err, data) {
                if(err) { console.log(err); }
                else { res.send(JSON.stringify(data, undefined, 2)); }
        });
});

// POST requests for all scores
// Because there are no other parameters, this is the same as the GET request
app.post('/scores', function (req, res) {
        var params = {
                TableName: 'highscores'
        };
        dynamodb.scan(params, function(err, data) {
                if(err) { console.log(err); }
                else { res.send(JSON.stringify(data, undefined, 2)); }
        });
});

// POST request for a user's score for a game
// Like GET, the username is still in the URL. However, it reads the game from the POST request body.
app.post('/scores/:name', function (req, res) {
	
        var scores = dynasty.table('highscores');
	if(!req.body.game) { // if required parameter is missing
		res.send('error');
	} else { // return row if exists
        scores
                .find({hash: req.params.name, range: req.body.game})
                .then(function(data) {
			if(data) {
                        	res.send(data);
			} else {
				res.send('not found');
			}
                });
	}
});

// *** There are no batch delete options *** //

// DELETE request for a user's score
app.delete('/scores/:name', function (req, res) {
	var scores = dynasty.table('highscores');
	if(!req.query.game) {
		res.send('error');
	} else {
	scores
		.remove({hash: req.params.name, range: req.query.game})
		.then(function(data) {
			res.send('success');
		});
	}
});

// DELETE request for a user
// Cascades to delete rows from the scores table associated with that user
app.delete('/users/:name', function (req, res) {
	var users = dynasty.table('users');
	users
		.remove(req.params.name)
		.then(function(resp) {
			console.log(resp);
		
	var scores = dynasty.table('highscores');
	scores
		.find({hash: req.params.name, range: 'Tetris'}) // see if user has scores in table
		.then(function(data) { 
			if(data) {
				// remove scores for two game titles
				// see report for why this is the case
				scores
					.remove({hash: req.params.name, range: 'Tetris'})
					.then(function(resp) {
						console.log(resp);
					});
				scores
					.remove({hash: req.params.name, range: 'Flappy Bird'})
					.then(function(resp) {
						console.log(resp);
					});
			}
		});
	res.send('success');
	});
});
	
// Configure the server
// Runs on EC2 instance's public IP with port forwarding 80 -> 8080
var server = app.listen(8080, function () {

  var host = server.address().address;
  var port = server.address().port;

  console.log('Assignment 3 part 2 is listening at http://%s:%s', host, port);

});
