% The answer should be [4, 2] and -8.
syms x1 x2;
func = x1 ^ 2 + 2 * x2 ^ 2 - 4 * x1 - 2 * x1 * x2;
param = [x1; x2];
x0 = [1; 1];
[x_min, f_min] = DampedNewton(func, param, x0);
disp(x_min);
disp(f_min);