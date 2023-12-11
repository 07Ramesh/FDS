#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

class cBinary
{
    struct node *head, *last;

public:
    cBinary()
    {
        head = NULL;
        last = NULL;
    }
    struct node *create();
    void display();
    void onec();
    void twoc();
    void add(struct node *, struct node *);
};

struct node *cBinary ::create()
{
    int n, rem;
    struct node *nn;
    cout << "Enter Decimal Number : ";
    cin >> n;

    while (n != 0)
    {
        rem = n % 2;
        n = n / 2;
        nn = new node;
        nn->prev = nn->next = NULL;
        nn->data = rem;
        if (head == NULL)
        {
            last = head = nn;
        }
        else
        {
            head->prev = nn;
            nn->next = head;
            head = nn;
        }
    }
    return last;
}

void cBinary ::display()
{
    struct node *temp;
    temp = head;
    // cout<<" \n Binary Equivalent of Decimal is : ";
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

void cBinary::onec()
{
    struct node *temp;
    temp = head;
    // cout<<"\n1's complement of number : ";
    while (temp != NULL)
    {
        if (temp->data == 1)
        {
            temp->data = 0;
        }
        else
        {
            temp->data = 1;
        }
        temp = temp->next;
    }
    cout << "\n1's complement of number : ";
    display();
}

void cBinary::twoc()
{
    struct node *temp;
    temp = last;
    int carry = 1;
    while (temp != NULL)
    {
        if (temp->data == 0 && carry == 0)
        {
            temp->data = 0;
            carry = 0;
        }
        else if (temp->data == 0 && carry == 1)
        {
            temp->data = 1;
            carry = 0;
        }
        else if (temp->data == 1 && carry == 0)
        {
            temp->data = 1;
            carry = 0;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->prev;
    }
    cout << "\ntwos no:";
    display();
}
void cBinary::add(struct node *p, struct node *q)
{
    int a[10];
    int i;
    i = 0;
    struct node *temp1, *temp2;
    temp1 = p;
    temp2 = q;
    int carry;
    carry = 0;
    while (temp1 != NULL)
    {
        while (temp2 != NULL)
        {
            while (i <= 10)
            {
                if (temp1->data == 1 && temp2->data == 1 && carry == 0)
                {
                    a[i] = 0;
                    carry = 1;
                }
                else if (temp1->data == 0 && temp2->data == 1 && carry == 0)
                {
                    a[i] = 1;
                    carry = 0;
                }
                else if (temp1->data == 1 && temp2->data == 0 && carry == 1)
                {
                    a[i] = 0;
                    carry = 1;
                }
                else if (temp1->data == 0 && temp2->data == 0 && carry == 0)
                {
                    a[i] = 0;
                    carry = 0;
                }
                else if (temp1->data == 0 && temp2->data == 1 && carry == 1)
                {
                    a[i] = 0;
                    carry = 1;
                }
                else if (temp1->data == 1 && temp2->data == 0 && carry == 0)
                {
                    a[i] = 1;
                    carry = 0;
                }
                i++;
            }
            temp2 = temp2->prev;
        }
        temp1 = temp1->prev;
    }

    for (i = 0; i < 4; i++)
    {
        cout << a[i];
    }
}

int main()
{
    cBinary b, c;
    int ch;
    struct node *a, *p;
    cout << "\n1. create\n2. display\n3. one's complement\n4. two's complement\n5. addition\n6. exit";
    while (ch != 6)
    {
        cout << "\n\nenter the choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.create();
            break;
        case 2:
            b.display();
            break;
        case 3:
            b.onec();
            break;
        case 4:
            b.twoc();
            break;
            /*	case 5:
                    b.add(a,p);
                    break;
                case 6:
                    cout<<"exit";
                    break;*/

        case 5:
            a = b.create();
            p = c.create();
            b.add(a, p);
            break;

        case 6:
            return 0;
        default:
            cout << "\n!!!!wrong choice!!!!!";
            break;
        }
    }
    while (true)
        return 0;
}
