% The answer should be [0; 1] and -3.
G = [2 0; 0 2];
g = [-2; -4];
A = [-1 0; 0 -1; 1 1]';
b = [0; 0; 1];
[x_min, f_min, lambda] = ActiveSetMethod(G, g, 0, A, b);
disp(x_min);
disp(f_min);
disp(lambda);

% The answer should be [0.5; 2.25] and -13.75.
G = [2 -1; -1 4];
g = [-1; -10];
A = [3 2; -1 0; 0 -1]';
b = [6; 0; 0];
[x_min, f_min, lambda] = ActiveSetMethod(G, g, 0, A, b);
disp(x_min);
disp(f_min);
disp(lambda);