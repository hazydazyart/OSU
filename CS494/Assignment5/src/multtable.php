<?php
session_start();
if(isset($_GET['action']) && $_GET['action'] == 'end') {
	$_SESSION = array();
	session_destroy();
	$filePath = explode('/',$_SERVER['PHP_SELF'],-1);
	$filePath = implode('/',$filePath);
	$redirect = "http://" . $_SERVER['HTTP_HOST'] . $filePath;
	header("Location: {$redirect}/Logout.html", true);
	die();
}

echo "<!DOCTYPE html>
<html>
<head>
	<meta charset='utf-8'>
	<title>Multtable</title>
</head>
<body>";

$valid_input = true;

if(session_status() == PHP_SESSION_ACTIVE) {
	if(isset($_GET['min-multiplicand'])) {
		$_SESSION['min-multiplicand'] = $_GET['min-multiplicand'];
		if(!is_numeric($_SESSION['min-multiplicand'])){
			echo "Error: Minimum multiplicand must be a number." . "<br>";
			$valid_input = false;
		}
	} else {
		echo "Error: Missing parameter: mininmum multiplicand." . "<br>";
		$valid_input = false;
	}

	if(isset($_GET['max-multiplicand'])) {
		$_SESSION['max-multiplicand'] = $_GET['max-multiplicand'];
		if(!is_numeric($_SESSION['max-multiplicand'])){
			echo "Error: Maximum multiplicand must be a number." . "<br>";
			$valid_input = false;
		}
	} else {
		echo "Error: Missing parameter: maximum	multiplicand." . "<br>";
		$valid_input = false;
	}

	if(isset($_GET['min-multiplier'])) {
		$_SESSION['min-multiplier'] = $_GET['min-multiplier'];
		if(!is_numeric($_SESSION['min-multiplier'])){
			echo "Error: Minimum multiplier must be a number." . "<br>";
			$valid_input = false;
		}
	} else {
		echo "Error: Missing parameter: mininmum multiplier." . "<br>";
		$valid_input = false;
	}

	if(isset($_GET['max-multiplier'])) {
		$_SESSION['max-multiplier'] = $_GET['max-multiplier'];
		if(!is_numeric($_SESSION['max-multiplier'])){
			echo "Error: Maximum multiplier must be a number." . "<br>";
			$valid_input = false;
		}
	} else {
		echo "Error: Missing parameter: maximum multiplier." . "<br>";
		$valid_input = false;
	}
	
	if($valid_input && ($_SESSION['min-multiplier'] > $_SESSION['max-multiplier'])) {
		echo "Error: min-multiplier is larger than max-multiplier." . "<br>";
		$valid_input = false;
	}
	if($valid_input && ($_SESSION['min-multiplicand'] > $_SESSION['max-multiplicand'])) {
		echo "Error: min-multiplicand is larger than max-multiplicand." . "<br>";
		$valid_input = false;
	}


	if($valid_input) {
		echo "<h2> Multiplication Table </h2>";
		echo "<table>";
		$height = $_SESSION['max-multiplicand'] - $_SESSION['min-multiplicand'] + 2;
		$width = $_SESSION['max-multiplier'] - $_SESSION['max-multiplicand'] + 2;
		echo "<tr><th></th>";
		
		for($i = $_SESSION['min-multiplier']; $i <= $_SESSION['max-multiplier']; $i++) {
			echo "<th>";
			echo $i;
		}
		for($j = $_SESSION['min-multiplicand']; $j <= $_SESSION['max-multiplicand']; $j++) {
			echo "<tr><th>";
			echo $j;
			for($i = $_SESSION['min-multiplier']; $i <= $_SESSION['max-multiplier']; $i++) {
				echo "<td>";
				echo $i * $j;
			}
		}
	}
}
echo "</body>
</html>";



?>