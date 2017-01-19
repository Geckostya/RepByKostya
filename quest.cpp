TODO list: 04, 11, 12, 13
01. Программа, состоящая из нескольких файлов.

- заголовочные файлы
	Заголовочные файлы нужны в первую очередь, чтобы избежать ошибок в программе, чтобы они обнаружились на стадии компиляции.
В них содержатся объявления функций, чтобы компилятор знал, какой интерфейс у функций. Использование заголовочных файлов предотвращает
коллизии имён, а также, если программист изменит функцию в своём файле - ему потребуется изменить её и в заголовочном, который подключен к
другим файлам, в которых может использоваться эта функция, соотвественно эти файлы должны быть перекомпилированы или переписаны, если,
например, изменили возвращаемое значение функции. Заголовочные файлы подключаются командой для препроцессора #include headername,
она вставляет всё, что написано в заголовочном файле в файл с кодом.

- компиляция и линковка
	Сборка кода в программу обычно происходит в несколько этапов. Рассмотрим на примере языка Си. Сначала работает препроцессор,
который редактирует код, заменяет некоторые конструкции на более понятные для машины, выполняет все команды препроцессора, 
например #include или #define. Далее идёт трансляция в ассемблерный код, \??\из него\??\ в объектные файлы. Далее на стадии линковки
связываются все имена переменных и функций с физическими адресами машины. На выходе получаем executable файл.

- утилита make
	make служит для упрощённой сборки проектов. Особенно полезен, когда в проекте много файлов. Он построим на простом принципе, есть цели
и их зависимости. Если зависимости изменились, то нужно изменить цель - следовательно вызываются команды, написанные ниже. Важной
особенностью является то, что команды нужно писать с отступом с помощью tab. Выглядит это как-то так:
<цель>: <зависимости>
	<команды>
порядок записей в makefile тоже важен. По умолчанию выполняется первая цель, поэтому обычно её делают на подобии такого
all: bin main 
Чтобы вызвались соответствующие зависимости, которые являются целями ниже. Чтобы использовать make, достаточно написать в консоли make,
тогда он вызовется со стандартными настройками, можно также указывать явно цели, использовать ключи на принудительное исполнение комманд
цели или изменения кол-ва потоков и т.д.

=======================================================================================================================

02. Указатели, массивы, ссылки. Три вида памяти. Работа с кучей на C.

- применение указателей и ссылок
	Указатель на переменную - это номер ячейки памяти, её адрес, если быть точнее, в котором хранятся данные переменной. Если переменная
состоит из нескольких байтов - берётся первый байт. Синтаксически указатель применяется так int* a; - это указатель на память размера
sizeof(int). Указатели также имеют особое значение - 0, но оно именно особое, в нём может храниться что-то абсолютно непонятное, это не
нулевой адрес в памяти, просто пустое значение, означающее, что указатель не указывает в осмысленное место. При работе с указателями и
памятью нужно быть очень аккуратными, чтобы не указать в ту память, которую ещё не инициализировали, или, что ещё хуже, в ту память, которая
уже занята под что-то другое, куда лезть не стоило. Можно делать указатель на указатель int**, или брать значение, лежащие в памяти, на
которую указывает указатель - int* a = 123212; *a = 1; 
	Ссылки - это(вот я хз, это про ссылки с++ или про ссылки на память, скорее всего второе, но может нет) просто взятие адреса памяти
переменной. Например int* a = &b; - это мы создали указатель, которые указывает на память переменной b. 
(c++ вариант) Ссылка - это синтаксический сахар, добавленный в c++, чтобы избежать постоянного взятия адреса, при вызовах функций
а также избавиться от звёздочек, для работы со значениями. При компиляции это просто заменяется на указатели и разыменование(как отличать ссылки
плюсов от ссылок, которые взятие адреса? Или второе не ссылки вовсе?). //TODO написать про хэдеры из-за ссылок, если это тут надо.
	Массивы - это тоже указатели. int a[100]; a можно использовать, как указатель. Обращение к переменным на самом деле происходит так:
a[i] == *(a + i); из-за этой особенности можно писать i[a];

- арифметика указателей
С указателями можно работать, как с обычными интовыми переменными, операторы +, -, ++ и т.п., при этом просто адрес сдвинется
на нужное кол-во ячеек, например int* a = &b; a += x; - адрес сдвинется на x*sizeof(int). //Что ещё про это сказать?

