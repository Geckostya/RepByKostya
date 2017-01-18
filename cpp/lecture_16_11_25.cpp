Поговорим о наследовании

вспомним о списке, у него две особенности будет
1 не бывает пустым
2 хитрый деструктор

struct linked_list
	node* head;
sturct node
	int value;
	node* next;
//.hpp
class list{
private:
	int value;
	list* next;
public:
	list(int v);
	~list();
	size_t length();
	void add (int v);
private:
	add(int v);
	list(const list&);
	list& operator=(const list&)
}
//.cpp

list::list(int v){
	value = v; next = null;
}
void list::add(int v){
	list *cur = this;
	while(cur->next != null)
		cur=cur->next;
	cur->next = new list();
}
size_t list::length(){
	list *cur = this; size_t count = 0;
	while(cur->next != null){
		cur = cur->next, count++;
	return count;
	}
}

//2016 год, хочу двусвязный
class double_list::public list{
private:
	list *prev;
public:
	double_list(int v);
	~double_list();
	//ф-цию length переделывать не нужно, и тааак сойдёт
	void add(int v);
private:
	double_list(const double_list &&);//нет конструктора копий
	double_list& operator=(const double_list&);
	//override - перекрытие
}
// cpp
double_list::double_list(int v):list(v){
	prev = null; //лень менять всё, таких изменений хватит, поэтому напишем list(v)
	//он сначала вызовет метод list, после его завершения доделает всё остальное
}

void double_list::add(int v){
	double_list *cur = this;
	while(cur->next != null)
		cur=cur->next;
	cur->next = new double_list();
	cur->next->prev = cur;
}//Ничего не скомпилируется...
тут куча ошибок. Разные типы приводятся, лист к дабл листу, а ещё нужно специальное слово для перекрытия.
ещё нужно разобраться с модификаторами. Займёмся этим в следующий раз.