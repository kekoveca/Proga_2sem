#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    list<string> names = {"Ilya", "Nikita", "Alex", "Sonya", "Anton"};
    names.sort();
    cout << "names: { ";
    for(const auto& el: names){
        cout << el << " ";
    };
    cout << "}";
}