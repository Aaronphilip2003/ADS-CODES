#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Dictionary {
public:
    struct Node {
        string keyword;
        string meaning;
        Node* left;
        Node* right;
        int height;
        Node(string keyword, string meaning) : keyword(keyword), meaning(meaning), left(NULL), right(NULL), height(1) {}
    };

    Node* root;

    Dictionary() {
        root = NULL;
    }

    int height(Node* node) {
        if (node == NULL)
            return 0;
        else
            return node->height;
    }

    int getBalance(Node* node) {
        if (node == NULL)
            return 0;
        else
            return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insert(Node* node, string keyword, string meaning) {
        if (node == NULL)
            return new Node(keyword, meaning);

        if (keyword < node->keyword)
            node->left = insert(node->left, keyword, meaning);
        else if (keyword > node->keyword)
            node->right = insert(node->right, keyword, meaning);
        else {
            node->meaning = meaning;
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && keyword < node->left->keyword)
            return rightRotate(node);

        if (balance < -1 && keyword > node->right->keyword)
            return leftRotate(node);

        if (balance > 1 && keyword > node->left->keyword) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && keyword < node->right->keyword) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void insert(string keyword, string meaning) {
        root = insert(root, keyword, meaning);
    }

    Node* findMin(Node* node) {
    if (node == NULL)
        return NULL;
    else if (node->left == NULL)
        return node;
    else
        return findMin(node->left);
}

Node* deleteNode(Node* node, string keyword) {
    if (node == NULL)
        return node;

    if (keyword < node->keyword)
        node->left = deleteNode(node->left, keyword);
    else if (keyword > node->keyword)
        node->right = deleteNode(node->right, keyword);
    else {
        if (node->left == NULL || node->right == NULL) {
            Node* temp = node->left ? node->left : node->right;

            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else
                *node = *temp;

            delete temp;
        } else {
            Node* temp = findMin(node->right);
            node->keyword = temp->keyword;
            node->meaning = temp->meaning;
            node->right = deleteNode(node->right, temp->keyword);
        }
    }

    if (node == NULL)
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void display(Node* node) {
    if (node != NULL) {
        display(node->left);
        cout << node->keyword << " : " << node->meaning << endl;
        display(node->right);
    }
}

void display() {
    display(root);
}

};

int main() {
    Dictionary dict;
    dict.insert("apple", "a fruit");
    dict.insert("banana", "a fruit with a yellow skin");
    dict.insert("carrot", "a vegetable that is orange");
    dict.insert("dog", "a four-legged animal");
    dict.insert("elephant", "a large, grey animal with a trunk");
    dict.insert("flower", "a plant with colorful petals");

    dict.display();
    return 0;
}
