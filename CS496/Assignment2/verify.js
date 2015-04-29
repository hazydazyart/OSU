// Send login information to login.php
function login() {
	var username = document.login_form.name.value;
	var password = document.login_form.pass.value;
	
	var parameters = "name=" + encodeURIComponent(username) + "&pass=" + encodeURIComponent(password);
	
	var loginattempt = ajaxRequest('login.php', 'post', parameters);
	
	verify(loginattempt);
}

// ajaxRequest from Homework4 edited to:
// - remove stringify (parameters stringified in login()
// - remove post/get check (will always be post for this assignment
function ajaxRequest(URL, type, parameters) {
  var httpRequest;

  // Code from Mozilla AJAX guide
  // Checks which browser is being used so correct XML HTTP request is made
  if (window.XMLHttpRequest) {
    httpRequest = new XMLHttpRequest();
  } else if (window.ActiveXObject) {
    httpRequest = new ActiveXObject("Microsoft.XMLHTTP");
  }

  // Create object to be returned and initialize its variables
  var returned = new Object();
  returned.success = '';
  returned.code = '';
  returned.codeDetail = '';
  returned.response = '';
  
  // For help with the XMLHTTP object, I used w3.org,
  // particularly http://www.w3.org/TR/2007/WD-XMLHttpRequest-20071026/
  httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState === 4) {
      returned.code = httpRequest.status;
	  returned.codeDetail = httpRequest.statusText;
	  returned.response = httpRequest.responseText;
	    if (httpRequest.status === 200) {
          returned.success = true;
        } else {
          returned.success = false;
        }
    }
  };
  
    httpRequest.open(type, URL, false);
    httpRequest.setRequestHeader('Content-Type',
    'application/x-www-form-urlencoded');
    httpRequest.send(parameters);
 
  return returned;
}

function verify(attempt) {
	var status = attempt.response.trim();
	//console.log(status);
	if(status != 'Error') {
		window.location.href = "main.php";
	} else {
		document.getElementById('error').innerHTML = 'Error: login information not found. Please check your username or password and try again.';
	}
}