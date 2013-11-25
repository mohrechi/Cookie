function [x_min, f_min] = PHR_Desc(func, param, h, g, x0, lambda, mu, c)
x_min = x0;
for i = 1 : 100
    g = PHR_grad(func, param, h, g, x_min, lambda, mu, c);
    if norm(g) < 1e-6
        break
    end
    x_min = x_min - 0.001 * g;
end
f_min = PHR_func(func, param, h, g, x_min, lambda, mu, c);