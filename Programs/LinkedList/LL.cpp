#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert Node at beginning Linked List

void InsertAtHead(node* &head,int val)
{
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }

    n->next = head;
    head = n;
}

   // Insertion of Node at End of list

void InsertAttail(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// Delete First Node of the Linked List

void deletefirstNode(node* &head)
{
    node* todelete = head;
    head = head->next;
    delete todelete;
}

 // Delete any Particular node with given Value

void deletion(node* &head, int val)
{
    if(head == NULL)
    {
        return;
    }
    if(head->next == NULL)
    {
        deletefirstNode(head);
        return;
    }
    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

// Function to delete nth node from the End of Linked List

node* removeNthFromEnd(node* head, int n) {
       node* fast = head, *slow = head;
        for(int i = 1; i <= n; i++){
            fast = fast->next;
        }
        if(fast == NULL){
            return head->next;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
}

// Function to reverse the linked list

node* reverselist(node* &head)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

// To Display the list or Traversing of list

void display(node* head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

// Search For an Element in the linked List

bool searching(node *head,int key){
    node* temp;
    temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;

}

/* code for sorting a linked list
   input : 4->2->1->3
   output : 1->2->3->4
*/
 node* sortList(node* head) {
        if(head == NULL){
            return NULL;
        }
        node* temp = head;
        vector<int> ans;
        while(temp != NULL){
            ans.push_back(temp->data);
            temp = temp->next;
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        sort(ans.begin(),ans.end());
        cout<<"\n";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        node* newHead = new node(ans[0]);
        node* finl = newHead;
        for(int i=1;i<ans.size();i++){
            finl->next = new node(ans[i]);
            finl = finl->next;
        }
        return newHead;
    }

/*
    Intersection of two linked list below
    Input:
        L1 = 1->2->3->4->6
        L2 = 2->4->6->8
    Output: 2 4 6

*/

node* intersection(node* temp1,node* temp2){
   
    node* dummyhead = new node(0);
    node* head = dummyhead;


    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data == temp2->data){
            head->next = new node(temp1->data);
            head = head->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data)
            temp1 = temp1->next;
        else
            temp2 = temp2->next;
    }
    return dummyhead->next;
}

/* Reverse linked list in k-size */  

node* ReverseinKsize(node* head,int k){
    if(head == NULL){
        return NULL;
    }
    node* curr = head;
    node* prev = NULL;
    node* nextPtr = NULL;

    int count = 0;

    while(curr != NULL && count < k){
        nextPtr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPtr;
        count++;
    }

    if(nextPtr != NULL){
        head->next = ReverseinKsize(nextPtr,k);
    }
    return prev;
}
// MAIN FUNCTION

int main()
{
    node* head = NULL;
    InsertAttail(head,4);
    InsertAttail(head,2);
    InsertAttail(head,1);
    InsertAttail(head,3);
    display(head);
    node* ans = sortList(head);
    display(ans);
    // InsertAtHead(head,7);
    // display(head);
    // cout<<searching(head,4);
    cout<<endl;
    // node* newhead = reverselist(head);
    // display(newhead);
   /* deletion(head,3);
    display(head);
    deletefirstNode(head);
    display(head); */

}