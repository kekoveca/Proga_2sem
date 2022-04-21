#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

bool caseInsCharCompareN(char a, char b) {
    return(toupper(a) == toupper(b));
}

string toLower(string& s){
    for(auto& el: s){
        el = tolower(el);
    }
}

bool caseInsCompare(const string& s1, const string& s2) {
    return((s1.size() == s2.size()) && equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareN));
}


int main(){
    unsigned N;
    cin >> N;

    map <string, int> m;

    for(unsigned i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        m[tmp]++;
    }

    for(auto& el: m){
        if(el.second != 1)
            cout << el.first << " is " << el.second << endl;
    }

}