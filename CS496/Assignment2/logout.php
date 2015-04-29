<?php
	error_reporting(E_ALL);
	ini_set('display_errors', 1);
	
	session_start();
	if (!isset($_SESSION['loggedIn'])){
	  header("Location: main.php");
	}
	$_SESSION = array();
	session_destroy();
	header("Location: main.php");
?>