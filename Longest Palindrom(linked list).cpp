/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

int sameElelements(Node *a, Node *b)
{
    int c=0;
    Node *s = a, *t = b;
    while(s!=NULL && t!=NULL)
    {
        if (s->data==t->data)
        {
            c++;
            s = s->next;
            t = t->next;
        }
    else
      break;
    }
    
    return c;
}

int maxPalindrome(Node *head)
{
   Node *curr = head, *prev = NULL;
   int ans =0;
   while(curr != NULL)
   {
       Node *next = curr->next;
       curr->next = prev;
       
       // for even length
       ans = max( ans , 2*sameElelements(curr, next));
       // odd length
       ans = max( ans , 2*sameElelements(prev, next) + 1);
       
       prev = curr;
       curr = next;
       
   }
   
   return ans;
}
