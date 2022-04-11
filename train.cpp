#include <iostream>
using namespace std;

class Train{
    private:
    double mass;
    double p;
    double x;

    public:
    // Создать паровоз массой m, 
    // стоящий в начале координат
    Train(double m){
        this->x = 0;
        this->p = 0;
        this->mass = m;
    }

    // Ехать с текущей скоростью в течение времени dt
    void move(double dt){
        this->x += (this->p / this->mass) * dt;
    }

    // Изменить полный импульс паровоза (p = mv) на dp
    // Изменение может менять знак скорости
    void accelerate(double dp){
        this->p += dp;
    }

    // Получить текущую координату паровоза
    double getX(){
        return this->x;
    }
};

int main(){
    Train t(10);
    t.accelerate(1); // Скорость стала 0.1
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.accelerate(-2); // Скорость стала -0.1
    t.move(3);
    cout << "Current X: " << t.getX() << endl;
    return 0;
}
