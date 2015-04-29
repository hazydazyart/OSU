<?php
	error_reporting(E_ALL);
	ini_set('display_errors', 1);
	
	$mysqli = new mysqli('oniddb.cws.oregonstate.edu','conleyme-db','t50AD6dCxtftZ7zb','conleyme-db');
	
	if ($mysqli->connect_error) {
		die('Connect Error: (' . $mysqli->connect_errno . ') ' . $mysqli->connect_error);
	}

	$registered = false;
	
	$user = "";
	$pass1 = "";
	$pass2 = "";
	$response = "";
	$error1 = false;
	$error2 = false;
	$error3 = false;
	$error4 = false;
	
	if(isset($_POST['login'])) {
		$user = $_POST['login'];
	}
	if(isset($_POST['pass'])) {
		$pass1 = $_POST['pass'];
	}
	if(isset($_POST['checkpass'])) {
		$pass2 = $_POST['checkpass'];
	}

	if(!($query = $mysqli->prepare("SELECT * FROM usernames WHERE name = ?"))) {
		echo 'Preparation failed: (' . $mysqli->errno . ') ' . $mysqli->error;
	}

	if(!$query->bind_param("s", $user)) {
		echo 'Failed to bind: (' . $query->errno . ') ' . $query->error;
	}
	if(!$query->execute()) {
		echo 'Execute failed: (' . $query->errno . ') ' . $query->error;
	}
	$result = $query->get_result(); 
	$row_count = $result->num_rows;
	
	if($row_count > 0) {
		// error 1: username exists
		$error1 = true;
	}
	$userlength = strlen($user);
	if($userlength < 5 || $userlength > 20) {
		// error 2: username too long or short
		$error2 = true;
	}
	if($pass1 != $pass2) {
		// error 3: passwords don't match
		$error3 = true;
	} 
	$passlength = strlen($pass1);
	if ($passlength < 5 || $passlength > 20) {
		// error 4: password too short or long
		$error4 = true;
	}
	
	if(!$error1 && !$error2 && !$error3 && !$error4) {
		$registered = true;
		// enter new user into database
		if(!($reg = $mysqli->prepare("INSERT INTO usernames (name, password) VALUES (?,?)"))) {
			echo 'Preparation failed: (' . $mysqli->errno . ') ' . $mysqli->error;
		}
		if(!($reg->bind_param("ss", $user, $pass1))) {
			echo 'Failed to bind: (' . $reg->errno . ') ' . $reg->error;
		}
		if(!($reg->execute())) {
			echo 'Execute failed: (' . $reg->errno . ') ' . $reg->error;
		}
		$reg->close();
	}
	$query->close();
?>
<!DOCTYPE html>
<html>
	<head>
        <meta charset="utf-8">
        <title>Pokemon Team Builder</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="ajax_verify.js"></script>
	</head>

<body>
<div class ="main">

	<h1>The Pokemon Team Builder</h1>

	<?php
	if($registered) { ?>
	<p>Thank you for registering! Click <a href="main.php">here</a> to log in!</p>
	<?php } else {
		if($error1) { ?>
			<div class="error">Error: username already exists. Please choose a new username.</div>
	<?php }
		if($error2) { ?>
			<div class="error">Error: password must be between 5-20 characters.</div>
	<?php }
		if ($error3) { ?>
			<div class="error">Error: passwords do not match.</div>
	<?php }
		if($error4) { ?>
			<div class="error">Error: username must be between 5-20 characters.</div>
	<?php } ?>
		<p>Click <a href="signup.php">here</a> to try again.</p>
	<?php }
	?>
	</div>
</body>
</html>
