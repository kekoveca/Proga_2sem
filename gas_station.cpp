#include <iostream> 

using namespace std;

class GasStation {
protected:
    int _size = 0;
    unsigned _capacity;

public:
    // Конструктор, принимающий один параметр - ёмкость резервуара колонки
    // Резервуар создаётся пустой
    GasStation(unsigned capacity): _capacity(capacity){
    }

    // Залить в резервуар колонки n литров топлива
    // Если столько не влезает в резервуар - не заливать ничего, выбросить std::exception
    void fill(unsigned int n){
        if(_size + n > _capacity) 
            throw runtime_error("Не влезает столько");
        else 
            _size += n;
    }

    // Заправиться, забрав при этом из резервура n литров топлива
    // Если столько нет в резервуаре - не забирать из резервуара ничего, выбросить std::exception
    void tank(unsigned int n){
        int tmp = n;
        if(_size - tmp < 0)
            throw runtime_error("Столько забрать нельзя");
        else
            _size -= n;
    }

    // Запросить остаток топлива в резервуаре
    unsigned int get_limit() const{
        return _size;
    }
};

int main(){
    GasStation s = GasStation(1000);            // Колонка на 1000, пока пустая
    s.fill(300);                                // Это влезет в резервуар, 
    cout << s.get_limit() << endl;              // ... так что здесь увидим на экране 300.

    s.tank(100);                                // Забрали из резервуара 100, 
    s.fill(300);                                // ... после чего долили ещё 300,
    cout << s.get_limit() << endl;              // ... так что на экране ожидаем 500.

    for(unsigned int i = 0; i < 5; i++)         // В цикле забрали 5 раз по 50,
        s.tank(50);
    cout << s.get_limit() << endl;              // ... так что на экране ожидаем 250.

    s.fill(1000);                               // А вот тут ожидаем exception.
                                                // (После проверки exception-а строку стоит просто убрать.)

    for(unsigned int i = 0; i < 50; i++) {      // Теперь пытаемся забрать 50 раз по 100,
        s.tank(100);                            // из-за чего на третьей попытке ждём exception. 
        cout << s.get_limit() << endl;
    }
}