- глобальная/статическая память, стек, куча
	Глобальная память - это память, выделяющаяся при открытии программы, кусок памяти определённого размера, в котором хранятся константы и
всё, что не будет менять размеры в течении использования. Стэк - это динамическая память, которая быстро работает и используется для 
хранения локальных переменных функций. Куча - это динамическая память, в которой могут, в отличии от стека, храниться большие объекты,
массивы на несколько миллионов переменных, например. При выделении переменных на стеке - они заполнены чем-то, чем угодно, при выделении
переменных на куче они инициализируются нулями, если выделение было не функцией malloc.
//чувствую я надобность форматирования

- malloc/calloc/realloc
	Это сишные функции из библиотеки stdlib, они нужны для выделения памяти. malloc(size_t x) выделяет память, 
calloc(size_t num, size_t size) выделяет и инициализирует нулями num*size ячеек, а realloc(void* ptr, size_t size) перевыделяет память.
Чтобы не было утечек - хорошие ребята чистят за собой память функцией free(void *ptr); Память выделяется на куче, что довольно важно.

- void*
	Это упоротый костыль, кхм, возможность делать указатели на память без явного указания типа. арифметика с этим работать не будет, ибо
размер void - 0.(поправьте, если я гоню) Можно приводить указатели к разным типам, таким образом предавать в функцию какие угодно типы.

=======================================================================================================================

03. Структуры. Связный список на C.
- неинтрузивная реализация
	Список - это какой-то блок данных и указатель на следующий блок, если список двусвязный, то ещё и на предыдущий.
struct Node {
	int x; // данные
	struct Node* next;
}

struct list {
	struct Node head;
}

void new_node(struct list* l) {
	struct Node* n = malloc(sizeof(Node));
	n->next = &(l->head);
	l->head = *n;
}
void del_node(struct Node* n) {//двусвязный
	n->prev->next = n->next;
	n->next->prev = n->prev;
	free(n);
}

- интрузивная реализация
Отличается тем, что список хранит ноды, в которых значения, а также нода интрузивного списка. Интрузивный список связан, а вот блоки со
значениями не имеют указателей друг на друга. Интрузивный список позволяет создать лишь одну реализацию списка, а потом можно делать
различные блоки со значениями, различными типами и функциями, которые будут работать поверх одного интрузивного списка.	
реализация в качестве упражнения ;]
Для удобства используем такой дейфайн #define container_of(ptr, type, member) (type*)((char*)(ptr) - offsetof(type, member))
container_of(указатель на интрузивную ноду, тип который её содержит, название поля с нашей интрузивной нодой), а возвращает это
указатель на ноду с данными.

- typedef
всё просто. typedef long long ll;
typedef struct pos{
	//pass	
} pos_t;
/*delete*/Вопрос к читателю, тайпдефы - это работа для препроцессора?

=======================================================================================================================

04. Функции. Указатели на функции.
- как происходит вызов функции
- реализация сортировки
void sort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

=======================================================================================================================

05. Обзор стандартной библиотеки C.

- string.h (memcpy, memcmp, strcpy, strcmp, strcat, strstr, strchr) //<=================== 1 пункт
	Всем привет, с вами kostya55516, сегодня мы будем обозревать string.h.
void* memcpy (void* destination, const void* source, size_t num);
Эта штука копирует в destination num байтов из source.

int memcmp (const void* ptr1, const void* ptr2, size_t num);
сравнивает куски памяти. возвращает 0, если они одинаковые, >0, если в ptr1 встретился байт с большим unsigned int значением,
чем в ptr2 и <0 в противном случае.

int strcmp (const char* str1, const char* str2);
то же самое, но для строк. Если одна строка короче другой - сравнение будет соотвественно <0 при str1 короче.

char* strcat (char* destination, const char* source);
Конкатенирует строки. Приклеивает source к destination справа. Возвращает destination.

char* strstr (const char* str1, const char* str2);
Возвращает указатель на начало второй строки, если она находится в первой. Например strstr(str, "cpp");/*str = "it's a cpp, baby";*/
в этой строке найдётся cpp и вернётся указатель на символ 'c' в этой строке. Если его не нашлось - возвращается нулевой указатель.

char* strchr (const char* str, int character);
та же муть, но находит символ в строке.


