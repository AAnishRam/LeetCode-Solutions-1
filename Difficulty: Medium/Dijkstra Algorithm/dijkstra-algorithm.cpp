//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
  
    // using priority_queue
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    // vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    //     // Code here
    //     int n = adj.size();
        
    //     // syntax for pq
    //     // priority_queue<Type, vector<Type>, comparator<Type>> variableName
    //     //this is min heap
        
    //     //{distance, nnode}
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
    //     // for max heap
    //     // priority_queue<int>pq is enough
        
        
    //     vector<int> distance(n, INT_MAX);
        
    //     distance[src] = 0;
    //     pq.push({0, src});
        
    //     while(!pq.empty())
    //     {
    //         int node = pq.top().second;
    //         int dist = pq.top().first;
    //         pq.pop();
            
    //         for(auto it : adj[node])
    //         { 
    //             int adjNode = it.first;
    //             int edgeWeight = it.second;
                
    //             if(dist + edgeWeight < distance[adjNode])
    //             {
    //               distance[adjNode] = dist + edgeWeight ;
    //               pq.push({distance[adjNode], adjNode});
    //             }
    //         }
    //     }
        
    //     return distance;
    // }
    
    
    
    // using set
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        set<pair<int, int>> st;
        vector<int> distance(n, INT_MAX);
        
        distance[src] = 0;
        st.insert({0, src});
        
        while(!st.empty())
        {
            auto it = *(st.begin());
            st.erase(it);
            
            int node = it.second;
            int dist = it.first;
            
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                
                if(dist + edgeWeight < distance[adjNode])
                {
                    if(distance[adjNode] != INT_MAX)
                        st.erase({distance[adjNode], adjNode});
                    distance[adjNode] = dist + edgeWeight;
                    st.insert({distance[adjNode], adjNode});
                }
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
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends