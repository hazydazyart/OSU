<?php
session_start();
if($_SERVER['REQUEST_METHOD'] != 'POST') {
	$_SESSION = array();
	session_destroy();
	$filePath = explode('/',$_SERVER['PHP_SELF'],-1);
	$filePath = implode('/',$filePath);
	$redirect = 'http://' . $_SERVER['HTTP_HOST'] . $filePath;
	header("Location: {$redirect}/login.php", true);
	die();
}

echo "<!DOCTYPE html>
<html>
<head>
	<meta charset='utf-8'>
	<title>Content</title>
</head>
<body>";

if(session_status() == PHP_SESSION_ACTIVE) {
	if(empty($_POST['user'])) {
		echo "Please enter a username. Click <a href='login.php?action=logout'>here</a> to return to the login page.";
	} else {
		$_SESSION['name'] = $_POST['user'];

		if(!isset($_SESSION['visits'])) {
			$_SESSION['visits'] = 0;
		}

		$_SESSION['visits'] = $_SESSION['visits'] + 1;
		
		echo "Hello, " . $_SESSION['name'] . ". You have visited this site " . $_SESSION['visits'] . " times.";
		echo " Click <a href='login.php?action=logout'>here</a> to log out.";
	}
}
echo "</body>
</html>";

?>