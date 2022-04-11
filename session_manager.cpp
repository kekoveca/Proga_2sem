#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class SessionManager
{
private:
    map<string, bool> people;
public:
    // Вход пользователя.
    // Один пользователь может войти несколько раз подряд, 
    // считать его при этом нужно один раз.
    void login(const string& username){
        people[username] = true;
    }

    // Выход пользователя.
    // Пользователь может выйти несколько раз подряд, 
    // падать при этом не нужно.
    void logout(const string& username){
        people[username] = false;
    }

    // Сколько сейчас пользователей залогинено.
    int getNumberOfActiveUsers() const{
        unsigned online{};
        for(auto it = people.begin(); it != people.end(); it++){
            if(it->second == true) online++;
        }
        return online;
    }
};

int main(){
    SessionManager m;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("bob");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("whoever");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("bob");
    cout << m.getNumberOfActiveUsers() << endl;
}