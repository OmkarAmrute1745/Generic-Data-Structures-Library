#include <iostream>
#include <stdexcept>
using namespace std;

/*
    Generic Data Structures Library
    --------------------------------
    Based on the user's original generic data-structure style:
    - node structure + template class
    - First / Last pointers
    - iCount
    - Display / Count
    - InsertFirst / InsertLast / InsertAtPos
    - DeleteFirst / DeleteLast / DeleteAtPos

    Extended with:
    - Stack
    - Queue
    - Deque
    - Priority Queue
    - Binary Search Tree
    - Hash Table
*/

// ============================================================
// 1. SINGLY LINEAR LINKED LIST
// ============================================================

template <class T>
struct nodeSL
{
    T data;
    nodeSL<T>* next;
};

template <class T>
class SinglyLL
{
private:
    nodeSL<T>* First;
    int iCount;

public:
    SinglyLL();
    ~SinglyLL();

    void Display();
    int Count();
    bool IsEmpty();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    bool Search(T No);
    int Frequency(T No);
    void Reverse();
    T GetFirst();
    T GetLast();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
SinglyLL<T>::~SinglyLL()
{
    while (First != NULL)
    {
        DeleteFirst();
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    nodeSL<T>* temp = First;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
bool SinglyLL<T>::IsEmpty()
{
    return First == NULL;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    nodeSL<T>* newn = new nodeSL<T>;
    newn->data = No;
    newn->next = First;
    First = newn;
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    nodeSL<T>* newn = new nodeSL<T>;
    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        nodeSL<T>* temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
        return;
    }

    if (iPos == iCount + 1)
    {
        InsertLast(No);
        return;
    }

    nodeSL<T>* temp = First;

    for (int i = 1; i < iPos - 1; i++)
    {
        temp = temp->next;
    }

    nodeSL<T>* newn = new nodeSL<T>;
    newn->data = No;
    newn->next = temp->next;
    temp->next = newn;

    iCount++;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }

    nodeSL<T>* temp = First;
    First = First->next;

    delete temp;
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (First == NULL)
    {
        return;
    }

    if (First->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
        return;
    }

    nodeSL<T>* temp = First;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
        return;
    }

    if (iPos == iCount)
    {
        DeleteLast();
        return;
    }

    nodeSL<T>* temp = First;

    for (int i = 1; i < iPos - 1; i++)
    {
        temp = temp->next;
    }

    nodeSL<T>* target = temp->next;
    temp->next = target->next;

    delete target;
    iCount--;
}

template <class T>
bool SinglyLL<T>::Search(T No)
{
    nodeSL<T>* temp = First;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

template <class T>
int SinglyLL<T>::Frequency(T No)
{
    int iFrequency = 0;
    nodeSL<T>* temp = First;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            iFrequency++;
        }

        temp = temp->next;
    }

    return iFrequency;
}

template <class T>
void SinglyLL<T>::Reverse()
{
    nodeSL<T>* prev = NULL;
    nodeSL<T>* current = First;
    nodeSL<T>* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    First = prev;
}

template <class T>
T SinglyLL<T>::GetFirst()
{
    if (First == NULL)
    {
        throw runtime_error("List is empty");
    }

    return First->data;
}

template <class T>
T SinglyLL<T>::GetLast()
{
    if (First == NULL)
    {
        throw runtime_error("List is empty");
    }

    nodeSL<T>* temp = First;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp->data;
}


// ============================================================
// 2. DOUBLY LINEAR LINKED LIST
// ============================================================

template <class T>
struct nodeDLL
{
    T data;
    nodeDLL<T>* next;
    nodeDLL<T>* prev;
};

template <class T>
class DoublyLL
{
private:
    nodeDLL<T>* First;
    nodeDLL<T>* Last;
    int iCount;

public:
    DoublyLL();
    ~DoublyLL();

