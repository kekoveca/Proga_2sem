#include <iostream>
using namespace std;

class Item {
public:
    // Так можно создать предмет, указав его название, вес, уровень и магичность
    Item(string title, int weight, int level, bool magical);
    // Получить вес предмета
    int getWeight();
    // Получить уровень предмета
    int getLevel();
    // Получить, является ли предмет магичным
    int isMagical();
};

class Player {
protected:
    // Сила и уровень героя
    int strength;
    int level;
public:
    // Создать героя, все подробности будут указаны позже
    Player() { }
    // Удалить героя, ничего умного эта процедура пока что не требует
    virtual ~Player() { }

    // Базовые методы, пока что очень простые.
    // На данном этапе можно считать, что для всех героев они ведут себя одинаково, 
    // так что пусть будут в базовом классе.

    // Задать силу
    void setStrength(int strength) {
        this->strength = strength;
    }
    // Задать уровень
    void setLevel(int level) {
        this->level = level;
    }

    // Получить силу
    int getStrength() {
        return this->strength;
    }
    // Получить уровень
    int getLevel() {
        return this->level;
    }

    // Проверка, может ли игрок использовать предмет
    virtual bool canUse(Item* item) = 0;
};

class Knight: public Player{    
    bool canUse(Item* item){
        if(item->isMagical() == 1){
            return false;
        }
        else{
            if(((item->getWeight() < this->strength)) and (item->getLevel() < this->level)){
                return true;
            }
            else return false;
        }
    }
};

class Wizard: public Player{    
    bool canUse(Item* item){
        if(((item->getWeight() < this->strength)) and (item->getLevel() < this->level)){
            return true;
        }
        else return false;
    }
};