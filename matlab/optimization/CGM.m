syms x1 x2 x3 lambda;
f = x1 ^ 2 - 2 * x1 * x2 + 2 * x2 ^ 2 + x3 ^ 2 - x2 * x3 + 2 * x1 + 3 * x2 - x3;
grad = gradient(f);
xk = [0; 0; 0];
sk = [0; 0; 0];
gk = [1; 0; 0];
for i = 1 : 100
    gkk = subs(grad, [x1, x2, x3], xk);
    if sum(gkk .^ 2) < 1e-6
        break
    end
    disp(['Iteration' num2str(i)]);
    mu = sum(gkk .^ 2) / sum(gk .^ 2);
    skk = -gkk + mu * sk;
    fl = subs(f, [x1, x2, x3], xk + skk .* lambda);
    fld = diff(fl);
    step = solve(fld);
    xkk = xk + step .* skk;
    fmin = subs(f, [x1, x2, x3], xkk);
    xk = xkk;
    gk = gkk;
    sk = skk;
    disp(['x = ' char(xk')]);
    disp(['f = ' char(subs(f, [x1, x2, x3], xk))]);
    disp(' ');
end