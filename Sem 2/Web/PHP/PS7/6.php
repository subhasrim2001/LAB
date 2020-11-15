<?php
	$conj;
    if(isset($_GET['sent'])) {
		$ar = str_split($_GET['sent']);
        $conj = $ar[0];
		for ($i=1; $i < count($ar); $i++) {
			if($ar[$i] != " ") {
				$conj.=$ar[$i];
			}
		}
    }
?>
<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-6 Subhasri
		</title>
	</head>
	<body>
		<h1>Sentence with spaces:</h1>
        <form>
            <input type = "text" name = "sent" placeholder="Enter a sentence with spaces">
			<br><br>
            <input type="submit">
        </form>
		<br><br>

        <?php
         if(isset($_GET['sent']))
        {
            echo "<p> Sentence without spaces: <br>" . $conj . "</p>";
        }
        ?>
	</body>
</html>