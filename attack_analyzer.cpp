#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Connection
{
protected:
    string source;
    unsigned short int port;
    unsigned long long timestamp;

public:
    Connection(string source, unsigned short int port, unsigned long long timestamp) {
        this->source = source;
        this->port = port;
        this->timestamp = timestamp;
    }
    ~Connection() {}

    string getSource() const {
        return source;
    }

    unsigned short int getPort() const {
        return port;
    }

    unsigned long long getTimestamp() const {
        return timestamp;
    }
};

struct tp{
    unsigned long long time;
    unsigned short int port;
};

bool compareStructs(tp s1, tp s2){
    return (s1.time < s2.time);
}

class IntrusionDetector{
    protected:
    map<string, vector<tp>> adresses;
    unsigned long long timeThreshold_self;
    unsigned short int portLimit_self;

    bool isBad(unsigned long long timeThreshold, unsigned short int portLimit, const vector<tp>& v)const{
    for(unsigned int i = 0; ; i++){
        if(v.empty() == true)
            return false;

        // cout << "Step " << i << "; ";
        set<int> ports;
        // cout << "set " << i << " created. ";
        
        bool state = false;
        
        for(unsigned long long j = i; v.at(j).time - v.at(i).time < timeThreshold ; j++){
            if(v.at(j).time == prev(end(v))->time){
                state = true;
                break;
            }
            ports.insert(v.at(j).port);
        }

        // cout << "{";
        // for(const auto& el: ports){
        //     cout << el << " ";
        // }

        // cout << "} ";

        if(ports.size() >= portLimit)
            return true;
        // cout << endl;
        if(state == true) 
            break;
        } 
    // cout << endl;
    return false;
}

    public:
    // Задать временное окно для анализа (см. описание логики выше)
    void setTimeThreshold(unsigned short int timeThreshold){
        timeThreshold_self = timeThreshold;
    }

    // Задать минимальное количество портов для срабатывания (см. описание логики выше)
    void setPortLimit(unsigned short int portLimit){
        portLimit_self = portLimit;
    }

    // Вызов этого метода уведомляет анализатор о новом подключении.
    void handleConnection(const Connection& c){
        tp timePort = {c.getTimestamp(), c.getPort()};
        adresses[c.getSource()].push_back(timePort); 
        sort(adresses.at(c.getSource()).begin(), adresses.at(c.getSource()).end(), compareStructs);
    }

    // Проверить, является ли указанный адрес нарушителем
    bool isIntruder(const string& source) const{
        return isBad(timeThreshold_self, portLimit_self, adresses.at(source));
    }
};

int main(){
    IntrusionDetector id;
    id.setTimeThreshold(2);
    id.setPortLimit(2);

    id.handleConnection({"evil.com", 21, 100504});
    id.handleConnection({"evil.com", 22, 100501});
    id.handleConnection({"evil.com", 23, 100502});
    id.handleConnection({"evil.com", 24, 100503});
    id.handleConnection({"evil.com", 25, 100500});
    cout << boolalpha << "Checking if evil.com is intruder: " << id.isIntruder("evil.com") << endl;

    id.handleConnection({"load.com", 80, 100504});
    id.handleConnection({"load.com", 80, 100501});
    id.handleConnection({"load.com", 80, 100502});
    id.handleConnection({"load.com", 80, 100503});
    id.handleConnection({"load.com", 80, 100500});
    cout << boolalpha << "Checking if load.com is intruder: " << id.isIntruder("load.com") << endl;
}