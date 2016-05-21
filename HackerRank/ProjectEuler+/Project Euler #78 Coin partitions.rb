MAXN = 60000 + 10
MOD = 1000000007
pentagonal = []
sign = []
(2..MAXN).each do |i|
    k = i / 2
    k = -k if i & 1 > 0
    g = k * (3 * k - 1) / 2
    pentagonal.push g
    if k & 1 > 0 then sign.push true else sign.push false end
    break if g >= MAXN
end
ans = Array.new MAXN, 0
ans[0] = 1
(0...MAXN).each do |i|
    (0...MAXN).each do |j|
        k = i + pentagonal[j]
        if i == 0 and j < 20 then
            puts j.to_s + ' ' + pentagonal[j].to_s
        end
        break if k >= MAXN
        if sign[j] then ans[k] += ans[i] else ans[k] -= ans[i] end
        ans[k] = (ans[k] + MOD) % MOD
    end
end
t = gets.to_i
t.times do
    n = gets.to_i
    puts ans[n]
end