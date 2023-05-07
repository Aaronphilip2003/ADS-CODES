#include<iostream>
#include<string>
using namespace std;

class Dictionay{
    public:
    struct Node{
        string keyword;
        string meaning;
        Node* left;
        Node* right;
        Node(string keyword,string meaning):keyword(keyword),meaning(meaning),left(NULL),right(NULL){}
    };

    Node* root;

    Dictionay()
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
};

int main()
{
    Dictionay dict;
    dict.insert("Pringles","They are potato chips");
    dict.insert("Apple","A fruit wow");
    dict.insert("Charger","An electronic device");
    dict.display();
    return 0;
}