- stdlib.h (malloc/free, calloc, realloc, atoi, strtoll, srand/rand, qsort) //<=================== 2 пункт
void* malloc (size_t size);
первый гость нашей программы, выделяет на куче память такого размера и возвращает указатель на начало выделенного блока
Если выделить не получилось - возвращает нулевой указатель

void free (void* ptr);
освобождает память, выделенную malloc-ом и его друзьями. 

void* realloc (void* ptr, size_t size);
перевыделяет память с новым размером size, возвращает указатель на память, данные сохраняются. Может оставить данные на своём месте,
а может выделить на новом и скопировать.	

void* calloc (size_t num, size_t size);
выделяет num*size, инициализирует нулями. в остальном, как malloc

int atoi (const char * str);//ужасная функция
Пропускает пробелы, находит знак перед числом, если он есть и переводит цифры из строки в интовое значение, учитывая знак. Если какая-то
ошибка, преобразовать не получается - будет что угодно.

long long int strtoll (const char* str, char** endptr, int base);
Конвертит строку в long long int. Если endptr не ноль, то endptr указывает на указатель на символ после числа. Делает то же, что и strtol,
но для long long. Если всё ок - вернёт число, если невалидна строка - вернёт ноль, если переполнение значения - янепонимат//посмотрите
//cppreference и поясните мне, плиз

void srand (unsigned int seed);
инициализирует генератор рандома по сиду. Обычно подключается time.h и пихают в качестве сида время.

int rand (void);
генерирует рандомное число, опираясь на прошлую функцию.

void qsort (void* base, size_t num, size_t size,
            int (*compar)(const void*,const void*));
Сортит! base - массив, num - кол-во элементов, size - размер элемента, compar - компаратор.

=======================================================================================================================

06. Ввод-вывод на C.

- FILE, fopen, fclose, r/w, t/b, буферизация

	FILE - Этот тип данных определяет поток и содержит информацию, необходимую для управления потоком, в том числе указатель
на буфер потока, и его показатели состояния. Файловые объекты обычно создаются с помощью вызова функций fopen или tmpfile,
которые возвращают ссылку на объект связанный с файлом. 

FILE* fopen(const char* fname, const char* modeopen); 
	Функция fopen открывает файл, имя которого указано в параметре fname и связывает его с потоком, который может быть
идентифицирован для выполнения различных операций с файлом. Операции с потоком, выполнение которых разрешено определяются
параметром modeopen. 
«r» Режим открытия файла для чтения. Файл должен существовать. 
«w» Режим создания пустого файла для записи. Если файл с таким именем уже существует его содержимое стирается, и файл
рассматривается как новый пустой файл. 
«a» Дописать в файл. Операция добавления данных в конец файла. Файл создается, если он не существует. 
Для того, чтобы открыть двоичный файл, символ b должен быть включен в режим доступа. 
Если файл был успешно открыт, функция возвращает указатель на объект файла, который используется для идентификации потока
и выполнения операций с файлом. В противном случае, возвращается нулевой указатель. 

int fclose(FILE* filestream ); 
	Функция fclose закрывает и разъединяет файл filestream, связанный с потоком. 
Все внутренние буферы, связанные с потоком сбрасываются: содержание любого незаписанного буфера записывается и содержание
любого непрочитанного буфера сбрасывается. Если файл успешно закрыт, возвращается нулевое значение. 
В случае ошибки, возвращается EOF. 

- stdin, stdout

Поток номер 0 (stdin) зарезервирован для чтения входных данных. 
Поток номер 1 (stdout) зарезервирован для вывода данных. 

- printf, scanf, fprintf, fscanf, sprintf, scanf

int printf(const char* format, ... ); 
	Пишет отформатированное по строке в stdout 

int scanf(const char* format, arg-list, *char ptr); 
	Функция scanf() является процедурой ввода общего назначения, считывающей данные из потока stdin. 

int fprintf(FILE* stream, const char* format, ... ); 
	Функция fprintf выполняет форматированный вывод в файл. Записывает в указанный поток последовательность символов в формате,
указанном аргументом format. 

int fscanf(FILE* fp, const char* format, ..., *char ptr); 
	Функция fscanf выполняет форматированное чтение из файла.

int sprintf(char* buf, const char* format, arg-list); 
	Функция sprintf() идентична printf(), за исключением того, что вывод производится в массив, указанный аргументом buf.
