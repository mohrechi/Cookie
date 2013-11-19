function [x_min, f_min] = ActiveSetMethod(G, g, c, A, b, x0)
m = size(b, 1);
find = 1;
for i = 1 : 100
    if find == 1
        J = [];
        for j = 1 : m
            if abs(A(:, j)' * x0 - b(j)) < 1e-6
                J(size(J, 1) + 1, :) = j;
            end
        end
        find = 0;
    end
    Atmp = [];
    btmp = [];
    for j = 1 : size(J, 1)
        Atmp(:, j) = A(:, J(j));
        btmp(j, :) = 0;
    end
    Gtmp = G;
    gtmp = G * x0 + g;
    [d, ~, lambda] = EqualityQuadratic(Gtmp, gtmp, Atmp, btmp);
    if norm(d) < 1e-6
        index = 1;
        minLambda = lambda(1);
        for j = 2 : size(lambda, 1)
            if lambda(j) < minLambda
                minLambda = lambda(j);
                index = j;
            end
        end
        if minLambda >= 0.0
            break;
        end
        newJ = [];
        for j = 1 : size(J, 1)
            if j ~= index
                newJ(size(newJ) + 1, :) = J(j, :);
            end
        end
        J = newJ;
    else
        alpha = 1.0;
        for j = 1 : m
            flag = 1;
            for k = 1 : size(J, 1)
                if J(k) == j
                    flag = 0;
                    break;
                end
            end
            if flag == 1
                if A(:, j)' * d > 0
                    temp = -(A(:, j)' * x0 - b(j)) / (A(:, j)' * d);
                    if temp < alpha
                        alpha = temp;
                    end
                end
            end
        end
        x0 = x0 + alpha * d;
        find = 1;
    end
end
x_min = x0;
f_min = 0.5 * x_min' * G * x_min + g' * x_min + c;