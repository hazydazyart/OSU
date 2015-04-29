// Megan Conley
// CS494-400 
// Assignment 4 - weather.js

// Define the XMLHttpRequest variable
var xmlreq = new XMLHttpRequest();
if (!xmlreq) {
    throw 'Unable to create XML HTTP Request.';
}

// Load user settings from local storage
// This function runs once the window loads to display the settings each time they
// visit the page. 
function loadUserSettings() {
    document.getElementById('cityName').value = localStorage.getItem('cName');
    document.getElementById('stateName').value = localStorage.getItem('sName');
    if (localStorage.getItem('maxTemp') === 'true') {
        document.getElementById('max').checked = true;
    }
    if (localStorage.getItem('minTemp') === 'true') {
        document.getElementById('min').checked = true;
    }
    if (localStorage.getItem('curTemp') === 'true') {
        document.getElementById('cur').checked = true;
    }
    if (localStorage.getItem('windSpd') === 'true') {
        document.getElementById('wind').checked = true;
    }
}

// Pushes each variable into local storage if the user chooses to save
function saveSettings() {
    localStorage.setItem('cName', document.getElementById('cityName').value);
    localStorage.setItem('sName', document.getElementById('stateName').value);
    localStorage.setItem('maxTemp', document.getElementById('max').checked);
    localStorage.setItem('minTemp', document.getElementById('min').checked);
    localStorage.setItem('curTemp', document.getElementById('cur').checked);
    localStorage.setItem('windSpd', document.getElementById('wind').checked);
}

// Updates page to display the weather report on the page using the response
// from getWeather() which is parsed by JSON
function displayWeatherReport() {
    var city = document.getElementById('cityName').value;
    var state = document.getElementById('stateName').value;
    var citystate = city + state;
    var minT = document.getElementById('min').checked;
    var maxT = document.getElementById('max').checked;
    var wWind = document.getElementById('wind').checked;
    var curT = document.getElementById('cur').checked;

    if (xmlreq.readyState == 4 && xmlreq.status == 200) {
        var parsed = JSON.parse(xmlreq.responseText);

        document.getElementById("cityOutput").innerHTML = document.getElementById('cityName').value;

        if (wWind === true) {
            document.getElementById("windSpd").innerHTML = parsed.wind.speed + ' MPH';
            document.getElementById("windNWSE").innerHTML = parsed.wind.deg;
        }
        if (maxT === true) {
            document.getElementById("maxOutput").innerHTML = parsed.main.temp_max + ' F';
        }
        if (minT === true) {
            document.getElementById("minOutput").innerHTML = parsed.main.temp_min + ' F';
        }
        if (curT === true) {
            document.getElementById("curTOutput").innerHTML = parsed.main.temp + ' F';
        }
	}
}

// Obtains weather report for the specified location from
// openweathermap.org in imperial units
// Once it gets a response, it calls the displayWeatherReport();
function getWeather() {
    var location = '';
    var city = document.getElementById('cityName').value;
    var state = document.getElementById('stateName').value;
    location = city + state;
    var getWeatherURL = 'http://api.openweathermap.org/data/2.5/weather?q=' + location + '&units=imperial';
    xmlreq.open('GET', getWeatherURL);
    xmlreq.send();
    xmlreq.onreadystatechange = function () {
        displayWeatherReport();
    };
}

// Once the user opens the page, the previous settings are loaded
// If no settings have been saved, all the boxes are empty
window.onload = function() {
	loadUserSettings();
}

// Clears local storage
function clearSettings() {
    localStorage.clear();
}