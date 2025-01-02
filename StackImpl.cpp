#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node* next;  // Correctly matching the 'Node' case
    Node(T val) {
        data = val;
        next = NULL;
    }
};

template<class T>
class Stack {
    Node<T>* head;  // Using a pointer to a Node
public:
    stack() {  // Constructor name matches the class name (lowercase)
        head = NULL;
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);  // Create new node
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop() {
        if (head == NULL) {
            cout << "Stack is empty.\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T top() {
        if (head == NULL) {
            cout << "Stack is empty.\n";
            return -1;  // Assuming stack holds integers
        }
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    stack<int> s;  // Create stack of integers
    s.push(3);
    s.push(2);
    s.push(1);
    
    while (!s.empty()) {
        cout << s.top() << " ";  // Print top element
        s.pop();  // Remove top element
    }
    
    cout << endl;
    return 0;
}
