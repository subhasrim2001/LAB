<?php
    $answer;
	if(isset($_GET['word']))
	{
		$word = $_GET['word'];
		$answer = $word;
		$rev_word = strrev($word);
		if(strcmp($word, $rev_word) == 0)
		{
			$answer.= " is a palindrome.";
		}
		else
		{
			$answer.= " is not a palindrome.";
		}
	}
?>
<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-7 Subhasri
		</title>
	</head>
	<body>
		<h1>Palindrome Checking</h1><br>
		<form>
			<input type = "text" name = "word" placeholder="Enter value"></input>
			<br><br>
			<input type = "submit"></input>
		</form>
		<br>
        <?php
        if(isset($_GET['word']))
        {
            echo "<p>" . $answer . "</p>";
        }
        ?>
		<br>
		<br>
	</body>
</html>