Возвращаемая величина равна количеству символов, действительно занесенных в массив. 

int sscanf(char* buf, const char* format, arg-list); 
	Функция sscanf() идентична функции scanf() во всем, кроме того, что данные считываются из массива, указанного аргументом buf,
а не из файла stdin. Возвращаемая величина равна количеству полей, значения которых действительно были при своены переменным. 

- fread, fwrite, fseek, ftell, fflush

size_t fread(void* ptrvoid, size_t size, size_t count, FILE* filestream); 
	Функция fread считывает массив размером — count элементов, каждый из которых имеет размер size байт, из потока, и сохраняет
его в блоке памяти, на который указывает ptrvoid. 
Индикатор положения потока увеличивается на общее число записанных байтов. Возвращается объект типа size_t, который содержит
общее количество, успешно считанных, элементов. 

size_t fwrite(const void* ptrvoid, size_t size, size_t count, FILE* filestream); 
	Функция fwrite записывает массив размером — count элементов, каждый из которых имеет размер size байт, в блок памяти,
на который указывает ptrvoid — текущая позиция в потоке. 

int fseek(FILE* filestream, long int offset, int origin);
	Функция fseek перемещает указатель позиции в потоке. Устанавливает внутренний указатель положения в файле, в новую позицию, 
которая определяются путем добавления смещения к исходному положению. 
SEEK_SET Начало файла 
SEEK_CUR Текущее положение файла 
SEEK_END Конец файла
offset - Количество байт для смещения, относительно некоторого положения указателя. 
origin - Позиция указателя

long int ftell(FILE* filestream ); 
	Функция ftell возвращает значение указателя текущего положения потока. Для бинарных потоков, возвращается значение соответствующее
количеству байт от начала файла. 

int fflush(FILE* filestream ); 
	Если данный поток был открыт для записи (или, если он был открыт для обновления и последняя операция ввода/вывода была операцией
вывода) любые незаписанные данные в выходном буфере записываются в файл. Если аргумент является нулевым указателем, то открытый
файл очищается. Поток остается открытым после этого вызова. Нулевое значение указывает на успех. 

- обработка ошибок, feof, ferror

int feof (FILE* filestream ); 
	Функция feof проверяет, достигнут ли конец файла, связанного с потоком, через параметр filestream. Возвращается значение,
отличное от нуля, если конец файла был действительно достигнут. 

int ferror(FILE* filestream ); 
	Функция ferror отслеживает появление ошибки, связанной с потоком, который передаётся через параметр filestream. Если ошибка
была обнаружена, возвращается значение, отличное от нуля. Эту функцию целесообразно вызывать после выполнения предыдущей
операции с потоком. Таким образом. если предыдущая операция выполнится с ошибкой, функция ferror проинформирует об этом.

=======================================================================================================================

07. Классы и объекты.

- зачем нужно ООП?
	Люди пришли к ООП по нескольким причинам, но по сути, так просто исторически сложилось. Языки программирования делали всё более
высокоуровневыми, чтобы не задумываться, как там всё внутри устроено, чтобы ускорить написание кода и его повторное использование.
Три основные идеи ООП - инкапсуляция, наследование и полиморфизм. Если коротко, то инкапсуляция позволяет работать с кодом, с классом,
как с чёрным ящиком. У тебя есть какой-то объект и ты просто пользуешься его функциями, которые пришиты к нему, не имея представления,
как они рабоают. Программисты всегда двигались в сторону уменьшения сущностей, с которыми нужно работать, чтобы не забивать мозг лишними
вещами и работать быстрее.
	Также можно использовать код повторно. Захотелось изменить класс, добавить туда пару функций, какие-то исправить, а заново код писать
не хочется, ведь всё остальное можно оставить - ну тогда просто можно унаследоваться от класса и менять только необходимое.
	Плюс появилась перегрузка, можно было написать класс, который работал бы по-разному с разными типами, а также можно было бы
унаследоваться и перекрыть старые функции, изменив интерфейс класса, к примеру, поменять один блок на другой - это полиморфизм.

- инкапсуляция: private/public
	В классе есть два(вообще три, но о третьей позже) поля - приватное и публичное. Как понятно из названия, публичными полями могут
