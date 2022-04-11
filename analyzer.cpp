#include <iostream>
#include <vector>

using namespace std;

class Task
{
protected:
    int cpuNum;
    int size;

public:
    Task(int cpuNum, int size) {
        this->cpuNum = cpuNum;
        this->size = size;
    }

    // На каком ядре процессора выполняется задача
    int getCPU() const {
        return cpuNum;
    }

    // Оценка сложности задачи (в попугаях)
    int getSize() const {
        return size;
    }
};

class Analyzer{
    private:
    vector<Task> taski;

    public:
    // Создать анализатор для системы с numCores ядер
    Analyzer(int numCores){};

    // Проанализировать текущие задачи
    void analyze(const vector<Task>& tasks){
        taski = tasks;
    }

    // Сообщить общую нагрузку на заданное ядро
    int getLoadForCPU(int cpuNum){
        int k {};
        vector<Task>::iterator it;
        for(it = taski.begin(); it != taski.end(); ++it){
            if(it->getCPU() == cpuNum) k += it->getSize(); 
        }
        return k;
    }
};

int main(){
    int numberOfCores = 4;
    vector<Task> data = { {0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5} };
    Analyzer a(numberOfCores);
    a.analyze(data);
    for(int i = 0; i < numberOfCores; i++)
        cout << a.getLoadForCPU(i) << endl;
}