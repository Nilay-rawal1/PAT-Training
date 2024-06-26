#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to construct the binary tree in level-order fashion
Node* constructTree(int arr[], int n) {
    if (n == 0) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (i < n) {
        Node* current = q.front();
        q.pop();

        if (i < n) {
            current->left = new Node(arr[i++]);
            q.push(current->left);
        }

        if (i < n) {
            current->right = new Node(arr[i++]);
            q.push(current->right);
        }
    }

    return root;
}

// Utility function to check if the tree is a BST
bool isBSTUtil(Node* node, int min, int max) {
    if (node == NULL) {
        return true;
    }
    
    if (node->data < min || node->data > max) {
        return false;
    }

    return isBSTUtil(node->left, min, node->data - 1) && 
           isBSTUtil(node->right, node->data + 1, max);
}

bool isBST(Node* node) {
    return isBSTUtil(node, INT_MIN, INT_MAX);
}

int main() {
    int n;
   
    cin >> n;

    int arr[n];
  
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Node* root = constructTree(arr, n);

    if (isBST(root)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }

    return 0;
}
