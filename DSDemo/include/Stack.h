#ifndef STACK_H
#define STACK_H

#include "S:\seif\nagib\DSDemo\include\Node.h"
#include <iostream>

using namespace std ;

class Stack
{
public:
    int cnt;
    Node* top ;

    Stack()
    {
        cnt = 0;
        top = NULL;
        cout << "Stack Constructed" << endl;
    }

    ~Stack()
    {
        int dumb;
        while (Pop(dumb));
        cout << "Stack Destructed" << endl;
    }


    void Push(int val)
    {
        Node* node = new Node(val);
        node-> next = top;
        top = node;
        cnt++;
    }

    bool Pop(int &val)
    {
        if (isEmpty())
            return false;
        Node* temp = top;
        top = top->next;
        val = temp->data;
        delete temp;
        cnt--;
        return true;
    }

    bool Peek(int &val)
    {
        if (isEmpty())
            return false;
        val = top->data;
        return true;
    }

    int Size()
    {
        return cnt;
    }

    Stack* NXTgreater()
    {
        Node* current = top;
        int* arr = new int[cnt];
        Stack* ans = new Stack();
        for(int i = 0 ; i < cnt ; i++)
        {
            arr[i] = current->data;
            current = current->next;
            cout << arr[i] << endl;
        }
        int greater;
        for (int i = cnt-1 ; i >= 0; i--)
        {
            greater = -1;
            for (int j = i-1 ; j >= 0; j--)
            {
                if (arr[j] > arr[i])
                {
                    greater = arr[j];
                    break;
                }
            }
            ans->Push(greater);
        }
        delete[] arr;
        return ans;
        
    }

private:
    bool isEmpty()
    {
        return top == NULL;
    }

};


#endif // STACK_H
