/*This is a function problem.You only need to complete the function given below*/
/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/
/*  Function which returns the  root of 
    the flattened linked list. */
    
Node *merge(Node *a, Node *b)
{
  if (a==NULL)
   return b;
   
  if (b==NULL)
    return a;
  Node *res = NULL;  
    if (a->data < b->data)
      {
          a->bottom = merge(a->bottom, b);
          return a;
      }
    else
     {
         b->bottom = merge(a, b->bottom);
         return b;
     }
}
Node *flatten(Node *root)
{
   // Your code here
   Node *a, *b;
   Node *res=NULL;
   a = root;
   b = root->next;
   // merge result to all linked lists one by one
   while(a!=NULL)
    {
        res = merge(res, a);
        a = b;
        if(a!=NULL)
         b = a->next;
    }
    
  return res;
}
