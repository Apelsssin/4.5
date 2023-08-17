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
        arr = new T * [rows];
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

    const T* operator[] (size_t i) const {
        return arr[i];
    }

    Table(const Table& arr2) {
        for (int i = 0; i < cols; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
        rows = arr2.rows;
        cols = arr2.cols;
        arr = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            arr[i] = new T[cols];
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                arr[i][j] = arr2[i][j];
            }
        }

    }

    Table& operator=(const Table& arr2) {
        if (this != &arr2) {
            for (int i = 0; i < cols; ++i) {
                delete[] arr[i];
            }
            delete[] arr;
            rows = arr2.rows;
            cols = arr2.cols;
            arr = new T * [rows];
            for (int i = 0; i < rows; ++i) {
                arr[i] = new T[cols];
            }
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    arr[i][j] = arr2[i][j];
                }
            }
        }
        return  *this;
    }
};
int main() {
    auto test = Table <int>(2, 3);
    test[0][0] = 4;
    const Table<int> t1(2, 3);
    //t1[0][0] = 4;
    std::cout << test[0][0] << std::endl;
    std::cout << t1[0][0];
}