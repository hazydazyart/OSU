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
        <title>Pokemon Team Builder</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>

<body>
<div class = "container">
	<div class="left-nav">
	<h3>Navigation</h3>
	<ul>
		<li><a href="list_home.php">My Lists</a></li>
		<li><a href="create_list.php">Create a List</a></li>
		<li><a href="friends_lists.php">See Lists Shared With Me</a></li>
		<li><a href="find_friends.php">Find Friends</a></li>
	</ul>
	</div>
	
	<div class="main">
	<h1>Pokemon Team Builder: Dashboard</h1>
	
	<p>Welcome back, <?php echo $user ?>!</p>
	
	<p>Select an option to get started!</p>
	
	<p>Don't know what to do first? Try <a href="create_list.php">creating a new list</a>, then <a href="find_friends.php">find a friend to share your lists with!</a></p>
	</div>
	
	<div class = "right-nav">
	<h3>My Account</h3>
	<div class ="profile">
	<?php // if user already has profile picture, display it here
	$filename = 'images/'.$user.'.jpg';
	if(file_exists($filename)) { ?>
		<img src = "<?php echo $filename ?>" alt = "user profile photo">
	<?php } else { // if not, give them the royalty-free clipart temporary one ?>
		<img src = "images/temp.jpg" alt = "temporary profile photo">
	<?php } ?>
	<span>Currently logged<br>
			in as:<br>
			<b><?php echo $user ?></b></span>
	</div>
	<ul>
		<li><a href="settings.php">Settings</a></li>
		<li><a href="logout.php">Log Out</a></li>
	</ul>
	</div>
	
</div>
</body>
</html>