#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}  // Constructor to initialize the node
};

// Function to reverse the linked list iteratively
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;  // Save the next node
        curr->next = prev;  // Reverse the current node's pointer
        prev = curr;        // Move prev and curr one step forward
        curr = next;
    }
    return prev;  // prev will be the new head of the reversed list
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}   This approach reverses the list in-place with a time complexity of O(n) and space complexity of O(1).







