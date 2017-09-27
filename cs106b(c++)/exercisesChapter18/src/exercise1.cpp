#include "exercise1.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "tokenscanner.h"
#include "vector.h"
#include <fstream>
#include "simplegraph.h"
#include "stack.h"
#include "queue.h"
#include "pqueue.h"


//using namespace std;
//func prototypes

//for exercise 1
void readGraph(SimpleGraph & g, istream & infile);
void clearName(std::string &name);
void parseString(std::string & curLine, std::string &startName, std::string &finishName, int &cost, bool &bothDirections);
void fillGraph (SimpleGraph & g, std::string &startName, std::string &finishName, int &cost, bool &bothDirections);
//for exercise 2
void writeGraph(SimpleGraph & g, ostream & outfile);
//for exercise 3
void depthFirstSearch(Node *node);
void visitUsingDFS(Node *node, Set<Node *> & visited);
void depthFirstSearchStack(Node *node);
void visitUsingDFSStack(Node *node, Set<Node *> & visited, Stack< Node *> & stackForNodes);
//for exercise 4
void breadthFirstSearchQueue(Node *node);
void visitUsingBFSQueue(Node *node, Set<Node *> & visited, Queue< Node *> & stackForNodes);
//for exercise 5 we need to understand how to use pointers to func
int sumFunc(int a, int b) { return a + b;}
int minusFunc(int a, int b) { return a - b;}
int calc(int a, int b, int(*pointterToFunc)(int a, int b)) {
    return pointterToFunc(a, b);
}
//for exercise6 task was implemented in exercise 4 (we already check node if it in visited set)
//for exercise7
bool pathExists(Node *n1, Node *n2);
//for exercise8
int hopCount(Node *n1, Node *n2);
//for exercise11 Dijkstra’s algorithm
Vector<Arc *> findShortestPath(SimpleGraph & g, Node *start, Node *finish);
double getPathCost(const Vector<Arc *> &path);
void printPath(Vector<Arc *> path);
//for exercise12
bool isBipartite(SimpleGraph & g);
//for exercise13
SimpleGraph* findMinimumSpanningTree(SimpleGraph &sg);
void printArcs(SimpleGraph &sg);
//for exercise14
Set<Node *> findDominatingSet(SimpleGraph &g);
void printSet(Set<Node *> &set);

void exercise1() {
    SimpleGraph g;
    string filename = "airlinegraph.txt";
    ifstream infile;
    infile.open(filename);
    readGraph(g, infile);
    //for exercise2
    std::filebuf fb;
    fb.open ("test.txt",std::ios::out);
    std::ostream os(&fb);
    writeGraph(g,os);
    fb.close();
    //for exercise3
    //depthFirstSearch(g.nodeMap["Atlanta"]);
    depthFirstSearchStack(g.nodeMap["Atlanta"]);
    std::cout << std::endl;
    //for exercise4
    breadthFirstSearchQueue(g.nodeMap["Atlanta"]);
    //for exercise5
    std::cout << calc(5,5,&sumFunc) << std::endl;
    std::cout << calc(5,5,&minusFunc) << std::endl;
    //for exercise7
    std::cout << "path exist: "<< pathExists(g.nodeMap["Atlanta"],g.nodeMap["Seattle"]) << std::endl;
    //for exercise8
    std::cout << "Count of hop: "<< hopCount(g.nodeMap["Atlanta"],g.nodeMap["Seattle"]) << std::endl;
    //for exercise11 Dijkstra’s algorithm
    Vector<Arc *> path = findShortestPath(g, g.nodeMap["Atlanta"], g.nodeMap["Seattle"]);
    printPath(path);
    std::cout << "Is Bipartite: "<< isBipartite(g) << std::endl;
    //for exercise13
    SimpleGraph sg;
    filename = "spanningtree.txt";
    infile.clear();
    infile.close();
    infile.open(filename);
    readGraph(sg, infile);
    SimpleGraph *spanningTree = findMinimumSpanningTree(sg);
    printArcs(*spanningTree);
    std::cout << "Is Bipartite: "<< isBipartite(sg) << std::endl;
    //for exercise14
    Set<Node *> dominatingSet = findDominatingSet(sg);
    std::cout << "Nodes in dominating set: "<< std::endl;
    printSet(dominatingSet);
}

