flag=0
while read line 
do
  if [ $flag -eq 1 ] 
  then 
    printf ";"
  else 
    flag=1 
  fi
  printf "$line"
done