пользоваться все кому не лень, изменять публичные переменные, вызывать публичные функции. Но чтобы программисты, при использовании
твоего кода не выстрелили себе в ногу, что они очень любят делать в свободное время, есть приватные поля. К ним доступ имеют только
сам класс. Но машинный код не знает ничего про поля, их там и нет. Компилятор просто посмотрит на твой код и кинет ошибку,
если ты залез туда, куда не надо. 

- конструктор (overloading), деструктор
	Некоторые классы требуют хитрой инициализации - конструктора. Например вектор. Плюс плюсов - перегрузка. Можно создать несколько
конструкторов от разных параметров, на основе которых код будет делать разные вещи. Например если параметры не передались, он может по
умолчанию выбрать свои. Если передан один параметр - создаст вектор такого размера, если два - создаст и проанализирует. С++ может,
даже хочет, создать свой конструктор по умолчанию для твоего класса, если в классе нет сложной инициализации, работы с памятью, файлами и
т.п., то можно воспользоваться стандартной реализацией и просто не писать конструктор. Деструктор же нужен, чтобы убить всё то, что ты
натворил в конструкторе и работе с классом. Он вызывается автоматически, когда класс выходит из области видимости, т.е. если его объект был
создан внутри функции, то при её завершении вызовется деструктор. Обычно, когда не нужен конструктор - не нужен и деструктор, компилятор
сам справится, а когда пишется конструктор - тогда и деструктор нужен. 

- инициализация
	До вызова конструктора все поля инициализируются чем-то. Чтобы их проинициализировать, часто используется двоеточие после конструктора
и там инициализация полей. Такой метод идеологически устоявшийся, также позволяет избежать коллизии имён и проинициализировать ссылки.
Например, для класса фигуры конструктор со списком инициализации может выглядеть вот так:
Figure::Figure(int id, int x, int y) : id(id), x(x), y(y) {} как тут видно, имена полей класса и имена аргументов функции одинаковые,
но проблем не возникает.

=======================================================================================================================

08. Работа с кучей на C++.

- new/delete
	Это аналог malloc и free из си. У них могут быть внутренние различия, в зависимости от компилятора, поэтому лучше не смешивать
одно с другим.
int* a = new int[5];//квадратные скобки, чтобы забацать массив.
my_class* a = new my_class;//без скобок, чтобы создать элемент.
delete[] a;
delete my_class; 
ну тут тоже видны аналогии. 

- создание объектов в куче
	Delete и new вызывают деструкторы и конструкторы классов соотвественно. Также не стоит мешать создание массивов нью, а удаление
delete без скобок, ибо undefined behavior. Если создан массив классов, то delete[] пройдётся по массиву и вызовет деструктор.

- конструктор копий
	Конструктор копий, в основном, используется тогда, когда нужен конструктор и деструктор, тогда же нужен и оператор присваивания. 
Иначе же, стандартные реализации справляются. По сути оператор копирования - это тот же конструктор, но с объектом того же типа, чтобы
можно было сразу заинициализировать копию объекта, например:
my_class::my_class(my_class& obj) { //тут нужна именно ссылка, иначе мы будем копировать для конструктора копий.
	//new[]
	//mem copy
}
Конструктор копий вообще используется, когда мы пишем my_class a = b; или, когда вызываем функцию и передаём класс, как параметр.
Также конструктор копий позволяет сделать my_class a = 3; Но порой это нам не нужно и мы можем это запретить
explicit my_class(size_t size); тогда my_class b(3) скомпилируется, а my_class b = 3 нет.

- оператор присваивания
	Теперь мы хотим создать два объекта, а потом первому присвоить второй. Как мы это хотим? Через привычное равно. a = b. Для
этого нужно переопределить оператор равно. 
my_class& operator=(const my_class obj) { swap идиома; return *this; } У этого оператора должно быть возвращаемое значение,
иначе такие вещи, как тройное присваивание не будут работать. Возвращаем мы ссылку на объект, поэтому нужно разыменовывать 
указатель this. Swap идиома позволяет просто и быстро перекопировать значения. Мы передаём в оператор не ссылку, поэтому копия
уже создаётся, далее мы свопаем значения, а копия удаляется сама собой. Удобно.
 
=======================================================================================================================

09. Наследование и полиморфизм.

- protected
	Это поле, такое же, как и private/public. Оно так же, как и private, не даёт доступа к переменным и функциям из этого поля
