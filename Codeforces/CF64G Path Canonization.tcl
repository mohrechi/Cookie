set s [gets stdin]
while {[regsub {/\.(/|$)} $s / s]} {}
while {[regsub {/[[\w\.]+/\.\.(/|$)} $s {/} s]} {}
regsub /$ $s {} s
if {$s == ""} {
    set s /
}
if {[regexp {^/\.\.(/|$)} $s]} {
    puts -1
} else {
    puts $s
}
