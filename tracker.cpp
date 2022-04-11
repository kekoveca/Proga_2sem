#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Tracker
{
private:
    map<string, vector<unsigned long long>> people;
public:
    // При любом действии пользователя вызывается этот метод.
    // Методу передаётся:
    // - какой пользователь совершил действие (username);
    // - когда (timestamp - для простоты условные секунды от начала времён).
    // Внимание: не гарантируется, что timestamp расположены строго по
    // возрастанию, в них может быть любой бардак.
    void click(const string& username, unsigned long long timestamp){
        people[username].push_back(timestamp);
    }

    // По имени пользователя нужно вернуть, сколько всего было кликов
    unsigned long long getClickCount(const string& username) const{
        return people.at(username).size();
    }

    // Когда был первый клик
    unsigned long long getFirstClick(const string& username) const{
        return *min_element(people.at(username).begin(), people.at(username).end());
    }

    // Когда был последний клик
    unsigned long long getLastClick(const string& username) const{
        return *max_element(people.at(username).begin(), people.at(username).end());
    }
};