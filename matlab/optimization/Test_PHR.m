% The answer should be [0.8229; 0.9114] and 1.39346
syms x1 x2;
func = (x1 - 2) ^ 2 + (x2 - 1) ^ 2;
param = [x1; x2];
h = x1 - 2 * x2 + 1;
g = - 0.25 * x1 ^ 2 - x2 ^ 2 + 1;
x0 = [3; 3];
c = 2;
[x_min, f_min] = PHR(func, param, h, g, x0, c);
disp(x_min);
disp(f_min);