Сделаем чёрный ящик, будто это обычная переменная.(Тёмная материя)
BigInt a;
f(a); //f(BigInt a);
 дальше будет то, что уже написано в матрицах.
 Мы возвращаем ссылку на переменную, ибо она живёт и до и после выполнения функции.(operator+=)

 чтобы сделать BigInt c1 = 3 + b; нужно сделаь +(BigInt& a, BigInt& b); Тогда тройка перейдет в бигинт и они сложатся

 BigInt d = a++;
 BigInt e = ++a;

 BigInt& operator++(){//++a
 	*this+=1;
 	return *this;
 }

 BigInt operator++(size_t n){//a++;
 	BigInt t(*this);
 	*this+=1;
 	return t;//Долга
 }

 =======================

 Smart pointers;

 Person:
 char name[256];
 char phones[20][256];
 char end[256];

 Person *p = new Person();
 Person *p1 = new Person();
 delete p;

 //New знает про конструкторы, delete знает про диструкторы, в этом отличие от маллока и фри.
 Person *p = new Person [100];
 Если нет конструктора по умолчанию - не скомпилится

 Person **p = new Person* [100];
 for (i=0; i<100; i++)
 	p[i] = new Person(i);
 Тут наши ячейки лежат хаотично, что не хорошо, в отличие от предыдущего случая
Они не зайдут в КЭШ, значит это будет долгим обращением.

и нужно вызывать деструктор много раз, значит писать так:

 Person *p = new Person [100];
 delete [] p;

 МЫ НЕ ХОТИМ ЗНАТЬ ПРО ПАМЯТЬ, МЫ НЕ ХОТИМ С НЕЙ РАБОТАТЬ.

 Поэтому вспомним, откуда ноги растут. Много ошибок с мемликами и прочей хренью, надо всё это спрятать,
  зашить все кишки внутрь и замазать.
Сейчас займёмся нашими указателями.

Будем смартпоинтер для персона. Так проще.

class scoped_ptr 
{
	private:
		Person *p;
		scoped_ptr(const scoped_ptr p);//Чтобы не копировать объект
		operator=...
	public:
		scoped_ptr(Person *p){this->p = p;}
		~scoped_ptr(){delete this->p;}	
		Person* ptr(){return p;};
		Person* operator->(){return p;}
		Person& operator*(){return *p;}
}

траляля, там иф какой-то
if() {
	scoped_ptr p(new Person(Vasya));
	//p.ptr()->hasBirthday();
	p->hasBirthday();//будет воспринимать как p->->
	*p.hasBirthday();

	scoped_ptr p1 = p; дважды деструктор вызовится;
	printPerson(p); та же проблема

	//p.operator->()->hasBirthday();//LoL
}//А тут он убиваается, мвухаха, но мы хотим убрать p.ptr()
/*Person
	bool hasBirthday*/


Хотим круче!
class unique_ptr // auto_ptr
{
	private:
		Person *p;
	public:
		unique_ptr(Person *p){this->p = p;}
		~unique_ptr(){if (p) delete p;}	
		Person* ptr(){return p;};
		Person* operator->(){return p;}
		Person& operator*(){return *p;}
		unique_ptr(unique_ptr &o){
			this->p = o->p;
			o->p = NULL;
		}
}

PrintUser(p); //норм
PrintUser(p); // уже там Null, можно вызвать только один раз
Также скопировать можно только один раз.
можно писать ф-ции вот так f(unique_ptr &p); это будет работать, но это сложна
Надо делать обёртку.
На след. правктике будет самый мощный поинтер

shared_ptr
сейчас будет только идея.
Технология "подсчёт ссылок" "reference count(ref_count)"

Storage *stor;
Storage {
	int ref_count;
	Person *p;
}


if (   ){
	shared_ptr p1(new Person("Vasya"));//ref_count = 1;
	shared_ptr p2(p1);// ref_count = 2;
}
p1 -->|		  | -> Person;
p2 -->|storage|
В конструкторе нужно увеличивать наш ref_count;
в деструкторе уменьшать.
destuctor p1 -> ref_count = 1;
destuctor p2 -> ref_count = 0; del Person;

shared_ptr p2(new Person("Kolya"));
p1 = p2;

			storage:
p1 ---> | ref_count = 1 | --> | Vasya | <Person
p2 ---> | ref_count = 1 | --> | Kolya | <Person

при копировании:
p1 -v // | ref_count = 0 | --> | Vasya | <Person
p2 ---> | ref_count = 2 | --> | Kolya | <Person
