//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H


class Stack
{
private:
    int *num;
    int top;
public:
    Stack();
    ~Stack();
    int push(int n){
        if(isFull()){
            return 0;
        }
        ++top;
        num[top]=n;
        return n;
    }
    int pop(){
        int temp;
        if(isEmpty())
            return 0;
        temp=num[top];
        --top;
        return temp;
    }
    int isEmpty(){
        if(top==-1)
            return 1;
        else
            return 0;
    }
    int isFull(){
        if(top==(9999999))
            return 1;
        else
            return 0;
    }
    int peek(){
        if(isEmpty())
            return 0;
        return num[top];
    }
};


#endif //UNTITLED_STACK_H
