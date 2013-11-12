function [x_min, f_min] = ConjugateGradient(func, param, x0)
grad = gradient(func);
g0 = subs(grad, param, x0);
s0 = - g0;
x1 = LinearSearch(func, param, x0, s0);
for i = 1 : 100
    g1 = subs(grad, param, x1);
    if norm(g1) < 1e-6
        break
    end
    mu = sum(g1 .^ 2) / sum(g0 .^ 2);
    s1 = - g1 + mu * s0;
    x1 = LinearSearch(func, param, x1, s1);
    g0 = g1;
    s0 = s1;
end
x_min = double(x1);
f_min = double(subs(func, param, x_min));