вне этого класса, но отличается тем, что даёт доступ для наследников класса.

- virtual (overriding)
	Виртуальные функции передаются наследникам, подразумевая на то, что функции будут переписаны у них. Эти функции сделаны, чтобы
программа понимала во время работы, какую функцию нужно вызывать, основываясь на типе объекта. Для переопределения функции в дочернем
классе необходимо, чтобы интерфейс(все аргументы и возвращаемое значение) совпадал с оригиналом, иначе это будет просто перегрузкой.
Также необходимо обратить внимание на то, что конструктор не может быть виртуальным, но деструктор может.
	Например, если у нас есть класс list, у него наследник double list, то можно сделать в list функцию, которая принимает list,
при этом double list тоже может быть записан в качестве параметров этой функции при вызове, и проблем никаких не будет, ибо
двусвязный список - это тоже список. Но компилятор не может узнать на стадии компиляции, какую ему функцию нужно вызвать, которая
работает со списком или с двусвязным списком. Поэтому и существуют виртуальные функции.
Также виртаульные функции могут быть объявлены с присвоением нуля. Это будет говорить компилятору о том, что они обязательно должны 
быть перекрыты в дочерних классах. Такая запись означает также, что у этой функции нет реализации в этом классе.
virtual void print() const = 0;

- таблица виртуальных функций - статическое/динамическое связывание
	Если в классе есть виртуальная функция, то при компиляции создаётся таблица виртуальных функций, где грубо говоря, на идейном
уровне, в одном столбце стоит название, в другом адрес. Если линковка была статическая - при исполнении будет сразу комманда
"вызвать функцию по такому-то адресу", при динамической же будет командаа "найди такую функцию в таблице виртуальных функций и 
вызови её". У каждого объекта есть указатель на виртуальную функцию, чтобы программа могла понять, у какого класса какую таблицу
нужно смотреть. Естественно, мы платим за виртуальные функции скоростью работы программы.
// вроде всё, но как-то мало

=======================================================================================================================

10. Умные указатели.

- scoped_ptr
	Мы не хотим вечно думать о памяти, о том, чтобы её чистить, поэтому давайте сдеалем умный указатель, который сам будет
заботиться о высвобождении памяти, когда выходит из области видимоти.
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
Но у такой реализации есть проблемы.
if() {
	scoped_ptr p = new Person(Vasya);
	p->hasBirthday();//будет воспринимать как p->->
	*p.hasBirthday();

	scoped_ptr p1 = p; в конце дважды деструктор вызовится;
	//printPerson(p); та же проблема. При завершении функции указатель удалится, а при завершении этого if он снова захочет
	//удалить указатель, которого уже не существует.
}

if() {
	scoped_ptr p1 = new Person(Vasya);
	scoped_ptr p2 = new Person(Dima);
	p1 = p2;//утечка памяти и та же проблема с delete
}
Можно засунуть оператор присваивания и копирования в приватное поле, но это не избавит от всех проблем и обмануть всё равно получится

- auto_ptr
class auto_ptr // auto_ptr
{
	private:
		Person *p;
	public:
		auto_ptr(Person *p){this->p = p;}
		~auto_ptr(){if (p) delete p;}//!!
		Person* ptr(){return p;};
		Person* operator->(){return p;}
		Person& operator*(){return *p;}
		auto_ptr(auto_ptr &o){//!!
			this->p = o->p;
			o->p = NULL;
		}
}
Но тут также остались проблемы. Мы всё ещё не можем использовать его многократно при вызове функций или копировании.
PrintUser(p); //норм
PrintUser(p); // уже там Null, можно вызвать только один раз
Также скопировать можно только один раз.
можно писать ф-ции вот так func(unique_ptr &p); это будет работать, но это сложно, мы хотели себе облегчить жизнь,
а не следить за жизнью указателя.
Нужен счётчик созданных копий - это shared_ptr

- shared_ptr//шарит птр действительно шарит, что происходит.
Каждое копирование вызывает увеличение счётчика, а каждый выход за область видимости - уменьшение. А если счётчик ссылок
достиг нуля - удаляется и сам storage - то, что мы храним. 
p1 -->|storage| -> Person;
p2 -->|	 	  |
Два указателя будут работать с одним и тем же storage, который хранит наш объект.

