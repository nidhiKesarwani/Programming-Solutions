/* node structure  used in the program
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/*  Function which returns the  root of 
    the constructed binary tree. */
    
Node *createTree(int parent[], int n)
{
// Your code here
  int ro;
  for(int i =0; i<n; i++)
    if (parent[i]==-1)
      {
          ro = i;
          break;
      }
      
     
  Node *head = new Node(ro);    
  queue<Node *> Q;
  Q.push(head);
  
  while(!Q.empty())
    {
        Node *p = Q.front(); Q.pop();
        int l = -1, r = -1;
        int a = p->data;
        for(int i =0; i<n; i++)
          {
              if (parent[i]==a)
               {
                   if (l==-1)
                    {
                         l = i;
                         parent[i]=-1;
                    }
                   else
                     {
                         parent[i]=-1;
                         r = i;
                         break;
                     }
               }
          }
        if (l!=-1)
         {
           Node *h = new Node(l);
           p->left = h;
           Q.push(h);
         }
       if (r!=-1)
         {
           Node *h = new Node(r);
           p->right = h;
           Q.push(h);
         }  
    }
    
    return head;
}
