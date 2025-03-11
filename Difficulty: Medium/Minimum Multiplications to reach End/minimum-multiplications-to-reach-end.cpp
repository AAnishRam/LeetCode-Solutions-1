//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
    
    class Solution {
      public:
        int minimumMultiplications(vector<int>& arr, int start, int end) {
            
            queue<pair<int, int>> pq;
            
            pq.push({0, start});
            vector<int>dist(100000, INT_MAX);
            
            dist[start] = 0;
            
            while(!pq.empty())
            {
                int curVal = pq.front().second;
                int curCount = pq.front().first;
                pq.pop();
                
                if(curVal == end)
                    return curCount;
                
                for(int i=0; i<arr.size(); i++) {
                    int newVal = (curVal * arr[i]) % 100000;
    
                    if(curCount + 1 < dist[newVal])
                    {
                        pq.push({curCount + 1, newVal});    
                        dist[newVal] = curCount + 1;
                    }
                }
            }
            
            return -1;
        }
    };



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends