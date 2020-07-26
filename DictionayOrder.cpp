/*
Alien Dictionary - https://leetcode.com/problems/alien-dictionary/
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. 
You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. 
Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"

Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"

Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 
*/


class Solution {
public:
    // if cycle exixts, no topological sort
    bool cyclic(int u, vector<bool> &vis, vector<vector<int>> &graph, vector<bool> &inStack)
    {
        vis[u] = true;
        inStack[u] = true;
        for(int v : graph[u])
        {
            if(vis[v])
            {
                if(inStack[v]) return true;
                continue;
            }
            if(cyclic(v, vis, graph, inStack))
                return true;
        }
        inStack[u] = false;
        return false;
    }
    
    // simple DFS
    void DFS(int u, vector<bool> &vis, vector<vector<int>> &graph, vector<int> &res)
    {
        vis[u]=true;
        for(int v : graph[u])
        {
            if(!vis[v])
              DFS(v, vis, graph, res);   
        }
        // nowhere to go? add to the back of answer
        res.push_back(u);
    }
    
    string alienOrder(vector<string>& words) {
        
        // to keep the record of alphabet present
        vector<bool> isPresent(26,false);
        // each adjacent pair will tell the edges of graphs
        vector<vector<int>> graph(26);
        
        for(int i=0; i<words.size(); i++)
        {
            string s = words[i];
            // in case only one word is there, and duplicates are there
            // so record the presence of alphabets
            for(int j=0; j<s.length(); j++) isPresent[s[j]-'a']=true;
            
            // to get the edges
            if(i+1<words.size())
            {
                string t = words[i+1];
                int n =  min(s.length(), t.length()), j=0;
                bool found = false;
                while(j<n)
                {
                    isPresent[s[j]-'a']=true;
                    if(s[j]!=t[j])
                    {
                        int a = s[j]-'a';
                        int b = t[j]-'a';
                        graph[a].push_back(b);
                        found = true;
                        break;
                    }
                    j++;
                }
                // if no edge found, and later is completely the prefix of first string
                // like, "abc" , "ab"
                // this gives no information
                if(!found && s.length()>t.length()) return "";
                
                // record the presence of alphabets
                while(j<t.length()) isPresent[t[j++]-'a']=true;
            }
        }
        
        vector<bool> vis(26,false);
        // to check for the cycle in directed graph
        vector<bool> inStack(26,false);
         for(int i=0; i<26; i++)
         {
            
             if(!vis[i] && isPresent[i])
             {
                // cout<<i<<" ";
                 if(cyclic(i, vis, graph, inStack))
                 {
                    // cout<<"cyclic";
                     return "";
                 }
             }
         }
        //  reset the visited array
        for(int i=0; i<26; i++) vis[i]=false;
        // answer in reverse order
        vector<int> res;
        for(int i=0; i<26; i++)
        {
            if(isPresent[i] && !vis[i])
             DFS(i, vis, graph, res);
        }
        reverse(res.begin(), res.end());
        string ans="";
        for(int v : res)
        {
            char c = v+'a';
            ans+=c;
        }
        
        return ans;
    }
};
