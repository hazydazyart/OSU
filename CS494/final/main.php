<?php
	error_reporting(E_ALL);
	ini_set('display errors', 1);
	
	session_start();
	if(isset($_SESSION['loggedin'])) {
		header("Location: dash.php");
	}
?>

<!DOCTYPE html>
<html>
	<head>
        <meta charset="utf-8">
        <title>Pokemon Team Builder</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="ajax_verify.js"></script>
	</head>

<body>
<div class ="main">

	<h1>The Pokemon Team Builder</h1>

	<p>Welcome to the Pokemon Team Builder, where you can plan out your Pokemon teams including movesets. You can create an unlimited list of teams to be associated with your free account!</p>

	<p>Not a member of the PTB? <a href="signup.php">Register here!</a></p>

	<p>Log in to your account below:</p>

	<form method="post" name="login_form">
	<input type="text" name="name" placeholder="Username"/>
	<input type="password" name="pass" placeholder="Password">
	<input type="button" value="Log In" onclick="login();" />
	</form>
	<div id ="error" class="error"></div>

</div>
</body>
</html>
