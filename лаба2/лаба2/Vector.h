#include <iostream>
#include <limits>
#include <iterator>
#include <cstring>

using namespace std;

template <class TypeVal>
class Vector
{
protected:
    TypeVal* tVector;
    int size_v{};       // размер вектора
    int start_index_v{}; // индекс первого элемента вектора
    const int MAX_VECTOR_SIZE = 10000000;
public:
    explicit Vector(int size = 10, int start_index = 0);
    Vector(const Vector& v);                // конструктор копирования
    ~Vector();
    int get_size() const { return size_v; } // размер вектора
    int get_start_index_v() const { return start_index_v; } // индекс первого элемента
    TypeVal& operator[](int pos);             // доступ
    bool operator==(const Vector<TypeVal>& v) const;  // сравнение если равно
    bool operator!=(const Vector<TypeVal>& v) const;  // сравнение если не равно
    Vector<TypeVal>& operator=(const Vector& v);     // присваивание

    // скалярные операции
    Vector  operator+(const TypeVal& val);   // прибавить скаляр
    Vector  operator-(const TypeVal& val);   // вычесть скаляр
    Vector  operator*(const TypeVal& val);   // умножить на скаляр

    // векторные операции
    Vector  operator+(const Vector<TypeVal>& v);     // сложение
    Vector  operator-(const Vector<TypeVal>& v);     // вычитание
    TypeVal  operator*(const Vector<TypeVal>& v);     // скалярное произведение

    void input();
    void print();

    // ввод-вывод
    friend std::istream& operator>>(std::istream& in, Vector& v)
    {
        for (int i = 0; i < v.size_v; i++)
            in >> v.tVector[i];
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Vector& v)
    {
        for (int i = 0; i < v.size_v; i++)
            out << v.tVector[i] << ' ';
        return out;
    }
};

template<class TypeVal>
Vector<TypeVal>::Vector(int size, int start_index)
{
    setlocale(LC_ALL, "Russian");
    if (size < 0 || size > MAX_VECTOR_SIZE)
    {
        cout << "Ошибка!!!! в размере";
        std::exit(-1);
    }
    if (start_index < 0 || start_index > MAX_VECTOR_SIZE)
    {
        cout << "Ошибка!!!!!! в индексе";
        std::exit(-2);
    }
    size_v = size;
    start_index_v = start_index;
    tVector = new TypeVal[size_v];
}

template<class TypeVal>
Vector<TypeVal>::Vector(const Vector<TypeVal>& v)
{
    size_v = v.get_size();
    start_index_v = v.get_start_index_v();
    tVector = new TypeVal[size_v];

    for (int i = start_index_v; i < size_v; i++)
    {
        tVector[i] = v.tVector[i];
    }
}

template<class TypeVal>
Vector<TypeVal>::~Vector()
{
    delete[] tVector;
}

template<class TypeVal>
TypeVal& Vector<TypeVal>::operator[](int pos)
{
    setlocale(LC_ALL, "Russian");
    if (pos - start_index_v < 0 || pos - start_index_v >= size_v)
    {
        cout << "логическая ошибка!!!!!!";
        return -3;
    }
    return tVector[pos - start_index_v];
}

template<class TypeVal>
bool Vector<TypeVal>::operator==(const Vector<TypeVal>& v) const
{
    if (size_v != v.get_size())
    {
        return false;
    }

    for (int i = start_index_v; i < size_v; i++)
    {
        if (tVector[i] != v.tVector[i])
        {
            return false;
        }
    }
    return true;
}

template<class TypeVal>
bool Vector<TypeVal>::operator!=(const Vector<TypeVal>& v) const
{
    if (size_v != v.get_size())
    {
        return true;
    }

    for (int i = start_index_v; i < size_v; i++)
    {
        if (tVector[i] != v.tVector[i] && tVector[i] && v.tVector[i])
        {
            return true;
        }
    }
    return false;
}

template<class TypeVal>
Vector<TypeVal>& Vector<TypeVal>::operator=(const Vector& v)
{
    if (this != &v)
    {
        size_v = v.get_size();
        start_index_v = v.get_start_index_v();
        delete[] tVector;
        tVector = new TypeVal[size_v];

        for (int i = start_index_v; i < size_v; i++)
        {
            tVector[i] = v.tVector[i];
        }
    }

    return *this;
}

template<class TypeVal>
Vector<TypeVal> Vector<TypeVal>::operator+(const TypeVal& val)
{
    Vector<TypeVal> res = *this;
    for (int i = start_index_v; i < size_v; i++)
    {
        res[i] = tVector[i] + val;
    }
    return res;
}

template<class TypeVal>
Vector<TypeVal> Vector<TypeVal>::operator-(const TypeVal& val)
{
    Vector<TypeVal> res = *this;
    for (int i = start_index_v; i < size_v; i++)
    {
        res[i] = tVector[i] - val;
    }
    return res;
}

template<class TypeVal>
Vector<TypeVal> Vector<TypeVal>::operator*(const TypeVal& val)
{
    Vector<TypeVal> res = *this;
    for (int i = start_index_v; i < size_v; i++)
    {
        res[i] = tVector[i] * val;
    }
    return res;
}

template<class TypeVal>
Vector<TypeVal> Vector<TypeVal>::operator+(const Vector<TypeVal>& v)
{
    setlocale(LC_ALL, "Russian");
    if (size_v != v.get_size())
    {
        cout << "логическа ошибка, нельзя работать с разными по размеру векторами";
        return -4;
    }

    Vector<TypeVal> res(v);
    for (int i = start_index_v; i < size_v; i++)
    {
        res[i] = res[i] + tVector[i];
    }
    return res;
}

template<class TypeVal>
Vector<TypeVal> Vector<TypeVal>::operator-(const Vector<TypeVal>& v)
{
    setlocale(LC_ALL, "Russian");
    if (size_v != v.get_size())
    {
        cout << "логическа ошибка, нельзя работать с разными по размеру векторами";
        return -4;
    }

    Vector<TypeVal> res(*this);
    for (int i = start_index_v; i < size_v; i++)
    {
        res[i] = res[i] - v.tVector[i];
    }
    return res;
}

template<class TypeVal>
TypeVal Vector<TypeVal>::operator*(const Vector<TypeVal>& v)
{
    TypeVal res = 0;

    setlocale(LC_ALL, "Russian");
    if (size_v != v.get_size())
    {
        cout << "логическа ошибка, нельзя работать с разными по размеру векторами";
        return -4;
    }

    for (int i = start_index_v; i < size_v; i++)
    {
        res = res + tVector[i] * v.tVector[i];
    }
    return res;
}

template<class TypeVal>
inline void Vector<TypeVal>::input()
{
    for (int i = 0; i < this->size_v; i++)
    {
        std::cout << "a[" << i << "] = ";
        std::cin >> this->tVector[i];
    }
}

template<class TypeVal>
inline void Vector<TypeVal>::print()
{
    for (int i = 0; i < this.Size(); i++)
    {
        std::cout << this->tVector[i] << " ";
    }
}
