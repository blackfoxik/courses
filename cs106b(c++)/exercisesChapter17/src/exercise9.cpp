#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "set.h"
#include "grid.h"
#include "exercise9.h"
#include "random.h"
#include "sethybrid.h"
using namespace std;



//func prototypes

void exercise9() {
     SetHybrid<int> s;
     s.add(20);
     s.add(2000);
     cout<< s.isEmpty() << endl;
     cout<< s.size() << endl;
     s.remove(20);
     cout<< s.size() << endl;
     cout<< s.isEmpty() << endl;
}






