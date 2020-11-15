<?php
	if(isset($_GET['email']))
	{
		$email = $_GET['email'];
		if(filter_var($email, FILTER_VALIDATE_EMAIL))
		{
			$msg = "The email id is valid";
		}
		else
		{
			$msg = "The email id is invalid";
		}
	}
?>
<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-13 Subhasri
		</title>
	</head>
	<body>
		<h1>Validate Email </h1>
		<form>
			<input type = "text" name = "email" placeholder = "Enter a email"></input>
			<br><br>
			<input type = "submit"></input>
		</form>
		<br><br>
		<?php
		if(isset($_GET['email']))
		{
			echo $msg;
		}
		?>
	</body>
</html>