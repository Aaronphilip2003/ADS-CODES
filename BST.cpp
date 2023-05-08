#include<iostream>
#include<string>
using namespace std;

class Dictionary{
    public:
    struct Node{
        string keyword;
        string meaning;
        Node* left;
        Node* right;
        Node(string keyword,string meaning):keyword(keyword),meaning(meaning),left(NULL),right(NULL){}
    };

    Node* root;

    Dictionary()
    {
        root=NULL;
    }

    void insert(string keyword,string meaning)
    {
        Node* node=new Node(keyword,meaning);
        if(root==NULL)
        {
            root=node;
        }
        else
        {
            Node* current=root;
            while(true)
            {
                if(keyword<current->keyword)
                {
                    if(current->left==NULL)
                    {
                        current->left=node;
                        break;
                    }
                    else
                    {
                        current=current->left;
                    }
                }
                else if(keyword>current->keyword)
                {
                    if(current->right==NULL)
                    {
                        current->right=node;
                        break;
                    }
                    else
                    {
                        current=current->right;
                    }
                }
                else
                {
                    current->meaning=meaning;
                    delete node;
                    break;
                }
            }

        }

    }


    
    void display()
    {
        displayTree(root);
    }

    void displayTree(Node* node)
    {
        if(node!=NULL)
        {
            displayTree(node->left);
            cout<<node->keyword<<":"<<node->meaning<<endl;
            displayTree(node->right);
        }
    }

    Node* copy(Node* node)
    {
        if(node==NULL)
        {
            return NULL;
        }
        Node* newnode=new Node(node->keyword,node->meaning);
        newnode->left=copy(node->left);
        newnode->right=copy(node->right);
        return newnode;

    }

    void mirror(Node* node)
    {
        if(node==NULL)
        {
            return;
        }

        mirror(node->left);
        mirror(node->right);

        Node* temp=node->left;
        node->left=node->right;
        node->right=temp;

    }

    
};


int main()
{
    Dictionary dict;
    dict.insert("Pringles","They are potato chips");
    dict.insert("Apple","A fruit wow");
    dict.insert("Charger","An electronic device");
    

    // display both dictionaries to verify that they are independent
    cout << "Original dictionary:" << endl;
    dict.display();
    cout << endl;

    Dictionary dictCopy(dict);
    dict.insert("Orange","Another fruit");
    dict.insert("Laptop","A portable computer");

    cout << "Copy of dictionary:" << endl;
    dictCopy.display();
    cout << endl;

    dict.mirror(dict.root);
    cout << "Mirrored dictionary:" << endl;
    dict.display();
    cout << endl;

    return 0;
}
