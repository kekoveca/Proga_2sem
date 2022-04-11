#include <iostream>
using namespace std;

class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};

class ZooKeeper {
private:
    int count{};

public:
    // Создаём смотрителя зоопарка
    ZooKeeper() {}

    // Смотрителя попросили обработать очередного зверя.
    // Если зверь был опасный, смотритель фиксирует у себя этот факт.
    void handleAnimal(Animal* a){
        if(a->isDangerous() == 1)
        count++;
    };

    // Возвращает, сколько опасных зверей было обработано на данный момент.
    int getDangerousCount(){
        return count;
    };
    
};

int main(){
    
}