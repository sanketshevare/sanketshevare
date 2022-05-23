#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
class bst
{

public:
    node *root;
    bst()
    {
        root = NULL;
    }

    void create()
    {
        node *curr, *temp;
        int ans = 1;
        cout << "enter data:";

        curr = new node;
        cin >> curr->data;
        curr->left = curr->right = NULL;
        if (root == NULL)
        {
            root = curr;
        }
        else
        {
            temp = root;
            while (1)
            {
                if (curr->data <= temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = curr;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = curr;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }

        void insert()
        {
            node *curr, *temp;
            int ans = 1;
            cout << "enter data:";

            curr = new node;
            cin >> curr->data;
            curr->left = curr->right = NULL;
            if (root == NULL)
            {
                root = curr;
            }
            else
            {
                temp = root;
                while (1)
                {
                    if (curr->data <= temp->data)
                    {
                        if (temp->left == NULL)
                        {
                            temp->left = curr;
                            break;
                        }
                        else
                        {
                            temp = temp->left;
                        }
                    }
                    else
                    {
                        if (temp->right == NULL)
                        {
                            temp->right = curr;
                            break;
                        }
                        else
                        {
                            temp = temp->right;
                        }
                    }
                } // end of while
            }
        }

        void inorder(node * root)
        {
            if (root != NULL)
            {
                inorder(root->left);
                cout << " " << root->data;
                inorder(root->right);
            }
        }
        void preorder(node * root)
        {
            if (root != NULL)
            {
                cout << "  " << root->data;
                preorder(root->left);
                preorder(root->right);
            }
        }
        void postorder(node * root)
        {
            if (root != NULL)
            {
                postorder(root->left);
                postorder(root->right);
                cout << " " << root->data;
            }
        }

        void display()
        {

            int ch;
            cout << "1.Inorder\n2.Preorder\n3.Postorder" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                inorder(root);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                postorder(root);
                break;
            }
        }
    };
    int main()
    {
        bst b;
        int key, ch;
        do
        {
            cout << "\n1.create\n2.insert\n3.display\n";
            cout << "enter your choice:";
            cin >> ch;
            switch (ch)
            {
            case 1:
                b.create();
                break;
            case 2:
                b.insert();
                break;
            case 3:
                b.display();

                break;
            }
        } while (ch != 0);
        return 0;
    }
