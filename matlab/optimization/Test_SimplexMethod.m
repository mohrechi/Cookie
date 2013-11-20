% The answer should be [1/5, 0, 8/5, 0, 0, 4] and -27/5.
c = [-3; -1; -3; 0; 0; 0];
A = [2 1 1 1 0 0; 1 2 3 0 1 0; 2 2 1 0 0 1];
b = [2; 5; 6];
base = [4, 5, 6];
[x_min, f_min] = SimplexMethod(c, A, b, base);
disp(x_min);
disp(f_min);

% The answer should be [0, 2 / 5, 9 / 5] and 11 / 5;
c = [4; 1; 1];
A = [2 1 2; 3 3 1];
b = [4; 3];
[x_min, f_min] = SimplexMethod(c, A, b);
disp(x_min);
disp(f_min);

% The answer should be [1, 2, 0, 0, 0] and 11;
c = [3; 4; 5; 0; 0];
A = [-1, -2, -3, 1, 0; -2, -2, -1, 0, 1];
b = [-5; -6];
base = [4, 5];
[x_min, f_min] = SimplexMethod(c, A, b, base);
disp(x_min);
disp(f_min);