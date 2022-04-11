#include <iostream>
#include <string>
#include <sstream> 
#include <ostream>
using namespace std;

std::istream& operator >> (istream& is, string a){
    is >> a;     
    return is;
}

int main(){
    string A;
    cin >> A;
    cout << A;
}