<?php
	error_reporting(E_ALL);
	ini_set('display_errors', 1);
	
	$mysqli = new mysqli('login info');
	
	if ($mysqli->connect_error) {
    die('Connect Error: (' . $mysqli->connect_errno . ') ' . $mysqli->connect_error);
	}
	$usersearch = "SELECT * FROM innodb.users WHERE username = ? AND password = ?";
	if(!($query = $mysqli->prepare($usersearch))) {
		echo 'Preparation failed: (' . $mysqli->errno . ') ' . $mysqli->error;
	}
	
	$user = $_POST['name'];
	$pass = $_POST['pass'];
	
	if(!$query->bind_param("ss", $user, $pass)) {
		echo 'Failed to bind: (' . $query->errno . ') ' . $query->error;
	}
	if(!$query->execute()) {
		echo 'Execute failed: (' . $query->errno . ') ' . $query->error;
	}
	$query->store_result(); 
	$row_count = $query->num_rows;
	$query->close();
	if($row_count == 0) { 
		echo "Error";
	} else {
		session_start();
		if(!isset($_SESSION['name'])) {
			$_SESSION['name'] = $user;
		}
		if(!isset($_SESSION['loggedin'])) {
			$_SESSION['loggedin'] = true;
		} 
		header("Location: main.php");
	} ?>
	
