select Country.Name
from Country left join City on City.CountryCode = Country.Code
group by Country.Name
having Country.Population/2 > sum(City.Population) and Country.Population > 0

order by Country.Name;