    void Display();
    void DisplayReverse();
    int Count();
    bool IsEmpty();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    bool Search(T No);
    void Reverse();
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
DoublyLL<T>::~DoublyLL()
{
    while (First != NULL)
    {
        DeleteFirst();
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    nodeDLL<T>* temp = First;

    cout << "NULL <=> ";

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

template <class T>
void DoublyLL<T>::DisplayReverse()
{
    nodeDLL<T>* temp = Last;

    cout << "NULL <=> ";

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->prev;
    }

    cout << "NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
bool DoublyLL<T>::IsEmpty()
{
    return First == NULL;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    nodeDLL<T>* newn = new nodeDLL<T>;

    newn->data = No;
    newn->prev = NULL;
    newn->next = First;

    if (First == NULL)
    {
        First = Last = newn;
    }
    else
    {
        First->prev = newn;
        First = newn;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    nodeDLL<T>* newn = new nodeDLL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = Last;

    if (Last == NULL)
    {
        First = Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
        return;
    }

    if (iPos == iCount + 1)
    {
        InsertLast(No);
        return;
    }

    nodeDLL<T>* temp = First;

    for (int i = 1; i < iPos - 1; i++)
    {
        temp = temp->next;
    }

    nodeDLL<T>* newn = new nodeDLL<T>;

    newn->data = No;
    newn->next = temp->next;
    newn->prev = temp;

    temp->next->prev = newn;
    temp->next = newn;

    iCount++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }

    nodeDLL<T>* temp = First;

    if (First == Last)
    {
        First = Last = NULL;
    }
    else
    {
        First = First->next;
        First->prev = NULL;
    }

    delete temp;
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (Last == NULL)
    {
        return;
    }

    nodeDLL<T>* temp = Last;

    if (First == Last)
    {
        First = Last = NULL;
    }
    else
    {
        Last = Last->prev;
        Last->next = NULL;
    }

    delete temp;
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
        return;
    }

    if (iPos == iCount)
    {
        DeleteLast();
        return;
    }

    nodeDLL<T>* temp = First;

    for (int i = 1; i < iPos; i++)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    iCount--;
}

template <class T>
bool DoublyLL<T>::Search(T No)
{
    nodeDLL<T>* temp = First;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

template <class T>
void DoublyLL<T>::Reverse()
{
    nodeDLL<T>* current = First;
    nodeDLL<T>* temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        First = temp->prev;
    }

    temp = First;
    Last = NULL;

    while (temp != NULL)
    {
        Last = temp;
        temp = temp->next;
    }
}


// ============================================================
// 3. SINGLY CIRCULAR LINKED LIST
// ============================================================

template <class T>
struct nodeSCL
{
    T data;
    nodeSCL<T>* next;
};

template <class T>
class SinglyCL
{
private:
    nodeSCL<T>* First;
    nodeSCL<T>* Last;
    int iCount;

public:
    SinglyCL();
    ~SinglyCL();

    void Display();
    int Count();
    bool IsEmpty();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    bool Search(T No);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
SinglyCL<T>::~SinglyCL()
{
    while (iCount > 0)
    {
        DeleteFirst();
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    if (First == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    nodeSCL<T>* temp = First;

    do
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }
    while (temp != First);

    cout << "(First)\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
bool SinglyCL<T>::IsEmpty()
{
    return First == NULL;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    nodeSCL<T>* newn = new nodeSCL<T>;

    newn->data = No;

    if (First == NULL)
    {
        First = Last = newn;
        newn->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }

    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    nodeSCL<T>* newn = new nodeSCL<T>;

    newn->data = No;

    if (First == NULL)
    {
        First = Last = newn;
        newn->next = First;
    }
    else
    {
        newn->next = First;
        Last->next = newn;
        Last = newn;
    }

    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
        return;
    }

    if (iPos == iCount + 1)
    {
        InsertLast(No);
        return;
    }

    nodeSCL<T>* temp = First;

    for (int i = 1; i < iPos - 1; i++)
    {
        temp = temp->next;
    }

    nodeSCL<T>* newn = new nodeSCL<T>;
    newn->data = No;
    newn->next = temp->next;
    temp->next = newn;

    iCount++;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }

    if (First == Last)
    {
        delete First;
        First = Last = NULL;
    }
    else
    {
        nodeSCL<T>* temp = First;
        First = First->next;
        Last->next = First;
        delete temp;
    }

    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (First == NULL)
    {
        return;
    }

    if (First == Last)
    {
        delete First;
        First = Last = NULL;
        iCount--;
        return;
    }

    nodeSCL<T>* temp = First;

    while (temp->next != Last)
    {
        temp = temp->next;
    }

    delete Last;
    Last = temp;
    Last->next = First;

    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
        return;
    }

    if (iPos == iCount)
    {
        DeleteLast();
        return;
    }

    nodeSCL<T>* temp = First;

    for (int i = 1; i < iPos - 1; i++)
    {
        temp = temp->next;
    }

    nodeSCL<T>* target = temp->next;
    temp->next = target->next;

    delete target;
    iCount--;
}

template <class T>
bool SinglyCL<T>::Search(T No)
{
    if (First == NULL)
    {
        return false;
    }

    nodeSCL<T>* temp = First;

    do
    {
        if (temp->data == No)
        {
            return true;
        }

        temp = temp->next;
    }
    while (temp != First);

    return false;
}


// ============================================================
// 4. DOUBLY CIRCULAR LINKED LIST
// ============================================================

template <class T>
struct nodeDC
{
    T data;
    nodeDC<T>* next;
    nodeDC<T>* prev;
};

template <class T>
class DoublyCL
{
private:
    nodeDC<T>* First;
    nodeDC<T>* Last;
    int iCount;

public:
    DoublyCL();
    ~DoublyCL();

    void Display();
    void DisplayReverse();
    int Count();
    bool IsEmpty();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    bool Search(T No);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
DoublyCL<T>::~DoublyCL()
{
    while (iCount > 0)
    {
        DeleteFirst();
    }
}

template <class T>
void DoublyCL<T>::Display()
{
    if (First == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    nodeDC<T>* temp = First;

    cout << "<=> ";

    do
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }
    while (temp != First);

    cout << "(First)\n";
}

template <class T>
void DoublyCL<T>::DisplayReverse()
{
    if (Last == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    nodeDC<T>* temp = Last;

    cout << "<=> ";

    do
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->prev;
    }
    while (temp != Last);

    cout << "(Last)\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
bool DoublyCL<T>::IsEmpty()
{
    return First == NULL;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    nodeDC<T>* newn = new nodeDC<T>;
    newn->data = No;

    if (First == NULL)
    {
        First = Last = newn;
        newn->next = newn;
        newn->prev = newn;
    }
    else
    {
        newn->next = First;
        newn->prev = Last;

        First->prev = newn;
        Last->next = newn;

        First = newn;
    }

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    nodeDC<T>* newn = new nodeDC<T>;
    newn->data = No;

    if (First == NULL)
    {
        First = Last = newn;
        newn->next = newn;
        newn->prev = newn;
    }
    else
    {
        newn->next = First;
        newn->prev = Last;

        Last->next = newn;
        First->prev = newn;

        Last = newn;
    }

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
        return;
    }

    if (iPos == iCount + 1)
    {
        InsertLast(No);
        return;
    }

    nodeDC<T>* temp = First;

    for (int i = 1; i < iPos - 1; i++)
    {
        temp = temp->next;
    }

    nodeDC<T>* newn = new nodeDC<T>;
    newn->data = No;

    newn->next = temp->next;
    newn->prev = temp;

    temp->next->prev = newn;
    temp->next = newn;

    iCount++;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }

    if (First == Last)
    {
        delete First;
        First = Last = NULL;
    }
    else
    {
        nodeDC<T>* temp = First;

        First = First->next;
        First->prev = Last;
        Last->next = First;

        delete temp;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (Last == NULL)
    {
        return;
    }

    if (First == Last)
    {
        delete Last;
        First = Last = NULL;
    }
    else
    {
        nodeDC<T>* temp = Last;

        Last = Last->prev;
        Last->next = First;
        First->prev = Last;

        delete temp;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
        return;
    }

    if (iPos == iCount)
    {
        DeleteLast();
        return;
    }

    nodeDC<T>* temp = First;

    for (int i = 1; i < iPos; i++)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    iCount--;
}

template <class T>
bool DoublyCL<T>::Search(T No)
{
    if (First == NULL)
    {
        return false;
    }

    nodeDC<T>* temp = First;

    do
    {
        if (temp->data == No)
        {
            return true;
        }

        temp = temp->next;
    }
    while (temp != First);

    return false;
}


// ============================================================
// 5. STACK
// ============================================================

template <class T>
struct nodeSK
{
    T data;
    nodeSK<T>* next;
};

template <class T>
class Stack
{
private:
    nodeSK<T>* First;
    int iCount;

public:
    Stack();
    ~Stack();

    void Display();
    int Count();
    bool IsEmpty();

    void Push(T No);
    T Pop();
    T Peek();
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
Stack<T>::~Stack()
{
    while (First != NULL)
    {
        Pop();
    }
}

template <class T>
void Stack<T>::Display()
{
    nodeSK<T>* temp = First;

    cout << "TOP\n";

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |\n";
        temp = temp->next;
    }

    cout << "BOTTOM\n";
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
bool Stack<T>::IsEmpty()
{
    return First == NULL;
}

template <class T>
void Stack<T>::Push(T No)
{
    nodeSK<T>* newn = new nodeSK<T>;

    newn->data = No;
    newn->next = First;
    First = newn;

    iCount++;
}

template <class T>
T Stack<T>::Pop()
{
    if (First == NULL)
    {
        throw runtime_error("Stack is empty");
    }

    nodeSK<T>* temp = First;
    T value = First->data;

    First = First->next;

    delete temp;
    iCount--;

    return value;
}

template <class T>
T Stack<T>::Peek()
{
    if (First == NULL)
    {
        throw runtime_error("Stack is empty");
    }

    return First->data;
}


// ============================================================
// 6. QUEUE
// ============================================================

template <class T>
struct nodeQue
{
    T data;
    nodeQue<T>* next;
};

template <class T>
class Queue
{
private:
    nodeQue<T>* First;
    nodeQue<T>* Last;
    int iCount;

public:
    Queue();
    ~Queue();

    void Display();
    int Count();
    bool IsEmpty();

    void EnQueue(T No);
    T DeQueue();
    T Peek();
};

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
Queue<T>::~Queue()
{
    while (First != NULL)
    {
        DeQueue();
    }
}

template <class T>
void Queue<T>::Display()
{
    nodeQue<T>* temp = First;

    cout << "FRONT -> ";

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }

    cout << "NULL <- REAR\n";
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

template <class T>
bool Queue<T>::IsEmpty()
{
    return First == NULL;
}

template <class T>
void Queue<T>::EnQueue(T No)
{
    nodeQue<T>* newn = new nodeQue<T>;

    newn->data = No;
    newn->next = NULL;

    if (Last == NULL)
    {
        First = Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }

    iCount++;
}

template <class T>
T Queue<T>::DeQueue()
{
    if (First == NULL)
    {
        throw runtime_error("Queue is empty");
    }

    nodeQue<T>* temp = First;
    T value = First->data;

    First = First->next;

    if (First == NULL)
    {
        Last = NULL;
    }

    delete temp;
    iCount--;

    return value;
}

template <class T>
T Queue<T>::Peek()
{
    if (First == NULL)
    {
        throw runtime_error("Queue is empty");
    }

    return First->data;
}


// ============================================================
// 7. DEQUE
// ============================================================

template <class T>
struct nodeDQ
{
    T data;
    nodeDQ<T>* next;
    nodeDQ<T>* prev;
};

template <class T>
class Deque
{
private:
    nodeDQ<T>* First;
    nodeDQ<T>* Last;
    int iCount;

public:
    Deque();
    ~Deque();

    void Display();
    void DisplayReverse();
    int Count();
    bool IsEmpty();

    void InsertFirst(T No);
    void InsertLast(T No);

    T DeleteFirst();
    T DeleteLast();

    T PeekFirst();
    T PeekLast();
};

template <class T>
Deque<T>::Deque()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
Deque<T>::~Deque()
{
    while (First != NULL)
    {
        DeleteFirst();
    }
}

template <class T>
void Deque<T>::Display()
{
    nodeDQ<T>* temp = First;

    cout << "FRONT -> ";

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }

    cout << "NULL <- REAR\n";
}

template <class T>
void Deque<T>::DisplayReverse()
{
    nodeDQ<T>* temp = Last;

    cout << "REAR -> ";

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->prev;
    }

    cout << "NULL <- FRONT\n";
}

template <class T>
int Deque<T>::Count()
{
    return iCount;
}

template <class T>
bool Deque<T>::IsEmpty()
{
    return First == NULL;
}

template <class T>
void Deque<T>::InsertFirst(T No)
{
    nodeDQ<T>* newn = new nodeDQ<T>;

    newn->data = No;
    newn->prev = NULL;
    newn->next = First;

    if (First == NULL)
    {
        First = Last = newn;
    }
    else
    {
        First->prev = newn;
        First = newn;
    }

    iCount++;
}

template <class T>
void Deque<T>::InsertLast(T No)
{
    nodeDQ<T>* newn = new nodeDQ<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = Last;

    if (Last == NULL)
    {
        First = Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }

    iCount++;
}

template <class T>
T Deque<T>::DeleteFirst()
{
    if (First == NULL)
    {
        throw runtime_error("Deque is empty");
    }

    nodeDQ<T>* temp = First;
    T value = First->data;

    if (First == Last)
    {
        First = Last = NULL;
    }
    else
    {
        First = First->next;
        First->prev = NULL;
    }

    delete temp;
    iCount--;

    return value;
}

template <class T>
T Deque<T>::DeleteLast()
{
    if (Last == NULL)
    {
        throw runtime_error("Deque is empty");
    }

    nodeDQ<T>* temp = Last;
    T value = Last->data;

    if (First == Last)
    {
        First = Last = NULL;
    }
    else
    {
        Last = Last->prev;
        Last->next = NULL;
    }

    delete temp;
    iCount--;

    return value;
}

template <class T>
T Deque<T>::PeekFirst()
{
    if (First == NULL)
    {
        throw runtime_error("Deque is empty");
    }

    return First->data;
}

template <class T>
T Deque<T>::PeekLast()
{
    if (Last == NULL)
    {
        throw runtime_error("Deque is empty");
    }

    return Last->data;
}


// ============================================================
// 8. PRIORITY QUEUE
// ============================================================

template <class T>
struct nodePQ
{
    T data;
    int priority;
    nodePQ<T>* next;
};

template <class T>
class PriorityQueue
{
private:
    nodePQ<T>* First;
    int iCount;

public:
    PriorityQueue();
    ~PriorityQueue();

    void Display();
    int Count();
    bool IsEmpty();

    void EnQueue(T No, int iPriority);
    T DeQueue();
    T Peek();
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    while (First != NULL)
    {
        DeQueue();
    }
}

template <class T>
void PriorityQueue<T>::Display()
{
    nodePQ<T>* temp = First;

    while (temp != NULL)
    {
        cout << "| Data: " << temp->data
             << " | Priority: " << temp->priority << " |\n";

        temp = temp->next;
    }
}

template <class T>
int PriorityQueue<T>::Count()
{
    return iCount;
}

template <class T>
bool PriorityQueue<T>::IsEmpty()
{
    return First == NULL;
}

template <class T>
void PriorityQueue<T>::EnQueue(T No, int iPriority)
{
    nodePQ<T>* newn = new nodePQ<T>;

    newn->data = No;
    newn->priority = iPriority;
    newn->next = NULL;

    if (First == NULL || iPriority < First->priority)
    {
        newn->next = First;
        First = newn;
    }
    else
    {
        nodePQ<T>* temp = First;

        while (temp->next != NULL &&
               temp->next->priority <= iPriority)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }

    iCount++;
}

template <class T>
T PriorityQueue<T>::DeQueue()
{
    if (First == NULL)
    {
        throw runtime_error("Priority Queue is empty");
    }

    nodePQ<T>* temp = First;
    T value = First->data;

    First = First->next;

    delete temp;
    iCount--;

    return value;
}

template <class T>
T PriorityQueue<T>::Peek()
{
    if (First == NULL)
    {
        throw runtime_error("Priority Queue is empty");
    }

    return First->data;
}


// ============================================================
// 9. BINARY SEARCH TREE
// ============================================================

template <class T>
struct nodeBST
{
    T data;
    nodeBST<T>* left;
    nodeBST<T>* right;
};

template <class T>
class BST
{
private:
    nodeBST<T>* Root;
    int iCount;

    void InOrder(nodeBST<T>* temp);
    void PreOrder(nodeBST<T>* temp);
    void PostOrder(nodeBST<T>* temp);

    bool Search(nodeBST<T>* temp, T No);

    void Destroy(nodeBST<T>* temp);

    int Height(nodeBST<T>* temp);
    int CountLeaf(nodeBST<T>* temp);

public:
    BST();
    ~BST();

    void Insert(T No);
    bool Search(T No);

    void InOrder();
    void PreOrder();
    void PostOrder();

    int Count();
    int Height();
    int CountLeaf();
    bool IsEmpty();
};

template <class T>
BST<T>::BST()
{
    Root = NULL;
    iCount = 0;
}

template <class T>
BST<T>::~BST()
{
    Destroy(Root);
}

template <class T>
void BST<T>::Destroy(nodeBST<T>* temp)
{
    if (temp == NULL)
    {
        return;
    }

    Destroy(temp->left);
    Destroy(temp->right);

    delete temp;
}

template <class T>
void BST<T>::Insert(T No)
{
    nodeBST<T>* newn = new nodeBST<T>;

    newn->data = No;
    newn->left = NULL;
    newn->right = NULL;

    if (Root == NULL)
    {
        Root = newn;
        iCount++;
        return;
    }

    nodeBST<T>* temp = Root;

    while (true)
    {
        if (No < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = newn;
                break;
            }

            temp = temp->left;
        }
        else if (No > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = newn;
                break;
            }

            temp = temp->right;
        }
        else
        {
            delete newn;
            return;
        }
    }

