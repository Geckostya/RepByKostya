select Country.Name, Country.Population, Country.SurfaceArea

from ((City as Capt inner join Capital on Capt.Id = Capital.CityId) 
	 inner join Country on Capt.CountryCode = Country.Code) 

	left join City as Ci on Ci.CountryCode = Country.Code

group by Country.Code
having Capt.Population < max(Ci.Population)

order by Country.Population/1.0 * Country.SurfaceArea desc
;

/*Названия стран, у которых столица - не самый многочисленный город.
 Если для страны не задан ни один город, то выводить ее не нужно.
  Вывод должен быть отсортирован в порядке уменьшения плотности населения страны,
   при равной плотности в лексикографическом порядке (вывод: название страны,
    население страны, площадь страны) (1,25 балла)*/