Set<Node *> findDominatingSet(SimpleGraph &g) {

    PriorityQueue<Node *> nodesInPQ;
    for ( auto it = g.nodes.begin(); it != g.nodes.end(); it++ ) {
        Node *curNode = *it;
        nodesInPQ.enqueue(curNode, curNode->arcs.size());
    }

    Stack<Node *> stcNodes;
    while (!nodesInPQ.isEmpty()) {
        stcNodes.add(nodesInPQ.dequeue());
    }

    Set<Node *> result;
    while (!stcNodes.isEmpty()) {
        Node *curNode = stcNodes.pop();
        Set<Node *> curSet;
        curSet.add(curNode);
        for (auto it = curNode->arcs.begin(); it != curNode->arcs.end(); it++) {
            Arc *curArc = *it;
            curSet.add(curArc->finish);
        }
        Set<Node *> nodesAndNeighboursInResult;
        for (auto it = result.begin(); it != result.end(); it ++) {
            Node *curNodeInSet = *it;
            nodesAndNeighboursInResult.add(curNodeInSet);
            for (auto innerIt = curNodeInSet->arcs.begin(); innerIt != curNodeInSet->arcs.end(); innerIt++) {
                Arc *curArc = *innerIt;
                nodesAndNeighboursInResult.add(curArc->finish);
            }
        }
        Set<Node *> dif = curSet - nodesAndNeighboursInResult;
        if (dif.size() > 0) result.add(curNode);
    }
    return result;
}

void printSet(Set<Node *> &set) {
    for ( auto it = set.begin(); it != set.end(); it++ ) {
        Node *curNode = *it;
        cout << curNode->name << endl;
    }
}

void printArcs(SimpleGraph &sg) {
    cout << "arcs:" << endl;
    for ( auto it = sg.arcs.begin(); it != sg.arcs.end(); it++ ) {
        Arc *curArc = *it;
        cout << curArc->start->name << " " << curArc->finish->name << " cost: " << curArc->cost << endl;
    }
}

SimpleGraph* findMinimumSpanningTree(SimpleGraph &sg) {
    SimpleGraph *result = new SimpleGraph;
    //copy all nodes
    for ( auto it = sg.nodes.begin(); it != sg.nodes.end(); it++ ) {
        Node *curNode = *it;
        Node *newNode = new Node;
        newNode ->name = curNode->name;
        //curNode->arcs.clear();
        result->nodes.add(newNode);
        result->nodeMap.add(newNode->name, newNode);
    }
    //get arcs by sorted by cost
    PriorityQueue< Arc *> arcs;
    for ( auto it = sg.arcs.begin(); it != sg.arcs.end(); it++ ) {
        Arc *curArc = *it;
        arcs.add(curArc,curArc->cost);
    }
    while (!arcs.isEmpty()) {
        Arc *cur = arcs.dequeue();
        Node *start = result->nodeMap.get(cur->start->name);
        Node *finish = result->nodeMap.get(cur->finish->name);

        if (pathExists(start,finish)) {
          cout << start->name << " " << finish->name << " cost: " << cur->cost << " (not needed)"<< endl;
        } else {
            Arc *newArc = new Arc;
            newArc->cost = cur->cost;
            //startToFin
            newArc->start = start;
            newArc->finish = finish;
            //finToStart
            Arc *newArcFTS = new Arc;
            newArcFTS->cost= cur->cost;
            newArcFTS->start = finish;
            newArcFTS->finish = start;

            start->arcs.add(newArc);
            finish->arcs.add(newArcFTS);
            result->arcs.add(newArc);
            result->arcs.add(newArcFTS);
            cout << cur->start->name << " " << cur->finish->name << " cost: " << cur->cost << endl;
        }
    }
    return result;
}

bool isBipartite(SimpleGraph & g) {
    Node *first = g.nodes.first();

    for ( auto it = g.nodes.begin(); it != g.nodes.end(); it++ ) {
        Node *curNode = *it;
        if (first != curNode) {
            if (!pathExists(first, curNode)) {
               if (!pathExists(curNode, first)) return true;
          }
        }
    }
    return false;
}

