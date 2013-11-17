syms x1 x2;

% Test data 1, the answer should be [4; 2] and -8.
func = x1 ^ 2 + 2 * x2 ^ 2 - 4 * x1 - 2 * x1 * x2;
param = [x1; x2];
x = [1; 1];
[x_min, f_min] = ConjugateGradient(func, param, x);
disp(x_min);
disp(f_min);

% Test data 2, the answer should be [1; 1] and -1.
func = x1 ^ 3 + x2 ^ 3 - 3 * x1 * x2;
param = [x1; x2];
x = [2; 2];
[x_min, f_min] = ConjugateGradient(func, param, x);
disp(x_min);
disp(f_min);
