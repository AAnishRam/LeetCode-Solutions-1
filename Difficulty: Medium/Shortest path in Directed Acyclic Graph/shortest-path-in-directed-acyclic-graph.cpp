//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void dfs(int node, stack<int> &st, vector<vector<pair<int, int>>> &adj, vector<int> &visited)
    {
        visited[node] = 1;
        
        for(auto adjNode : adj[node])
        {
            if(!visited[adjNode.first])
                dfs(adjNode.first, st, adj, visited);
        }
        
        st.push(node);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        
        for(int i = 0; i<E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        
        vector<int> visited(V, 0);
        stack<int> st;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                dfs(i, st, adj, visited);
        }
        
        vector<int> distance(V, INT_MAX);
        
        distance[0] = 0;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            
            if (distance[node] != INT_MAX) {  

                for(auto adjNode : adj[node])
                {
                    int v = adjNode.first;
                    int weight = adjNode.second;
                    
                    if(distance[node] + weight < distance[v])
                        distance[v] = distance[node] + weight;
                }
            }
        }
        
         for (int i = 0; i < V; i++) {
            if (distance[i] == INT_MAX) {
                distance[i] = -1;
            }
        }
        
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends