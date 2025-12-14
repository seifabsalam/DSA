#ifndef CQUEUE_H
#define CQUEUE_H

#include <iostream>

using namespace std;

class CQ
{
public:
    CQ(int val)
    {
        queueSize = val;
        arr = new int[queueSize];
        head = tail = cnt = 0;
        cout << "CQ Constructed" << endl;
    }

    ~CQ()
    {
        delete[] arr;
        cout << "CQ Destructed" << endl;
    }

    bool Enqueue(int val)
    {
        //O(1)
        if(IsFull())
            return false;
        arr[tail] = val;
        tail = (tail+1) % queueSize;
        cnt++;
        return true;

    }

    bool Dequeue(int &val)
    {
        //O(1)
        if(IsEmpty())
            return false;
        val = arr[head];
        head = (head+1) % queueSize;
        cnt--;
        return true;

    }

    bool IsEmpty()
    {
        return (cnt == 0);
    }
    bool IsFull()
    {
        return (cnt == queueSize);
    }
    int Size()
    {
        return cnt;
    }
private:
    int queueSize;
    int head, tail,cnt;
    int *arr;

};

#endif // CQUEUE_H