class shared_ptr {
  public:
    shared_ptr(Matrix* obj = 0);
    shared_ptr(const shared_ptr& other);
    shared_ptr& operator=(shared_ptr other);
    ~shared_ptr();

    Matrix* ptr() const;
    bool isNull() const;
    void reset(Matrix* obj = 0);

    Matrix* operator->() const;
    Matrix& operator*() const;

  private:
    class Storage {
      public:
        Storage(Matrix* mtx);
        ~Storage();

        void incr();
        void decr();

        int getCounter() const;
        Matrix* getObject() const;

      private:
        Matrix *data_;
        int ref_count_;
    };

  private:
    Storage *storage_;
};

Реализация всего лежит тут: "https://dpaste.de/cCVv", там не мало. Но для ответа на билет достаточно будет описать идею
и оговорить ключевые моменты реализации.

=======================================================================================================================

11. Перегрузка операторов.

- бинарные и унарные
	Бинарные операторы - операторы, работающие с двумя объектами, напрмиер +, -, +=, &&...
	Унарные работают с одним объектом - [], ++, *...

Пример бинарного оператора и его перегрузки:
bool Matrix::operator==(const Matrix& m){
	if (размеры не равны)
		return false;
	if(какие-то значени не равны)
		return false;
  return true;
}

Matrix& Matrix::operator+=(const Matrix& m) {
  	for (std::size_t i=0; i<_rows; i++)
		for (std::size_t j=0; j<_cols; j++)
			_data[i][j] += m._data[i][j];
  return *this;
}

Matrix& Matrix::operator+(const Matrix& m) {
  return *this += m;
}
//зачастую операторы выражаются через другие. Например все операторы сравнения можно выразить через меньше

Унарные операторы реализуются также, важно рассмотреть несколько особенностей. Во-превых, это разница операторов ++

 BigInt& operator++(){//++a
 	*this+=1;
 	return *this;
 }

 BigInt operator++(size_t n){//a++;
 	BigInt t(*this);
 	*this+=1;
 	return t;//этот оператор работает дольше из-за копирования.
 }
оператор [] тоже имеет особеннсоти. Его следует дважды, с const и без.
int* operator[](std::size_t i);
const int* operator[](std::size_t i) const;
Это нужно из-за разницы в присваивании и просто взяитии значения. Если у нас указатель на константый объект, мы не сможем
взять по нему значения первым способом.

"https://dpaste.de/wVKr#L146" пример с практики.

- в классе/вне классе

Операторы пишутся вне класса, если у нас нет доступа к коду этого класса. А ещё если нам хочется написать оператор,
у которого слева, например, int, а справа какой-нибудь класс. Тогда, если у нас есть приведение типов, то мы сможем, например,
прибавить к инту наш класс.
Matrix operator+(Matrix, const Matrix& right); //вот мы объявили в h файле
Matrix operator+(Matrix left, const Matrix& right) {//и реализовали в cpp
	return left += right;
}
так строчка Matrix a = 2 + b; будет работать корректно, если есть приведение типа инта к матрице.

- friend

Мы можем указать в классе дружественные функции. Это функции, которые не относятся к самому классу, при это они могут быть
записаны с private и protected модификаторами доступа, но всё равно быть видны вне класса. По сути своей это обычные функции,
к ним не нужно дописывать class::, ибо они не являются частью класса, а также они не будут вызываться через точку.
friend void setData(char *, int, Woman25&);
setData("Инна", 50, Inna);

- приведение типов

1.BigInt a = 3; Ну вот приведение
BigInt a = (BigInt)3;//теперь более явно.

Начнём с первого случая. Что это и с чем это есть? Чтобы оно сработало - у нашего класса должен быть конструктор вот такой:
BigInt(int)

BigInt a = (BigInt)3;
	^		 |
	|		 v
 a(tmp)<----tmp
Современные комиляторы могут это сделать быстрее, без создания третьей переменной.
Проблема в том, что это может быть не слишком разумно, ибо BigInt(3) просто создаст массив размера 3, поэтому можно запретить
подобное присвоение с помощью explicit BigInt(size_t);

=======================================================================================================================

12. Ключевые слова extern, static, inline.
- extern у переменных
- static у переменных и функций
- static у полей и методов
- inline у функций

=======================================================================================================================

13. Разное
- Автотесты
- Декомпозиция программы (Model, View)
- Ключевые слова const, enum

=======================================================================================================================
