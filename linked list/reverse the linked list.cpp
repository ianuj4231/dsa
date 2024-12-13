#include <iostream>
using namespace std;

// Define a singly linked list node structure
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {} // Constructor to initialize node
};

// Function to reverse a linked list
ListNode* reverseLinkedList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* preNode = nullptr;  // Initialize previous node to nullptr
    ListNode* currNode = head;    // Start with the head node

    while (currNode != nullptr) {
        ListNode* nextNode = currNode->next; // Save the next node
        currNode->next = preNode;           // Reverse the link
        preNode = currNode;                 // Move preNode to currNode
        currNode = nextNode;                // Move currNode to nextNode
    }

    return preNode; // New head of the reversed list
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function for testing
int main() {
    // Create a linked list: 4 -> 8 -> 15 -> 16 -> NULL
    ListNode* head = new ListNode(4);
    head->next = new ListNode(8);
    head->next->next = new ListNode(15);
    head->next->next->next = new ListNode(16);

    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
  // o-1 space and o-n time
