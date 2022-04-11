#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

auto print = [](const int& el){
    cout << el << " ";
};

auto read = [](int& el){
    cin >> el; 
};

int main(){
    unsigned n;
    cin >> n;
    vector <int> vect;
    vect.resize(n);
    for_each(vect.begin(), vect.end(), read);
    for_each(vect.rbegin(), vect.rend(), print);
}
