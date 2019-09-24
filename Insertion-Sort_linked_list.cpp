struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Solution::insertionSortList(ListNode* A) {
    
    ListNode *tmp, *p, *q;
    p = A, q = A->next;
    
    while(q!=NULL)
    {
        if (A->val > q->val)
        {
            p->next = q->next;
            q->next = A;
            A = q;
            q = p->next;
        }
        else
        {
            tmp = A;
            while(tmp->next->val <= q->val && tmp->next!=q)
             tmp = tmp->next;
             
            if (tmp->next != q)
             {
                 p->next = q->next;
                 q->next = tmp->next;
                 
                 tmp->next = q;
                 q = p->next;
             }
            else
             {
                 p = q;
                 q =q->next;
             }
        }
    }
    
    return A;
}
