 struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 
ListNode*  mergeInPlaceUtil(ListNode *a, ListNode *b)
{
   ListNode *cur1, *next1, *cur2, *next2;
   if (a->next==NULL)
     {
         a->next = b;
         return a;
     }
   cur1 = a, next1 = a->next;
   cur2 = b, next2 = b->next;
   
   while( next1!=NULL && cur2!=NULL)
   {
       if (cur2->val >= cur1->val && cur2->val <= next1->val )
       {
           next2 = cur2->next;
           cur1->next = cur2;
           cur2->next = next1;
           
           cur1 = cur2;
           cur2 = next2;
           
       }
       else
         {
             if (next1->next==NULL)
               {
                   next1->next = cur2;
                   return a;
               }
             else
             {
                 cur1 = cur1->next;
                 next1= next1->next;
             }
         }
   }
   
   return a;
}
// merge in constant space

ListNode* mergeInPlace(ListNode *a, ListNode *b)
{
     if(a==NULL)
      return b;
      
     if (b==NULL)
      return a;
      
     if (a->val < b->val)
        return mergeInPlaceUtil(a, b);
     else
         return mergeInPlaceUtil(b, a);
}


// merge in O(n) space
ListNode* merge(ListNode *a, ListNode *b)
{
    if(a==NULL)
      return b;
      
     if (b==NULL)
      return a;
      ListNode* result = NULL;  
    if (a->val <= b->val)
     {
         result = a;
         result->next = merge(a->next, b);
         
     }
    else
     {
         result = b;
         result->next = merge(a, b->next);
        
     }
     return result;
}

ListNode* Solution::sortList(ListNode* A) {
    
    if (A==NULL || A->next==NULL)
      return A;
     // Partition starts 
     ListNode *a, *b;
     a = A, b = A->next;
     
     while(a!=NULL && b!=NULL)
     {
         b = b->next;
         if (b!=NULL)
           {
               a = a->next;
               b = b->next;
           }
     }
     
    b = a->next;
    a->next = NULL;
    
    a = A;
    
   // Partition ends
   
   a = sortList(a);
   b = sortList(b);
   
   A = mergeInPlace(a, b);
   
   return A;
}
