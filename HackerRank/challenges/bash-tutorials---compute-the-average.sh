read N
total=0
for i in $(seq 1 $N); do
  read num
  total=$(( $total + $num ))
done
printf "%.3f\n" `echo "$total / $N" | bc -l`
