<?php
	$cur_time = localtime(time(), true);
	$cur_time = $cur_time['tm_hour'] . ":" . $cur_time['tm_min'] . ":" . $cur_time['tm_sec'];
	header("Refresh: 1");
?>
<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-4 Subhasri
		</title>
		<style>
			span {
				color: white;
				background-color: black;
			}
		</style>
	</head>
	<body>
		Digital Clock with current server time<br>
		<h2><span><?php echo $cur_time; ?></span></h2>
	</body>
</html>