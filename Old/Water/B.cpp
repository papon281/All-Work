#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node *rearrangeEvenOdd(struct Node *head)
{
    if (head == NULL)
        return NULL;

    struct Node *odd = head;
    struct Node *even = head->next;

    struct Node *evenFirst = even;

    while (1)
    {
        if (!odd || !even || !(even->next))
        {
            odd->next = evenFirst;
            break;
        }

        odd->next = even->next;
        odd = even->next;

        if (odd->next == NULL)
        {
            even->next = NULL;
            odd->next = evenFirst;
            break;
        }

        even->next = odd->next;
        even = odd->next;
    }

    return head;
}

void print(struct Node * node)
{
    int first = 1;
    while (node != NULL)
    {
        if(first){
            cout<<node->data;
            first = 0;
        } else {
            cout << " "<<node->data;
        }
        node = node->next;
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int num,c=0;
    struct Node* head = new Node;
    struct Node* temp = new Node;
    cin>>num;
    head->data=num;
    for(int i=2; i<=n; i++)
    {
        if(c==0)
        {
            cin>>num;
            temp->data=num;
            head->next=temp;
            c++;
        }
        else
        {
            cin>>num;
            struct Node * temp1 = new Node;
            temp1->data=num;
            temp->next=temp1;
            temp=temp1;
        }
    }
    head=rearrangeEvenOdd(head);
    print(head);
    return 0;
}
