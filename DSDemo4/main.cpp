#include <iostream>

using namespace std;

#include ".\BST.h"
#include "AVL.h"

int main() {

    // Binary Search Tree
    BST tree;

    tree.Insert(Employee(20, "Ali", 30));
    tree.Insert(Employee(10, "Sara", 25));
    tree.Insert(Employee(30, "Omar", 28));
    tree.Insert(Employee(25, "Mona", 22));

    cout << "InOrder Traversal: ";
    tree.DFS_InOrder();

    cout << "Levels = " << tree.levelsNumber() << endl;

    Employee maxEmp = tree.GetMaximum();
    cout << "Max ID = " << maxEmp.ID << endl;

    Employee minEmp = tree.GetMinimum();
    cout << "Min ID = " << minEmp.ID << endl;

    tree.Delete(10);

    cout << "After deleting 10: ";
    tree.DFS_InOrder();
    cout << "===============================================" ;

    // AVL

    AVL avl_tree;

    avl_tree.Insert(Employee(101, "Seif", 30));
    avl_tree.Insert(Employee(50, "Ashraf", 25));
    avl_tree.Insert(Employee(150, "Ali", 40));
    avl_tree.Insert(Employee(75, "Mona", 28));
    avl_tree.Insert(Employee(120, "Ziad", 35));

    cout << "\n";
    avl_tree.InorderTraversal();

    return 0;
}
