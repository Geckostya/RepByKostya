select GovernmentForm, max(SurfSum)
from 
(
	select GovernmentForm, sum(Country.SurfaceArea) as SurfSum
	from Country
	group by GovernmentForm
);
