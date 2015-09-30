i=1
while read word; do
  array[i]=$word
  i=$((i + 1))
done
echo "${array[@]/[A-za-z]/.}"
