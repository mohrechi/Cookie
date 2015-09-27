MAXP = 1e6.to_i
is_prime = Array.new MAXP, true
t_primes = {}
(2...MAXP).each do |i|
  if is_prime[i] then
    t_primes[i * i] = 0
    ((i + i)...MAXP).step(i).each do |j|
      is_prime[j] = false
    end
  end
end
n = gets
x = gets.split.map &:to_i
x.each do |i|
  if t_primes.has_key? i then
    puts 'YES'
  else
    puts 'NO'
  end
end
