#include "one.h"
#include <stdlib.h>
#include <iostream>
LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    while(head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertFront(int val)
{
    Node* pNode = new Node(val);
    pNode->next = head;
    head = pNode;
}

void LinkedList::insertBack(int val)
{
    Node* pNode = new Node(val);
    Node* pBack = head;
    while(pBack->next)
        pBack = pBack->next;
    
    if (!pBack){
        head = pNode;
    }
    else{
        pBack->next = pNode;
    }
}

void LinkedList::removeFront()
{
    if (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::removeBack()
{
    if (!head)
    {
        return;
    }
    else if(!head->next)
    {
        delete head;
        head = nullptr;
    }
    else{
        Node* pBackPre = head;
        Node* pBack = head->next;
        while(pBack->next)
        {
            pBackPre = pBack;
            pBack = pBack->next;
        }

        delete pBack;
        pBackPre->next = nullptr;
    }
}

bool LinkedList::isEmpty() const
{
    return head == nullptr;
}

void LinkedList::printList() const
{
    Node* pNode = head;
    while(pNode)
    {
        std::cout << pNode->data << " ";
        pNode = pNode->next;
    }
    std::cout << std::endl;
}

int LinkedList::length() const
{
    int nLength = 0;
    Node* pNode = head;
    while(pNode){
        nLength++;
        pNode = pNode->next;
    }
    return nLength;
}

int main()
{
    LinkedList list;
    list.insertFront(1);
    list.insertFront(2);
    list.insertFront(3);
    list.insertFront(4);
    list.insertFront(5);
    list.insertBack(6);
    list.insertBack(7);
    list.insertBack(8);
    list.insertBack(9);
    list.insertFront(10);
    list.printList();
    std::cout << list.length() << std::endl;

    list.removeBack();
    list.removeBack();
    list.removeBack();
    list.removeBack();
    list.removeBack();
    list.removeBack();
    list.removeBack();
    list.removeBack();
    list.removeBack();
    // list.removeBack();
    list.removeBack();
    // list.removeBack();

    // list.removeFront();
    // list.removeFront();
    // list.removeFront();
    // list.removeFront();
    // list.removeFront();
    // list.removeFront();
    // list.removeFront();
    // list.removeFront();
    // list.removeFront();
    list.printList();
    std::cout << list.length() << std::endl;
    std::cout << list.isEmpty() << std::endl;

    return 0;
}