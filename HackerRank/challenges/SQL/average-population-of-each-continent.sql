SELECT country.Continent, floor(avg(city.Population)) AS AveragePop
FROM City city
INNER JOIN Country country
ON city.CountryCode = country.Code
GROUP BY(country.Continent);