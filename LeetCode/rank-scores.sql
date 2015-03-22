SELECT Scores.Score, COUNT(Rank.Score)
FROM Scores, (SELECT DISTINCT Score FROM Scores) Rank
WHERE Scores.Score <= Rank.Score
GROUP BY Scores.Id, Scores.Score
ORDER BY Scores.Score DESC;
