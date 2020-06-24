<?php
    if(isset($_GET['URL']))
    {
        $conn= mysqli_connect("localhost", "root", "", "URL");
        if (!$conn)
        {
            echo "Error: " . mysqli_connect_error();
        }
        else
        {
            $sql = "INSERT INTO URLTable(URL, Description) VALUES('$_GET[URL]', '$_GET[Description]')";
            if (mysqli_query($conn, $sql))
             {
                //
             }
             else
             {
                 echo "Error: " . $sql. "<br>" . mysqli_error($conn);
             }
        }
    }

?>

<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-15 Subhasri
		</title>
        <style>
            table,th,td,tr{
                border: 2px solid blue;
            }
        </style>
	</head>
	<body>
        <h1>Adding URL and Description into Database = URL, Table = URLTable</h1>
        <form>
            <h3>Enter the URL</h3>
            <input type = "text" name = "URL" placeholder="Enter the URL"></input>
			<br><br>
            <h3>Enter the URL Description</h3>
            <input type = "text" name = "Description" placeholder="Enter the Description "></input>
			<br><br>
            <input type="submit"></input>
        </form>
        <?php

            if(isset($_GET['URL']))
            {
                $sql = "SELECT * FROM URLTable";
                $retval = mysqli_query($conn,$sql);
                $row;
                echo "<h2>URLTable</h2>";
                echo "<table>";
                echo "<tr>";
                echo "<th>URL</th>";
                echo "<th>Description</th>";
                echo "</tr>";
                while ($row = mysqli_fetch_assoc($retval))
                {
                    echo "<tr>";
                    echo "<td>$row[URL]</td>";
                    echo "<td>$row[Description]</td>";
                    echo "</tr>";
                }
                echo "</table>";
            }
        ?>
	</body>
</html>