<?php
	$isValid = "false";
	if(isset($_POST['userId']))
	{
		$conn = mysqli_connect("localhost", "root", "", "phpworksheet");
		if(!$conn)
		{
			echo "Error: " . mysqli_connect_error();
		}
		else
		{
			$sql = "SELECT * FROM ps7_16";
			$retval = mysqli_query($conn, $sql);
			$row;
			while($row = mysqli_fetch_assoc($retval))
			{
				if($_POST['userId'] == $row['userId'] && $_POST['password'] == $row['password'])
				{
					$isValid = "true";
				}
			}
		}
	}
?>
<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-16 Subhasri
		</title>
	</head>
	<body>
		<h1>Authentication</h1>
		<form method="post">
			<h3>User Id:</h3>
			<input type = "text" name = "userId" placeholder = "User ID"></input>
			<br><br>
			<h3>Password:</h3>
			<input type = "password" name = "password" placeholder = "Password"></input>
			<br><br>
			<input type = "submit"></input>
		</form>
		<?php
			if(isset($_POST['userId']))
			{
				if($isValid == "true") 
				{
					header("Location: 16_protected.html");
				}
				else
				{
					echo "Will not open protected page";
				}
			}
		?>
	</body>
</html>