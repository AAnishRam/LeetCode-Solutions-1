//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  
  
    vector<int> bfs(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        vector<int> temp;
        
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        
        while(!q.empty())
        {
            int ver = q.front();
            q.pop();
            temp.push_back(ver);
            
            for(auto it : adj[ver])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
                
            }
        }
        
        sort(temp.begin(), temp.end());
        
        return temp;
    }
    
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        
        vector<int> visited(v, 0);
        vector<vector<int>> ans;
        vector<vector<int>> adj(v);
        
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i = 0; i < v; i++)
        {
            if(!visited[i])
            {
                vector<int> temp = bfs(i, adj, visited);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends