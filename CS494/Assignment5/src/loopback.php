<?php
echo "<!DOCTYPE html>
<html>
<head>
	<meta charset='utf-8'>
	<title>Loopback</title>
</head>
<body>";

header('Content-Type: text/plain');
$myArr = array();
$type = array(
	'Type' => ''
);

$parameters = array();

$myArr['Type'] = $_SERVER['REQUEST_METHOD'];

if($myArr['Type'] == 'GET') {
	foreach($_GET as $key => $value) {
		$parameters[$key] = $value;
	}
}

if($myArr['Type'] == 'POST') {
	foreach($_POST as $key => $value) {
		$parameters[$key] = $value;
	}
}

if(empty($_GET) || empty($_POST)) {
	$myArr[] = null;
}

$myArr['parameters'] = $parameters;

echo JSON_encode($myArr);

echo "</body>
</html>";
?>