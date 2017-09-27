#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
using namespace std;

//for subtask a
/*struct eMailMsg {
    string to;
    string from;
    string message;
    string subject;
    int date;
    int time;
};*/

//for subtask c
struct eMailMsg {
    Vector<string> to;
    string from;
    string message;
    string subject;
    int date;
    int time;
};

void RemoveSpan(Vector<eMailMsg> &allMessages){
    for(int i = allMessages.size()-1; i>=0; i--){
        if(allMessages[i].subject.find("SPAM",0) != string::npos){
          allMessages.remove(i);
    }
    }
}

void printTheLetters(Vector<eMailMsg> &allMessages){
    for(int i = 0; i < allMessages.size(); i++){
        cout<< "Number " << i <<" subject "<< allMessages[i].subject << endl;
        cout<< "last to is " << allMessages[i].to[allMessages[i].to.size()-1] << endl;
    }

}

int main() {
    Vector<eMailMsg> allMessages;
    eMailMsg let1;
    let1.date = 1;
    let1.from = "Hurricane";
    let1.message = "ok";
    let1.subject = "important";
    let1.time = 2;
    //for subtask a
    //let1.to = "my friends";

    //for task c
    Vector<string> let1To;
    let1To.add("John");
    let1To.add("Sally");
    let1.to = let1To;


    eMailMsg let2;
    let2.date = 10;
    let2.from = "cocos";
    let2.message = "ok";
    let2.subject = "SPAM";
    let2.time = 2;
    //for subtask a
    //let2.to = "everyone";

    //for task c
    Vector<string> let2To;
    let2To.add("Mary");
    let2To.add("Lilu");
    let2.to = let2To;

    allMessages.add(let1);
    allMessages.add(let2);
    cout << "Before:\n" ;
    printTheLetters(allMessages);
    cout << "--------\n After:\n";
    RemoveSpan(allMessages);
    printTheLetters(allMessages);

    return 0;
}
