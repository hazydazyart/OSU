<!DOCTYPE html>
<html>

<head>
        <meta charset="utf-8">
        <title>Pokemon Team Builder</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src ="ajax_verify.js"></script>
		
</head>

<body>
<div class = "main">
	
	<h1>The Pokemon Team Builder</h1>

	<p>Registering for an account is easy - all you need is a username and password. That's right, no email address - we will not send you any unwanted spam. This does mean that passwords <b>cannot</b> be recovered, so please choose carefully.</p>

	<p>Fill out the information below:</p>
	<form action ="register.php" method ="post">
	<input type="text" name="login" placeholder="Username"/>
	<input type="password" name="pass" placeholder="Password"/>
	<input type="password" name="checkpass" placeholder="Enter password again"/>
	<input type="submit" name ="register" value="Register"/>
	</form>

</div>
</body>
</html>
