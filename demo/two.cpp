#include "two.h"
#include <iostream>
void Stack::push(int value)
{
    Node* pNode = new Node(value);
    pNode->next = top;
    top = pNode;
}

void Stack::pop()
{
    if (isEmpty()) return;
    else {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int Stack::peek()
{
    if (isEmpty())
        return -1;
    else {
        return top->data;
    }
}

bool Stack::isEmpty()
{
    return top == nullptr;
}

void Stack::display()
{
    Node* pNode = top;
    while(pNode)
    {
        std::cout << pNode->data << " ";
        pNode = pNode->next;
    }
    std::cout << std::endl;
}

Stack::~Stack()
{
    while(top)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    // st.pop();
    st.display();
    std::cout << st.peek() << std::endl;
    std::cout << st.isEmpty() << std::endl;
    
    return 0;
}