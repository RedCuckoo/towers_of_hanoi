#include "hanoi.h"


hanoi::hanoi (int amount){
    left = new staticStack (amount);
    middle = new staticStack (amount);
    right = new staticStack (amount);
    this->amount = amount;

    for (int i=amount;i>=1;i--){
        left->add(i);
    }
}

int hanoi::another (int one, int two){
    switch (one + two){
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 1;
        default:
            return -1;
    }
}

int hanoi::moveFromTo (int f, int t){
    if (f == t){
        return 0;
    }
    else{
        operations++;
        staticStack *from = (f == 1) ? (left) : ((f == 2) ? (middle) : right);
        staticStack *to = (t == 1) ? (left) : ((t == 2) ? (middle) : right);
        to->add(from->peek());
        from->pop();
        return t;
    }
    #ifdef OUT
        out();
    #endif // OUT
}

void hanoi::moveTopTwo (int from, int to){
    int other = another(from, to);
    moveFromTo(from,other);
    moveFromTo(from, to);
    moveFromTo(other, to);
}

void hanoi::solveRec (int from, int to, int am){
    int other = another(from, to);
    if (am>amount){
        cout<<"YOU DONT HAVE ENOUGH DISKS TO DO THIS\n";
        return;
    }

    if (am == 0){
        cout<<"YOU TRIED TO MOVE 0 DISKS\n";
        return;
    }

    if (am == 1){
        moveFromTo(from, to);
    }
    else{
        solveRec (from, other,am-1);
        solveRec (from, to, 1);
        solveRec (other,to,am-1);
    }
}

void hanoi::makeLegalMove(int f, int t){
    staticStack *from= (f == 1) ? (left) : ((f == 2) ? (middle) : right);
    staticStack *to = (t == 1) ? (left) : ((t == 2) ? (middle) : right);

    int ftop = from->peek();
    int ttop = to->peek();

    if (ftop == ttop){
        return;
    }

    if ((ftop > ttop || ftop == -1) && ttop != -1){
        to->pop();
        from->add(ttop);
    }
    else{
        from->pop();
        to->add (ftop);
    }

    #ifdef OUT
        out();
    #endif // OUT

    return;
}

void hanoi::solveIt(){
    int i=1;
    int temp;
    while (!(left->peek() == -1 && middle->peek() == -1)){
        temp = i%3;
        if (temp == 1) {
            makeLegalMove(1,3);
        }
        else if (temp == 2){
            makeLegalMove(1,2);
        }
        else{
            makeLegalMove(2,3);
        }
        i++;
    }
}


void hanoi::out(){
    cout<<"left: ";
    left->out();
    cout<<"middle: ";
    middle->out();
    cout<<"right: ";
    right->out();
    cout<<endl;
}

