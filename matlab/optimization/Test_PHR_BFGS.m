syms x1 x2;
func = 100 * (x1 ^ 2 - x2) ^ 2 + (x1 - 1) ^ 2;
param = [x1; x2];
x0 = [10; 10];
[x_min, f_min] = PHR_BFGS(func, param, [], [], x0, [], [], 4);
disp(x_min);
disp(f_min);