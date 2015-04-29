<?php
	$user = "";
	session_start();
	if(!isset($_SESSION['loggedin'])) {
		header("Location: main.php");
	}
	if(isset($_SESSION['name'])) {
		$user = $_SESSION['name'];
	}
	
	$friend = $_POST['name'];
//Turn on error reporting
ini_set('display_errors', 'On');
//Connects to the database
$mysqli = new mysqli('oniddb.cws.oregonstate.edu','conleyme-db','t50AD6dCxtftZ7zb','conleyme-db');


// Prepare delete query
if(!($stmt = $mysqli->prepare("DELETE FROM friends WHERE user = ? AND friend = ?"))){
        echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

// Bind variable
if(!($stmt->bind_param("is",$user, $friend))){
        echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

// Execute query
if(!$stmt->execute()){
        echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

header("Location: find_friends.php");
?>


