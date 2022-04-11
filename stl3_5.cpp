#include <iostream>
#include <set>
#include <algorithm>
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

    int k;
    cin >> k;

    auto print_if = [&k](const int& el){
    if(el <= k)
    cout << el << " ";
    };

    // for(auto& el: vect){
    //     if(el > k){
    //         vect.erase(find(vect.begin(), vect.end(), el));
    //     }
    // }
    for_each(begin(vect), end(vect), print_if);
}