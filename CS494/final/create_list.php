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
		<h1>Pokemon Team Builder: Build A List</h1>
		
		<h3>Build a Team List</h3>
			<p>Create a new team by entering a unique numerical identifier for your list.<br>
			
				Then add new Pokemon using the dropdown menu.<br>

				You can remove a Pokemon by hitting the delete button on that row.<br>
				
				A team can be at most 6 Pokemon, so choose wisely!<br>
			</p>
			
			
			<p><b>Create a List here:</b></p>
			<form action ="team_list.php" method="post">
			<b>List ID:</b>
			<input type="number" name ="newlistid" />
			<input type="submit" name="add_list" value = "Create List"/>
			</form>
		
			
			<p><b>Add A Pokemon to A List</b></p>
			<form method="post" name = "addpkmn" action = "add_pkmn.php">
			<b>Pokemon</b>
			<select name="pkmn">
				<?php
				if(!($stmt = $mysqli->prepare("SELECT name FROM pokemon ORDER BY name ASC"))){
						echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
				}
				if(!$stmt->execute()){
						echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
				}
				if(!$stmt->bind_result($name)){
						echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
				}
				while($stmt->fetch()){
				 echo '<option value = "' . $name . '"> ' . $name . '</option>\n';
				}
				$stmt->close();
				?>
			</select>
			<b>List</b>
			<select name ="listid">
				<?php
				if(!($stmt = $mysqli->prepare("SELECT DISTINCT listid FROM team_list WHERE username = '$user'"))){
						echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
				}	
				if(!$stmt->execute()){
						echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
				}
				if(!$stmt->bind_result($id)){
						echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
				}
				while($stmt->fetch()) {
				 echo '<option value=" '. $id . ' "> ' . $id . '</option>\n';
				}
				$stmt->close();
				?>		
			<input type="submit" value="Add Pokemon to List" />
			</form>
			<div id = "error" class = "error"></div>
			<div id = "success"></div>
			<p></p>
			<button onclick = "toggle('lists')" name = "listsbutton">Show/Hide Lists</button>
			<div id = "lists" class = "toggle">
			
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
	
	
	