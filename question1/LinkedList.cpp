#include "LinkedList.h"
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