Vector<Arc *> findShortestPath(SimpleGraph & g, Node *start, Node *finish) {
    Vector<Arc *> path;
    PriorityQueue< Vector<Arc *> > queue;
    Map<string, double> fixed;
    while (start != finish) {
        if (!fixed.containsKey(start->name)) {
            fixed.put(start->name, getPathCost(path));
            for (Arc *arc : start->arcs) {
                if (!fixed.containsKey(arc->finish->name)) {
                    path.add(arc);
                    queue.enqueue(path, getPathCost(path));
                    path.remove(path.size() - 1);
                }
            }
        }
        if (queue.isEmpty()) {
            path.clear();
            return path;
        }
        path = queue.dequeue();
        start = path[path.size() - 1]->finish;
    }
    return path;
}

double getPathCost(const Vector<Arc *> &path) {
   double cost = 0;
   for (Arc *arc : path) {
       cost += arc->cost;
   }
   return cost;
}

void printPath(Vector<Arc *> path) {
    for (Arc *arc : path) {
        std::cout << arc->start->name<< "->";
    }
    std::cout << path.get(path.size() - 1)->finish->name;
    std::cout << std::endl;
}

int hopCount(Node *n1, Node *n2) {

    if (n1 == n2) return 0;
    Map<string, Vector< Node*> > paths;
    Vector<Node *> newPath;
    newPath.add(n1);
    paths.add(n1->name ,newPath);

    Set<Node *> visited;
    Queue<Node *> queueForNodes;
    queueForNodes.enqueue(n1);
    while (!queueForNodes.isEmpty()) {
        Node *curNode = queueForNodes.dequeue();

        if (!visited.contains(curNode)) {
            visited.add(curNode);
            //std::cout << "was visited: " << curNode->name << endl;
            newPath = paths.get(curNode->name);
        }
        for (Arc *arc : curNode->arcs) {
            if (!visited.contains(arc->finish)) {
                queueForNodes.enqueue(arc->finish);
                Vector<Node *> neighbourNodes = newPath;
                 neighbourNodes.add(arc->finish);
                 if (paths.containsKey(arc->finish->name)) {
                     if (paths.get(arc->finish->name).size() > newPath.size()) {
                         paths.add(arc->finish->name, neighbourNodes);
                     }
                 } else {
                    paths.add(arc->finish->name, neighbourNodes);
                 }

            }
        }
    }
    return (visited.contains(n2)) ? paths.get(n2->name).size() : -1;
}

bool pathExists( Node *n1, Node *n2) {
    Set<Node *> visited;
    Queue<Node *> queueForNodes;
    queueForNodes.enqueue(n1);
    visitUsingBFSQueue(n1, visited, queueForNodes);
    return visited.contains(n2);
}

void visitUsingBFSQueue(Node *node, Set<Node *> & visited, Queue< Node *> & queueForNodes) {
    while (!queueForNodes.isEmpty()) {
        Node *curNode = queueForNodes.dequeue();
        if (!visited.contains(curNode)) {
            visited.add(curNode);
            //std::cout << "was visited: " << curNode->name << endl;
        }
        for (Arc *arc : curNode->arcs) {
            if (!visited.contains(arc->finish)) {
                queueForNodes.enqueue(arc->finish);
            }
        }
    }
}

void breadthFirstSearchQueue(Node *node) {
    Set<Node *> visited;
    Queue<Node *> queueForNodes;
    queueForNodes.enqueue(node);
    visitUsingBFSQueue(node, visited, queueForNodes);
}

void visitUsingDFSStack(Node *node, Set<Node *> & visited, Stack< Node *> & stackForNodes) {
    while (!stackForNodes.isEmpty()) {
        Node *curNode = stackForNodes.pop();
        if (!visited.contains(curNode)) {
            visited.add(curNode);
            std::cout << "was visited: " << curNode->name << endl;
        }
        for (Arc *arc : curNode->arcs) {
            if (!visited.contains(arc->finish)) {
                stackForNodes.push(arc->finish);
            }
        }
    }
}

