<?php
	$email = $_POST["email"];
	$hash = $_POST["hash"];
	$to_email = $email;
	$subject = "Order Confirmed";
	$body = "Check your order here http://localhost/package/login/cart/public/order/" . $hash ;
	$headers = "From: subhasrim2001.2@gmail.com";
	if (mail($to_email, $subject, $body, $headers)) {
		echo "Email successfully sent to $to_email...";
	} else {
		echo "Email sending failed...";
	}
?> 