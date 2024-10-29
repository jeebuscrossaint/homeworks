#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    // Constructor
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    // Create n nodes
    void createNodes(int n) {
        if (n <= 0) return;
        
        cout << "Enter " << n << " values:" << endl;
        int value;
        
        // Create first node
        cin >> value;
        head = new Node(value);
        tail = head;
        
        // Create remaining n-1 nodes
        for (int i = 1; i < n; i++) {
            cin >> value;
            Node* newNode = new Node(value);
            
            // Set up links
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            // If list is empty
            head = tail = newNode;
        } else {
            // Insert before current head
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    // Delete from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if (head == tail) {
            // Only one node
            delete head;
            head = tail = nullptr;
            return;
        }
        
        // More than one node
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    
    // Display the list forward
    void displayForward() {
        Node* current = head;
        cout << "NULL <-> ";
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    
    // Display the list backward
    void displayBackward() {
        Node* current = tail;
        cout << "NULL <-> ";
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }
    
    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    DoublyLinkedList list;
    
    // Example usage
    cout << "Creating nodes:" << endl;
    list.createNodes(3);  // Create 3 nodes
    
    cout << "Initial list (forward):" << endl;
    list.displayForward();
    
    cout << "Initial list (backward):" << endl;
    list.displayBackward();
    
    cout << "Inserting 42 at beginning:" << endl;
    list.insertAtBeginning(42);
    list.displayForward();
    
    cout << "Deleting from end:" << endl;
    list.deleteFromEnd();
    list.displayForward();
    
    return 0;
}
