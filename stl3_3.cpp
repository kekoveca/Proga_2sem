#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

auto print = [](const int& el){
    cout << el << " ";
};

int main(){
    unsigned n;
    cin >> n;
    multiset<int> s1;
    for(unsigned i = 0; i < n; i++){
        int a;
        cin >> a;
        s1.insert(a);
    }
    multiset<int> s2;
    for(unsigned i = 0; i < n; i++){
        int a;
        cin >> a;
        s2.insert(a);
    }
    set<int> s3;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.end()));
    for_each(s3.begin(), s3.end(), print);
}