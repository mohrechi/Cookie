function val = PHR_func(func, param, h, g, x0, lambda, mu, c)
m = size(h, 1);
p = size(g, 1);
val = double(subs(func, param, x0));
for i = 1 : m
    hi = double(subs(h(i), param, x0));
    val = val - lambda(i) * hi;
    val = val + c / 2 * (hi ^ 2);
end
for j = 1 : p
    gj = double(subs(g(j), param, x0));
    val = val + 1 / (2 * c) * (max(0, mu(j) - c * gj) - mu(j) ^ 2);
end