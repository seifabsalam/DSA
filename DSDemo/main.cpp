#include <iostream>
#include "include\LinkedList.h"
#include "include\Stack.h"
#include "include\Queue.h"
#include "include\Cirrcular_Queue.h"

using namespace std;

int main()
{
    LinkedList* List = new LinkedList;
    ///cout << "HII" << endl;
    List->AddSorted(5);
    List->AddSorted(6);
    List->AddSorted(4);
    List->AddSorted(1);
    List->AddSorted(11);
    List->Display();
    cout << endl;
    delete List;
}
