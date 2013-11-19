% The answer should be [0; 1] and -3.
G = [2 0; 0 2];
g = [-2; -4];
A = [-1 0; 0 -1; 1 1]';
b = [0; 0; 1];
x0 = [0; 0];
[x_min, f_min] = ActiveSetMethod(G, g, 0, A, b, x0);
disp(x_min);
disp(f_min);