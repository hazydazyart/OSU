<?php
	error_reporting(E_ALL);
	ini_set('display_errors', 1);

	$user = "";
	session_start();
	if(!isset($_SESSION['loggedin'])) {
		header("Location: main.php");
	}
	if(isset($_SESSION['name'])) {
		$user = $_SESSION['name'];
	}
	
	$sex = "";
	$animal = "";
	$astro = "Select";
	$exercise = "false";
	$art = "false";
	$music = "false";
	$study = "false";
	$kale = "";
	$success = "";
	$update = "false";
	
	$s_error = "";
	$animal_error = "";
	$astro_error = "";
	$k_error = "";
	
	$mysqli = new mysqli('login info');
	
	if ($mysqli->connect_error) {
    die('Connect Error: (' . $mysqli->connect_errno . ') ' . $mysqli->connect_error);
	}

	//check if settings already entered by user
	$usersearch = "SELECT * FROM innodb.settings WHERE user = '$user'";
	if($rows = $mysqli->query($usersearch)) {
		if($rows->num_rows > 0) {
			$obj = $rows->fetch_object();
			$sex = $obj->sex;
			$astro = $obj->astro;
			$animal = $obj->animal;
			$exercise = $obj->exercise;
			$art = $obj->art;
			$study = $obj->study;
			$music = $obj->music;
			$kale = $obj->kale;
			$update = "true";
		}
	}

	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		if(empty($_POST["sex"])) {
			$s_error = "Sex is a required field.";
		} else {
			$sex = $_POST["sex"];
		}
		if(empty($_POST["animal"])) {
			$animal_error = "Favorite animal is a required field.";
		} else {
			$animal = strtolower($_POST["animal"]);
		}
		if(empty($_POST["astro"])) {
			$astro_error = "Astrological sign is a required field.";
		} else {
			$astro = $_POST["astro"];
		}	
		if(!isset($_POST["exercise"])) {
			$exercise = "false";
		} else {
			$exercise = "true";
		}
		if(!isset($_POST["art"])) {
			$art = "false";
		} else {
			$art = "true";
		}
		if(!isset($_POST["music"])) {
			$music = "false";
		} else {
			$music = "true";
		}
		if(!isset($_POST["study"])){
			$study = "false";
		} else {
			$study = "true";
		}
		if(empty($_POST["kale"])) {
			$k_error = "Opinion towards kale is a required field.";
		} else {
			$kale = $_POST["kale"];
		}		
	
		if($s_error == "" && $animal_error == "" && $astro_error == "" && $k_error =="") {
			if($update == "false") {
				if(!($query = $mysqli->prepare("INSERT INTO innodb.settings(user,sex,animal,astro,exercise,art,study,music,kale) VALUES (?,?,?,?,?,?,?,?,?)"))) {
					echo 'Preparation failed: (' . $mysqli->errno . ') ' . $mysqli->error;
				}
				if(!$query->bind_param("sssssssss", $user, $sex, $animal, $astro, $exercise, $art, $study, $music, $kale)) {
					echo 'Failed to bind: (' . $query->errno . ') ' . $query->error;
				}
				if(!$query->execute()) {
					echo 'Execute failed: (' . $query->errno . ') ' . $query->error;
				}		
				$success = "Successfully updated settings.";
			} else {
				$sql = "UPDATE innodb.settings SET sex='$sex', animal='$animal', astro='$astro', exercise='$exercise', art='$art', study='$study', music='$music', kale='$kale' WHERE user='$user'";
				if($mysqli->query($sql) == TRUE) {
					$success = "Successfully edited settings.";
				} else {
					$success = "Unknown error.";
				}
			}
		}
	} 
	
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Super Accurate Horoscopes</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body>
		<div class="nav">
		<a href="home.php">Home</a> - <a href="settings.php">Edit Settings</a> - <a href="view.php">View Settings</a> - <a href="horoscope.php">Horoscope</a> - <a href="logout.php">Logout</a>
		</div>
		<div class="main">

			<p>Hello, <?php echo $user; ?>. </p>
			
			<p>For an accurate horoscope, please enter the following details. If you have already set your settings, they will be filled in for you below, and you may edit them if anything has changed.</p>
			
			<p><span class="error">* indicates a required field</span></p>
			<form action="" method="post">
				<b>Sex:</b><span class="error">*</span><br>
				<input type="radio" name="sex" <?php if($sex == "male") { echo "checked"; } ?> value="male">Male<br>
				<input type="radio" name="sex" <?php if($sex == "female") { echo "checked"; } ?> value="female">Female<br>
				<input type="radio" name="sex" <?php if($sex == "none") { echo "checked"; } ?>value="none">Prefer not to say<br>
				<span class="error"><?php echo $s_error; ?></span><br>
				<b>Favorite animal:</b><span class="error">*</span><br>
				<input type="text" name="animal" value="<?php echo $animal; ?>"/><br>
				<span class="error"><?php echo $animal_error; ?></span><br>
				<b>Astrological sign:</b><span class="error">*</span><br>
				<select name="astro">
					<option selected="selected"><?php echo $astro ?></option>
					<option disabled="disabled">------</option>
					<option value="Aries" name="astro">Aries</option>
					<option value="Taurus" name="astro">Taurus</option>
					<option value="Gemini" name="astro">Gemini</option>
					<option value="Cancer" name="astro">Cancer</option>
					<option value="Leo" name="astro">Leo</option>
					<option value="Virgo" name="astro">Virgo</option>
					<option value="Libra" name="astro">Libra</option>
					<option value="Scorpio" name="astro">Scorpio</option>
					<option value="Sagittarius" name="astro">Sagittarius</option>
					<option value="Capricorn" name="astro">Capricorn</option>
					<option value="Squarius" name="astro">Pisces</option>
					<option value="Ophiuchus" name="astro">Ophiuchus</option>
				</select><br>
				<span class="error"><?php echo $astro_error; ?></span><br>
				<b>Hobbies:</b><br>
				<input type ="checkbox" name="exercise" <?php if($exercise == "true") { echo "checked"; } ?> value="y">I enjoy exercise, indoor or outdoor<br>
				<input type ="checkbox" name="art" <?php if($art == "true") { echo "checked"; } ?> value="y">I enjoy creating or looking at art<br>
				<input type ="checkbox" name="study" <?php if($study == "true") { echo "checked"; } ?> value="y">I enjoy reading and learning new things<br>
				<input type ="checkbox" name="music" <?php if($music == "true") { echo "checked"; } ?> value="y">I enjoy listening to or creating my own music<br>
				<br>
				<b>Do you like kale?</b><span class="error">*</span><br>
				<input type="radio" name="kale" <?php if($kale == "yes") { echo "checked"; } ?> value="yes">Yes<br>
				<input type="radio" name="kale" <?php if($kale == "no") { echo "checked"; } ?> value="no">No<br>
				<span class="error"><?php echo $k_error; ?></span><br>
				<input type="submit" value="Submit">
				<span class="success"><?php echo $success; ?></span>
			</form>

		</div>
	</body>
</html>