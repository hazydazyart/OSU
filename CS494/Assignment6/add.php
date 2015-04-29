<?php
//Turn on error reporting
ini_set('display_errors', 'On');
//Connects to the database
$mysqli = new mysqli('oniddb.cws.oregonstate.edu','conleyme-db','t50AD6dCxtftZ7zb','conleyme-db');
if ($mysqli->connect_error) {
    die('Connect Error (' . $mysqli->connect_errno . ') '
            . $mysqli->connect_error);
}

//  get variables from POST request
$name = $_POST['name'];
$category = $_POST['category'];
$price = $_POST['price'];

if(!empty($name) && !empty($category) && !empty($price)){
	if(is_numeric($price) && $price < 1000){
		$result = $mysqli->query("SELECT * FROM inventory WHERE name = '$name'");
		$row_cnt = $result->num_rows;
		if ($row_cnt == 0) {
			// Prepare insert query
			if(!($stmt = $mysqli->prepare("INSERT INTO inventory(name, category, price) VALUES (?,?,?)"))){
				echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
			}

			// Bind variables
			if(!($stmt->bind_param("ssd",$_POST['name'],$_POST['category'],$_POST['price']))){
				echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
			}

			if(!$stmt->execute()){
			// Execute query
				echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
			}
			$stmt->close();
			// Redirect back to main page now that insert query is done
			$path = explode('/', $_SERVER['PHP_SELF'], - 1);
			$path = implode('/', $path);
			$redirect = "http://" . $_SERVER['HTTP_HOST'] . $path;
			header("Location: {$redirect}/main.php");
		} else {
			echo 'Name of item must be unique. ';
		}
	} else {
			echo 'Price must be an integer under 1000. ';
		}
    } else { // one or more inputs were empty
	if(empty($name)) {
		echo 'Name is a required field. ';
	}
	if(empty($price)) {
		echo 'Price is a required field. ';
	}
}
?>

<!DOCTYPE html> 
<html>
  <head>
    <title>Grocery Store Inventory</title>
  </head>
  <body>
  <p>
  <a href="main.php">Click here to return to the main page.</a>
  </body>
</html>