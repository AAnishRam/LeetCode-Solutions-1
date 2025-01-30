//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        vector<int> visited (V,0);
        int count = 0;

        queue<int> q;
        
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                count++;
                q.push(i);
                visited[i] = 1;

                while(!q.empty())
                {
                    int currNode = q.front();
                    q.pop();
                    for(int j = 0; j<adj[currNode].size(); j++)
                    {
                        if(!visited[j] && adj[currNode][j] == 1)
                        {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends