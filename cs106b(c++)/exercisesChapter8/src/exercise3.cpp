
#include "console.h"
#include "simpio.h"  // for getLine
#include "stack.h"
#include "exercise3.h"
using namespace std;

struct task {
    int numberOfDisk;
    char start;
    char finish;
    char tmp;
};

void exercise3() {
    task task1{1,'A','B','C'};
    task task2{2,'A','C','B'};
    task task3{1,'B','C','A'};
    task task4{3,'A','B','C'};
    task task5{1,'C','A','B'};
    task task6{2,'C','B','A'};
    task task7{1,'A','B','C'};
    Stack<task> tasks;
    tasks.push(task7);
    tasks.push(task6);
    tasks.push(task5);
    tasks.push(task4);
    tasks.push(task3);
    tasks.push(task2);
    tasks.push(task1);
    for (int i = 1 ; i <= 7; i++) {
        task curTask = tasks.pop();
        cout << "Disk " << curTask.numberOfDisk << " move from " << curTask.start << " to " << curTask.finish << endl;
    }
    //cout << task1.finish << endl;
    //task1.numberOfDisk = 1;

    //int n = getInteger("Input n:");
    //cout<< countHanoiMoves1(n) << endl;
}
