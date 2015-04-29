<?php
	$user = "";
	session_start();
	if(!isset($_SESSION['loggedin'])) {
		header("Location: main.php");
	}
	if(isset($_SESSION['name'])) {
		$user = $_SESSION['name'];
	}
//Turn on error reporting
ini_set('display_errors', 'On');
//Connects to the database
$mysqli = new mysqli('oniddb.cws.oregonstate.edu','conleyme-db','t50AD6dCxtftZ7zb','conleyme-db');

$list = $_POST['listid'];
$pkmn = $_POST['pkmn'];

// Prepare delete query
if(!($stmt = $mysqli->prepare("DELETE FROM team_list WHERE listid = ? AND pokemon = ?"))){
        echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

// Bind variable from drop down list on main.php
if(!($stmt->bind_param("is",$list, $pkmn))){
        echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

// Execute query
if(!$stmt->execute()){
        echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

header("Location: create_list.php");
?>


