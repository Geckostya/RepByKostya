select City.Name from Country, City, Capital
where City.Id = Capital.CityId and Capital.CountryCode = Country.Code and Country.Name = 'Malaysia';