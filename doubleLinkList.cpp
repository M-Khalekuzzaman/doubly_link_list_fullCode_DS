#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *Prev;
    Node *Next;

    //Constructor declare
    Node(int data)
    {
        this -> data = data;
        this -> Prev = NULL;
        this -> Next = NULL;
    }
};
struct Test
{
    int countPosition[100];
};
void insertAtTail(Node* &head,int value)
{
    Node *newNode = new Node(value);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
    newNode->Prev = temp;
}
void insertAtHead(Node* &head,int value)
{
    Node *newNode = new Node(value);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    head->Prev = newNode;
    newNode->Next = head;
    head = newNode;
}

void insertAtAnyPosition(Node* &head,int value,int pos)
{
    Node *newNode = new Node(value);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    if(pos == 1)
    {
        head->Prev = newNode;
        newNode->Next = head;
        head = newNode;
        return;
    }
    pos--;
    Node *temp = head;
    for(int i = 1; i<pos; i++)
    {
        temp = temp->Next;
    }

    Node *save = temp->Next;
    temp->Next = newNode;
    newNode->Prev = temp;
    newNode->Next = save;
    save->Prev = newNode;
}
void deleteAtHead(Node* &head)
{
    Node *save = head->Next;
    head = save;
    head->Prev = NULL;
}

void deleteAtTail(Node* &head)
{
    Node *temp = head;
    while(temp->Next->Next != NULL)
    {
        temp = temp->Next;
    }
    Node *save = temp->Next;
    temp->Next = NULL;
    delete save;

}

//print link list function
void printLinList(Node* &head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data;
        if(temp->Next != NULL)
            cout<<" -> ";
        temp = temp->Next;
    }
    cout<<endl;
}
//reverse print link list
void reverseLinkList(Node* &head)
{
    Node *temp = head;
    while(temp->Next != NULL)
    {
        temp = temp->Next;
    }
    while(temp != NULL)
    {
        cout<<temp->data;
        if(temp->Prev != NULL)
            cout<<" <- ";
        temp = temp->Prev;
    }
    cout<<endl;
}
// delete at any position of doubly link list
void deleteAtAnyPosition(Node* &head,int pos)
{
    if(head == NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }
    Node *temp = head;
    pos--;
    for(int i = 1; i<pos; i++)
    {
        temp = temp->Next;
    }
    Node *save = temp->Next->Next;
    delete temp->Next;
    temp->Next = save;
    save->Prev = temp;

}
// search value by unique list
int searchValueUniqueList(Node* &head,int value)
{
    if(head == NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return 0;
    }
    Node *temp = head;
    int count = 1,flag = 0;
    while(temp != NULL)
    {
        int val = temp->data;
        if(val == value)
        {
            flag = 1;
            return count;
        }
        count++;
        temp = temp->Next;
    }

    if(flag == 0) return -1;
}
//search value by duplicate doubly link list
struct Test searchValueByDuplicateList(Node* &head,int value)
{
    Node *temp = head;
    if(head == NULL)
    {
        cout<<"Linked list is empty"<<endl;
    }
    struct Test T;
    int k = 1,count = 1;
    while(temp != NULL)
    {

        int val = temp->data;
        if(val == value)
        {
            T.countPosition[k] = count;
            k++;
        }
        count++;
        temp = temp->Next;
    }
    T.countPosition[0] = k;

    return T;

}
// insertion after a specific value by(unique link list)
void insertionValue(Node* &head,int value,int insert_value)
{
    Node *temp = head;
    int pos,count = 1;
    while(temp != NULL)
    {
        int val = temp->data;
        if(val == value)
        {
            pos = count;
        }
        count++;
        temp = temp->Next;
    }
    insertAtAnyPosition(head,insert_value,pos+1);
}
// insertionValueByDuplicateList
void insertionValueByDuplicateList(Node* &head,int value,int insert_value)
{
    Node *temp = head;
    if(head == NULL)
    {
        cout<<"Linked list is empty"<<endl;
    }
    struct Test T;
    int k = 1,count = 1;
    while(temp != NULL)
    {

        int val = temp->data;
        if(val == value)
        {
            T.countPosition[k] = count;
            k++;
        }
        count++;
        temp = temp->Next;
    }
    T.countPosition[0] = k;
    int size = T.countPosition[0];
    for(int i = 1; i<size; i++)
    {
        int pos = T.countPosition[i];
        insertAtAnyPosition(head,insert_value,pos+i);
    }
}
// count length
int countLength(Node* &head)
{
    Node *temp = head;
    int count = 1;
    while(temp->Next != NULL)
    {
        temp = temp->Next;
        count++;
    }

    return count;
}
int main()
{
    Node *head = NULL;

    cout<<"Choice 1 : Insert at Head"<<endl;
    cout<<"Choice 2 : Insert at Tail"<<endl;
    cout<<"Choice 3 : Insert at any Position"<<endl;
    cout<<"Choice 4 : Reverse link-list"<<endl;
    cout<<"Choice 5 : Delete at Head"<<endl;
    cout<<"Choice 6 : Delete at Tail"<<endl;
    cout<<"Choice 7 : Delete at any Position"<<endl;
    cout<<"Choice 8 : Count length"<<endl;
    cout<<"Choice 9 : Search value(Unique List)"<<endl;
    cout<<"Choice 10: Search a value (Duplication enabled List)"<<endl;
    cout<<"Choice 11: Insertion after a specific value (Unique List)"<<endl;
    cout<<"Choice 12: Insertion after a specific value (Duplication enabled List)"<<endl;
    cout<<"Choice 0 : Exit"<<endl<<endl;

    int value,pos,len,insert_value,choice = 2;
    while(choice != 0)
    {
        cout<<"Next Choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Insert your value to(Head): ";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<<"Insert your value to(Tail): ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
            cout<<"Insert your value & position : ";
            cin>>value>>pos;
            insertAtAnyPosition(head,value,pos);
            break;
        case 4:
            cout<<"Reverse link-list : ";
            reverseLinkList(head);
            break;
        case 5:
            deleteAtHead(head);
            break;
        case 6:
            deleteAtTail(head);
            break;
        case 7 :
            cout<<"You want to delete at position : ";
            cin>>pos;
            deleteAtAnyPosition(head,pos);
            break;
        case 8 :
            len = countLength(head);
            cout<<"Length is : "<<len<<endl;
            break;
        case 9 :
            cout<<"Enter your value you want to search(Unique-list): ";
            cin>>value;
            int p;
            p = searchValueUniqueList(head,value);
            if(p == -1) cout<<"NOT FOUND !!!"<<endl;
            else cout<<"Found at position : "<<p<<endl;
            break;
        case 10:
            cout<<"Enter your value you want to search(Duplication enabled List): ";
            cin>>value;
            struct Test T;
            T = searchValueByDuplicateList(head,value);
            int size;
            size = T.countPosition[0];
            cout<<"Position at : ";
            for(int i = 1; i<size; i++)
            {
                cout<<T.countPosition[i];
                if(i<size-1) cout<<",";
            }
            cout<<endl;
            break;
        case 11:
            cout<<"Insertion after a specific value (Unique List) : ";
            cin>>value>>insert_value;
            insertionValue(head,value,insert_value);
            break;
        case 12:
            cout<<"Insertion after a specific value (Duplication enabled List) : ";
            cin>>value>>insert_value;
            insertionValueByDuplicateList(head,value,insert_value);
            break;
        default:
            break;
        }

    }
    cout<<endl<<"Link-list : ";
    printLinList(head);



    return 0;
}
