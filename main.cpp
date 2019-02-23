#include <iostream>
#include "hanoi.h"

using namespace std;


int main()
{
    cout<<"HOW WOULD YOU LIKE TO SOLVE IT? REC - 0, IT - 1"<<endl;
    bool var;
    cin>>var;
    cout<<"How big is your tower?"<<endl;
    int height;
    cin>>height;
    cout<<endl;

    hanoi tower (height);

    (var) ? (tower.solveIt()) : (tower.solveRec(1,3,height));

    tower.out();
    cout<<tower.operations;
    return 0;
}
