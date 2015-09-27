SELECT Request_at Day, round(sum(case when Status like 'cancelled%' then 1 else 0 end) / count(*), 2) Rate
FROM Trips
INNER JOIN Users
ON Client_Id = Users_Id AND Banned = 'NO'
WHERE Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY Request_at
