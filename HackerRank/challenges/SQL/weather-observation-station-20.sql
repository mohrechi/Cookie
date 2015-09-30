SELECT ROUND(x.LAT_N, 4) FROM Station x, Station y
GROUP BY x.LAT_N
HAVING SUM(SIGN(1 - SIGN(y.LAT_N - x.LAT_N))) = (COUNT(*) + 1) / 2;