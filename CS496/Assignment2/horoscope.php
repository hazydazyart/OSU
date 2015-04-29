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
	
	// Set up horoscope strings
	$female = "While you may love your pet above everything else, please note that marrying animals is still illegal in all 50 states.";
	$male = "Please note that while it can be difficult to fend off unwanted advances, dandruff and strong body odor are not the best ways to avoid conflict.";

	$animal1 = "The reason people avoid you is because you try to apply pack mentality to human beings.";
	$animal2 = "Remember that next time you visit the pet store that there is such a thing as too many cats.";
	$animal3 = "Your attempts to be creative and 'quirky' will often fall flat with others.";
	
	$aries = "You have been experiencing conflicts within your circle of friends lately. Being less of a selfish jerk as the moon moves into the third quarter may help. Sign to watch out for: Sagittarius.";
	$taurus = "No man can halt the moving of the stars above. This is a metaphor advising you to avoid being so obnoxiously stubborn. Sign to watch out for: Sagittarius.";
	$gemini = "One's merits should speak for themselves. Mercury moving into the second house is the perfect time to stop posting 20 identical selfies daily. Sign to watch out for: Sagittarius.";
	$cancer = "Simply because Cancer is the sign of the crab does not give you free reign to be a moody jerk. Sign to watch out for: Sagittarius.";
	$leo = "Leos are known for their great egos. This week, Leos should watch out and avoid flexing needlessly in tinted windows, as you can never be too sure who is behind them, judging you. Sign to watch out for: Sagittarius.";
	$virgo = "Love is in the air as spring goes into bloom. Not for you, of course, but speaking in general. Sign to watch out for: Sagittarius.";
	$libra = "Libras are known to be flaky. When thinking about how all of your friendships have gone wrong, you may find the answer is within your own personality. Sign to watch out for: Sagittarius.";
	$scorpio = "Showing up at the house of the love of your life unexpected - especially before you have even officially met - works better in film than in real life. Try not to let the infamous Scorpio obsessiveness end in a restraining order. Sign to watch out for: Sagittarius.";
	$sagittarius = "Most people tend to think of Sagittarius as the 'best' sign - they are fit, well-spoken, and generally confident people. You could at least pick one of these options to aspire to being. Sign to watch out for: All of them.";
	$capricorn = "Your friends are aware that you eye their wallets every time they pay for something. Sign to watch out for: Sagittarius.";
	$aquarius = "Your relationship with your partner may become strained this week as they begin to tire of endless trick questions like 'Does this make me look fat?' Sign to watch out for: Sagittarius.";
	$pisces = "Wearing shirts with clever math jokes on them are not the best way to share your high intellect with others. Sign to watch out for: Sagittarius";
	$ophiuchus = "There are only 12 zodiac signs; you are either a liar or a hippy.";
	
	$ex = "Skipping leg day may lead to a sharply decreasing level of swole with Venus in the first quarter.";
	$ar = "It is good to have hobbies, but please remember that not all of them can be made into a career.";
	$mu = "The great master composers roll in their grave every time you refer to your new beat made in FruityLoops as a masterpiece.";
	$st = "You likely suffer from a Vitamin D deficiency.";
	$all = "People around you are beginning to catch on to the fact that you are a compulsive liar - beware.";
	
	$nokale = "You appear to have a lack of appreciation for the finer things in life. It would behoove you to check the nutritional content of your next Hot Pocket dinner.";
	$yeskale = "You are a paragon of health and prosperity. Do not let the odd odors your food elicits put you off your path.";
	
	$mysqli = new mysqli('login info');
	
	if ($mysqli->connect_error) {
    die('Connect Error: (' . $mysqli->connect_errno . ') ' . $mysqli->connect_error);
	}

	//check if settings already entered by user
	$usersearch = "SELECT * FROM innodb.settings WHERE user = '$user'";
	if($rows = $mysqli->query($usersearch)) {
		if($rows->num_rows == 0) {
			$settings = "false";
			$obj[] = "";
		} else {
			$settings = "true";
			while($result = $rows->fetch_object()) {
				$obj[] = $result;
			}
		}
	}
	
	$alldata = array (
		'user_data' => $obj,
		'h_array' => array (
			array ('male' => $male), 
			array ('female' => $female), 
			array ('dog' => $animal1),
			array ('cat' => $animal2),
			array ('other' => $animal3),
			array ('aries' => $aries), 
			array ('taurus' => $taurus), 
			array ('gemini' => $gemini), 
			array ('cancer' => $cancer), 
			array ('leo' => $leo), 
			array ('virgo' => $virgo), 
			array ('sagittarius' => $sagittarius), 
			array ('capricorn' => $capricorn), 
			array ('aquarius' => $aquarius), 
			array ('pisces' => $pisces), 
			array ('ophiuchus' => $ophiuchus),
			array ('ex' => $ex), 
			array ('ar' => $ar), 
			array ('mu' => $mu), 
			array ('st' => $st), 
			array ('all' => $all), 
			array ('nokale' => $nokale), 
			array ('yeskale' => $yeskale), 
			array ('set' => $settings)
		),
	);
	
try{
  // define template directory location
  $loader = new Twig_Loader_Filesystem('templates');
  
  // initialize Twig environment
  $twig = new Twig_Environment($loader);
  
  // load template
  $template = $twig->loadTemplate('horoscope.tpl');

  // set template variables
  // render template
  echo $template->render(array (
    'data' => $alldata,
  ));
  
} catch (Exception $e) {
  die ('ERROR: ' . $e->getMessage());
}
?>