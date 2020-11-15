<?php
	if(isset($_GET['fname']))
	{
		setcookie("fname", $_GET['fname']);
	}
	if(isset($_GET['lname']))
	{
		setcookie("lname", $_GET['lname']);
	}
?>
<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-11 Subhasri
		</title>
	</head>
	<body>
		<h1> Storing and retriving cookies </h1>
		<br><br>
		<form>
			<input type = "text" name = "fname" placeholder="First name"></input>
			<br><br>
			<input type = "text" name = "lname" placeholder="Last name"></input>
			<br><br>
			<input type = "submit" value="Submit"></input>
		</form>
		<br>
		If you refresh the page, data will exist due to cookies.
		<br>
		<?php
			if(isset($_GET['fname']))
			{
				echo "First name: {$_COOKIE['fname']} <br><br>";
			}
			if(isset($_GET['lname']))
			{
				echo "Last name: {$_COOKIE['lname']}";
			}
		?>
	</body>
</html>