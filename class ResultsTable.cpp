#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ResultsTable
{
private:
    vector<unsigned int> table;
public:
    // Зарегистрировать новый результат, 
    // нас волнуют только баллы, имена пользователей не важны
    void addResult(unsigned int score){
        table.push_back(score);
    }

    // Получить минимальный балл из всех результатов за всё время
    unsigned int getMinScore() const{
        // sort(table.begin(), table.end());
        return *min_element(table.begin(), table.end());
    }

    // Получить, сколько баллов у игрока на заданном месте.
    // Внимание: места нумеруются так, как это принято на турнирах, то есть 
    // лучший результат - 1-ое место, за ним 2-ое место и т.д.
    unsigned int getScoreForPosition(unsigned int positionNumber) const{
        vector<unsigned int> table_reserve = table;
        sort(table_reserve.rbegin(), table_reserve.rend());
        return table_reserve[positionNumber - 1];
    }
};

int main(){
    ResultsTable t;

    t.addResult(30);
    t.addResult(85);
    t.addResult(12);
    t.addResult(31);

    cout << "1st place score: " << t.getScoreForPosition(1) << endl;
    cout << "2nd place score: " << t.getScoreForPosition(2) << endl;
    cout << "3rd place score: " << t.getScoreForPosition(3) << endl;
    cout << "Min score during the tournament: " << t.getMinScore() << endl;
}