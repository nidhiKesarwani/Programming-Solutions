/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Your task is to complete the function this function
// function should return the size of the loop
int countNodesinLoop(struct Node *head)
{
      // your code here
    Node *slow, *fast;
    slow = head, fast = head;
    int isLoop=0;
    while(slow && fast && fast->next)
    {
         slow = slow->next;
         fast = fast->next->next;
        if(slow==fast)
          {
             isLoop=1;
             break;
          }
    }
    
    if(isLoop==0)
      return 0;
    
    int l =1;
    slow = slow->next;
    while(slow!=fast)
      {
           slow = slow->next;
           l++;
      }
     return l;
}
