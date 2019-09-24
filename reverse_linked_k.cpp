
#include<bits/stdc++.h> 
using namespace std; 

struct node 
{ 
	int data; 
	struct node* next; 
	 
}; 

node* insert(int data, node *head)
{
    node *p = new node;
    p->data = data;
    p->next = NULL;
    
   if(head==NULL)
    head = p;
   else
   {
   	 node *temp = head;
    while(temp->next!=NULL)
     {
         temp = temp->next;
     }

     temp->next = p;
   }
   return head;
  // cout<<"inserted"<<endl;
}

node *reverse(node *head, int k)
{
    bool change = true;
    node *temp = head;
    node *prev = NULL;
    node *curr, *next;
    curr = head;
    while(temp!=NULL)
    {
        if(change)
        {
          int c=1;
          while(c<=k && curr!=NULL)
          {
              next = curr->next;
              curr->next = prev;
              prev = curr;
              curr = next;
              temp = curr;
              c++;
          }
          change = false;
        }
        else
        {
           int c =1;
           while(c<=k && curr!=NULL)
           {
               prev = curr;
               curr = curr->next;
               temp = curr;
               c++;
           } 
           change = true; 
        }
        
    }
}

void print(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
    	//cout<<"print";
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	node *head;
    head = NULL;

    int n, k;
    cin>>n>>k;

    while(n--)
     {
         int t;
     cin>>t;

     head = insert(t, head);
     }
    //print (head);
    head = reverse(head, k);
	return 0; 
} 
