#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int val;
    Node* next;
    
    Node(int value) : val(value), next(nullptr) {}  // Constructor to initialize the node
};

// Function to remove the nth node from the end of the list
Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = new Node(0); // Create a dummy node to handle edge cases
    dummy->next = head;
    
    Node* fast = dummy;
    Node* slow = dummy;
    
    // Move fast pointer n steps ahead
    for (int i = 0; i <= n; ++i) {
        fast = fast->next;
    }
    
    // Move both fast and slow pointers until fast reaches the end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // Remove the nth node from the end
    slow->next = slow->next->next;
    
    return dummy->next;  // Return the head of the modified list
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    // Remove the 2nd node from the end (should remove node with value 3)
    head = removeNthFromEnd(head, 2);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
