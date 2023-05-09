#include <iostream>
using namespace std;

class Treenode_TBT {
  int data;
  int lbit = 0;
  int rbit = 0;
  Treenode_TBT *left;
  Treenode_TBT *right;

  friend class Tree;
  friend Treenode_TBT *inorder_succ(Treenode_TBT *);

public:
  Treenode_TBT() {
    lbit = 1;
    rbit = 1;
  }
};

class Tree {
  Treenode_TBT *root;
  Treenode_TBT *head;

public:
  void create_TBT();
  void preorder_TBT();
  void inorder_TBT();
  Tree() {
    head = new Treenode_TBT;
    head->data = -1;
    head->left = head;
    head->right = head;
    head->rbit = 0;
  }
};

void Tree::create_TBT() {

  root = new Treenode_TBT;
  cout << "Enter the Value of the Root Node" << endl;
  cin >> root->data;

  head->left = root;
  head->lbit = 0;

  root->left = head;
  root->right = head;

  char choice;
  do {
    int flag = 0;
    Treenode_TBT *temp = root;
    Treenode_TBT *curr = new Treenode_TBT;

    cout << "Enter the New Value " << endl;
    cin >> curr->data;
    curr->left = NULL;
    curr->right = NULL;

    while (flag == 0) {
      cout << "Enter L for Left  |  R for Right" << endl;
      cin >> choice;
      if (choice == 'l' || choice == 'L') {
        if (temp->lbit == 1) {
          curr->right = temp;
          curr->left = temp->left;
          temp->left = curr;
          temp->lbit = 0;
          flag = 1;
        } else {
          temp = temp->left;
        }
      }
      if (choice == 'R' || choice == 'r') {
        if (temp->rbit == 1) {
          curr->left = temp;
          curr->right = temp->right;
          temp->right = curr;
          temp->rbit = 0;
          flag = 1;
        }

        else {
          temp = temp->right;
        }
      }
    }
    cout << "Enter Y to Accept more Data" << endl;
    cin >> choice;
  } while (choice == 'y' || choice == 'Y');
}

void Tree::preorder_TBT() {
  Treenode_TBT *temp = head->left;
  while (temp != head) {
    cout << temp->data << endl;
    while (temp->lbit != 1) {
      temp = temp->left;
      cout << temp->data << endl;
    }
    while (temp->rbit == 1) {
      temp = temp->right;
    }
    temp = temp->right;
  }
}

void Tree::inorder_TBT() {
  Treenode_TBT *temp = head;
  while (1) {
    temp = inorder_succ(temp);
    if (temp == head) {
      break;
    }
    cout << temp->data << endl;
  }
}

Treenode_TBT *inorder_succ(Treenode_TBT *temp) {
  Treenode_TBT *x = temp->right;
  if (temp->rbit == 0) {
    while (x->lbit == 0) {
      x = x->left;
    }
  }
  return x;
}

int main() {
  Tree tbt;
  int choice;

  tbt.create_TBT();

label:
  cout << "Enter 1 for Inorder Traversal\nEnter 2 for Preorder Traversal"
       << endl;

  cin >> choice;
  printf("\n\n");

  switch (choice) {
  case 1:
    tbt.inorder_TBT();
    break;

  case 2:
    tbt.preorder_TBT();
    break;

  default:
    break;
  }
  cout << "Enter 1 To continue\nEnter 0 to Exit" << endl;
  cin >> choice;

  if (choice == 1) {
    goto label;
  } else {
    goto exit;
  }
exit:

  return 0;
}
