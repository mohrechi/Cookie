i=0
while read array[$i]; do
  i=$((i + 1))
done
declare -a pattern=(${array[@]/*[Aa]*/})
echo "${pattern[@]}"
