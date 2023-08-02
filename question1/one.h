class LinkedList
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
    Node *head;

public:
    LinkedList();
    ~LinkedList();
    void insertFront(int val);
    void insertBack(int val);
    void removeFront();
    void removeBack();
    bool isEmpty() const;
    void printList() const;
    int length() const;
};