#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class IntStack 
{
private:
    Node* top;

public:
    IntStack() : top(nullptr) {}

    ~IntStack() 
    {
        while (top)
        {
            pop();
        }
    }

    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() const 
    {
        if (isEmpty()) 
        {
            throw out_of_range("Stack is empty. Cannot peek.");
        }
        return top->data;
    }

    bool isEmpty() const 
    {
        return top == nullptr;
    }

    void display() const 
    {
        Node* current = top;
        while (current) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    IntStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack elements: ";
    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    cout << "After pop, stack elements: ";
    stack.display();
}
