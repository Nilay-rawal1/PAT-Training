#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

// Function to insert a new node at the end of the list
void insertAtEnd(Node*& head, int val) {
    if (head == NULL) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(val);
}

// Function to reverse k nodes in the list
Node* reverseKGroup(Node* head, int k) {
    if (!head || k == 1) return head;
    
    Node* dummy = new Node(0);
    dummy->next = head;
    
    Node* curr = dummy;
    Node* nex = dummy;
    Node* pre = dummy;
    int count = 0;
    
    // Count the number of nodes in the list
    while (curr->next) {
        curr = curr->next;
        count++;
    }
    
    while (count >= k) {
        curr = pre->next;
        nex = curr->next;
        for (int i = 1; i < k; i++) {
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr;
        count -= k;
    }
    
    return dummy->next;
}

// Function to print the list
void printList(Node* head) {
    while (head) {
        cout << head->val;
        head = head->next;
        if (head) cout << endl;
    }
    cout << endl;
}

int main() {
    int x;
    Node* head = NULL;

    // Read input and form the linked list
    while (cin >> x && x != -1) {
        insertAtEnd(head, x);
    }
    cout<<endl;
    int k;
    cin >> k;

    // Reverse every k nodes in the linked list
    head = reverseKGroup(head, k);

    // Print the modified list
    printList(head);

    return 0;
}
