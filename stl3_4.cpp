#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

auto print = [](const int& el){
    cout << el << " ";
};

int main(){
    unsigned n;
    cin >> n;
    vector <int> v1;
    multiset <int> s1;
    for(unsigned i = 0; i < n; i++){
        int a;
        cin >> a;
        s1.insert(a);
        v1.push_back(a);
    }
    multiset<int> s2;
    for(unsigned i = 0; i < n; i++){
        int a;
        cin >> a;
        s2.insert(a);
    }
    multiset <int> s3;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.end()));
    for(auto& elem: v1){
        for(auto element: s3){
            if(element == elem){
                cout << elem << " ";
                s3.erase(s3.find(element));
                break;
            }
        }
    }
}