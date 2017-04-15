proc fact {n} {
    if {$n == 0} {
        return 1
    }
    return [expr $n*[fact [expr $n-1]]]
}
set line [gets stdin]
scan $line "%d" n
puts [fact $n]
