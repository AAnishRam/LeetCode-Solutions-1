//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectCycle(int src, vector<vector<int>>& adj, vector<int> &visited) {
        
        int n = adj.size();
        

        queue<pair<int, int>> q;
        
        q.push({src, -1});
        visited[src] = 1;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjNode : adj[node])
            {
                if(!visited[adjNode])
                {
                    q.push({adjNode, node});
                    visited[adjNode] = 1;
                }
                else if(adjNode != parent)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        
        
        //this is for connected components
        for(int i = 0; i< n;i++)
        {
            if(!visited[i])
            {
                if(detectCycle(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends