select Country.Name, count(City.Name) as cnt
from Country left join City on CountryCode = Code and City.Population > 1000000
group by Country.Name

order by cnt desc, Country.Name;