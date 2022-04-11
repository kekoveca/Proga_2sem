#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct parameters{
    array<long, 2> minmax{{0, 0}};
    unsigned count {};
};

class TelemetryController{
    map<string, parameters> devices;

    public:
    // Получить и обработать событие. Параметрами передаются:
    // - device - идентификатор устройства, с которого пришло значение;
    // - value - собственно значение некоторой величины, переданное устройством.
    void handleEvent(const string& device, long value){
        if(devices.find(device) == devices.end()){
            devices[device].count++;
            devices[device].minmax[0] = value;
            devices[device].minmax[1] = value;
        } 
        else{
            devices[device].count++;
            sort(devices[device].minmax.begin(), devices[device].minmax.end());
            if(value < devices[device].minmax[0])
                devices[device].minmax[0] = value;
            if(value > devices[device].minmax[1])
                devices[device].minmax[1] = value;
        }
    }

    // По идентификатору устройства возвращает, 
    // сколько всего значений от него пришло за всё время
    unsigned int getEventsCount(const string& device) const{
        return devices.at(device).count;
    }

    // По идентификатору устройства возвращает 
    // минимальное значение за всё время, пришедшее от данного устройства
    long getMinValue(const string& device) const{
        return devices.at(device).minmax.at(0);
    }

    // По идентификатору устройства возвращает 
    // максимальное значение за всё время, пришедшее от данного устройства
    long getMaxValue(const string& device) const{
        return devices.at(device).minmax.at(1);
    }
};

int main(){
    TelemetryController tc;

    tc.handleEvent("d1", 42);
    tc.handleEvent("d1", 99);
    tc.handleEvent("d2", 100);


    cout << "Events count for d1: " << tc.getEventsCount("d1") << endl;
    cout << "Min value for d1: " << tc.getMinValue("d1") << endl;
    cout << "Max value for d1: " << tc.getMaxValue("d1") << endl;
    cout << "Min value for d2: " << tc.getMinValue("d2") << endl;
    cout << "Max value for d2: " << tc.getMaxValue("d2") << endl;
}