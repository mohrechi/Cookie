set line [gets stdin]
scan $line "%d %d %d" n m k
puts [expr ($k-1)/$n + ($k-1)%$n*$m + 1]
