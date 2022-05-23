#include <iostream>

using namespace std;
#define max 10

struct data
{
    long int client_ph;
    int client_id;
};

class Telephone
{
public:
    data ht[max];

public:
    Telephone()
    {
        for (int i = 0; i < max; i++)
        {
            ht[i].client_id = 0;
            ht[i].client_ph = 0;
        }
    }

    int hash(long int key)
    {
        return (key % max);
    }

    void insert()
    {

        data d;
        int iPos;
        char cAns;
        cout << "Enter id" << endl;
        cin >> d.client_id;
        cout << "\n Enter Phone Number:";
        cin >> d.client_ph;
        iPos = hash(d.client_id);
        cout << iPos << endl;

        if (ht[iPos].client_id == 0)
        {
            ht[iPos] = d;
        }
        else
        {
            for (int i = iPos + 1; i % max != iPos; i++)
            {
                ht[i] = d;
                break;
            }
        }
    }

    void display()
    {

        cout << "\nSrno\tid\tPhone number\n";

        for (int i = 0; i < max; i++)
        {
            cout << i << "\t" << ht[i].client_id << "\t" << ht[i].client_ph << endl;
        }
    }

    void delete1()
    {
        int x, flag;
        cout << "Enter Phone Number To Delete:- " << endl;
        cin >> x;
        for (int i = 0; i < max; i++)
        {
            if (ht[i].client_ph == x)
            {
                ht[i].client_ph = 0;
                flag = 0;
                cout << "Phone Number deleted Successfully" << endl;
            }
        }
        if (flag = 1)
        {
            cout << "Client Phone Numbar Not Found!" << endl;
        }
    }
};

int main()
{
    Telephone t;
    int ch;
    do
    {

        cout << "0.EXIT" << endl
             << "1.INSERT" << endl
             << "2.DISPLAY" << endl
             << "3.DELETE" << endl;

        cin >> ch;

        switch (ch)
        {
        case 1:
            t.insert();
            break;

        case 2:
            t.display();
            break;
       
        case 3:
            t.delete1();
            break;
        default:
            cout << "Failed!";
            break;
        }
    } while (ch != 0);
}
