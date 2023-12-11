#include <iostream>
using namespace std;
struct node
{
    int N;
    struct node *next;
};
class SEa
{
public:
    struct node *insert();
    void display(struct node *);
    void intersect(struct node *, struct node *);
    void unio(struct node *, struct node *);
    void diff1(struct node *, struct node *);
    void diff2(struct node *, struct node *);
};

struct node *SEa::insert()
{
    int n, i;
    node *temp, *nn, *start;
    start = NULL;
    cout << "How many students?";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        nn = new node;
        cout << "Enter roll no of students in a class:";
        cin >> nn->N;
        nn->next = NULL;

        if (start == NULL)
        {
            start = nn;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {

                temp = temp->next;
            }
            temp->next = nn;
        }
    }
    return (start);
}
void SEa::display(struct node *t)
{
    int count = 0;
    node *temp = t;
    while (temp != NULL)
    {
        cout << temp->N << "\t";
        temp = temp->next;
        count++;
    }
    cout << " \n Total no of stu=" << count << "\n";
}
void SEa::intersect(struct node *p, struct node *tmp)
{
    struct node *q;
    while (p != NULL)
    {
        q = tmp;
        int found = 0;

        while (q != NULL)
        {
            if (p->N == q->N)
            {
                found = 1;
                cout << p->N << "\t";
                break;
            }
            q = q->next;
        }
        p = p->next;
    }
}
void SEa::unio(struct node *p, struct node *q)
{
    struct node *t = p;
    while (t != NULL)
    {
        cout << t->N << "\t";
        t = t->next;
    }
    // p=head
    for (q; q != NULL; q = q->next)
    {
        int found = 0;
        for (t = p; t != NULL; t = t->next)
        {
            if (q->N == t->N)
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
            cout << q->N << "\t";
    }
}
void SEa::diff1(struct node *p, struct node *q)
{

    while (p != NULL)
    {
        struct node *t = q;
        int found = 0;
        while (t != NULL)
        {
            if (p->N == t->N)
            {
                found = 1;
                break;
            }

            t = t->next;
        }
        if (found == 0)
        {
            cout << p->N << "\t";
        }
        p = p->next;
    }
}
/*void SEa::diff2(struct node *p,struct node *q)
{
 while(q!=NULL)
 {
 int found=0;
 while(p!=NULL)
 {
 if(q->N==p->N)
 {
 found=1;
 break;
 }

 p=p->next;
 }
 if(found==0)
 {
 cout<<q->N<<"\t";
 }
 q=q->next;
 }
}*/
int main()
{
    struct node *head = NULL, *head1 = NULL;
    SEa a;
    char x;
    int choice, m;
    cout << "HOW many total stud?";
    cin >> m;
    do
    {
        cout << "1.Insert" << endl
             << "2.Display" << endl
             << "3.Students who like both" << endl
             << "4.Students who like either vanilla or butterscotch"<< endl
             << "5.Students who like only vanilla"<<endl<<"6.Students who like only Butterscotch "<<endl;
          cout << "Enter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Students like vanilla:";
            head = a.insert();
            cout << "Stuednts like Butterscotch:";
            head1 = a.insert();
            break;

        case 2:
            cout << "Students like vanilla:\n";
            a.display(head);

            cout << "Students like Butterscotch:\n";
            a.display(head1);
            break;

        case 3:
            cout << "Students who like both" << endl;
            a.intersect(head, head1);
            break;

        case 4:
            cout << "Students who like either vanilla or  Butterscotch "<<endl;
                    a.unio(head, head1);
            break;

        case 5:
            cout << "Students who like only Vanilla" << endl;
            a.diff1(head, head1);
            break;

        case 6:
            cout << "Students who like only Butterscotch " << endl;
            a.diff1(head1, head);
            break;
        }
        cout << " \n do u want to continue(y/n):";
        cin >> x;
    } while (x == 'y');
    return 0;
}