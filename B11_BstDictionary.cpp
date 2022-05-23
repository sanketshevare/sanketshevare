#include <iostream>
#include <string>
using namespace std;
class dictionary;
class node
{
    string word, meaning;
    node *left, *right;

public:
    friend class dictionary;
    node()
    {
        left = NULL;
        right = NULL;
    }
    node(string word, string meaning)
    {
        this->word = word;
        this->meaning = meaning;
        left = NULL;
        right = NULL;
    }
};

class dictionary
{

public:
    node *root;
    dictionary()
    {
        root = NULL;
    }

    void create()
    {
        int n;
        string wordI, meaningI;
        cout << "\nHow many Word to insert?:\n";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter Word: ";
            cin >> wordI;
            cout << "\nEnter Meaning: ";
            cin >> meaningI;
            insert(wordI, meaningI);
        }
    }

    bool insert(string word, string meaning)
    {
        node *p = new node(word, meaning);
        if (root == NULL)
        {
            root = p;
            return true;
        }
        node *curent = root;
        node *parent = root;
        while (curent != NULL)
        {
            if (word > curent->word)
            {
                parent = curent;
                curent = curent->right;
            }
            else if (word < curent->word)
            {
                parent = curent;
                curent = curent->left;
            }
            else
            {
               
                return false;
            }
        }
        if (word > parent->word)
        {
            parent->right = p;
            return true;
        }
        else
        {
            parent->left = p;

            return true;
        }
    }

    void display(node *root)
    {
        if (root)
        {

            display(root->left);

            cout << " WORD: " << root->word << " MEANING: " << root->meaning << endl;
            display(root->right);
        }
    }
};
int main()
{
    string word;
    dictionary d;
    d.create();
    d.display(d.root);

    return 0;
}
