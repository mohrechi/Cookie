<?php
$pi = 3.1415926;
fscanf(STDIN, "%d", $caseNumber);
for($i=1;$i<=$caseNumber;$i++)
{
	fscanf(STDIN, "%lf%lf", $x, $y);
	$year = (int)ceil($pi * ($x * $x + $y * $y) / 100);
	print "Property ".$i.": This property will begin eroding in year ".$year.".\n";
}
print "END OF OUTPUT.";