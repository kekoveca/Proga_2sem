#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

struct int_str {
    unsigned long long a;
    string b;
};

class Compare{
public:
    bool operator()(const int_str& lhs, const int_str& rhs) const
    {
        if (lhs.a == rhs.a)
            return lhs.b < rhs.b;
        else
        {
            return lhs.a > rhs.a;
        }
    }
};

int main(){

    unsigned N;
    cin >> N;

    map <string, set<string>> str_set;

    for(unsigned i = 0; i < N; i++){
        string original;
        cin >> original;
        string lower_reg = original;
        transform(original.begin(), original.end(), lower_reg.begin(), ::tolower);
        str_set[lower_reg].insert(original);
    }

    set<int_str, Compare> s;

    for (auto& it : str_set) {
        s.insert(int_str{ it.second.size(), it.first });
    }
    
    for (auto& it : s)
        if(it.a > 2)
            cout << it.b << endl;
}