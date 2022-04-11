#include <iostream>
#include <string>
using namespace std;


class Student
{
    private:
    string Name;
    unsigned int Score;

    public:
    // Задать имя студента
    void setName(string name){
        Name = name;
    }

    // Указать количество баллов за контрольную
    void setScore(unsigned int score){
        Score = score;
    }

    // Получить имя студента
    string getName() const{
        return Name;
    }

    // Получить количество баллов студента
    unsigned int getScore() const{
        return Score;
    }
};

istream& operator >> (istream& is, Student& student){
    string str;
    getline(cin, str);
    student.setName(str);
    student.setScore(0);
    return is;
}

ostream& operator << (ostream& os, Student& student){
    os << "'" << student.getName() << "': " << student.getScore();
    return os;
}


int main() {
    Student s;
    cin >> s;
    s.setScore(10);
    cout << s << endl;

}