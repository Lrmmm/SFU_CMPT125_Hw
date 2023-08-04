#include<iostream>
#include "LinkedList.h"
#include "Stack.h"
int main()
{

    std::cout << "Test LinkedList ================================" << std::endl;
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

    std::cout << "Test Stack ================================" << std::endl;
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    st.display();
    std::cout << st.peek() << std::endl;
    std::cout << st.isEmpty() << std::endl;
    return 0;
}