#include <iostream>
struct ElemList1
{
    int data;
    ElemList1 *next;
};

void display(ElemList1 *head)
{
    while (head != NULL)
    {
        std::cout << head->data;
        head = head->next;
    }
}
void pushFront(ElemList1 **head, int val)
{
    ElemList1 *p = new ElemList1;
    p->data = val;
    p->next = *head;
    *head = p;
}
void pushFront1(ElemList1 *& head, int val)
{
    ElemList1 *p = new ElemList1;
    p->data = val;
    p->next = *head;
    head = p;
}
void popFront(ElemList1 *& head)
{
    if (head == NULL)
    {
        return;
    }
    ElemList1 *p = head;
    head = head->next;
    delete p;
}
ElemList1 *find(ElemList1 * head, int val)
{
    while (head != NULL)
    {
        if (head->data == val)
            return head;
        head = head->next;
    }
    return NULL;
}
/*
 ^ listy jednokierunkowe
*/

struct ElemList2
{
    int data;
    ElemList1 *next, *prev;
};
void pushFront(ElemList2 *& head, int val)
{
    ElemList2 *p = new ElemList2;
    p->data = val;
    p->prev = NULL;

    p->next = head;
    if(head != NULL)
        head->prev = p;

    head = p;
}
void popFront(ElemList2 *& head)
{
    if (head == NULL)
        return;
    ElemList2 *p = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete p;
}
/*
^ listy dwukierunkowe
*/


int main()
{
    ElemList1 *h1 = NULL;
    std::cout << "Hello World";
}