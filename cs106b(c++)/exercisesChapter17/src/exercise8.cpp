#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "set.h"
#include "grid.h"
#include "exercise8.h"
#include "random.h"
#include "setcharvector.h"
using namespace std;



//func prototypes

void exercise8() {
     SetCharVector<char> s;
     s.add('A');
     cout<< s.isEmpty() << endl;
     cout<< s.size() << endl;
     s.remove('A');
     cout<< s.size() << endl;
     cout<< s.isEmpty() << endl;
}









