
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
template <class T>
class get_sum {
    T n;
public:
    get_sum() : n {0} { }
    void operator() (auto it) {
        if (it % 3 == 0)
            n += it;
    }
    T get_() {
        return n;
    };
};


template <class T>
class get_count {
    int m;
public:
    get_count() : m{ 0 } { }
    void operator() (auto it) {
        if (it % 3 == 0)
                ++m;
    }
    int get_() {
        return m;
    };
};

void print (auto v,int size) {
    for (int it : v) {
        std::cout << it << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    //std::vector v{ 4, 1, 3, 6, 25, 54 };
    std::list v{ 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN] :  ";
    print(v, v.size());
    get_sum <int> x;
    get_count <int> y;
    x = std::for_each(v.begin(), v.end(), x);
    y = std::for_each(v.begin(), v.end(), y);

    std::cout << "[OUT] : get_sum() = " << x.get_() << std::endl;
    std::cout << "[OUT] : get_count() = " << y.get_() << std::endl;
}
