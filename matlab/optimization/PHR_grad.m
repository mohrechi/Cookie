function val = PHR_grad(func, param, h, g, x0, lambda, mu, c)
m = size(h, 1);
p = size(g, 1);
val = double(subs(gradient(func, param), param, x0));
for i = 1 : m
    hi = double(subs(h(i), param, x0));
    hg = double(subs(gradient(h(i), param), param, x0));
    val = val - lambda(i) * hg;
    val = val + c * hi * hg;
end
for j = 1 : p
    gj = double(subs(g(j), param, x0));
    gg = double(subs(gradient(g(j), param), param, x0));
    val = val + (c * gj - mu(j)) * gg;
end