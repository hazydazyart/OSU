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
	$mysqli = new mysqli('oniddb.cws.oregonstate.edu','conleyme-db','t50AD6dCxtftZ7zb','conleyme-db');
	
	if ($mysqli->connect_error) {
		die('Connect Error: (' . $mysqli->connect_errno . ') ' . $mysqli->connect_error);
	}
	$isnull = false;
	$isnotnum = false;
	$success = false;

	$listid = $_POST['newlistid'];
	
	// List functions
	if($listid == "" || $listid == NULL) {
		$isnull = true;
	} 
	if(!is_numeric($listid)) {
		$isnotnum = true;
	}
	if(!$isnull && !$isnotnum) { // no errors
		if(!($insert = $mysqli->prepare("INSERT INTO team_list (username, listid) VALUES (?, ?)"))) {
			echo 'Preparation failed: (' . $mysqli->errno . ') ' . $mysqli->error;
		}
		if(!($insert->bind_param("si", $user, $listid))) {
			echo 'Failed to bind: (' . $insert->errno . ') ' . $insert->error;
		}
		if(!($insert->execute())) {
			echo 'Execute failed: (' . $insert->errno . ') ' . $insert->error;
		}
		$success = true;
		$insert->close();
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
	<div class ="main">

	<h1>The Pokemon Team Builder</h1>

	<?php
	if($success) { ?>
		<p>List created succesfully! Click <a href="create_list.php">here</a> to create a new list or to add Pokemon to your list.</p>
	<?php 
	} else {
		if($isnull) { ?>
			<div class="error">Error: please enter a value. Click <a href="create_list.php">here</a> to try again.</div>
	<?php 
		}
		if($isnotnum) { ?>
			<div class="error">Error: value must be a number. Click <a href="create_list.php">here</a> to try again.</div>
		<?php 
		}
	} ?>
	</div>
		<div class = "right-nav">
		<h3>My Account</h3>
			<div class ="profile">
			<?php // if user already has profile picture, display it here
			$filename = 'images/'.$user.'.jpg';
			if(file_exists($filename)) { ?>
				<img src = "<?php echo $filename ?>" alt = "user profile photo">
			<?php } else { // if not, give them the royalty-free clipart temporary one ?>
				<img src = "images/temp.jpg">
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