#include <iostream>
#include <string>
using namespace std;

class VectorN{
    int* a;
    unsigned int size {};

    public:
    // Конструктор вектора размерности n
    VectorN(unsigned int n){
        a = new int[n];
        size = n;
    }

    // Деструктор
    ~VectorN(){
        delete[] a;
    }

    // Получение размерности вектора
    unsigned getSize() const{
        return size;
    }

    // Получение значения i-ой координаты вектора,
    // i находится в диапазоне от 0 до n-1
    int getValue(unsigned int i) const{
        return a[i];
    }

    // Задание значения i-ой координаты вектора равным value,
    // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, int value){
        a[i] = value;
    }

    // Оператор == проверяет два вектора на равенство, 
    // равны они, если строго равны всех их координаты
    bool operator == (const VectorN& vector) const{
        unsigned int k{};
        for(unsigned int i = 0; i < size; i++){
            if(a[i] == vector.a[i])
            k++;
        }
        return k == size;
    } 

    // Оператор != проверяет два вектора на неравенство,
    // они не равны, если хотя бы одна координата отличается
    bool operator != (const VectorN& vector) const{
        return !(*this == vector);
    }

    // Оператор + складывает два вектора покоординатно,
    // возвращает результат как новый экземпляр вектора
    VectorN operator + (const VectorN& vector) const{
        VectorN sum(size);
        for(unsigned int i = 0; i < size; i++) sum.a[i] = vector.a[i] + a[i];
        
        return sum;
    }

    // Оператор * умножает вектор на скаляр типа int покоординатно,
    // возвращает результат как новый экземпляр вектора.
    // Умножение должно работать при любом порядке операндов.
    VectorN operator * (int a) const{
        VectorN mult(size);
        for(unsigned int i = 0; i < size; i++) mult.a[i] = this->a[i] * a;
        return mult;
    }
};

VectorN operator* (int alpha, const VectorN& v){
    VectorN mult(v.getSize());
    for(unsigned int i = 0; i < v.getSize(); i++) mult.setValue(i, alpha*v.getValue(i));
    return mult;
}

int main(){
    VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    cout << (a == b) << endl;
    cout << (a != b) << endl;

    VectorN c = a + b;
    VectorN d = 5 * c;

    for(unsigned int i = 0; i < a.getSize(); ++i)
        cout << d.getValue(i) << endl;
}