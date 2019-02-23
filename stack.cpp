#include <iostream>
#include "stack.h"

staticStack::staticStack (int maxSize){
    stackBody = new int [maxSize];
    p = NULL;
}

void staticStack::add(int v){
    if (!p){
        pointer *n_p = new pointer;
        *stackBody = v;
        n_p->next = stackBody;
        p = n_p;
    }
    else{
        p->next++;
        *(p->next) = v;
    }
}

void staticStack::pop (){
    if (!p){
        cout<<"THE STACK IS ALREADY EMPTY"<<endl;
    }
    else if (p->next == stackBody){
        p = NULL;
    }
    else{
        p->next--;
    }
}

int staticStack::peek()const{
    if (!p){
        return -1;
    }
    else{
        return *(p->next);
    }
}

void staticStack::out ()const{
    if (!p){
        cout<<"Stack is empty"<<endl;
    }
    else{
        int* temp = p->next;
        for (int* i = stackBody;i-1!=temp;i++){
            cout<<*i<<" ";
        }
        cout<<endl;
    }
}
