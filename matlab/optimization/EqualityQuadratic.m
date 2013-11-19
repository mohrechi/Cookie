function [x_min, f_min, lambda] = EqualityQuadratic(G, g, A, b)
x_min = [G, A; A' zeros(size(A, 2), size(A, 2))] \ [-g; b];
lambda = x_min(size(g) + 1 : size(x_min, 1));
x_min = x_min(1 : size(g));
f_min = 0.5 .* x_min' * G * x_min + g' * x_min;