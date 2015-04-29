<?php

error_reporting(E_ALL);
ini_set('display_errors', 1);
	
	$mysqli = new mysqli('login info');
	
if ($mysqli->connect_error) {
	die('Connect Error: (' . $mysqli->connect_errno . ') ' . $mysqli->connect_error);
}

$username_error = "";
$pass1_error = "";
$pass2_error = "";
$user = "";
$dbuser = "";
$pass1 = "";
$pass2 = "";
$success = "";


if ($_SERVER["REQUEST_METHOD"] == "POST") {
	if(empty($_POST["login"])) {
		$username_error = "Username is a required field.";
	} else {
		$user = $_POST["login"];
		if(!preg_match("/^[a-zA-Z]/",$user)) {
			$username_error = "Username must contain only letters.";
		} else {
			if(!($query = $mysqli->prepare("SELECT * FROM innodb.users WHERE username = ?"))) {
				echo 'Preparation failed: (' . $mysqli->errno . ') ' . $mysqli->error;
			}
			if(!$query->bind_param("s", $user)) {
				echo 'Failed to bind: (' . $query->errno . ') ' . $query->error;
			}
			if(!$query->execute()) {
				echo 'Execute failed: (' . $query->errno . ') ' . $query->error;
			}
			$query->store_result();
			$row_count = $query->num_rows;
			
			if($row_count > 0) {
				$username_error = "This username already exists. Please choose another username.";
			}
		}
	}

	if(empty($_POST["pass1"])) {
		$pass1_error = "Password is a required field.";
	} else {
		$pass1 = $_POST["pass1"];
		if(!preg_match("/^[a-zA-Z]/",$pass1)) {
			$username_error = "Password must contain only letters.";
		} 
	}

	if(empty($_POST["pass2"])) {
		$pass2_error = "Please enter your password again.";
	} else {
		$pass2 = $_POST["pass2"];
		if($pass1 != $pass2) {
			$pass2_error = "Passwords must match.";
	}
		} 
	
	if($username_error == "" && $pass1_error == "" && $pass2_error == "") {
		if(!($query = $mysqli->prepare("INSERT INTO innodb.users(username, password) VALUES (?,?)"))) {
			echo 'Preparation failed: (' . $mysqli->errno . ') ' . $mysqli->error;
		}
		if(!$query->bind_param("ss", $user, $pass1)) {
			echo 'Failed to bind: (' . $query->errno . ') ' . $query->error;
		}
		if(!$query->execute()) {
			echo 'Execute failed: (' . $query->errno . ') ' . $query->error;
		}		
		$success = "Successfully registered!";
	}
}

?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Super Accurate Horoscopes</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body>
		<div class = "main">
			<h1>The Most Super Accurate Horoscopes Ever</h1>
			<p>Registering for an account is easy - all you need is a username and password. Please choose a username and password below. Once you create your account, just provide a few simple details about yourself to get your horoscope!
			<p>Fill out the information below:</p>
			<form action ="" method ="post">
				<input type="text" name="login" placeholder="Username"/>
				<span class="error"> <?php echo $username_error; ?></span>
				<input type="password" name="pass1" placeholder="Password"/>
				<span class="error"> <?php echo $pass1_error; ?></span>
				<input type="password" name="pass2" placeholder="Enter password again"/>
				<span class="error"> <?php echo $pass2_error; ?></span>
				<input type="submit" name ="register" value="Register"/>
				<span class="success"> <?php echo $success; ?>
			</form>
		</div>
	</body>
</html>