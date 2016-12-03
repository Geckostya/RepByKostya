select Country.Name, Rate
from Country inner join LiteracyRate on Code = CountryCode

group by CountryCode
having max(Year) = Year

order by Rate desc limit 1;