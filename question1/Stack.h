class Stack
{
private:
    struct Node
    {
        int data;
        Node *next;
        /* This allows you to make a Node using
        Node *nodeName(val) and have both the data
        initialized to val and the node pointer
        initialized to nullptr */
        Node(int val) : data(val), next(nullptr) {}
    };
    Node *top;

public:
    Stack() : top(nullptr) {}
    // Push an element onto the stack
    void push(int value);
    // Pop the top element from the stack
    void pop();
    // Get the value of the top element without removing it
    int peek();
    // Check if the stack is empty
    bool isEmpty();
    // Display the stack elements
    void display();
    // Destructor to free memory
    ~Stack();
};