Singletone

Class Config для настроек.
hashtable h;
constructor() загружает все настройки в хэш таблицу.
int lookup(const *char key);

class logger{
	void log();
}

Board
	Config g;

View
	Config cfg;

class Config{												Config.cpp
private:													Config* Config::ptr = NULL;
	static Config* ptr;
	hashtable ht;											
	Config(){												
		while (!fend(f)){
		FILE* f = fopen();										
			ht.insetf();
			....
		}
	}

public:
	int lookup(const* char key);
	static Config* get_instance(){
		static Config cfg();
		retrun &cfg;
	}
	static Config* get_instance(){
		if(!ptr) ptr = new Config();
		return ptr;
	}
}

1. Я хочу, чтобы нельзя было писать Config cfg();// private (well done)

class Board() {
	Board(){
		int sz = Config::get_instance()->lookup("board-size");
	}
}

====================
Static inline



