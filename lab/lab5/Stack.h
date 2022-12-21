#include <iostream>
#include <cstdlib>

#define SIZE 10

class Stack
{
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size = SIZE);         // �����������
    ~Stack();                       // ����������

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
};