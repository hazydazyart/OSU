<?php
//Turn on error reporting
ini_set('display_errors', 'On');
//Connects to the database
$mysqli = new mysqli('oniddb.cws.oregonstate.edu','conleyme-db','t50AD6dCxtftZ7zb','conleyme-db');
if ($mysqli->connect_error) {
    die('Connect Error (' . $mysqli->connect_errno . ') '
            . $mysqli->connect_error);
}

// Prepare delete query
if(!($stmt = $mysqli->prepare("UPDATE inventory SET price = (price * ?) WHERE category = ?"))){
        echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
}

$modifier = $_POST['modifier'] / 100;
$category = $_POST['category'];

// Bind variable from chosen category from main.php
if(!($stmt->bind_param("ds",$modifier,$category))){
        echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
}

// Execute query
if(!$stmt->execute()){
        echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
}

$stmt->close();

// Redirect back to main page now that insert query is done
$path = explode('/', $_SERVER['PHP_SELF'], - 1);
$path = implode('/', $path);
$redirect = "http://" . $_SERVER['HTTP_HOST'] . $path;
header("Location: {$redirect}/main.php");
?>