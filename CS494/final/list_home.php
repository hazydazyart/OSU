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
	<h1>Pokemon Team Builder: Lists</h1>
	
	<p>View your team lists below!</p>
	<?php
		if($rows = $mysqli->query("SELECT listid, pokemon FROM team_list WHERE username = '$user' AND pokemon IS NOT NULL ORDER BY listid ASC")){
			if($rows->num_rows){
				while($poke = $rows->fetch_object()){
					$pokemon[] = $poke;
				}
			} 
		}?>
		<h3>Your Teams</h3>
		<table>
		<thead>
		   <tr>
			<th>List ID</th>
			<th>Pokemon</th>
		   <tr>
		 </thead>
		<?php 
			foreach($pokemon as $p){
				$thislist = $p->listid;
				$thisname = $p->pokemon;
		?>
			<tr>
			<td><?php echo $thislist; ?></td>
			<td><?php echo $thisname; ?></td>
			</tr>
	<?php } ?>
		</table>
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