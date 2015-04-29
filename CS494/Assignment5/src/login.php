<?php
session_start();
if(isset($_GET['action']) && $_GET['action'] == 'logout') { // if user chose to logout, destroy previous session
	$_SESSION = array();
	session_destroy();
}

echo "<!DOCTYPE html>
<html>
<head>
	<meta charset='utf-8'>
	<title>Login</title>
</head>
	
<body>
	<section>
		<form action='content.php' method='POST'>
			<b>Username</b> <input type='text' name='user' />
			<input type='submit' value='Login'>
		</form>
	</section>
</body>
</html>";
?>