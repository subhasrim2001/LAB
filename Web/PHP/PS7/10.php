<?php
session_start();
$conn = mysqli_connect("localhost", "root", "", "phpworksheet");
if(isset($_POST['add_to_cart']))
{
	if(isset($_SESSION["shopping_cart"]))
	{
		$item_array_id = array_column($_SESSION["shopping_cart"], "item_id");
		if(!in_array($_GET["id"], $item_array_id))
		{
			$count = count($_SESSION["shopping_cart"]);
			$item_array = array(
				'item_id'			=>	$_GET["id"],
				'item_name'			=>	$_POST["hidden_name"],
				'item_price'		=>	$_POST["hidden_price"],
				'item_quantity'		=>	$_POST["quantity"]
			);
			$_SESSION["shopping_cart"][$count] = $item_array;
		}
		else
		{
			echo '<script>alert("Item Already Added")</script>';
		}
	}
	else
	{
		$item_array = array(
			'item_id'			=>	$_GET["id"],
			'item_name'			=>	$_POST["hidden_name"],
			'item_price'		=>	$_POST["hidden_price"],
			'item_quantity'		=>	$_POST["quantity"]
		);
		$_SESSION["shopping_cart"][0] = $item_array;
	}
}
if(isset($_GET["action"]))
{
	if($_GET["action"] == "delete")
	{
		foreach($_SESSION["shopping_cart"] as $keys => $values)
		{
			if($values["item_id"] == $_GET["id"])
			{
				unset($_SESSION["shopping_cart"][$keys]);
				echo '<script>alert("Item Removed")</script>';
				echo '<script>window.location="10.php"</script>';
			}
		}
	}
}	
?>
<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-10 Subhasri
		</title>
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js"></script>
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" />
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
		<style>
			.one {
				border: 1px solid #333;
				background-color: #f1f1f1;
				border-radius:5px;
				padding:16px;
			}
			img {
				width: 400px;
				height: 400px;
			}
			table, tr, th, td {
				border: 1px solid black;
			}
		</style>
	</head>
	<body>
		<div class="container">
		<h3 align = "center">Catalogue</h3><br>
		<?php
			$sql = "SELECT * FROM product ORDER BY id ASC";
			$result = mysqli_query($conn, $sql);
			if(mysqli_num_rows($result) > 0)
			{
				while($row = mysqli_fetch_array($result))
				{
		?>
					<div class="col-md-4">
					<form method="post" action="10.php?action=add&id=<?php echo $row['id']; ?>">
						<div class="one" align="center">
						<img class="img-responsive" src="<?php echo $row["image"]; ?>"></img><br>
						<h4 class="text-info"><?php echo $row["name"]; ?></h4>
						<h4 class="text-danger">Rs. <?php echo $row["price"]; ?></h4>
						<input type="text" name="quantity" value="1"></input>
						<input type="hidden" name="hidden_name" value="<?php echo $row["name"]; ?>" />
						<input type="hidden" name="hidden_price" value="<?php echo $row["price"]; ?>" />
						<input type="submit" name="add_to_cart" style="margin-top:5px;" class="btn btn-success" value="Add to Cart" />
						</div>
					</form>
					<br><br><br><br><br><br><br><br>
					</div>
		<?php
				}
			}
		?>
		<br>
			<h3>Order Details</h3>
			<div>
				<table class="table table-bordered">
					<tr>
						<th>Item Name</th>
						<th>Quantity</th>
						<th>Price</th>
						<th>Total</th>
						<th>Action</th>
					</tr>
					<?php
					if(!empty($_SESSION["shopping_cart"]))
					{
						$total = 0;
						foreach($_SESSION["shopping_cart"] as $keys => $values)
						{
					?>
					<tr>
						<td><?php echo $values["item_name"]; ?></td>
						<td><?php echo $values["item_quantity"]; ?></td>
						<td>$ <?php echo $values["item_price"]; ?></td>
						<td>$ <?php echo number_format($values["item_quantity"] * $values["item_price"], 2);?></td>
						<td><a href="10.php?action=delete&id=<?php echo $values["item_id"]; ?>"><span>Remove</span></a></td>
					</tr>
					<?php
							$total = $total + ($values["item_quantity"] * $values["item_price"]);
						}
					?>
					<tr>
						<td colspan="3" align="right">Total</td>
						<td align="right">$ <?php echo number_format($total, 2); ?></td>
						<td></td>
					</tr>
					<?php
					}
					?>
						
				</table>
			</div>
	</body>
</html>