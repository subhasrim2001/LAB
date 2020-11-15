<?php
if(isset($_GET['month_temp'])) {
	$month_temp = $_GET['month_temp'];
	$temp_array = explode(',', $month_temp);
	$temp_array_length = count($temp_array);
	$tot_temp = 0;
	function average()
	{
		global $tot_temp;
		$tot_temp = 0;
		global $temp_array;
		foreach($temp_array as $temp)
		{
			$tot_temp += $temp;
		}
		global $temp_array_length;
		$avg_high_temp = $tot_temp/$temp_array_length;
		echo "Average Temperature is : ".$avg_high_temp. " "; 
	}
	sort($temp_array);
	function lowest()
	{
		global $temp_array;
		echo " <br>List of five lowest temperatures :";
		for ($i=0; $i< 5; $i++)
		{	 
			echo $temp_array[$i].", ";
		}	
	}
	function highest()
	{
		global $temp_array;
		global $temp_array_length;
		echo "<br>List of five highest temperatures :";
		for ($i=($temp_array_length-5); $i< ($temp_array_length); $i++)
		{
			echo $temp_array[$i].", ";
		}	
	}
}

?>
<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-5 Subhasri
		</title>
	</head>
	<body>
		<form>
			Enter temp in the format t1,t2,t3 and so on:
			<input type="text" name="month_temp" placeholder="Enter temp"></input>
			<br><br>
			<input type="submit">
		</form>
		<br><br>
		<?php
			if(isset($_GET['month_temp']))
			{
				average();
				highest();
				lowest();
			}
		?>
	</body>
</html>