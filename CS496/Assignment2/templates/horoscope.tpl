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
	{% for d in data.user_data %}
	<h1>Your Personalized Horoscope</h1>
		{% for a in data.h_array %}
			{% if a.set == 'false' %}
				<p>Please enter your <a href="settings.php">settings</a> to view your personalized horoscope.</p>
			{% else %}
				{% if d.sex == 'female' %}
					{{ a.female }}
				{% elseif d.sex == 'male' %}
					{{ a.male }}
				{% endif %}
				{% if d.animal == 'dog' %}
					{{ a.dog }}
				{% elseif d.animal == 'cat' %}
					{{ a.cat }}
				{% endif %}
				{% if d.astro == 'Aries' %}
					{{ a.aries }}
				{% endif %}
				{% if d.astro == 'Taurus' %}
					{{ a.taurus }}
				{% endif %}
				{% if d.astro == 'Cancer' %}			
					{{ a.cancer }}
				{% endif %}
				{% if d.astro == 'Pisces' %}
					{{ a.pisces }}
				{% endif %}
				{% if d.astro == 'Capricorn' %}
					{{ a.capricorn }}
				{% endif %}
				{% if d.astro == 'Sagittarius' %}
					{{ a.sagittarius }}
				{% endif %}
				{% if d.astro == 'Gemini' %}
					{{ a.gemini }}
				{% endif %}
				{% if d.astro == 'Libra' %}
					{{ a.libra }}
				{% endif %}
				{% if d.astro == 'Virgo' %}
					{{ a.virgo }}
				{% endif %}
				{% if d.astro == 'Aquarius' %}
					{{ a.aquarius }}
				{% endif %}
				{% if d.astro == 'Leo' %}
					{{ a.leo }}
				{% endif %}
				{% if d.astro == 'Ophiuchus' %}
					{{ a.ophiuchus }}
				{% endif %}
				
				{% if d.exercise == 'true' %}
					{{ a.ex }}
				{% endif %}
				{% if d.art == 'true' %}
					{{ a.ar }}
				{% endif %}
				{% if d.music == 'true' %}
					{{ a.mu }}
				{% endif %}
				{% if d.study == 'true' %}
					{{ a.st }}
				{% endif %}
				{% if d.kale == 'yes' %}
					{{ a.yeskale }}
				{% elseif d.kale == 'no' %}
					{{ a.nokale }}
				{% endif %}				
			{% endif %}
		{% endfor %}
	{% endfor %}
		
  </body>
</html>