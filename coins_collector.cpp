#include <iostream>

using namespace std;

class MoneyBox {
protected:
    unsigned sum = 0;
    unsigned count = 0;

public:
    // Конструктор и деструктор, если нужны

    // Добавить монетку достоинством value
    void addCoin(unsigned int value){
        count++;
        sum += value;
    }

    // Получить текущее количество монеток в копилке
    unsigned int getCoinsNumber() const{
        return count;
    }

    // Получить текущее общее достоинство всех монеток
    unsigned int getCoinsValue() const{
        return sum;
    }
};

int main(){
    MoneyBox m;
    // Добавили монетку достоинством 10
    m.addCoin(10);
    // Добавили монетку достоинством 5
    m.addCoin(5);

    // Ожидаем, что монеток внутри 2 штуки
    cout << m.getCoinsNumber() << endl;
    // Ожидаем, что общее достоинство всех монеток 15
    cout << m.getCoinsValue() << endl;
}