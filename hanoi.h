#include <iostream>
#define OUT
#include "stack.h"

using std::cout;
using std::endl;

class hanoi {
private:
    staticStack *left;
    staticStack *middle;
    staticStack *right;
    int amount;
    int another (int one, int two);
public:
    double operations = 0;
    hanoi (int amount);
    int moveFromTo (int f, int t);
    void moveFromToIt (int from, int to);
    void moveTopTwo (int from, int to);

    void solveRec (int from, int to, int am);

    void makeLegalMove (int from, int to);

    void solveIt ();

    void out();
};
