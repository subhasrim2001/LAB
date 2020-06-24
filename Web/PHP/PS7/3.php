<?php
	session_start();
	if(isset($_SESSION['views'])) {
		$_SESSION['views'] += 1;
	}
	else {
	$_SESSION['views'] = 1;		
	}

?>
<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-3 Subhasri
		</title>
	</head>
	<body>
		<h2> Visitors </h2><br>
		No of visitors : 
		<?php
			echo $_SESSION['views'];
		?>		
	</body>
</html>