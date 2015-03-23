i=0
while read array[$i]; do
  i=$(($i + 1))
done
echo ${array[@]}
