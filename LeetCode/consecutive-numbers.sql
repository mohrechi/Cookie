SELECT DISTINCT a.Num
FROM Logs a
    JOIN Logs b
    ON a.Num = b.Num AND a.Id + 1 = b.Id
        JOIN Logs c
        ON b.Num = c.Num AND b.Id + 1 = c.Id;
