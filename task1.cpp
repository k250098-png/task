#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int sumArray(int arr[], int n) {
    if (n <= 0) return 0;
    return arr[n - 1] + sumArray(arr, n - 1);
}

int findMax(int A[], int n) {
    if (n == 1) return A[0];
    int maxOfRest = findMax(A, n - 1);
    return (A[n - 1] > maxOfRest) ? A[n - 1] : maxOfRest;
}

bool isPalindromeHelper(const string& str, int start, int end) {
    if (start >= end) return true;
    if (str[start] != str[end]) return false;
    return isPalindromeHelper(str, start + 1, end - 1);
}

bool isPalindrome(const string& str) {
    if (str.empty()) return true;
    return isPalindromeHelper(str, 0, str.length() - 1);
}

void reverse(int arr[], int start, int end) {
    if (start >= end) return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverse(arr, start + 1, end - 1);
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    displayList(head->next);
}

int searchList(Node* head, int value, int currentIndex = 0) {
    if (head == nullptr) return -1;
    if (head->data == value) return currentIndex;
    return searchList(head->next, value, currentIndex + 1);
}

int main() {
    int arr[] = {4, 15, 7, 22, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "(a) Sum of array elements: " << sumArray(arr, n) << endl;
    cout << "(b) Maximum element in array: " << findMax(arr, n) << endl;
    
    string str1 = "racecar";
    string str2 = "hello";
    cout << "(c) isPalindrome(\"" << str1 << "\"): " << (isPalindrome(str1) ? "true" : "false") << endl;
    cout << "(c) isPalindrome(\"" << str2 << "\"): " << (isPalindrome(str2) ? "true" : "false") << endl;
    
    cout << "(d) Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    reverse(arr, 0, n - 1);
    
    cout << "    Reversed array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    
    cout << "(e) Linked List elements: ";
    displayList(head);
    
    int target1 = 30;
    int target2 = 100;
    cout << "(f) Index of " << target1 << ": " << searchList(head, target1) << endl;
    cout << "(f) Index of " << target2 << ": " << searchList(head, target2) << endl;
    
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
