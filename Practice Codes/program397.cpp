#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

int main()
{
    PNODE newn = NULL;

    // newn = (PNODE) malloc (sizeof(NODE));        in C

    newn = new NODE;        // in C++

    newn -> data = 11;
    newn -> next = NULL;

    cout << newn -> data ;

    // free(newn);      deallocation in C
    delete newn;

    cout << newn -> data ;




    return 0;
}