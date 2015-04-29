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
		<script src = "ajax_verify.js"></script>
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
		<h1>Pokemon Team Builder: Find Friends</h1>
		
		<h3>Select a User to Add as Friend</h3>
			<p>Choose a username from the dropdown list below to add them as a friend.<br>
			
				Once they are on your friend list, they can see the team lists you've made.<br>

				You won't be able to see their lists until they also add you as a friend.<br>

			</p>
			<b>Add A Friend</b>
			<form method="post" action = "add_friend.php">
			<b>User</b>
			<select name="friend">
				<?php
				if(!($stmt = $mysqli->prepare("SELECT name FROM usernames WHERE name != '$user' ORDER BY name ASC"))){
						echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
				}
				if(!$stmt->execute()){
						echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
				}
				if(!$stmt->bind_result($name)){
						echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
				}
				while($stmt->fetch()){
				 echo '<option> ' . $name . '</option>\n';
				}
				$stmt->close();
				?>
			</select>
			<input type="submit" value="Add as Friend"></input>
			</form>
			<br>
			<button onclick = "toggle('friends')" name = "listsbutton">Show/Hide Friends</button>
			<div id = "friends" class = "toggle">
			<?php
			if($rows = $mysqli->query("SELECT friend FROM friends WHERE user = '$user'")){
					if($rows->num_rows){
						while($friended = $rows->fetch_object()){
							$myfriends[] = $friended;
					}
				} else {
					echo '<p>You haven\'t added any friends yet.</p>';
				}
			} ?>
				<table>
				<thead>
				   <tr>
					<th>People You've Friended</th>
				   <tr>
				 </thead>
				<?php 
					foreach($myfriends as $f){
					$thisname = $f->friend;
				?>
					<tr>
					<td>
					<?php $filename = 'images/'.$f->friend.'.jpg';
					if(file_exists($filename)) { ?>
						<img src = "<?php echo $filename ?>" alt = "user profile photo"></img>
					<?php } else { // if not, give them the royalty-free clipart temporary one ?>
						<img src = "images/temp.jpg"></img>
				<?php } ?>
					</td>
					<td><?php echo $thisname; ?></td>
					<td><form method="POST" action="delete_friend.php"><input type="hidden" value="<?php echo $thisname;?>" name="name" />
					<input type="submit" value='Remove Friend' />
					</form>
				  </tr>
				<?php
				}
				if($rows = $mysqli->query("SELECT user FROM friends WHERE friend = '$user'")){
					if($rows->num_rows){
						while($added = $rows->fetch_object()){
							$iamfriend[] = $added;
						}
					} else {
					echo '<p>No one has added you as a friend yet.</p>';
					} 
				}?>
				</table>
				<p></p>
				<table>
				<thead>
				   <tr>
					<th>People Who've Added You as a Friend</th>
				   <tr>
				 </thead>
				<?php 
					foreach($iamfriend as $f){
						$thisname = $f->user;
				?>
					<tr>
					<td>
					<?php $filename = 'images/'.$f->user.'.jpg';
					if(file_exists($filename)) { ?>
						<img src = "<?php echo $filename ?>" alt = "user profile photo"></img>
					<?php } else { // if not, give them the royalty-free clipart temporary one ?>
						<img src = "images/temp.jpg"></img>
				<?php } ?>
					</td>
					<td><?php echo $thisname; ?></td>
				    </tr>
			<?php } ?>
				</table>
			</div>
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
	
	
	