    iCount++;
}

template <class T>
bool BST<T>::Search(nodeBST<T>* temp, T No)
{
    if (temp == NULL)
    {
        return false;
    }

    if (temp->data == No)
    {
        return true;
    }

    if (No < temp->data)
    {
        return Search(temp->left, No);
    }

    return Search(temp->right, No);
}

template <class T>
bool BST<T>::Search(T No)
{
    return Search(Root, No);
}

template <class T>
void BST<T>::InOrder(nodeBST<T>* temp)
{
    if (temp == NULL)
    {
        return;
    }

    InOrder(temp->left);
    cout << temp->data << " ";
    InOrder(temp->right);
}

template <class T>
void BST<T>::PreOrder(nodeBST<T>* temp)
{
    if (temp == NULL)
    {
        return;
    }

    cout << temp->data << " ";
    PreOrder(temp->left);
    PreOrder(temp->right);
}

template <class T>
void BST<T>::PostOrder(nodeBST<T>* temp)
{
    if (temp == NULL)
    {
        return;
    }

    PostOrder(temp->left);
    PostOrder(temp->right);
    cout << temp->data << " ";
}

template <class T>
void BST<T>::InOrder()
{
    InOrder(Root);
    cout << "\n";
}

template <class T>
void BST<T>::PreOrder()
{
    PreOrder(Root);
    cout << "\n";
}

