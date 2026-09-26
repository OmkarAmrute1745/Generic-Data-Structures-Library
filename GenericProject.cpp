#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
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
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
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
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Linear
//
/////////////////////////////////////////////////////////////


template <class T>
struct nodeDLL
{
    T data;
    struct nodeDLL * next;
    struct nodeDLL * prev;
};

template <class T>
class DoublyLL
{
    private:
        struct nodeDLL<T> * First;
        struct nodeDLL<T> * Last;
        int iCount;
    public :
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T> :: Display()
{
    struct nodeDLL<T> * temp = NULL;
    temp = First;

    cout<<" NULL <=> ";
    while(temp != NULL)
    {
        cout<<" | "<<temp -> data<<" | <=>";
        temp = temp -> next;
    }
    cout<<" NULL\n";
}

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T No)
{
    struct nodeDLL<T> * newn = NULL;

    newn = new nodeDLL<T>;
    newn->data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL) // LL is empty
    {
        First = newn;
    }
    else // LL contains more than 1 node
    {
        newn -> next = First;
        First -> prev = newn;

        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T No)
{
    struct nodeDLL<T> * newn = NULL;
    struct nodeDLL<T> * temp = NULL;

    newn = new nodeDLL<T>;
    newn->data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL) // LL is empty
    {
        First = newn;
    }
    else // LL contains more than 1 node
    {
        temp = First;

        while(temp -> next != NULL )
        {
            temp = temp -> next;
        }
        newn -> prev = temp;
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T No, int iPos)
{
    struct nodeDLL<T> * newn = NULL;
    struct nodeDLL<T> * temp = NULL;

    newn = new nodeDLL<T>;
    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;
    int i = 0;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
    
        iCount++;
    }
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        printf("Unable to delete element as LL is empty\n");
        return;
    }
    else if(First -> next == NULL)
    {
        delete (First);
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete (First -> prev);
        (First -> prev) = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct node * temp = NULL;

    if(First == NULL)
    {
        printf("Unable to delete element as LL is empty\n");
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete (temp -> next);
        temp -> next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    struct nodeDLL<T> * temp = NULL;

    int i = 0;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
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
        temp = First;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        delete (temp -> next -> prev);
        temp -> next -> prev = temp;

        iCount--;
    }
}


/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////


template <class T>
struct nodeSCL
{
    T data;
    struct nodeSCL * next;
};

template <class T>
class SinglyCL
{
    private:
        struct nodeSCL<T> * First;
        struct nodeSCL<T> * Last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    if(First == NULL && (Last == NULL))
    {
        cout<<"Linked List is empty\n";
        return;
    }

    do
    {
        cout<<" | "<<First-> data<<" | -> ";
        First = First -> next;

    }while(First != Last -> next);
    cout<<"NULL\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct nodeSCL<T> * newn = NULL;
    
    newn = new nodeSCL<T>;
    
    newn -> data = No;
    newn -> next = NULL;

    if( (First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    } 
    (Last) -> next = (First); 
    
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeSCL<T> * newn = NULL;
    
    newn = new nodeSCL<T>;
    
    newn -> data = No;
    newn -> next = NULL;

    if( (First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last -> next = newn;
        Last = newn;
    } 
    (Last) -> next = (First); 
    
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSCL<T> * newn = NULL;
    struct nodeSCL<T> * temp = First;
    int i = 0;

    if((iPos < 1) && (iPos > iCount + 1))
    {
        cout<<"Unable to Add element\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeSCL<T>;

        newn -> data = No;
        newn -> next = NULL;

        for(i = 1 ; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    struct nodeSCL<T> * temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        cout<<"Unble to delete element\n";
        return;
    }
    else if(First == Last) // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else // more than one node
    {
        temp = First;

        First = First -> next;

        delete temp;
        Last -> next = First;
    }

    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeSCL<T> * temp = First;

    if((First == NULL) && (Last == NULL))
    {
        cout<<"Unble to delete element\n";
        return;
    }
    else if(First == Last) // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else // more than one node
    {
        while(temp -> next != Last)
        {
            temp = temp -> next;
        }
        free(Last);
        Last = temp;

        Last -> next = First;
    }

    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeSCL<T> * newn = NULL;
    struct nodeSCL<T> * temp1 = First;
    struct nodeSCL<T> * temp2 = NULL;
    int i = 0;

    if((iPos < 1) && (iPos > iCount))
    {
        cout<<"Unable to Add element\n";
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

        for(i = 1 ; i < iPos - 1; i++)
        {
            temp1 = temp1 -> next;
        }