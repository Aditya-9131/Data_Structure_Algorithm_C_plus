#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        next = NULL;  // Corrected 'Null' to 'NULL'
    }    
};

class List { 
public:        // Corrected class name to match the destructor's definition
    Node* head;
    Node* tail;
    List() {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void pop_front() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
};
void printList(Node*head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}
bool isCycle(Node*head){
   Node*slow = head;
   Node*fast = head;
   while(fast!=NULL && fast->next != NULL ){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
        cout <<"cycle exist\n";
        return true;
    }
   }
   cout<<"cycle doesn,t exist\n";
   return false;
}
void removeCycle(Node*head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;
    while(fast!=NULL && fast->next!= NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout<<"cycle exist\n";
            isCycle = true;
            break;
        }
    }
    if(!isCycle){
        cout<<"cycle doesn't exist\n";
        return;
    }
    slow = head;
    if(slow == fast){
      while(fast->next != slow){
        fast = fast->next;
      }
      fast->next = NULL;
    }else{
        Node*prev = fast;
        while(slow!=fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
    }
}
Node*reverse(Node*head){
    Node*prev = NULL;
    Node*curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}
void zigZagLL(Node*head){
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = right;

    while(left != NULL && right != NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;
        tail = right;

        left = nextLeft;
        right = nextRight;
    }
    if(right != NULL){
        tail->next = right;
    }
    return head;
}
int main() {
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next = ll.head;
    removeCycle(ll.head);
    printList(ll.head);
    return 0;
}
