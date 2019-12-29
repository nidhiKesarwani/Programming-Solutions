/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int m=0, n=0;
    Node *temp = head1;
    while(temp)
    {
        n++;
        temp = temp->next;
    }
    
    temp = head2;
    
    while(temp)
    {
        m++;
        temp = temp->next;
    }
    Node *p,*q;
    
    if(n>m)
    {
        int d = n-m;
        p = head1;
        while(d--)
         p = p->next;
         
        q = head2;
    }
    else
    {
        int d = m-n;
        p = head1;
        q = head2;
         while(d--)
          q = q->next;
    }
    
    while(p!=q)
    {
        p=p->next;
        q=q->next;
    }
    
    return p->data;
}