void depthFirstSearchStack(Node *node) {
    Set<Node *> visited;
    Stack<Node *> stackForNodes;
    stackForNodes.push(node);
    visitUsingDFSStack(node, visited, stackForNodes);
}

void visitUsingDFS(Node *node, Set<Node *> & visited) {
    if (visited.contains(node)) return;
    visited.add(node);
    std::cout << "was visited: " << node->name << endl;
    for (Arc *arc : node->arcs) {
        visitUsingDFS(arc->finish, visited);
    }
}

void depthFirstSearch(Node *node) {
    Set<Node *> visited;
    visitUsingDFS(node, visited);
}

void writeGraph(SimpleGraph & g, ostream & outfile) {
    Set<string> printedNodeNames;
    for ( auto it = g.arcs.begin(); it != g.arcs.end(); it++ ) {
        Arc *curArc = *it;
        string start = curArc->start->name;
        string finish = curArc->finish->name;
        int cost = curArc->cost;
        outfile << start + "->" + finish + " (" + integerToString(cost) + ")" + "\n";
        printedNodeNames.add(start);
    }
    for ( auto it = g.nodes.begin(); it != g.nodes.end(); it++ ) {
        Node *curNode = *it;
        if (!printedNodeNames.contains(curNode->name)) {
            outfile << curNode->name + "\n";
        }
    }

}

void readGraph(SimpleGraph & g, istream & infile) {
    TokenScanner ts;
    ts.setInput(infile);
    ts.ignoreWhitespace();
    ts.addWordCharacters(" ");
    ts.addWordCharacters("-");
    ts.addWordCharacters("(");
    ts.addWordCharacters(")");

    while (ts.hasMoreTokens()) {
        string curLine = ts.nextToken();
        string startName = "";
        string finishName = "";
        int cost = 0;
        bool bothDirections = true;
        parseString(curLine, startName, finishName, cost, bothDirections);
        std::cout << curLine << std::endl;
        fillGraph(g, startName, finishName, cost, bothDirections);
    }

}

void clearName(std::string &name) {
    while (name[0] == ' ') {
        name = name.substr(1);
    }
    while (name[name.size() - 1] == ' ') {
        name = name.substr(0, name.size() - 1);
    }
}

void parseString(std::string & curLine, std::string &startName, std::string &finishName, int &cost, bool &bothDirections) {
    int posDash = curLine.find("-");
    if ( posDash == -1) {
        startName = curLine;
        return;
    }
    startName = curLine.substr(0, posDash - 1);
    if (curLine[posDash + 1] == '>') {
        bothDirections = false;
        posDash++;
    }
    int posOpenBracket = curLine.find("(");
    int posCloseBracket = curLine.find(")");
    if (posOpenBracket == -1) {
        finishName = curLine.substr(posDash);
    } else {
        finishName = curLine.substr(posDash + 1, posOpenBracket - posDash - 1);
        string costStr = curLine.substr(posOpenBracket + 1, posCloseBracket - posOpenBracket - 1);
        cost = stringToInteger(costStr);
    }
    clearName(startName);
    clearName(finishName);
}

void fillGraph (SimpleGraph & g, std::string &startName, std::string &finishName, int &cost, bool &bothDirections) {
    Node *start = NULL;

    if(!g.nodeMap.containsKey(startName)) {
        start = new Node;
        start->name = startName;
        g.nodes.add(start);
        g.nodeMap.add(startName, start);
    } else {
        start = g.nodeMap.get(startName);
    }

    if (finishName == "") return;
    Node *finish = NULL;
    if(!g.nodeMap.containsKey(finishName)) {
        finish = new Node;
        finish->name = finishName;
        g.nodes.add(finish);
        g.nodeMap.add(finishName, finish);
    } else {
        finish = g.nodeMap.get(finishName);
    }

    Arc *startFinish = new Arc;
    startFinish->cost = cost;
    startFinish->start = start;
    startFinish->finish = finish;
    start->arcs.add(startFinish);
    g.arcs.add(startFinish);

    if(bothDirections) {
        Arc *finishStart = new Arc;
        finishStart->cost = cost;
        finishStart->start = finish;
        finishStart->finish = start;
        finish->arcs.add(finishStart);
        g.arcs.add(finishStart);
    }

}
