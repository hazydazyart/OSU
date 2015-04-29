<?php
	$user = "";
	session_start();
	if(!isset($_SESSION['loggedin'])) {
		header("Location: main.php");
	}
	if(isset($_SESSION['name'])) {
		$user = $_SESSION['name'];
	}

	$success = false;
	$error = false;
	$recipient = $_POST['recip'];
	$message = mysql_real_escape_string($_POST['message']);

//Turn on error reporting
	ini_set('display_errors', 'On');
//Connects to the database
	$mysqli = new mysqli('oniddb.cws.oregonstate.edu','conleyme-db','t50AD6dCxtftZ7zb','conleyme-db');
// Prepare insert query
	if(!($stmt = $mysqli->prepare("INSERT INTO messages(sender, recipient, message) VALUES (?,?,?)"))){
		$error = true;
		echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
	}

// Bind variables
	if(!($stmt->bind_param("sss", $user, $recipient, $message))){
		$error = true;
		echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
	}

// Execute query
	if(!$stmt->execute()){
		$error = true;
		echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
	} 
	$stmt->close();
	if(!$error) {
		$success = true;
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
		<p>
		<ul>
			<li><a href="list_home.php">My Lists</a></li>
			<li><a href="create_list.php">Create a List</a></li>
			<li><a href="friends_lists.php">See Lists Shared With Me</a></li>
			<li><a href="find_friends.php">Find Friends</a></li>
			<li><a href="share.php">Share Lists With Friends</a></li>
		</ul>
		</p>
	</div>
	<div class ="main">

	<h1>The Pokemon Team Builder</h1>

	<?php
	if($success) { ?>
		<p>Message sent successfully.</p>
	<?php 
	} else { ?>
			<div class="error">An error occurred. Please try again.</div>
		<?php 
		} ?>
	</div>
		<div class = "right-nav">
		<h3>My Account</h3>
			<div class ="profile">
			<?php // if user already has profile picture, display it here
			$filename = 'images/'.$user.'.jpg';
			if(file_exists($filename)) { ?>
				<img src = "<?php echo $filename ?>" alt = "user profile photo"></img>
			<?php } else { // if not, give them the royalty-free clipart temporary one ?>
				<img src = "images/temp.jpg"></img>
			<?php } ?>
			<span>Currently logged<br>
					in as:<br>
					<b><?php echo $user ?></b></span>
			</div>
		<p>
		<ul>
			<li><a href="settings.php">Settings</a></li>
			<li><a href="logout.php">Log Out</a></li>
		</ul>
		</p>
	</div>
</div>
</body>
