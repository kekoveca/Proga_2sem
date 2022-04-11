#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Animal {
public:
    virtual string getType() const = 0;
    virtual ~Animal() {}
};

class ZooKeeper {
private:
    map<string,int> animals;
public:
    // Создаём смотрителя зоопарка
    ZooKeeper(){};

    // Смотрителя попросили обработать очередного зверя.
    void handleAnimal(const Animal& a){
        animals[a.getType()]++;
    }

    // Возвращает, сколько зверей такого типа было обработано.
    // Если таких не было, возвращает 0.
    int getAnimalCount(const string& type) const{
        auto it = animals.find(type);
        if(it != animals.end()){
            return it->second;
        }
        else return 0;
    }
};