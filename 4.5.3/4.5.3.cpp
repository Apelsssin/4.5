
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
template <class T>
class SumFunctor {
    T n;
public:
    SumFunctor() : n {0} { }
    void operator() (auto it) {
        if (it % 3 == 0)
            n += it;
    }
    T get_sum() {
        return n;
    };
};


template <class T>
class CountFuntor {
    int m;
public:
    CountFuntor() : m{ 0 } { }
    void operator() (auto it) {
        if (it % 3 == 0)
                ++m;
    }
    int get_count() {
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
    SumFunctor <int> x;
    CountFuntor <int> y;
    x = std::for_each(v.begin(), v.end(), x);
    y = std::for_each(v.begin(), v.end(), y);

    std::cout << "[OUT] : get_sum() = " << x.get_sum() << std::endl;
    std::cout << "[OUT] : get_count() = " << y.get_count() << std::endl;
}
