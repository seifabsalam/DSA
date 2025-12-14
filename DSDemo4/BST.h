#ifndef BST_H
#define BST_H

#include "Node.h"
#include "Employee.h"

class BST {
private:
    Node* root;
    
    //-------------------------------------------
    // Helper: Get Balance Factor
    //-------------------------------------------
    int getBalanceFactor(Node* node) {
        if (node == NULL) return 0;
        return height(node->left) - height(node->right);
    }

    //-------------------------------------------
    // Helper: Right Rotate
    //-------------------------------------------
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        return x;
    }

    //-------------------------------------------
    // Helper: Left Rotate
    //-------------------------------------------
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        return y;
    }

    //-------------------------------------------
    // Helper: Left-Right Rotate
    //-------------------------------------------
    Node* leftRightRotate(Node* node) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //-------------------------------------------
    // Helper: Right-Left Rotate
    //-------------------------------------------
    Node* rightLeftRotate(Node* node) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    //-------------------------------------------
    // Helper: Recursive Insert
    //-------------------------------------------
    Node* insert(Node* node, Employee e) {
    if (node == NULL)
        return new Node(e);

    if (e.ID < node->data.ID)
        node->left = insert(node->left, e);
    else if (e.ID > node->data.ID)
        node->right = insert(node->right, e);
    else
        return node; // Duplicate keys not allowed

    // Get balance factor
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && e.ID < node->left->data.ID)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && e.ID > node->right->data.ID)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && e.ID > node->left->data.ID)
        return leftRightRotate(node);

    // Right Left Case
    if (balance < -1 && e.ID < node->right->data.ID)
        return rightLeftRotate(node);

    return node;
}

    //-------------------------------------------
    // Helper: Recursive Search
    //-------------------------------------------
    Node* search(Node* node, int id) {
        if (node == NULL || node->data.ID == id)
            return node;

        if (id < node->data.ID)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    //-------------------------------------------
    // Helper: Find Minimum Node (leftmost)
    //-------------------------------------------
    Node* getMinNode(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    //-------------------------------------------
    // Helper: Delete Node
    //-------------------------------------------
    Node* deleteNode(Node* node, int id) {
    if (node == NULL)
        return NULL;

    if (id < node->data.ID)
        node->left = deleteNode(node->left, id);
    else if (id > node->data.ID)
        node->right = deleteNode(node->right, id);
    else {
        if (node->left == NULL || node->right == NULL) {
            Node* temp = node->left ? node->left : node->right;
            if (temp == NULL)
                return NULL;
            else
                return temp;
        }

        Node* minNode = getMinNode(node->right);
        node->data = minNode->data;
        node->right = deleteNode(node->right, minNode->data.ID);
    }

    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && getBalanceFactor(node->left) >= 0)
        return rightRotate(node);

    // Left Right Case
    if (balance > 1 && getBalanceFactor(node->left) < 0)
        return leftRightRotate(node);

    // Right Right Case
    if (balance < -1 && getBalanceFactor(node->right) <= 0)
        return leftRotate(node);

    // Right Left Case
    if (balance < -1 && getBalanceFactor(node->right) > 0)
        return rightLeftRotate(node);

    return node;
    }

    //-------------------------------------------
    // DFS Traversals (Recursive)
    //-------------------------------------------
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data.ID << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data.ID << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data.ID << " ";
    }

    //-------------------------------------------
    // Height of tree = number of levels
    //-------------------------------------------
    int height(Node* node) {
        if (node == NULL) return 0;

        int L = height(node->left);
        int R = height(node->right);

        return max(L, R) + 1;
    }

public:
    // Constructor
    BST() : root(NULL) {}

    //-------------------------------------------
    // Public Insert
    //-------------------------------------------
    void Insert(Employee e) {
        root = insert(root, e);
    }

    //-------------------------------------------
    // Public Search
    //-------------------------------------------
    Employee* Search(int id) {
        Node* res = search(root, id);
        if (res == NULL) return NULL;
        return &(res->data);
    }

    //-------------------------------------------
    // Public Delete
    //-------------------------------------------
    void Delete(int id) {
        root = deleteNode(root, id);
    }

    //-------------------------------------------
    // Get Minimum Employee (smallest ID)
    //-------------------------------------------
    Employee GetMinimum() {
        Node* node = root;
        while (node && node->left != NULL)
            node = node->left;
        return node->data;
    }

    //-------------------------------------------
    // Get Maximum Employee (right-most node)
    //-------------------------------------------
    Employee GetMaximum() {
        Node* node = root;
        while (node && node->right != NULL)
            node = node->right;
        return node->data;
    }

    //-------------------------------------------
    // DFS Traversals
    //-------------------------------------------
    void DFS_InOrder() {
        inorder(root);
        cout << endl;
    }

    void DFS_PreOrder() {
        preorder(root);
        cout << endl;
    }

    void DFS_PostOrder() {
        postorder(root);
        cout << endl;
    }

    //-------------------------------------------
    // Number of Levels
    //-------------------------------------------
    int levelsNumber() {
        return height(root);
    }
};
#endif // BST_H
