function [x_min, f_min] = QuadraticApproach(func, param, ieq)
n = size(param, 1);
m = size(ieq, 1);
x0 = zeros(n, 1);
B = eye(n);
for i = 1 : 1
    c = zeros(n + 1, 1);
    c(1) = -1;
    A = zeros(n + 1, m + 2);
    b = zeros(m + 2, 1);
    for j = 1 : m
        if j <= m / 2
            A(1, j) = double(subs(ieq(j), param, x0));
        else
            b(j) = - double(subs(ieq(j), param, x0));
        end
        A(2 : n + 1, j) = double(subs(gradient(ieq(j), param), param, x0))';
    end
    A(1, m + 1) = -1;
    A(1, m + 2) = 1;
    b(m + 2) = 1;
    x = linprog(c, A', b);
    xi = x(1);
    G = B;
    g = double(subs(gradient(func, param), param, x0));
    A = zeros(n, m);
    b = zeros(m, 1);
    for j = 1 : m
        if j <= m / 2
            b(j) = - xi * double(subs(ieq(j), param, x0));
        else
            b(j) = - double(subs(ieq(j), param, x0));
        end
        A(:, j) = double(subs(gradient(ieq(j), param), param, x0))';
    end
    [d, ~, mu] = ActiveSetMethod(G, g, 0, A, b);
    if norm(d) < 1e-6
        break;
    end
    if i == 1
        lambda0 = zeros(m, 1);
        for j = 1 : m
            lambda0(j) = abs(mu(j));
        end
    else
        lambda1 = zeros(m, 1);
        for j = 1 : m
            lambda1(j) = abs(mu(j));
            temp = 0.5 * (lambda0 + abs(mu(j)));
            if temp  > lambda1(j)
                lambda1(j) = temp;
            end
            lambda0(j) = lambda1(j);
        end
    end
    x1 = x0;
    minF = double(subs(func, param, x0)) + sum(lambda0 .* max(0, double(subs(ieq, param, x0))));
    for j = 1 : 1000
        newX = x0 + d * j / 1000;
        newF = double(subs(func, param, newX)) + sum(lambda0 .* max(0, double(subs(ieq, param, newX))));
        if newF < minF
            x1 = newX;
            minF = newF;
        end
    end
    if norm(x1 - x0) < 1e-6
        break;
    end
    L = func;
    for j = 1 : m
        L = L + mu(j) * ieq(j);
    end
    y = double(subs(gradient(L, param), param, x1)) - double(subs(gradient(L, param), param, x0));
    s = x1 - x0;
    theta = 1;
    if y' * s < 0.2 * s' * B * s
        theta = (0.8 * s' * B * s) / (s' * B * s - y' * s);
    end
    eta = theta * y + (1.0 - theta) * B * s;
    B = B - (B * s * s' * B) / (s' * B * s) + (eta * eta') / (eta' * s);
    x0 = x1;
end
x_min = double(x0);
f_min = double(subs(func, param, x_min));