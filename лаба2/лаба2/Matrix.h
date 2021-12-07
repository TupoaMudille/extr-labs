#include "Vector.h"

template <class TypeVal>
class Matrix : public Vector<Vector<TypeVal> >
{
public:
    const int MAX_MATRIX_SIZE = 1000;
    explicit Matrix(int s = 10);
    Matrix(const Matrix& vt);                    // copy
    Matrix(const Vector<Vector<TypeVal> >& vt); // type conversion
    bool operator==(const Matrix& vt) const;      // if ravno
    bool operator!=(const Matrix& vt) const;      // if neravno
    Matrix& operator= (const Matrix& vt);        // prisvoit
    Matrix  operator+ (const Matrix& vt);        // summ
    Matrix  operator- (const Matrix& vt);        // razn

    void input_matrix();
    void print_matrix();

    // ââîä // âûâîä
    friend std::istream& operator>>(std::istream& in, Matrix& vt)
    {
        for (int i = 0; i < vt.Size; i++)
            in >> vt.tVector[i];
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Matrix& vt)
    {
        for (int i = 0; i < vt.Size; i++)
            out << vt.tVector[i] << std::endl;
        return out;
    }
};

template <class TypeVal>
Matrix<TypeVal>::Matrix(int s) : Vector<Vector<TypeVal> >(s)
{

    if (s <= 0 || s > MAX_MATRIX_SIZE)
    {
        cout << "errror!!!! in size";
        std::exit(-6);
    }
    for (int i = 0; i < s; i++)
    {
        this->tVector[i] = Vector<TypeVal>(s - i, i);
    }
}

template <class TypeVal> // copy
Matrix<TypeVal>::Matrix(const Matrix<TypeVal>& vt) :
    Vector<Vector<TypeVal> >(vt) {}

template <class TypeVal> // type converter
Matrix<TypeVal>::Matrix(const Vector<Vector<TypeVal> >& vt) :
    Vector<Vector<TypeVal> >(vt) {}

template <class TypeVal> // if ravno
bool Matrix<TypeVal>::operator==(const Matrix<TypeVal>& vt) const
{
    return Vector<Vector<TypeVal>>::operator==(vt);
}

template <class TypeVal> // if neravno
bool Matrix<TypeVal>::operator!=(const Matrix<TypeVal>& vt) const
{
    return !(*this == vt);
}

template <class TypeVal> // prisvoit
Matrix<TypeVal>& Matrix<TypeVal>::operator=(const Matrix<TypeVal>& vt)
{
    Vector<Vector<TypeVal>>::operator=(vt);
    return *this;
}

template <class TypeVal> // summ
Matrix<TypeVal> Matrix<TypeVal>::operator+(const Matrix<TypeVal>& vt)
{
    return Vector<Vector<TypeVal>>::operator+(vt);
}

template <class TypeVal> // razn
Matrix<TypeVal> Matrix<TypeVal>::operator-(const Matrix<TypeVal>& vt)
{
    return Vector<Vector<TypeVal>>::operator-(vt);
}

template<class TypeVal>
inline void Matrix<TypeVal>::input_matrix()
{
    for (int i = 0; i < this->
        size_v; i++)
    {
        std::cout << "[" << i << "] " << "\n";
        this->tVector[i].input();
    }
}

template<class TypeVal>
inline void Matrix<TypeVal>::print_matrix()
{
    for (int i = 0; i < this->size_v; i++)
    {
        std::cout << this->tVector[i] << std::endl;
    }
}
