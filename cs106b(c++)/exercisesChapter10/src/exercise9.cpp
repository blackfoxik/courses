

#include "exercise9.h"


using namespace std;

//general
void exercise9() {
cout <<
"f(N) < g(N)" << endl;
cout << "prove that 15f(N) + 6g(N) is O(g(N))" << endl;
cout << "Answer: " << endl;
cout <<"Despite f(n) < g(N) in Big - O notation we use the worst case because we want to " <<
"know TOP boundary. 15 and 6 are constants which we can eliminate, so we have f(N) + g(N) " <<
"but g(N) is worse than f(N) and rely on this we can use g(N) instead of F(N) : g(N) + g(N) = 2g(N)" <<
"but 2 is also constant so we eliminate it too and left only g(N) " << endl;

}





