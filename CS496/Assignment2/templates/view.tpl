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
	<h1>Your Settings</h1>
	{% for d in data.user_data %}
		{% if data.set == 'false' %}
			<p>Please enter your <a href="settings.php">settings</a> to view your personalized horoscope.</p>
		{% else %}
			{% for d in data.user_data %}
				<h1>The current settings for {{ d.user }}:</h1>
				<h3>Sex</h3>
					<p>{{ d.sex}}</p>
				<h3>Favorite Animal</h3>
					<p> {{ d.animal }} </p>
				<h3>Astrological Sign</h3>
					<p>{{ d.astro }}</p>
				<h3>Hobbies</h3>
					{% if d.exercise == "true" %}
						<p>Exercise</p>
					{% endif %}
					{% if d.art == "true" %}
						<p>Art</p>
					{% endif %}
					{% if d.study == "true" %}
						<p>Study</p>
					{% endif %}
					{% if d.music == "true" %}
						<p>Music</p>
					{% endif %}	
				<h3>Preference toward kale</h3>
					{% if d.kale == "no" %}
						<p> Dislike </p>
					{% else %}
						<p>Like</p>
					{% endif %}
			{% endfor %}
		{% endif %}
	{% endfor %}
  </body>
</html>