
#include <iostream>

template <class T>
class Table {
    size_t rows;
    size_t cols;
    T** arr;

public:
    Table(size_t r, size_t c) {
        rows = r;
        cols = c;
        arr = new T* [rows];
        for (int i = 0; i < r; ++i) {
            arr[i] = new T[cols];
        }
    }

    ~Table() {
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    T* operator[] (size_t i) {
        return arr[i];
    }

    const T& operator[] (size_t i) const {
        return **arr[i];
    }



};
int main()
{
    auto test = Table <int>(2, 3);
    test[0][0]= 4;
    std::cout << test[0][0]; // выводит 4
}