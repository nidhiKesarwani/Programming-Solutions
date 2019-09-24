#include <bits/stdc++.h>
using namespace std;

struct trie{
    int pref;
    unordered_map<char, trie*> children;
    bool isEnd;
};

trie* getNode()
{
    trie *t = new trie;
    t->isEnd = false;
    t->pref  = 0;
    return t;
}

void insert(trie *t, string s)
{
    trie *cur = t;
    for(char c : s)
    {
      if (!cur->children[c])
        cur->children[c] = getNode();

     cur->children[c]->pref++;
     cur = cur->children[c];
    }
    cur->isEnd = true;
}

void deletString(trie *t, string s)
{
    trie * curr = head;
    for(char c : s)
     {
         cur->children[c]->pref--;
         cur = cur->children[c];
     }
     if (cur->pref==0)
       cur->isEnd = false;
}
string findLongestPrefixofAll(trie *head, int n)
{
    string  s = "";
    trie *cur = head;
    while(cur!=nullptr)
    {
        trie *temp = nullptr;
        for(char c = 'a'; c<='z'; c++)
          if (cur->children[c]!=nullptr && cur->children[c]->pref == n)
          {
              temp = cur->children[c];
              s+=c;
              break;
          }
          cur = temp;
    }
    return s;
}



int main()
{
    trie *head = getNode();
     for(string s : A)
       insert(head, s);
     string s= findLongest(head, A.size());
    return 0;
}