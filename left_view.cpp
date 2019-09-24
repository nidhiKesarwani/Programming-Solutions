#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void leftView(Node *root)
{
   // Your code here
   int level=-1;
   queue <pair<Node *, int> > q;
   q.push(make_pair(root, 0));
   while(!q.empty())
   {
       Node *p = q.front().first;
       int l = q.front().second;

       if(l>level)
       {
           level++;
           cout<<p->data<<" ";
       }

       if(p->left)
        q.push(make_pair(p->left, l+1));

    if(p->right)
    q.push(make_pair(p->right, l+1));
   }
}