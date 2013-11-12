function [x_min, f_min] = BFGS(func, param, x0)
grad = gradient(func);
g0 = subs(grad, param, x0);
s0 = - g0;
H0 = eye(size(x0, 1));
x1 = LinearSearch(func, param, x0, s0);
detx = x1 - x0;
for i = 1 : 100
    g1 = subs(grad, param, x1);
    detg = g1 - g0;
    if norm(g1) < 1e-6
        break
    end
    mu = 1 + (detg' * H0 * detg) / (detx' * detg);
    H1 = H0 + (mu * detx * detx' - H0 * detg * detx' - detx * detg' * H0) / (detx' * detg);
    s1 = - H1 * g1;
    x0 = x1;
    x1 = LinearSearch(func, param, x1, s1);
    detx = x1 - x0;
    g0 = g1;
    H0 = H1;
end
x_min = double(x1);
f_min = double(subs(func, param, x_min));