// Megan Conley
// CS494 400
// Assignment 4 - studentlibrary.js

function ajaxRequest(URL, Type, Parameters) {
  var httpRequest;

  // Code from Mozilla AJAX guide
  // Checks which browser is being used so correct XML HTTP request is made
  if (window.XMLHttpRequest) {
    httpRequest = new XMLHttpRequest();
  } else if (window.ActiveXObject) {
    httpRequest = new ActiveXObject("Microsoft.XMLHTTP");
  }

  // Stringifies the parameters so they can be added
  // to the URL as a single string
  // Code from AJAX lecture this week
  function urlStringify(p) {
    var str = [];
    for (var key in p) {
      var s = encodeURIComponent(key) + '=' + encodeURIComponent(p[key]);
        str.push(s);
      }
      return str.join('&');
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
  
  if (Type == 'POST') {
    httpRequest.open('POST', URL, false);
	var POSTparameter = urlStringify(Parameters);
    httpRequest.setRequestHeader('Content-Type',
    'application/x-www-form-urlencoded');
    httpRequest.send(POSTparameter);
  }
  if (Type == 'GET') {
    var GETurl = URL + '?' + urlStringify(Parameters);
    httpRequest.open('GET', GETurl, false);
    httpRequest.send();
  }
 
  return returned;
}

// Check if local storage is available
// If it is not null, it exists - true returned
// If it is null, it does not exist - false returned 
function localStorageExists() {
  if (window.localStorage !== null) {
    return true;
  } else {
    return false;
  }
}