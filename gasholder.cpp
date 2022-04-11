#include <iostream>
using namespace std;

class GasHolder{
    private:
    double volume, temp, nu, press, R;

    public:
    // Создать газгольдер заданного объёма.
    // Температура созданного термостата равна 273 К.
    GasHolder(float v){
        volume = v;
        temp = 273;
        R = 8.31;
        nu = 0;
    }

    // Уничтожить газгольдер.
    ~GasHolder(){}

    // Впрыск порции газа массой m и молярной массой M.
    // Считать, что газ принимает текущую температуру газгольдера за пренебрежимо малое время.
    void inject(float m, float M){
        this->nu += m/M;  
    }
    // Подогреть газгольдер на dT градусов.
    // Считать, что нагрев возможен до любых значений температуры.
    void heat(float dT){
        this->temp += dT;
    }

    // Охладить газгольдер на dT градусов.
    // При попытке охладить ниже 0 К температура становится ровно 0 К.
    void cool(float dT){
        if(this->temp - dT <= 0){
            this->temp = 0;
        }
        else{
            this->temp -= dT;
        }
    }

    // Получить текущее давление в газгольдере.
    // Считать, что для газа верно уравнение состояния PV = (m/M)RT. 
    // Значение постоянной R принять 8.31 Дж/(моль*К).
    float getPressure(){
        return (this->nu * this->R * this->temp)/this->volume;
    }
};

int main(){
    GasHolder h(1.0);
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.heat(273);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    return 0;
}