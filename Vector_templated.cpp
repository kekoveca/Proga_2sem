#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Vector2D
{
private:
    T x;
    T y;
public:
    // Конструкторы
    Vector2D(T _x, T _y) : x(_x), y(_y) {
    }

    // Пустой конструктор, теперь он нужен
    // (иначе как будет создан вектор, пока он не считан с cin?)
    Vector2D() : Vector2D(0, 0) {
    }

    // Деструктор
    ~Vector2D(){
        
    }

    // Получение координат
    T getX() const{
        return x;
    }
    T getY() const{
        return y;
    }

    // Задание координат
    void setX(T x){
        this->x = x;
    }
    void setY(T y){
        this->y = y;
    }

    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector2D& v2) const{
        return x == v2.x && y == v2.y;
    }

    // Ещё один перегруженный оператор - неравенство векторов
    // Да, это отдельный оператор! Хинт - настоящие джедаи смогут для != использовать уже написанное ==
    bool operator!= (const Vector2D& v2) const{
        return !(*this == v2);
    }

    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator+ (const Vector2D& v2) const{
        return Vector2D(x + v2.x, y + v2.y);
    }

    // Вычитание векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator- (const Vector2D& v2) const{
        return Vector2D(x - v2.x, y - v2.y);
    }

    // Оператор умножения вектора на скаляр, исходный вектор не меняется, возвращается новый вектор
    Vector2D operator* (const int a) const{
        return Vector2D(a*x, a*y);
    }
};

// Оператор умножения скаляра на вектор, исходный вектор не меняется, возвращается новый вектор
// Неожиданно, правда? Умножение скаляра на вектор - это отдельный оператор, причём описанный *вне* класса.
template <typename T>
Vector2D<T> operator* (int a, const Vector2D<T>& v){
    return Vector2D<T>(a*v.getX(), a*v.getY());
}

// Вывод вектора, ожидается строго в формате (1; 1)
template <typename T>
ostream& operator<<(ostream& os, const Vector2D<T>& v){
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

// Чтение вектора, читает просто две координаты без хитростей
template <typename T>
istream& operator>>(istream &is, Vector2D<T> &v){
    T x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
}

int main(){
    Vector2D<int> v1;
    cin >> v1;
    cout << "Read vector: " << v1 << endl;
    cout << "Vector multiplied by 42: " << v1 * 42 << endl;

    Vector2D<double> v2;
    cin >> v2;
    cout << "Read vector: " << v2 << endl;
    cout << "Vector multiplied by 42: " << 42 * v2 << endl;
}