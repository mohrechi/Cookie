function [x_min, f_min] = PHR(func, param, h, g, x0, c)
lambda = 0.1 * ones(size(h));
mu = 0.1 * ones(size(g));
for i = 1 : 100
    if sum(subs(h, param, x0) .^ 2) + sum(min(double(subs(g, param, x0)), mu / c) .^ 2) < 1e-10
        break
    end
    [x1, ~] = PHR_Desc(func, param, h, g, x0, lambda, mu, c);
    lambda = lambda - c .* double(subs(h, param, x1));
    mu = max(mu - c * double(subs(g, param, x1)), 0);
    x0 = x1;
end
x_min = double(x0);
f_min = double(subs(func, param, x_min));
