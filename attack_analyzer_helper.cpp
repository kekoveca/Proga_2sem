#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <vector>
#include <set>
using namespace std;

struct tp{
    unsigned long long time;
    unsigned short int port;
};

bool compareStructs(tp s1, tp s2){
    return (s1.time < s2.time);
}

bool is_bad(unsigned long long timeThreshold, unsigned short int portLimit, const vector<tp>& v){
    for(unsigned int i = 0; ; i++){
        if(v.empty() == true)
            return false;

        // cout << "Step " << i << "; ";
        set<int> ports;
        // cout << "set " << i << " created. ";
        
        bool state = false;
        
        for(unsigned long long j = i; (v.at(j).time - v.at(i).time) < timeThreshold; j++){
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


int main(){
    vector<tp> v = {{100500, 21}, {100600, 22}, {100700,23},{100800,24},{100900,25}};
    sort(v.begin(), v.end(), compareStructs);

    for(const auto& el: v){
        cout << "time: " << el.time << " port: " << el.port << endl;
    }
    cout << "Size : " << v.size() << endl;
    cout << endl;
    auto t = is_bad(5, 3, v);
    cout << boolalpha << t;

}