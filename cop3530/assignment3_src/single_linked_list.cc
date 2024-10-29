#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    
public:
    // Constructor
    LinkedList() : head(nullptr) {}
    
    // Create n nodes
    void createNodes(int n) {
        if (n <= 0) return;
        
        cout << "Enter " << n << " values:" << endl;
        int value;
        
        // Create first node
        cin >> value;
        head = new Node(value);
        Node* current = head;
        
        // Create remaining n-1 nodes
        for (int i = 1; i < n; i++) {
            cin >> value;
            current->next = new Node(value);
            current = current->next;
        }
    }
    
    // Insert in the middle at position pos (1-based indexing)
    void insertMiddle(int value, int pos) {
        if (pos <= 0) {
            cout << "Invalid position" << endl;
            return;
        }
        
        Node* newNode = new Node(value);
        
        // Insert at beginning if pos is 1
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        
        // Traverse to position - 1
        Node* current = head;
        for (int i = 1; i < pos - 1 && current != nullptr; i++) {
            current = current->next;
        }
        
        if (current == nullptr) {
            cout << "Position exceeds list length" << endl;
            delete newNode;
            return;
        }
        
        // Insert node
        newNode->next = current->next;
        current->next = newNode;
    }
    
    // Delete from middle at position pos (1-based indexing)
    void deleteMiddle(int pos) {
        if (head == nullptr || pos <= 0) {
            cout << "Invalid position or empty list" << endl;
            return;
        }
        
        // Delete first node if pos is 1
        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        // Traverse to position - 1
        Node* current = head;
        for (int i = 1; i < pos - 1 && current != nullptr && current->next != nullptr; i++) {
            current = current->next;
        }
        
        if (current == nullptr || current->next == nullptr) {
            cout << "Position exceeds list length" << endl;
            return;
        }
        
        // Delete node
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    
    // Display the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    
    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    
    // Example usage
    cout << "Creating nodes:" << endl;
    list.createNodes(3);  // Create 3 nodes
    
    cout << "Initial list:" << endl;
    list.display();
    
    cout << "Inserting 42 at position 2:" << endl;
    list.insertMiddle(42, 2);
    list.display();
    
    cout << "Deleting node at position 2:" << endl;
    list.deleteMiddle(2);
    list.display();
    
    return 0;
}
