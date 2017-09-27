#include "exercise2.h"
#include "sort.h"
#include "vector.h"

template <typename Tn>
void print(Vector<Tn> & vec) {
    for (int i = 0; i < vec.size(); i++) {
       std::cout << vec[i] << std::endl;
    }
}

void exercise2() {
    Vector<string> vec{"az", "ad", "ae", "er", "aa" , "bb"};
    print(vec);
    sort(vec);
    std::cout << std:: endl;
    print(vec);
}

