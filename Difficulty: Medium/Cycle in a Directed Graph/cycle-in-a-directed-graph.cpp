//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
  private:
    
    bool dfs(int node, vector<vector<int>> adj, vector<int> &visited, vector<int> &pathVisited)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto adjNode : adj[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjNode, adj, visited, pathVisited))
                    return true;
            }
            else if(pathVisited[adjNode])
            {
                return true;
            }
        }
        
        pathVisited[node] = 0;
        
        return false;
        
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
       int n = adj.size();
       vector<int> visited(n, 0);
       vector<int> pathVisited(n, 0);
       
       for(int i = 0; i < n; i++)
       {
           if(!visited[i])
           {
               if(dfs(i, adj, visited, pathVisited))
                    return true;
           }
       }
       
       return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends