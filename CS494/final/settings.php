<?php
	$user = "";
	session_start();
	if(!isset($_SESSION['loggedin'])) {
		header("Location: main.php");
	}
	if(isset($_SESSION['name'])) {
		$user = $_SESSION['name'];
	}
	
	$error1 = false;
	$error2 = false;
	$error3 = false;
// Image upload library from http://www.reconn.us/file_uploading.html
// I only changed the error handling so it could print in line with  my style formatting
//define a maxim size for the uploaded images in Kb
define ("MAX_SIZE","100"); 

//This function reads the extension of the file. It is used to determine if the file is an image by checking the extension. 
function getExtension($str) {
	$i = strrpos($str,".");
	if (!$i) { return ""; }
	$l = strlen($str) - $i;
	$ext = substr($str,$i+1,$l);
	return $ext;
}

//This variable is used as a flag. The value is initialized with 0 (meaning no error found) and it will be changed to 1 if an errro occures. If the error occures the file will not be uploaded.
$errors=0;
//checks if the form has been submitted
if(isset($_POST['Submit'])) 
{
//reads the name of the file the user submitted for uploading
	$image=$_FILES['image']['name'];
//if it is not empty
	if ($image) 
	{
//get the original name of the file from the clients machine
		$filename = stripslashes($_FILES['image']['name']);
//get the extension of the file in a lower case format
		$extension = getExtension($filename);
		$extension = strtolower($extension);
//if it is not a known extension, we will suppose it is an error and will not upload the file, otherwize we will do more tests
	if (($extension != "jpg"))	
	{
//print error message
		//error 1: unknown extension
		$error1 = true;
	}
	else
	{
//get the size of the image in bytes
//$_FILES['image']['tmp_name'] is the temporary filename of the file in which the uploaded file was stored on the server
		$size=filesize($_FILES['image']['tmp_name']);

//compare the size with the maxim size we defined and print error if bigger
	if ($size > MAX_SIZE*1024)
	{
		$error2 = true; // oversize
	}
//we will give an unique name
$image_name= $user.'.'.$extension;
//the new name will be containing the full path where will be stored (images folder)
$newname="images/".$image_name;
//we verify if the image has been uploaded, and print error instead
$copied = copy($_FILES['image']['tmp_name'], $newname);
if (!$copied) 
{
	$error3 = true; // unsuccessful copy/unknown root cause
}}}}

//If no errors registred, print the success message
if(isset($_POST['Submit']) && !$error1 && !$error2 && !$error3) 
{
	$success = true;
}

?>

<!DOCTYPE html>
<html>

<head>
        <meta charset="utf-8">
        <title>Pokemon Team Builder</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src ="ajax_verify.js"></script>
		
</head>

<body>
<div class = "container">
	<div class="left-nav">
	<h3>Navigation</h3>
	<ul>
		<li><a href="list_home.php">My Lists</a></li>
		<li><a href="create_list.php">Create a List</a></li>
		<li><a href="friends.php">See Lists Shared With Me</a></li>
		<li><a href="find_friends.php">Find Friends</a></li>
	</ul>
	</div>
	<div class="main">
	<h1>Account Settings</h1>

	<h3>Upload a profile picture</h3>
	<p>Profile pictures must adhere to the following specifications:</p>
		<ul>
			<li>Must be a .jpg format image</li>
			<li>Must be under 100 Kb</li>
			<li>Regardless of dimensions, it will be displayed as 100x100px</li>
		</ul>
	<form name="newad" method="post" enctype="multipart/form-data" action="">
	<table>
		<tr><td><input type="file" name="image"></td></tr>
		<tr><td><input name="Submit" type="submit" value="Upload Profile Picture"></td></tr>
	</table>	
	</form>
	<?php if(!$success) { ?>
	<div class="error"> <?php
		if($error1) { ?>
			Error: invalid extension. Only .jpg format images are allowed.
		<?php } 
		if($error2) { ?>
			Error: file over size limit. Files must be under 100 Kb.
		<?php }
		if($error3) { ?>
			Error: file upload unsuccessful. Please try again. 
		<?php } 
	} else { ?>
		File upload successful!
	<?php } ?>
		</div>
	</div>
	<div class = "right-nav">
	<h3>My Account</h3>
	<p>Currently logged in as: <?php echo $user ?></p>
	<ul>
		<li><a href="settings.php">Settings</a></li>
		<li><a href="logout.php">Log Out</a></li>
	</ul>
	</div>
</div>
</body>
</html>