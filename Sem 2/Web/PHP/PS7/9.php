<?php
    if(!isset($_SESSION['fname']))
    {
        if(isset($_GET['fname']))
        {
            $_SESSION['fname'] = $_GET['fname'];
        }
    }
    if(!isset($_SESSION['lname']))
    {
        if(isset($_GET['lname']))
        {
            $_SESSION['lname'] = $_GET['lname'];
        }
    }    
?>
<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-9 Subhasri
		</title>
	</head>
	<body>
		<h1> Store and retrive persistent data </h1><br>
		Enter data and it will be persistent<br><br>
		<form>
			<input type = "text" name = "fname" placeholder="First name"></input>
			<br><br>
			<input type = "text" name = "lname" placeholder="Last name"></input>
			<br><br>
			<input type = "submit" value = "Submit"></input>
		</form>
		<?php
			if(isset($_SESSION['fname']) && isset($_SESSION['lname']))
			{
				echo "<br><h1>Hello {$_SESSION['fname']} {$_SESSION['lname']}</h1>";
			}
			elseif(isset($_SESSION['fname']))
			{
				echo "<br><h1>Hello {$_SESSION['fname']} </h1>";
			}
			elseif(isset($_SESSION['lname']))
			{
				echo "<br><h1>Hello {$_SESSION['lname']} </h1>";
			}
		?>
	</body>
</html>