i=1
while read word; do
  array[i]=$word
  i=$((i + 1))
done
array=("${array[@]}" "${array[@]}" "${array[@]}")
echo "${array[@]}"
