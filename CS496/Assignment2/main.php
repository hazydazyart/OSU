<?php
	error_reporting(E_ALL);
	ini_set('display errors', 1);
	
	session_start();
	if(isset($_SESSION['loggedin'])) {
		header("Location: home.php");
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Super Accurate Horoscopes</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="verify.js"></script>
	</head>
	<body>
		<div class="main">
			<p>Login to your account below.</p>
			<p>Don't have an account? <a href="signup.php">Sign up for one now!</a></p>
			
			<form method="post" name="login_form">
				<input type="text" name="name" placeholder="Username"/>
				<input type="password" name="pass" placeholder="Password">
				<input type="button" value="Log In" onclick="login();" />
			</form>
			<div id="error" class="error"></div>
		</div>
	</body>
</html>