//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>>adj(n+1);
        
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n + 1, INT_MAX);
        vector<int> parent(n+1);
        
        for(int i=1;i<=n;i++)
        {
            parent[i] = i;
        }
        
        pq.push({0, 1});
        distance[1] = 0;

        while(!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeW = it.second;
                
                if(dist + edgeW < distance[adjNode])
                {
                    distance[adjNode] = dist + edgeW;
                    pq.push({distance[adjNode], adjNode});
                    parent[adjNode] = node;
                    
                }
            }
        }
        
        if(distance[n] == INT_MAX) return {-1};
        
        vector<int>ans;
        int node = n;
        
        while(parent[node] != node)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        ans.push_back(distance[n]);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends