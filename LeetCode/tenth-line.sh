num=$(cat file.txt | wc -l)
if (( $num >= 10 )); then
    head -n10 file.txt | tail -n1
fi