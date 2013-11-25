% The answer should be [2 / 7; 10 / 7; - 6 / 7].
G = eye(3);
g = [0; 0; 0];
A = [1 1; 2 -1; -1 1];
b = [4; -2];
[x_min, f_min, lambda] = EqualityQuadratic(G, g, A, b);
disp(x_min);
disp(f_min);
disp(lambda);

% The answer should be [1.9091; 1.9545; 0.1364].
G = [2 -2 0; -2 4 0; 0 0 2];
g = [0; 0; 1];
A = [1 1 1; 2 -1 1]';
b = [4; 2];
[x_min, f_min, lambda] = EqualityQuadratic(G, g, A, b);
disp(x_min);
disp(f_min);
disp(lambda);