
// 1 | 2 | 3 | 4 байты
#pragma pack(push, 1) // 1 байт - нет выравнивания. Он вырубит всё выравнивание везде.
struct{
	int8_t first;
	int16_t second;
	int32_t third;
	int64_t forth;
};
#pragma pack(pop); // с прагмами легко навредить или ошибиться.
// 1 0 0 0 | 2 0 0 | 3 0 | 4 возможно


го shared ptr заниматься!

RAII Resourse andaldkshn is initialisation.
в конструкторе забирает ресурс, а в деструкторе освобождает.
{
	int n;
	ifstream if("text.tx");
	if>>n;
}
закрыли скобку - удалили. 
Почти все стандартные классы реализованы по такой идеоме.