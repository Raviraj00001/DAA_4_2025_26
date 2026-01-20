//double linked list cpp file
#include <iostream> 
using namespace std;    
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};      
class DoubleLinkedList {
private:            
    Node* head;
    Node* tail; 
public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }   
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    //insert at head
    void insertAtHead(int val) {    
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    

    ~DoubleLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};


int main() {
    DoubleLinkedList dll;


    dll.append(10);

    dll.append(20);
    dll.append(30);
    dll.display(); // Output: 10 20 30
    return 0;
}