template <class T>
void BST<T>::PostOrder()
{
    PostOrder(Root);
    cout << "\n";
}

template <class T>
int BST<T>::Count()
{
    return iCount;
}

template <class T>
int BST<T>::Height(nodeBST<T>* temp)
{
    if (temp == NULL)
    {
        return 0;
    }

    int leftHeight = Height(temp->left);
    int rightHeight = Height(temp->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

template <class T>
int BST<T>::Height()
{
    return Height(Root);
}

template <class T>
int BST<T>::CountLeaf(nodeBST<T>* temp)
{
    if (temp == NULL)
    {
        return 0;
    }

    if (temp->left == NULL && temp->right == NULL)
    {
        return 1;
    }

    return CountLeaf(temp->left) + CountLeaf(temp->right);
}

template <class T>
int BST<T>::CountLeaf()
{
    return CountLeaf(Root);
}

template <class T>
bool BST<T>::IsEmpty()
{
    return Root == NULL;
}


// ============================================================
// 10. GENERIC HASH TABLE
// ============================================================

template <class K, class V>
struct nodeHash
{
    K key;
    V value;
    nodeHash<K, V>* next;
};

template <class K, class V>
class HashTable
{
private:
    static const int TABLE_SIZE = 17;

    nodeHash<K, V>* Table[TABLE_SIZE];
    int iCount;

    int HashFunction(K Key)
    {
        return static_cast<int>(Key) % TABLE_SIZE;
    }

public:
    HashTable();
    ~HashTable();

    void Insert(K Key, V Value);
    bool Search(K Key, V& Value);
    bool Delete(K Key);

    int Count();
    bool IsEmpty();

    void Display();
};

template <class K, class V>
HashTable<K, V>::HashTable()
{
    iCount = 0;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Table[i] = NULL;
    }
}

template <class K, class V>
HashTable<K, V>::~HashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        nodeHash<K, V>* temp = Table[i];

        while (temp != NULL)
        {
            nodeHash<K, V>* target = temp;
            temp = temp->next;
            delete target;
        }

        Table[i] = NULL;
    }
}

template <class K, class V>
void HashTable<K, V>::Insert(K Key, V Value)
{
    int index = HashFunction(Key);

    nodeHash<K, V>* temp = Table[index];

    while (temp != NULL)
    {
        if (temp->key == Key)
        {
            temp->value = Value;
            return;
        }

        temp = temp->next;
    }

    nodeHash<K, V>* newn = new nodeHash<K, V>;

    newn->key = Key;
    newn->value = Value;
    newn->next = Table[index];

    Table[index] = newn;

    iCount++;
}

template <class K, class V>
bool HashTable<K, V>::Search(K Key, V& Value)
{
    int index = HashFunction(Key);

    nodeHash<K, V>* temp = Table[index];

    while (temp != NULL)
    {
        if (temp->key == Key)
        {
            Value = temp->value;
            return true;
        }

        temp = temp->next;
    }

    return false;
}

template <class K, class V>
bool HashTable<K, V>::Delete(K Key)
{
    int index = HashFunction(Key);

    nodeHash<K, V>* temp = Table[index];
    nodeHash<K, V>* prev = NULL;

    while (temp != NULL)
    {
        if (temp->key == Key)
        {
            if (prev == NULL)
            {
                Table[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            delete temp;
            iCount--;

            return true;
        }

        prev = temp;
        temp = temp->next;
    }

    return false;
}

template <class K, class V>
int HashTable<K, V>::Count()
{
    return iCount;
}

template <class K, class V>
bool HashTable<K, V>::IsEmpty()
{
    return iCount == 0;
}

template <class K, class V>
void HashTable<K, V>::Display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "[" << i << "] ";

        nodeHash<K, V>* temp = Table[i];

        while (temp != NULL)
        {
            cout << "(" << temp->key << " : "
                 << temp->value << ") -> ";

            temp = temp->next;
        }

        cout << "NULL\n";
    }
}



/* ============================================================
   11. GENERIC ALGORITHMS
   ============================================================ */

template <class T>
void GenericSwap(T& First, T& Second)
{
    T temp = First;
    First = Second;
    Second = temp;
}

template <class T>
bool GenericSearch(T Arr[], int iSize, T Key)
{
    for (int i = 0; i < iSize; i++)
    {
        if (Arr[i] == Key)
        {
            return true;
        }
    }

    return false;
}

template <class T>
int GenericFrequency(T Arr[], int iSize, T Key)
{
    int iFrequency = 0;

    for (int i = 0; i < iSize; i++)
    {
        if (Arr[i] == Key)
        {
            iFrequency++;
        }
    }

    return iFrequency;
}

template <class T>
bool GenericContains(T Arr[], int iSize, T Key)
{
    return GenericSearch(Arr, iSize, Key);
}

template <class T>
T GenericMax(T Arr[], int iSize)
{
    if (iSize <= 0)
    {
        throw runtime_error("Array is empty");
    }

    T Max = Arr[0];

    for (int i = 1; i < iSize; i++)
    {
        if (Arr[i] > Max)
        {
            Max = Arr[i];
        }
    }

    return Max;
}

template <class T>
T GenericMin(T Arr[], int iSize)
{
    if (iSize <= 0)
    {
        throw runtime_error("Array is empty");
    }

    T Min = Arr[0];

    for (int i = 1; i < iSize; i++)
    {
        if (Arr[i] < Min)
        {
            Min = Arr[i];
        }
    }

    return Min;
}

template <class T>
void GenericReverse(T Arr[], int iSize)
{
    int iStart = 0;
    int iEnd = iSize - 1;

    while (iStart < iEnd)
    {
        GenericSwap(Arr[iStart], Arr[iEnd]);
        iStart++;
        iEnd--;
    }
}

template <class T>
void GenericSort(T Arr[], int iSize)
{
    for (int i = 0; i < iSize - 1; i++)
    {
        for (int j = 0; j < iSize - i - 1; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                GenericSwap(Arr[j], Arr[j + 1]);
            }
        }
    }
}

template <class T>
void GenericDisplay(T Arr[], int iSize)
{
    for (int i = 0; i < iSize; i++)
    {
        cout << Arr[i] << " ";
    }

    cout << "\n";
}


/* ============================================================
   12. GENERIC ITERATOR
   ============================================================ */

template <class T>
class GenericIterator
{
private:
    T* Current;

public:
    GenericIterator(T* Address = NULL)
    {
        Current = Address;
    }

    T& operator*()
    {
        return *Current;
    }

    GenericIterator<T>& operator++()
    {
        Current++;
        return *this;
    }

    bool operator!=(const GenericIterator<T>& Other) const
    {
        return Current != Other.Current;
    }

    bool operator==(const GenericIterator<T>& Other) const
    {
        return Current == Other.Current;
    }
};

template <class T>
void DisplayUsingIterator(T Arr[], int iSize)
{
    GenericIterator<T> Begin(Arr);
    GenericIterator<T> End(Arr + iSize);

    while (Begin != End)
    {
        cout << *Begin << " ";
        ++Begin;
    }

    cout << "\n";
}



/* ============================================================
   13. GENERIC SORTING ALGORITHMS
   ============================================================ */

template <class T>
void BubbleSort(T Arr[], int iSize)
{
    for (int i = 0; i < iSize - 1; i++)
    {
        bool bSwapped = false;

        for (int j = 0; j < iSize - i - 1; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                GenericSwap(Arr[j], Arr[j + 1]);
                bSwapped = true;
            }
        }

        if (!bSwapped)
        {
            break;
        }
    }
}

template <class T>
void SelectionSort(T Arr[], int iSize)
{
    for (int i = 0; i < iSize - 1; i++)
    {
        int iMin = i;

        for (int j = i + 1; j < iSize; j++)
        {
            if (Arr[j] < Arr[iMin])
            {
                iMin = j;
            }
        }

        if (iMin != i)
        {
            GenericSwap(Arr[i], Arr[iMin]);
        }
    }
}

template <class T>
void InsertionSort(T Arr[], int iSize)
{
    for (int i = 1; i < iSize; i++)
    {
        T Key = Arr[i];
        int j = i - 1;

        while (j >= 0 && Arr[j] > Key)
        {
            Arr[j + 1] = Arr[j];
            j--;
        }

        Arr[j + 1] = Key;
    }
}

template <class T>
int Partition(T Arr[], int iLow, int iHigh)
{
    T Pivot = Arr[iHigh];
    int iIndex = iLow - 1;

    for (int j = iLow; j < iHigh; j++)
    {
        if (Arr[j] <= Pivot)
        {
            iIndex++;
            GenericSwap(Arr[iIndex], Arr[j]);
        }
    }

    GenericSwap(Arr[iIndex + 1], Arr[iHigh]);

    return iIndex + 1;
}

