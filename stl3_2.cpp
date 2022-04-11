#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

auto read = [](int& el){
    cin >> el; 
};

int main(){
    unsigned n;
    cin >> n;
    multiset<int> s1;
    for(unsigned int i = 0; i < n; i++){
        int a;
        cin >> a;
        s1.insert(a);
    }
    multiset<int> s2;
    for(unsigned int i = 0; i < n; i++){
        int a;
        cin >> a;
        s2.insert(a);
    }
    cout << boolalpha << equal(s1.begin(), s1.end(), s2.begin(), s2.end());
}