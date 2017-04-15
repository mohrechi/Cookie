for {set n [gets stdin]} {$n > 0} {incr n -1} {
    lappend a [gets stdin]
}
set a [lsort -decreasing -integer -index 1 [lsort -index 0 $a]]
foreach {v} $a {
    set is [lsearch -all $a "* [lindex $v 1]"]
    set is "[expr {1+[lindex $is 0]}] [expr [llength $is]>1?1+[lindex $is end]:\"\"]"
    puts "[join $is -] [lindex $v 0]"
}
