<?php
	error_reporting(E_ALL);
	ini_set('display errors', 1);
	
	$user = "";
	session_start();
	if(!isset($_SESSION['loggedin'])) {
		header("Location: main.php");
	}
	if(isset($_SESSION['name'])) {
		$user = $_SESSION['name'];
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
		<div class="nav">
		<a href="home.php">Home</a> - <a href="settings.php">Edit Settings</a> - <a href="view.php">View Settings</a> - <a href="horoscope.php">Horoscope</a> - <a href="logout.php">Logout</a>
		</div>
		<p>Logged on as: <?php echo $user; ?>.</p>

		<p>Choose an option above to get started.</p>
		
		<p>If this is your first time here, please <a href="settings.php">tell us a bit about yourself</a> to get started.</p>
	</body>
</html>