flag=0
while read line || [ -n "$line" ];
do
  if [ $flag -eq 3 ]
  then 
    printf "\n"
    flag=1
  elif [ $flag -eq 0 ]
  then
    ((flag=flag + 1))
  else 
    printf ";"
    ((flag=flag + 1))
  fi
  printf "$line"
done