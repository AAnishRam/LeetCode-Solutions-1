//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        
        queue<pair<int, int>> q;
        
        q.push({src, 0});
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            for(auto adjNode : adj[node])
            {
                if(distance[adjNode] == INT_MAX)
                {
                    distance[adjNode] = dist + 1;
                    q.push({adjNode, dist+1});
                }
            }
        }
        
        for(int i =0 ;i<n;i++)
        {
            if(distance[i] == INT_MAX)
                distance[i] = -1;
        }
        
        return distance;
        
        
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends