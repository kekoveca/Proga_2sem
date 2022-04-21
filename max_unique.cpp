#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    unsigned N;
    cin >> N;
    
    map <int, int> m;

    for(unsigned i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }

    for(auto it = m.rbegin(); it != m.rend(); it = next(it)){
        if(it->second == 1){
            cout << it->first;
            return 0;
        }
    }
}