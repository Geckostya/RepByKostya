Дальше продолжим болтать о наследовании.
Есть три модификатора:

private:
public:
protected:

Но получается, что нужно заранее приспасабливать класс для расширения.

Но зато закрыли первую ошибку - protected.

Обсудим ошибку номмер три.

cur->next = dobule_list(..);
///Тут лист///тут дабл лист
нужно это поменять.
Нужно обсудить работу с данными.

list* l = new list();
l->value = 35;
l->nead = NULL;Это не скомпилится, ибо нет такого поля
 
 int *a = new ...
 char *b = new ...

 a = b;
 b = a;
 Тут может вылезти ошибка, си было бы пофиг, но надо писать так:
 a = (int*)b;
 b = (char*)a;

list *l - new list();
double_list* dl = new dobule_list();

l = dl;

l->next;//ok
l->value;//ok
l->prev;//NOT OK

dl = l;
//Вот это опасно
dl -> prev;
dl -> nex;
dl -> value;
Это всё скомпилится, но есть проблемы.
Но мы будем гулять по неинициализированной памяти.
Надо писать так.
dl = (double_list*) l;

Объект наследника можно использовать как и родителя, ибо он умеет всё то же самое.

Теперь в add_value нужно аккуратно поставить преобразования типов, инае не скомпилируется.
|--------------------------------\
|								  \
\								  /
/								  \
|		просто рисовать			  |
\		захотелось				  /
 |								  \
 |								  /
/								 /
|--------------------------------/
	  ____
      |   \
	  |  _/
      |_/
--------------
\			/
 \---------/


     _____
    /     \
   /       \
  /---------\
   |  ___  |
   | |_|_| |
   |_______|


void fill(list *l, int v, int num){
	for (int i = 0; i<num; i++){
		l -> add_value(v);
	}
}

int main(){
	double_list dl(3);
	list l (5);
	fill(&dl, 6, 10);
	fill(&l, 6, 10)0
}

Дабл лист умеет всё то же, что и лист, поэтому он может учавствовать во всех тех ф-циях, что и его родитель.
представим теперь, что fill был сделан год назад
Когда это компилируют, нужно знать, какую функцию вызывать.
l -> add_value(v);
Это называется динамическое связывание.
Адрес проставится из листа, и когда я вызову ф-цию для DL вызовется всё равно для L.

Нужно для этой магии волшебное слово.
list 
	protected:
		int value;
		list* nex;
		пожлауйста add_value();
Ладно, другое слово.
virtual add_value. Это надо писать только при объявлении, тогда магический ящик "компилятор" будет более зболтиво относиться к 
твоему коду и начнёт творить магию
.
Если я сделаю так - list *l1 = dl;
l1->add_value(); // вот тут нужна магия.

Теперь появились вирутальные ф-ции.
теперь рассмотим три ф-ции
/*adrs 300*/list_add_value;
/*adrs 400*/list_length;
/*adrs 500*/double_list_add_value;

add_value 	| adress
 	 		| list_add_value
 	 		|
 	 		|
  	 		|

 Есть табличка для каждого класса. Там написано что-то вроде:

 add_value | 500

 у нас сохраняется имя ф-ции и её адресс
 Тогда при динамическом свзяывании будет такая последовательность действий:
 1. пойди в табличку
 2. найди ф-цию
 3. вызови
 Выбор ф-ции происходит в момент выполнения программы.

====================
ещё вариант кода, который раньше был невозможен.
смарите
list *l;
stand(time(NULL));
int n = round();
if (n>0)
	l = new list(5);
else
	l = new double_list(6); 
l->add_value(7);

===========================================================================================================
бухгалтеру нужно пересчитывать зарплату, а ему лень, да и вечные ошибки.
Надо автоматизировать.
1.Developer
	salary
	level
	IsRelease
	bonus
2.Seller
char*_product
	price
	num
	percent
3. Tesler
 HR
 и вообщем-то надо написать так, чтобы можно было нормально добавить новых гадов и не нужно было бы
 всё перекодить.
 Worker DataBase - массив всех работников.

 Придумаем базовый класс Worker.

 class Worker{
 	char* name;
 	Worker(char* n){
 		name = new char strlen(n+1);
 		strcpy(name, n);
 	}
 	virtual ~Worker(){//Чтобы удалять всех адекватно
 		delete [] name;
 	}
 	virtual int get_salary() = 0;//Можно явно сказать, что ф-ция должна быть перккрыта
 	WorkerDataBase db;
 	Developer *d = new Developer("Mash", 1000, 5, False, 300);
 	Saller *p = new Saller("Petya", "Windows", 0.03, 100000);
 	db.add(d);
 	db.add(p);
 	int total = db.getTotalSalary();
 }

class WorkerDataBase
 	Worker* workers[100];
 	void add(Worker *w)
 		...
 	int getTotalSalary(){
 		int Salary = 0;
 		for(i = 0; i<size; i++)
  			salary += workers[i]->get_salary();
 		return salary;
 	}

 	~WorkerDataBase(){
 		for (auto x:all)
 			delete x;
 	}


class Developer:public Worker{
	int salary;
	int level;
	int bonus;
	bool IsRelease;
	Developer():Worker(name){};
	~Developer(){};
	int get_salary(){
		int ref = salary*level;
		if (IsRelease) ref += bonus;
		return ref;
	}
}

class Seller:public Worker{
	char *product; int pice; double percent, int num;
	seller (p):Worker(name){
		product = new char [strlen(product)+1];
	strcpy(product, p);
	}
	int get_salary()
		return bla bla bla;

}