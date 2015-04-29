<?php
	include 'Twig/Twig-1.18.0/lib/Twig/Autoloader.php';
	Twig_Autoloader::register();

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
	
	$mysqli = new mysqli('login info');
	
	if ($mysqli->connect_error) {
    die('Connect Error: (' . $mysqli->connect_errno . ') ' . $mysqli->connect_error);
	}

	//check if settings already entered by user
	$usersearch = "SELECT * FROM innodb.settings WHERE user = '$user'";
	if($rows = $mysqli->query($usersearch)) {
		if($rows->num_rows == 0) {
			$settings = "false";
			$obj[] = "false";
		} else {
			$settings = "true";
			while($result = $rows->fetch_object()) {
				$obj[] = $result;
			}
		}
	}
	
	$alldata = array (
		'user_data' => $obj,
		'set' => $settings
	);
	
try{
  // define template directory location
  $loader = new Twig_Loader_Filesystem('templates');
  
  // initialize Twig environment
  $twig = new Twig_Environment($loader);
  
  // load template
  $template = $twig->loadTemplate('view.tpl');

  // set template variables
  // render template
  echo $template->render(array (
	'data' => $alldata
  ));
  
} catch (Exception $e) {
  die ('ERROR: ' . $e->getMessage());
}
?>