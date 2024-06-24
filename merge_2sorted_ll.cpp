    #include<bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
   

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* p1=head1,*p2=head2;
    Node* dummy =new Node(-1);
    Node* h =dummy;
    while(p1!=NULL && p2!=NULL){
        if(p1->data<=p2->data){
            h->next=p1;
            p1=p1->next;
            
        }
        else{
            h->next=p2;
            p2=p2->next;
        }
        h=h->next;
    }
    if(p1!=NULL){
        h->next=p1;
        
    }
    if(p2!=NULL){
        h->next=p2;
        
    }
    return dummy->next;
}  