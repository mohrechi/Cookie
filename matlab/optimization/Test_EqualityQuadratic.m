% The answer should be [2 / 7; 10 / 7; - 6 / 7].
G = eye(3);
g = [0; 0; 0];
A = [1 1; 2 -1; -1 1];
b = [4; -2];
[x_min, f_min] = EqualityQuadratic(G, g, A, b);
disp(x_min);
disp(f_min);