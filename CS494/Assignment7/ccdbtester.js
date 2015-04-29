equest();
if (!xmlreq) {
    throw 'Unable to create XML HTTP Request.';
}


function getData() {
	var ccdbURL = 'http://ccdb.hemiola.com/'
	var filter = 'characters/radicals/85?filter=gb'
	var reqUrl = ccdbURL + filter;
	xmlreq.open('GET', reqURL);
	xmlreq.send();
	xmlreq.onreadystatechange = function() {
		displayData();
	}
}

function displayData() {
	if(xml.readyState == 4 && xmlreq.status = 200) {
		var parsed = JSON.parse(xmlreq.responseText);
	}

	for(var i = 0; i < parsed.length; i++) {
		var obj = parsed[i];
		for(var key in obj) {
			var attrName = key;
			var attrValue = obj[key];
			var t = attrName + ':' + attrValue;
			document.getElementById("output").innerHtml = t;
		}
	}
}
