#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

// bool caseInsCharCompareN(char a, char b) {
//     return(toupper(a) == toupper(b));
// }

// bool caseInsCompare(const string& s1, const string& s2) {
//     return((s1.size() == s2.size()) && equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareN));
// }

// bool operator == (const string& lhs, const string& rhs) {
//     return caseInsCompare(lhs, rhs);
// }

// struct Compare
// {
//     bool operator()(const string& lhs, const string& rhs) const
//     {
//         if (caseInsCompare(lhs, rhs))
//         {
//             return true;
//         }
//         else 
//         {
//             return lhs < rhs;
//         }
//     }
// };

int main(){

    unsigned N;
    cin >> N;

    map <string, set<string>> str_set;

    for(unsigned i = 0; i < N; i++){
        string original;
        cin >> original;
        string lower_reg;
        transform(original.begin(), original.end(), lower_reg.begin(), ::tolower);
        str_set[lower_reg].insert(original);
    }
    
    map <int, string> int_str;

    for(auto& el: str_set){
        auto tmp_size = el.second.size();
        int_str[tmp_size] = el.first;
    }

    for(auto& el: int_str){
        if(true)
            cout << el.first << " is " << el.second << endl;
    }
}