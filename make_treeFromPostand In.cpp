int search(int in[], int x, int st, int en)
{
    for(int i=st; i<=en; i++) {
        if(in[i]==x)
         return i;

       
    }
      return -1;
}

Node *build(int in[], int post[], int st, int en, int *rootI)
{
    if(st>en)
     return NULL;
     
    Node *head = (Node*) malloc (sizeof(Node));
    head->data = post[rootI];
    head->left = NULL;
    head->right = NULL;
    rootI--;
    
    if(st==en)
    return head;
    
    
    int mid = search (in, head->data, st, en);
    
    head->left = build(in, post, st, mid-1, rootI);
    head->right = build(in, post, mid+1, en, rootI);
    
    return head;
}
Node *buildTree(int in[], int post[], int n)
{
    // Yo
  int pi = n-1;
    return build(in, post, 0, n-1, &pi);
}