<?php
$length = array(0.0);
for($i=1;$length[$i-1]<=5.20;$i++)
{
	$length[$i] = $length[$i-1] + 1.0 / ($i + 1);
}
$n = $i;
while(fscanf(STDIN, "%lf", $c) == 1 && $c > 0.000001)
{
	for($i=0;$i<$n;$i++)
	{
		if($c < $length[$i])
		{
			print $i." card(s)\n";
			break;
		}
	}
}