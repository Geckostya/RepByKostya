// СТАНДАРТНАЯ БИБЛИОТЕКА СИ
//
//
1()
int short long
stdint.h
int8_t
uint8_t
int16_t
uint16_t
//===========================
2()ctype.h
int isopho(chat c)
int isdeigit (char c)
tolouer();
/=================================
3() assert.h
int a[10];
a[10] = 3 ???
assert(s!=NULL)4
#define NDEBUG

#ifdef NDEBUG
#else
	proverka
#endif

gcc -DNDEBUG -c main.c//MS VS

FILE *f = fopen("in.txt", "r");
assert(f!=NULL); // из-а НДЕБАГ эта программа будет без проверки, поэтому стоит писать условия и не проверять ошибки второго типа так
//==============================
4) math.h
cos sin sqrt
5) time.h
time_t;
time(time_t *t);
time_t a;
a = time(NULL); time(&a);// И возвращает и записывает.
clock()//возвращает секунды
//Если хотим замерить время работы нашей ф-ции
time_t start=time(NULL);
f();
time_t end=time(NULL);
//Если программа слишком бысрая - будет еньше секунды, надо в цикле
TICS //clock() мерит время в тактах. Но только для однопоточных программ.
clock_t start=clock();
f();
clock_t end=clock
//Если программа многопоточная, то функция будет равна t1+t2 - т.е. сколько тактов выполнили оба процессора
//
//
//==================  ВЕРНЁМСЯ К C++  ==================
//
//
.c
1() 
typedef struct my_array{
	int *array;
	size_t size;
}my_array_t;
2()
my_array_t a;
set(&a,0,5);
3()
void set(my_array_t *ma, size_t idx, int value);
//->
.cpp
1()
class my_array{
	private:
		int *array;
		size_t size;
	public:
		void set(size_t idx, int value);
}
2()
my_array a;
a.set(0,5);
3()
void my_array::
	set9(my_array_t *ma, size_t idx, int value);
/*Как же это работает на процессорном уровне, если он не знает, что это такое, понимает лишь простые программы?
Вспомним, что раньше С++ был на чистом си лишь препроцессором, сейчас многое поменялось,но это поможет пониманию
Это всё преобразовывается компилятором в ассемблере*/
a.set(0,5) ===> my_array_set_vartypes(&a, 0, 5);
void my_array:: set(size_t idx, int value);
	===>
my_array_set_.... set(my_array_t *this, size_t idx, int value);
//Компилятор лишь добавил указатель на память, где лежит эта штука.
//set и get не лежат в памяти, там лежат лишь array\size, а ф-ции лежат по одному разу на ELF, независимо от колличества переменных.
// просто при компилции компилятор преобразует из приятного синтаксиса объектный код, который был в си. 
// этим this можно пользоваться, по договорённости.
//=========
// PRIVATE не работает в ассемблере, все проверки происходят на стадии компиляции.
my_array a;
char *pa = (char*)&a;
int s=*(pa+8);
// Это обманет компилятор, так делать не стоит, ибо никто не сможет потом адекатно этим пользоваться,
// но если приспичило - можно и такой костыль сделать

//Будем разбираться на основе стандарта языка 2001ого года
1() const double pi=3.14;
class A{
	const double e;
	A::A(){
		e = 2.7;
	}
}
pi=4// ошибка, но во время компиляции.

// поговорим об указателях и констах

char s1[] = "Hello";
char s2[] = "World";

//#1
char const *p1 = s1; //const char *p1;
// конст защищает то, после чего нходится, т.е. просто чар.
p1[0] = 'A'; //error
p1 = s2; // good

//#2
char* const p2 = s1;
p2[0] = 'A'// good
p2 = s2;//error

//#3
char const * const p3=s1;

int strlen(const char *s){
	//s[1]='a';
}
strtok(char *s);

//
const char* s1;
char * s2 = (char*)s1;
s2[0] = 'A';

const char *s = "Hello";// char s[] = "Hello";//будет вообще-то варнинг, нужен const, допишу его
char *ss = (char*)s;// crash ss[0]=3;

---------------| 
|			   |
|			   |
|			   |
|для указателя |
|	global     |
|--------------|
|		ELF	   |
|			   |
|			   |
|--------------|

va |ra |pid |rw|
   |   |    | 1|
   // Вот эта штука реально память защищает.
//==================
4()
ССЫЛКИ!
swap (int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
swap(&c,&d);
//
swap (int &a, int &b){
	int t = a;
	a = b;
	b = t;
}
swap(c,d);
!!!!!!!!!!!!!!!!!!!! ЕСЛИ БЫЛ УКАЗАТЕЛЬ НА ИНТ, А В ДРУГОМ МЕСТЕ ПРОСТО ИНТ, ЧТО БУДЕТ ВООБЩЕ С ПЕРЕГРУЗКОЙ??
//Я не хочу об этом говорить, поговорим после теста.
5()
class my_arr{
	private:
		int *arr;
		size_t size;
	public:
		my_arr(size_t s);
		~my_arr();
		void set (size_t idx, int value);
		int get(size_t idx) const;// не меняет полей
		size_t get_size() const; 
}