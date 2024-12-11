#include <iostream>
#include <unordered_map>
using namespace std;

// Doubly Linked List Node
struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    
    // Remove a node from the linked list
    void remove(Node* node) {
        node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
    }
    
    // Add a node to the front of the linked list
    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        if (head->next) head->next->prev = node;
        head->next = node;
    }
    
    // Remove the least recently used node (from the back)
    void removeFromEnd() {
        if (tail->prev) {
            remove(tail->prev);
            cache.erase(tail->prev->key);
        }
    }

public:
    // Constructor
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);  // Dummy head
        tail = new Node(0, 0);  // Dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    // Get the value associated with the key
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;  // Key not found
        }
        Node* node = cache[key];
        remove(node);
        addToFront(node);
        return node->value;
    }
    
    // Put a key-value pair into the cache
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update value and move it to the front
            Node* node = cache[key];
            node->value = value;
            remove(node);
            addToFront(node);
        } else {
            // Key does not exist, insert new node
            if (cache.size() >= capacity) {
                removeFromEnd();  // Remove the least recently used item
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToFront(newNode);
        }
    }
};

int main() {
    LRUCache cache(2);
    
    // Sample operations
    cache.put(1, 10);
    cout << "Get 1: " << cache.get(1) << endl;  // returns 10
    cache.put(2, 20);
    cout << "Get 2: " << cache.get(2) << endl;  // returns 20
    cache.put(3, 30);
    cout << "Get 1: " << cache.get(1) << endl;  // returns -1 (evicted)
    cout << "Get 2: " << cache.get(2) << endl;  // returns 20
    cout << "Get 3: " << cache.get(3) << endl;  // returns 30

    return 0;
}


/*

Time Complexity:
get(key): O(1) because accessing a hash map and moving the node to the front of the list takes constant time.
put(key, value): O(1) because inserting into the hash map and managing the doubly linked list (removing and adding nodes) is done in constant time.
Space Complexity:
O(capacity): The space is used for storing the cache, which contains at most capacity nodes.
*/
