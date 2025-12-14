#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "S:\seif\nagib\DSDemo\include\Node.h"
#include <iostream>

using namespace std;

class LinkedList
{
    public:

        LinkedList()
        {
            head = tail = NULL;
        }

        ~LinkedList()
        {
            delete head;
            delete tail;
        }

        void AddSorted(int val)
    {
        if (head == NULL)
        {
            add(val);
            return;
        }
        if (val <= head->data)
        {
            Node* newNode = new Node(val);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            cnt++;
            return;
        }
        Node* current = head;
        while (current->next != NULL && current->next->data < val)
        {
            current = current->next;
        }
        if (current->next == NULL)
        {
            add(val);
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        cnt++;
    }

        // for testing
        void Display()  // O(n)
        {

            Node * current = head;
            // Loop
            while(current!= NULL)
            {
                // print data
                cout<<current->data<<"\t";

                //move next
                current = current->next;

            }
        }

        bool Search(int data)
        {
            // getNode(Data)
            if(getNode(data)!=NULL)
                return true;
            else return false;
        }


        bool Delete(int data)
        {
            // search
            Node * node = getNode(data);
            if(node!=NULL)
            {
                // delete
                //one element
                if(head == node && tail == node)
                {
                    head = tail = NULL;
                }

                // head
                else if(node == head)
                {
                    head = node->next;
                    head->prev = NULL;
                }

                // tail
                else if(node == tail)
                {
                    tail = node->prev;
                    tail->next = NULL;
                }

                // inbetween
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }

                delete node;
                cnt  --;
                return true;

            }
            else return false;
        }

        // DELETE TAIL
        bool Delete_tail()
        {
            Node * node = tail;
            if(node != NULL)
            {
                if (tail != NULL)
                    tail->next = NULL;
                else
                    head = NULL;
                delete node;
                cnt --;
                return true;
            }
            return false;
        }

        // DELETE HEAD
        bool Delete_head()
        {
            Node * node = head;
            if(node != NULL)
            {
                if (tail != NULL)
                    tail->next = NULL;
                else
                    head = NULL;
                delete node;
                cnt --;
                return true;
            }
            return false;
        }



        // 3. int count()

        int count()
        {
            return cnt;
        }

        // 4. getDataByIndex(int index)

        int getDataByIndex(int index)
        {
            if(index > cnt)
                return -1;
            Node* current = head;
            for(int i = 0; i < index-1; i++)
                current = current->next;
            return current->data;
        }


        // 5. void reverse() – in place

        void reverse()
        {
            Node* current = head;
            for (int i = 0; i < cnt; i++)
            {
                cross_arrows(*current);
                current = current->prev;
            }
            Node* temp = head;
            head = tail;
            tail = temp;
        }

        // 6. *LinkedList reverse()

        LinkedList* reverse_with_return()
        {
            LinkedList* cp = this ;
            cp->reverse();
            return cp;
        }


        // GET TAIL

        bool get_tail(int &val)
        {
            if(tail != NULL)
            {
                val = tail->data;
                return true;
            }
            else
                return false;
        }

        // GET HEAD

        bool get_head(int &val)
        {
            if(head != NULL)
            {
                val = head->data;
                return true;
            }
            else
                return false;
        }


    private:
        Node* head;
        Node* tail;
        int     cnt;

    Node* getNode(int data)
    {
        Node * current = head;
        while(current != NULL)
        {
            // found
            if(data == current->data)
                return current;
            //move next
            current = current->next;
        }
        return NULL;
    }

    // CROSS ARROWS

    void cross_arrows(Node& node)
    {
        Node* temp = node.next;
        node.next = node.prev;
        node.prev = temp;
    }

    void add(int data)  // O(1)
        {
            // insert new node
            Node * node = new Node(data);

            // List if it was empty
            if(head == NULL)
            {
                head = tail = node;
            }
            else
            {
                // connect it
                node->prev = tail;
                tail->next = node;
                tail = node;
            }
            cnt ++;

        }

        // 1. insertAfter (data, afterData)

        bool insertAfter (int data, int afterData)
        {
            Node* current = getNode(data);
            Node* newNode = new Node(afterData);
            if (current == NULL)
                return false;
            else
            {
                newNode->next = current->next;
                current->next->prev = newNode;
                current->next = newNode;
                newNode->prev = current;
                if (tail == current)
                    tail = newNode;
                cnt ++;
                return true;
            }
        }

        // 2. insertBefore (data, berforeData)

        bool insertBefore (int data, int beforeData)
        {
            Node* current = getNode(data);
            Node* newNode = new Node(beforeData);
            if (current == NULL)
                return false;
            else
            {
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
                newNode->next = current;
                if (head == current)
                    head = newNode;
                cnt ++;
                return true;
            }
        }
};

#endif // LINKEDLIST_H
