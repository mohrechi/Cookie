syms x1 x2;

% Test data 1, the answer should be [4; 2].
func = x1 ^ 2 + 2 * x2 ^ 2 - 4 * x1 - 2 * x1 * x2;
param = [x1 x2];
x = [1; 1];
step = [3; 1];
xn = LinearSearch(func, param, x, step);
disp(xn);

% Test data 2, the answer should be [1; 1].
func = x1 ^ 3 + x2 ^ 3 - 3 * x1 * x2;
param = [x1 x2];
x = [2; 2];
step = [-6; -6];
xn = LinearSearch(func, param, x, step);
disp(xn);