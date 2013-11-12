function xn = LinearSearch(func, param, x, step)
syms lambda;
func
param
x
step
phi = subs(func, param, x + lambda .* step);
lens = double(solve(diff(phi)));
row = size(lens, 1);
len = real(lens(1));
value = double(subs(phi, lambda, x + len .* step));
if row > 1
    for i = 2 : row
        temp = double(subs(phi, lambda, x + real(lens(i)) .* step));
        if temp < value
            len = real(lens(i));
            value = temp;
        end
    end
end
xn = x + len * step;