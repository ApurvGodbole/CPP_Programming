#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
    struct node * prev;           
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private : 
        PNODE first;
        int iCount;

    public :
        DoublyLL();

        void Display();

        int Count();

        void InsertFirst(int iNo);

        void InsertLast(int iNo);

        void InsertAtPos(int iNo , int iPos);

        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(int iPos);

};

DoublyLL::DoublyLL()
{
    this -> first = NULL;
    this -> iCount = 0;

}

void DoublyLL:: Display()
{
    PNODE temp = NULL ;

    temp = this -> first;

    cout << " NULL  <=> ";

    while(temp != NULL)
    {
        cout << " | " << temp -> data << " |  <=> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int DoublyLL::Count()
{
    return this -> iCount;
}

void DoublyLL:: InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(first == NULL)           // 0 nodes
    {
        this -> first = newn ;
    }
    else                        // 1 or more than 1 nodes
    {
        newn -> next = this -> first;
        this -> first -> prev = newn;
        this -> first = newn;
    }

    iCount++;
}

void DoublyLL:: InsertLast(int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(first == NULL)           // 0 nodes
    {
        this -> first = newn ;
    }
    else                        // 1 or more than 1 nodes
    {
        temp = this -> first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
            temp -> next = newn;
            newn -> prev = temp;
    }
    iCount ++;
}

void DoublyLL::InsertAtPos(int iNo , int iPos)
{
    int i = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    if((iPos < 1) || (iPos > iCount + 1) )
    {
        cout<<"Invalid Operation \n ";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos = iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        newn -> data = iNo;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = this -> first;

        for (i = 0 ; i < iPos ; i++)
        {
            temp = temp -> next;
        }
            temp -> next = newn;
            newn -> next = temp -> next;
            temp -> next -> prev = newn;
    }
    
}

void DoublyLL::  DeleteFirst()
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
    }
    else
    {
        temp = this -> first;
        this -> first = this -> first -> next;
        delete temp;
    }
}

void DoublyLL::  DeleteLast()
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
    }
    else
    {
        temp = this -> first;

        while (temp -> next -> next != NULL)        // type 3 while loop
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }
}

void DoublyLL::  DeleteAtPos(int iPos)
{
    int i = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;
    PNODE target = NULL;

    newn = new NODE;

    if((iPos < 1) || (iPos > iCount) )
    {
        cout<<"Invalid Operation \n ";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this -> first;

        for (i = 0 ; i < iPos ; i ++)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp -> next = target -> next;
        delete target; 
    }
}


int main()
{
    DoublyLL sobj ;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(121);
    sobj.Display();

    sobj.DeleteFirst();
    sobj.Display();

    sobj.DeleteLast();
    sobj.Display();

    sobj.InsertAtPos(11,2);
    sobj.Display();

    sobj.DeleteAtPos(2);
    sobj.Display();

    return 0;
}