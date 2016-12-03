select Name, max(Rate)
from 
(
	select Name, Rate
	from Country inner join LiteracyRate on Code = CountryCode

	group by CountryCode
	having max(Year) = Year
);
