% The answer should be [0 0] and 0.
syms x1 x2;
func = x1 ^ 2 + x1 * x2 + x2 ^ 2;
param = [x1 x2];
x0 = [3; 2];
[x_min, f_min] = BFGS(func, param, x0);
disp(x_min);
disp(f_min);