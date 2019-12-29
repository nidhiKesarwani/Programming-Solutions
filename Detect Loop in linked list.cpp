/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
*/
int detectloop(Node *head) {
    
    // your code here
    Node *slow, *fast;
    slow = head, fast = head;
    
    while(slow && fast && fast->next)
    {
         slow = slow->next;
         fast = fast->next->next;
        if(slow==fast) 
         //checking this before changing the pointers will always return true as at the 
         //very begining both are at head
          {
              return 1;
          }
       
    }
    return 0;
}
