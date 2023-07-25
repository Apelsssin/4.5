
#include <iostream>
#include <vector>
template <class T>
class get_sum {
    std::vector <T> v;
    T n = 0;
    int size;
public:
    get_sum(std::vector <T> v, int size) : v(v), size(size) { }
    T operator() () {
        for (int i = 0; i < size; ++i) {
            if (v[i] % 3 == 0)
                n += v[i];
        }
        return n;
    }
};

template <class T>
class get_count {
    std::vector <T> v;
    int m = 0;
    int size;
public:
    get_count(std::vector <T> v, int size) : v(v), size(size) { }
    int operator() () {
        for (int i = 0; i < size; ++i) {
            if (v[i] % 3 == 0)
                ++m;
        }
        return m;
    }
};

template <class T>
void print (std::vector<T> v,int size) {
    for (int it : v) {
        std::cout << it << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector v{ 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN] :  "; 
    print(v, v.size()); 
    get_sum x(v, v.size());
    get_count y(v, v.size());
    std::cout << "[OUT] : get_sum() = " << x() << std::endl; 
    std::cout << "[OUT] : get_count() = " << y() << std::endl;
}
