#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void displayList(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    
    cout << head->data << " ";
    displayList(head->next);
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    
    cout << "Linked List elements: ";
    displayList(head);
    
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
