$n, $s = gets.split.map &:to_i
$visit = Array.new 2 * $n + 1, false 
$path = Array.new 3
$lines = []
$first = {}
def dfs1(depth)
    if depth == 3 then
        return if $path[0] + $path[1] + $path[2] != $s
        key = $path[1]
        val = $lines.length
        if $first.has_key? key then
            $first[key].push val
        else
            $first[key] = [val]
        end
        $lines.push $path.clone
    else
        (1..$n * 2).each do |i|
            if not $visit[i] then
                $visit[i] = true
                $path[depth] = i
                dfs1 depth + 1
                $visit[i] = false
            end
        end
    end
end
dfs1 0
$ans = []
$path = Array.new $n
def dfs2(depth)
    if depth == $n then
        return if $lines[$path[depth - 1]][-1] != $lines[$path[0]][1]
        s = ''
        (0...depth).each do |i|
            s += $lines[$path[i]].join ''
        end
        $ans.push s
    elsif depth == 0
        (0...$lines.length).each do |i|
            line = $lines[i]
            $visit[line[0]] = true
            $visit[line[1]] = true
            $path[depth] = i
            dfs2 depth + 1
            $visit[line[1]] = false
            $visit[line[0]] = false
        end
    else
        last_line = $lines[$path[depth - 1]]
        $first[last_line[-1]].each do |i|
            line = $lines[i]
            next if $visit[line[0]] or $visit[line[1]]
            next if depth != $n - 1 and $visit[line[2]]
            next if line[0] < $lines[$path[0]][0]
            $visit[line[0]] = true
            $visit[line[1]] = true
            $path[depth] = i
            dfs2 depth + 1
            $visit[line[1]] = false
            $visit[line[0]] = false
        end
    end
end
dfs2 0
$ans.sort.each do |a|
    puts a
end