template <class T>
void QuickSort(T Arr[], int iLow, int iHigh)
{
    if (iLow < iHigh)
    {
        int iPivot = Partition(Arr, iLow, iHigh);

        QuickSort(Arr, iLow, iPivot - 1);
        QuickSort(Arr, iPivot + 1, iHigh);
    }
}

template <class T>
void Merge(T Arr[], T Temp[], int iLeft, int iMid, int iRight)
{
    int i = iLeft;
    int j = iMid + 1;
    int k = iLeft;

    while (i <= iMid && j <= iRight)
    {
        if (Arr[i] <= Arr[j])
        {
            Temp[k++] = Arr[i++];
        }
        else
        {
            Temp[k++] = Arr[j++];
        }
    }

    while (i <= iMid)
    {
        Temp[k++] = Arr[i++];
    }

    while (j <= iRight)
    {
        Temp[k++] = Arr[j++];
    }

    for (i = iLeft; i <= iRight; i++)
    {
        Arr[i] = Temp[i];
    }
}

template <class T>
void MergeSort(T Arr[], T Temp[], int iLeft, int iRight)
{
    if (iLeft >= iRight)
    {
        return;
    }

    int iMid = (iLeft + iRight) / 2;

    MergeSort(Arr, Temp, iLeft, iMid);
    MergeSort(Arr, Temp, iMid + 1, iRight);
    Merge(Arr, Temp, iLeft, iMid, iRight);
}

template <class T>
void Heapify(T Arr[], int iSize, int iIndex)
{
    int iLargest = iIndex;
    int iLeft = (2 * iIndex) + 1;
    int iRight = (2 * iIndex) + 2;

    if (iLeft < iSize && Arr[iLeft] > Arr[iLargest])
    {
        iLargest = iLeft;
    }

    if (iRight < iSize && Arr[iRight] > Arr[iLargest])
    {
        iLargest = iRight;
    }

    if (iLargest != iIndex)
    {
        GenericSwap(Arr[iIndex], Arr[iLargest]);
        Heapify(Arr, iSize, iLargest);
    }
}

template <class T>
void HeapSort(T Arr[], int iSize)
{
    for (int i = (iSize / 2) - 1; i >= 0; i--)
    {
        Heapify(Arr, iSize, i);
    }

    for (int i = iSize - 1; i > 0; i--)
    {
        GenericSwap(Arr[0], Arr[i]);
        Heapify(Arr, i, 0);
    }
}


/* ============================================================
   14. GENERIC SEARCHING ALGORITHMS
   ============================================================ */

template <class T>
int LinearSearch(T Arr[], int iSize, T Key)
{
    for (int i = 0; i < iSize; i++)
    {
        if (Arr[i] == Key)
        {
            return i;
        }
    }

    return -1;
}

template <class T>
int BinarySearch(T Arr[], int iSize, T Key)
{
    int iLow = 0;
    int iHigh = iSize - 1;

    while (iLow <= iHigh)
    {
        int iMid = iLow + (iHigh - iLow) / 2;

        if (Arr[iMid] == Key)
        {
            return iMid;
        }

        if (Arr[iMid] < Key)
        {
            iLow = iMid + 1;
        }
        else
        {
            iHigh = iMid - 1;
        }
    }

    return -1;
}

template <class T>
int RecursiveBinarySearch(T Arr[], int iLow, int iHigh, T Key)
{
    if (iLow > iHigh)
    {
        return -1;
    }

    int iMid = iLow + (iHigh - iLow) / 2;

    if (Arr[iMid] == Key)
    {
        return iMid;
    }

    if (Arr[iMid] < Key)
    {
        return RecursiveBinarySearch(Arr, iMid + 1, iHigh, Key);
    }

    return RecursiveBinarySearch(Arr, iLow, iMid - 1, Key);
}


// ============================================================
// DEMONSTRATION
// ============================================================

