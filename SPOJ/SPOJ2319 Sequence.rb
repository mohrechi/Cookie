maxn = 105

$c = Array.new maxn
$cs = Array.new maxn, 0
$csj = Array.new maxn, 0
maxn.times do |i|
    $c[i] = Array.new maxn, 0
    $c[i][0] = $cs[i] = 1
    (1..i).each do |j|
        $c[i][j] = $c[i - 1][j] + $c[i - 1][j - 1]
        $cs[i] += $c[i][j]
        $csj[i] += j * $c[i][j]
    end
end

def calc_sum(x)
    bits = Array.new
    while x > 0
        bits.push (x & 1)
        x >>= 1
    end
    num, cnt = 0, 0
    (bits.length - 1).downto(0).each do |i|
        if bits[i] == 1 then
            num += cnt * $cs[i] + $csj[i]
            cnt += 1
        end
    end
    num + cnt
end

def calc_interval(x, y)
    if x == 0 then
        calc_sum(y)
    else
        calc_sum(y) - calc_sum(x - 1)
    end
end

def calc_group(s)
    group_num = 0
    last, final = 0, 2 ** $k - 1
    while last <= final do
        l, r = last, final
        new_last = last
        while l <= r do
            mid = (l + r) / 2
            if calc_interval(last, mid) <= s then
                l = mid + 1
                new_last = [new_last, mid].max
            else
                r = mid - 1
            end
        end
        return $m + 1 if calc_interval(last, new_last) > s
        last = new_last + 1
        group_num += 1
        break if group_num > $m
    end
    group_num
end

$k, $m = gets.split.map &:to_i
s = 2 ** $k * $k
l, r = 1, s
while l <= r do
    mid = (l + r) / 2
    if calc_group(mid) <= $m then
        r = mid - 1
        s = [mid, s].min
    else
        l = mid + 1
    end
end
puts s
