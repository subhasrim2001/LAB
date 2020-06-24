<?php
    $states = "Mississippi Alabama Texas Massachusetts Kansas";
    $statesArray = [];
    $states1 = explode(' ',$states);
    foreach($states1 as $state)
	{
        $pattern = '/xas$/';
		if(preg_match($pattern, $state))
		{
       		$statesArray[0] = ($state);
		}
	}
    foreach($states1 as $state)
	{
		$pattern = '/^k.*s$/i';
        if(preg_match($pattern, $state))
		{
            $statesArray[1] = ($state);
		}
	}
    foreach($states1 as $state) 
	{
        $pattern = '/^M.*s$/';
		if(preg_match($pattern, $state))
		{
            $statesArray[2] = ($state);
		}
	}
    foreach($states1 as $state) 
	{
        $pattern = '/a$/';
		if(preg_match($pattern, $state))
		{
            $statesArray[3] = ($state);
		}
	}
    foreach($states1 as $state) 
	{
		$pattern = '/^M/';
        if(preg_match($pattern, $state))
		{
            $statesArray[4] = ($state);
		}
	}
	echo "Elements of statesArray:";
    foreach ( $statesArray as $element => $value )
	{
        print("<br>" . $value . " is the element " . $element);
    }
?>
<!DOCTYPE html>
<html>
	<head>
		<title>
			PS7-12 Subhasri
		</title>
	</head>
	<body>
		
	</body>
</html>