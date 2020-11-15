<!DOCTYPE html> 
<html>
<head>
	<title> PS7-14 Subhasri </title>
</head>
<body>
<?php 
	$servername = "localhost";
	$username = "root"; 
	$password = "";
	$dbname = "phpworksheet"; 
	$a=[];
	$conn = mysqli_connect($servername, $username, $password, $dbname);
	if ($conn->connect_error)
	{
		die("Connection failed: " . $conn->connect_error);
	}
	$sql = "SELECT * FROM student"; 
	$result = $conn->query($sql);
	echo "<br>";
	echo "<center> BEFORE SORTING </center>";
	echo "<table border='2'>";
	echo "<tr>"; 
	echo "<th>ID</th><th>FIRST NAME</th><th>LAST NAME</th><th>YEAR</th><th>TYPE</th></tr>";
	if ($result->num_rows > 0)
	{ 
		while($row = $result->fetch_assoc())
		{ 
			echo "<tr>"; 
			echo "<td>". $row["id"]."</td>";
			echo "<td>". $row["firstName"]."</td>";
			echo "<td>". $row["lastName"]."</td>"; 
			echo "<td>". $row["year"]."</td>"; 
			echo "<td>". $row["type"]."</td></tr>"; 
			array_push($a,$row["firstName"]); 
		} 
		asort($a);
	}
	else
	{
		echo "Table is Empty"; 
	}
	echo "</table>";
	echo "<center> AFTER SORTING(By First Name) </center>";
	echo "<table border='2'>";
	echo "<tr>"; 
	echo "<th>ID</th><th>FIRST NAME</th><th>LAST NAME</th><th>YEAR</th><th>TYPE</th></tr>";
	if(count($a) == 0)
	{
		echo "Table is Empty";
	}
	else
	{
		for($i = 0; $i < count($a); $i++)
		{
			$sql = "SELECT * FROM student WHERE firstName='";
			$sql.= $a[$i];
			$sql.= "'";
			$result = $conn->query($sql);
			$row = $result->fetch_assoc();
				echo "<tr>"; 
				echo "<td>". $row["id"]."</td>";
				echo "<td>". $row["firstName"]."</td>";
				echo "<td>". $row["lastName"]."</td>"; 
				echo "<td>". $row["year"]."</td>"; 
				echo "<td>". $row["type"]."</td></tr>"; 
		}
	}
	echo "</table>";
	$conn->close();	
?>
</body>
</html> 