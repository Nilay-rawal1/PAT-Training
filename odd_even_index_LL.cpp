#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to rearrange the list by grouping odd-indexed nodes first and then even-indexed nodes.
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) return nullptr;
    
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;
    
    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = evenHead;
    return head;
}

// Function to print the linked list.
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Input the number of elements in the linked list
    int n;
    
    cin >> n;

    if (n == 0) {
        cout << "The linked list is empty." << endl;
        return 0;
    }

    // Input the elements of the linked list
  
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Rearrange the list by grouping odd and even indexed nodes
    head = oddEvenList(head);

    // Print the reordered list
    
    printList(head);

    // Cleanup
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
