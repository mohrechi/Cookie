SELECT city.Name
FROM City city
INNER JOIN Country country
ON city.CountryCode = country.Code
WHERE country.Continent = 'Africa';