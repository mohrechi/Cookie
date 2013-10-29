syms x1  x2 lambda;
f = - x1 + x2 + 2 * x1 * x2 + x1 ^ 2 + 3 * x2 ^ 2;
g = gradient(f);
x0 = [0; 0];
Hk = [1, 0; 0, 1];
disp(['Iteration 1']);
gk = subs(g, [x1, x2], x0);
sk = -gk;
fl = subs(f, [x1, x2], x0 + sk .* lambda);
fld = diff(fl);
step = solve(fld);
xk = x0 + step .* sk;
detxk = xk - x0;
disp(['x = ' char(xk')]);
disp(['f = ' char(subs(f, [x1, x2], xk))]);
disp(' ');
for i = 2 : 100
    gkk = subs(g, [x1, x2], xk);
    if sum(gkk .^ 2) < 1e-6
        break
    end
    disp(['Iteration ' num2str(i)]);
    detgk = gkk - gk;
    Hkk = Hk + detxk * detxk' / (detxk' * detgk) - (Hk * detgk) * (Hk * detgk)' / (detgk' * Hk * detgk);
    skk = - Hkk * gkk;
    fl = subs(f, [x1, x2], xk + skk .* lambda);
    fld = diff(fl);
    step = solve(fld);
    xkk = xk + step .* skk;
    
    detxk = xkk - xk;
    xk = xkk;
    gk = gkk;
    Hk = Hkk;
    disp(['x = ' char(xk')]);
    disp(['f = ' char(subs(f, [x1, x2], xk))]);
    disp(' ');
end