int main()
{
    cout << "============================================\n";
    cout << " GENERIC DATA STRUCTURES LIBRARY\n";
    cout << "============================================\n\n";

    // Singly Linear Linked List
    cout << "----- Singly Linear Linked List -----\n";

    SinglyLL<int> objSL;

    objSL.InsertFirst(30);
    objSL.InsertFirst(20);
    objSL.InsertLast(40);
    objSL.InsertAtPos(25, 2);

    objSL.Display();
    cout << "Count : " << objSL.Count() << "\n";
    cout << "Search 25 : " << (objSL.Search(25) ? "Found" : "Not Found") << "\n";

    objSL.Reverse();
    cout << "After Reverse : ";
    objSL.Display();

    // Doubly Linear Linked List
    cout << "\n----- Doubly Linear Linked List -----\n";

    DoublyLL<string> objDLL;

    objDLL.InsertLast("Java");
    objDLL.InsertLast("C++");
    objDLL.InsertFirst("C");
    objDLL.InsertAtPos("Python", 2);

    objDLL.Display();
    cout << "Reverse : ";
    objDLL.DisplayReverse();

    // Singly Circular Linked List
    cout << "\n----- Singly Circular Linked List -----\n";

    SinglyCL<char> objSCL;

    objSCL.InsertLast('A');
    objSCL.InsertLast('B');
    objSCL.InsertLast('C');
    objSCL.InsertFirst('Z');

    objSCL.Display();
    cout << "Count : " << objSCL.Count() << "\n";

    // Doubly Circular Linked List
    cout << "\n----- Doubly Circular Linked List -----\n";

    DoublyCL<double> objDCL;

    objDCL.InsertLast(10.10);
    objDCL.InsertLast(20.20);
    objDCL.InsertLast(30.30);

    objDCL.Display();
    cout << "Reverse : ";
    objDCL.DisplayReverse();

    // Stack
    cout << "\n----- Stack -----\n";

    Stack<string> objStack;

    objStack.Push("C");
    objStack.Push("C++");
    objStack.Push("Java");

    objStack.Display();
    cout << "Peek : " << objStack.Peek() << "\n";
    cout << "Pop  : " << objStack.Pop() << "\n";

    // Queue
    cout << "\n----- Queue -----\n";

    Queue<int> objQueue;

    objQueue.EnQueue(10);
    objQueue.EnQueue(20);
    objQueue.EnQueue(30);

    objQueue.Display();
    cout << "Peek    : " << objQueue.Peek() << "\n";
    cout << "DeQueue : " << objQueue.DeQueue() << "\n";

    // Deque
    cout << "\n----- Deque -----\n";

    Deque<int> objDeque;

    objDeque.InsertFirst(20);
    objDeque.InsertFirst(10);
    objDeque.InsertLast(30);

    objDeque.Display();
    cout << "DeleteFirst : " << objDeque.DeleteFirst() << "\n";
    cout << "DeleteLast  : " << objDeque.DeleteLast() << "\n";

    // Priority Queue
    cout << "\n----- Priority Queue -----\n";

    PriorityQueue<string> objPQ;

    objPQ.EnQueue("Normal", 3);
    objPQ.EnQueue("High", 1);
    objPQ.EnQueue("Medium", 2);

    objPQ.Display();
    cout << "Peek : " << objPQ.Peek() << "\n";

    // BST
    cout << "\n----- Binary Search Tree -----\n";

    BST<int> objBST;

    objBST.Insert(50);
    objBST.Insert(30);
    objBST.Insert(70);
    objBST.Insert(20);
    objBST.Insert(40);
    objBST.Insert(60);
    objBST.Insert(80);

    cout << "InOrder   : ";
    objBST.InOrder();

    cout << "PreOrder  : ";
    objBST.PreOrder();

    cout << "PostOrder : ";
    objBST.PostOrder();

    cout << "Count     : " << objBST.Count() << "\n";
    cout << "Height    : " << objBST.Height() << "\n";
    cout << "Leaf      : " << objBST.CountLeaf() << "\n";


    // Generic Algorithms
    cout << "\n----- Generic Algorithms -----\n";

    int Numbers[] = {40, 10, 30, 20, 50, 20};
    int iSize = sizeof(Numbers) / sizeof(Numbers[0]);

    cout << "Original : ";
    GenericDisplay(Numbers, iSize);

    cout << "Search 30 : "
         << (GenericSearch(Numbers, iSize, 30) ? "Found" : "Not Found")
         << "\n";

    cout << "Frequency of 20 : "
         << GenericFrequency(Numbers, iSize, 20) << "\n";

    cout << "Max : " << GenericMax(Numbers, iSize) << "\n";
    cout << "Min : " << GenericMin(Numbers, iSize) << "\n";

    GenericSort(Numbers, iSize);

    cout << "Sorted : ";
    GenericDisplay(Numbers, iSize);

    GenericReverse(Numbers, iSize);

    cout << "Reversed : ";
    GenericDisplay(Numbers, iSize);


    // Generic Iterator
    cout << "\n----- Generic Iterator -----\n";

    string Languages[] = {"C", "C++", "Java", "Python"};
    int iLanguageCount =
        sizeof(Languages) / sizeof(Languages[0]);

    cout << "Using Iterator : ";
    DisplayUsingIterator(Languages, iLanguageCount);


    // Sorting and Searching
    cout << "\n----- Sorting and Searching -----\n";

    int SortArray[] = {64, 25, 12, 22, 11};
    int iSortSize = sizeof(SortArray) / sizeof(SortArray[0]);

    cout << "Original : ";
    GenericDisplay(SortArray, iSortSize);

    BubbleSort(SortArray, iSortSize);

    cout << "Bubble Sort : ";
    GenericDisplay(SortArray, iSortSize);

    int SearchArray[] = {10, 20, 30, 40, 50};
    int iSearchSize = sizeof(SearchArray) / sizeof(SearchArray[0]);

    cout << "Linear Search 30 : "
         << LinearSearch(SearchArray, iSearchSize, 30) << "\n";

    cout << "Binary Search 40 : "
         << BinarySearch(SearchArray, iSearchSize, 40) << "\n";

    cout << "Recursive Binary Search 50 : "
         << RecursiveBinarySearch(SearchArray, 0, iSearchSize - 1, 50)
         << "\n";

    // Hash Table
    cout << "\n----- Hash Table -----\n";

    HashTable<int, string> objHash;

    objHash.Insert(101, "Omkar");
    objHash.Insert(102, "Java");
    objHash.Insert(119, "C++");

    objHash.Display();

    string value;

    if (objHash.Search(102, value))
    {
        cout << "Key 102 Value : " << value << "\n";
    }

    cout << "\n============================================\n";
    cout << " End of Demonstration\n";
    cout << "============================================\n";

    return 0;
}
