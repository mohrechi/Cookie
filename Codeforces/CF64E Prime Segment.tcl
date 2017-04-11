proc not_prime {n} {
    for {set i 2} {$i < $n} {incr i} {
        if {$n % $i == 0 } {
            return 1
        }
    }
    return 0
}


set line [gets stdin]
scan $line "%d" n[]
set l $n
set r $n
while {[not_prime $l]} {
    incr l -1
}
while {[not_prime $r]} {
    incr r
}
puts "$l $r"
