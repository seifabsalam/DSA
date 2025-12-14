#include <iostream>
#include "S:\seif\nagib\DSDemo\include\LinkedList.h"
#include "S:\seif\nagib\DSDemo\include\Stack.h"
#include "S:\seif\nagib\DSDemo\include\Queue.h"
#include "S:\seif\nagib\DSDemo\include\Cirrcular_Queue.h"

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
