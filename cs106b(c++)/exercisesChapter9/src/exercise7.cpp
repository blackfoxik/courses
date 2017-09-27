
#include "console.h"
#include "simpio.h"  // for getLine
#include "lexicon.h"
#include "vector.h"
#include "exercise7.h"
#include <foreach.h>
#include <map.h>;
#include "set.h"
using namespace std;

//func prototypes
Vector< Map<string,char> > initCubes();
void printCubeSides(Vector< Map<string,char> > cubes);
int getCountOFDifferentSides(Vector< Map<string,char> > cubes, string side);
bool sidesDifferent(Vector< Map<string,char> > cubes);
void turnByVertAxe(Map<string,char> & cube);
void turnByVertAxe(Map<string,char> & cube, int countOfTurns);
void turnByHorizontalAxe(Map<string,char> & cube);
void turnByHorizontalAxe(Map<string,char> & cube, int countOfTurns);
bool solveInstantInsanity(Vector< Map<string,char> > & cubes, int index);
void solveInstantInsanity(Vector< Map<string,char> > & cubes);

//general
void exercise7() {
    Vector< Map<string,char> > cubes = initCubes();
    printCubeSides(cubes);
    cout << "solution is: " << endl;
    solveInstantInsanity(cubes);
    return;
}

void solveInstantInsanity(Vector< Map<string,char> > & cubes) {
    solveInstantInsanity(cubes, 0);
}

bool solveInstantInsanity(Vector< Map<string,char> > & cubes, int index) {
    if (sidesDifferent(cubes)) {
        printCubeSides(cubes);
        return true;
    }
    if (index > 3) {
        return false;
    }

    Vector< Map<string,char> > previousCubes = cubes;

    previousCubes = cubes;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
                previousCubes = cubes;
                turnByHorizontalAxe(previousCubes[index], i);
                turnByVertAxe(previousCubes[index], j);
                if (solveInstantInsanity(previousCubes, index + 1)) return true;

        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
                previousCubes = cubes;
                turnByVertAxe(previousCubes[index], i);
                turnByHorizontalAxe(previousCubes[index], j);
                if (solveInstantInsanity(previousCubes, index + 1)) return true;
        }
    }

    if (solveInstantInsanity(cubes, index + 1)) return true;


    return false;
}


void turnByHorizontalAxe(Map<string,char> & cube) {
    char tmp;
    tmp = cube.get("front");
    cube.put("front", cube.get("bottom"));
    cube.put("bottom", cube.get("top"));
    cube.put("top", tmp);

    tmp = cube.get("back");
    cube.put("back", cube.get("bottom"));
    cube.put("bottom", tmp);
}

void turnByHorizontalAxe(Map<string,char> & cube, int countOfTurns) {
    if (countOfTurns == 0) {
        return;
    } else {
        for (int i = 0; i < countOfTurns; i++) {
           turnByHorizontalAxe(cube);
        }
    }
}

void turnByVertAxe(Map<string,char> & cube) {
    char tmp;
    tmp = cube.get("left");
    cube.put("left", cube.get("front"));
    cube.put("front", cube.get("back"));
    cube.put("back", tmp);
    tmp = cube.get("right");
    cube.put("right", cube.get("front"));
    cube.put("front", tmp);
}

void turnByVertAxe(Map<string,char> & cube, int countOfTurns) {
    if (countOfTurns == 0) {
        return;
    } else {
        for (int i = 0; i < countOfTurns; i++) {
           turnByVertAxe(cube);
        }
    }
}

bool sidesDifferent(Vector< Map<string,char> > cubes) {
    int countDiffFrontSides = getCountOFDifferentSides (cubes, "front");
    int countDiffBackSides = getCountOFDifferentSides (cubes, "back");
    int countDiffTopSides = getCountOFDifferentSides (cubes, "top");
    int countDiffBottomSides = getCountOFDifferentSides (cubes, "bottom");
    int sum = countDiffFrontSides +
              countDiffBackSides +
              countDiffTopSides +
              countDiffBottomSides;
    if( sum < 16) {
        return false;
    } else {
        return true;
    }
}

int getCountOFDifferentSides(Vector< Map<string,char> > cubes, string side) {
    Set<char> diffSides;
    for (int i = 0; i < 4; i++) {
        diffSides.add(cubes[i].get(side));
    }
    return diffSides.size();
}

void printCubeSides(Vector< Map<string,char> > cubes) {

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0) {
                //print front
                if (j == 0) {
                  cout << "front: ";
                }
                cout << cubes[j].get("front");

            } else if (i == 1) {
                //print right
                if (j == 0) {
                  //cout << "right: ";
                }
                //cout << cubes[j].get("right");

            } else if (i == 2) {
                //print back
                if (j == 0) {
                  cout << "back:  ";
                }
                cout << cubes[j].get("back");
            } else if (i == 3){
                //print left
                if (j == 0) {
                  //cout << "left: ";
                }
                //cout << cubes[j].get("left");
            } else if (i == 4){
                //print top
                if (j == 0) {
                  cout << "top:   ";
                }
                cout << cubes[j].get("top");
            } else {
                //print bottom
                if (j == 0) {
                  cout << "btm:   ";
                }
                cout << cubes[j].get("bottom");
        }

    }
       if(i == 0 || i == 2 || i == 4 || i == 5) cout << endl;
    }
    cout << endl;
}

Vector< Map<string,char> > initCubes() {

   Map<string,char> cube0;
   cube0.add("front",'W');
   cube0.add("right",'B');
   cube0.add("back",'B');
   cube0.add("left",'R');
   cube0.add("top",'G');
   cube0.add("bottom",'G');

   Map<string,char> cube1;
   cube1.add("front",'W');
   cube1.add("right",'W');
   cube1.add("back",'G');
   cube1.add("left",'B');
   cube1.add("top",'R');
   cube1.add("bottom",'G');

   Map<string,char> cube2;
   cube2.add("front",'R');
   cube2.add("right",'R');
   cube2.add("back",'W');
   cube2.add("left",'B');
   cube2.add("top",'W');
   cube2.add("bottom",'G');

   Map<string,char> cube3;
   cube3.add("front",'G');
   cube3.add("right",'R');
   cube3.add("back",'R');
   cube3.add("left",'R');
   cube3.add("top",'B');
   cube3.add("bottom",'W');

   Vector< Map<string,char> > cubes;
   cubes.add(cube0);
   cubes.add(cube1);
   cubes.add(cube2);
   cubes.add(cube3);

   return cubes;

}



