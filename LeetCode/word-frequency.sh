cat 'words.txt' | tr -s ' ' '\n' | sort | uniq -c | sort -r -k 1,1 | awk '{print $2" "$1}'