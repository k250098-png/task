#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int searchList(Node* head, int value, int currentIndex = 0) {
    if (head == nullptr) return -1;
    if (head->data == value) return currentIndex;
    return searchList(head->next, value, currentIndex + 1);
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    
    int target1 = 30;
    int target2 = 100;
    
    cout << "Index of " << target1 << ": " << searchList(head, target1) << endl;
    cout << "Index of " << target2 << ": " << searchList(head, target2) << endl;
    
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
