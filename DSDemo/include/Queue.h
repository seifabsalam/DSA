#ifndef QUEUE_H
#define QUEUE_H

#include "include\Node.h"

class Q
{
    Node* front;
    Node* rear;
    int cnt;

    bool isEmpty()
    {
        return (front == NULL) && (rear == NULL);
    }

    // CROSS ARROWS

    void cross_arrows(Node& node)
    {
        Node* temp = node.next;
        node.next = node.prev;
        node.prev = temp;
    }

public:
    Q()
    {
        front = NULL;
        rear = NULL;
        cnt = 0;
        cout << "Q Constructed!!" << endl;
    }

    ~Q()
    {
        int dumb;
        while(Dequeue(dumb));
        cout << "Q Destructed" << endl;
    }

    void Enqueue(int val)
    {
        Node* node = new Node(val);

        if(isEmpty())
        {
            front = rear = node;
        }
        else
        {
            rear->next = node;
            node->prev = rear;
            rear = node;
        }
        cnt ++;
    }

    bool Dequeue(int &val)
    {
        if(isEmpty())
            return false;
        val = front->data;
        Node* temp = front;
        front = front->next;
        if(front != NULL)
            front->prev = NULL;
        else
            rear = NULL;
        delete temp;
        cnt --;
        return true;
    }


    int Size()
    {
        return cnt;
    }

    void reverse()
    {
        Node* current = front;
        for (int i = 0; i < cnt; i++)
        {
            cross_arrows(*current);
            current = current->prev;
        }
        Node* temp = front;
        front = rear;
        rear = temp;
    }

};


#endif // QUEUE_H
