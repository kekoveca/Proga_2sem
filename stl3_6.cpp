#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

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
    vector <int> vect1;
    vector <int> vect2;
    vector <int> vect3;

    vect1.resize(n);
    for_each(vect1.begin(), vect1.end(), read);
    for(auto& el: vect1){
        if(el % 2 == 0)
            vect2.push_back(el);
        else 
            vect3.push_back(el);
    }

    sort(rbegin(vect2),rend(vect2));
    sort(begin(vect3), end(vect3));
    auto it2 = begin(vect2);
    auto it3 = begin(vect3);

    for(auto& elem: vect1){
        if(elem % 2 == 0){
            cout << *it2 << " ";
            it2 = next(it2);
        } else {
            cout << *it3 << " ";
            it3 = next(it3);
        }
    }
}