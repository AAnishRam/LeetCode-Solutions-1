//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    
    void recur(long long mul, vector<long long> &ans, long long n)
    {
        if(mul > n)
            return;
            
        ans.push_back(mul);
        
        recur((mul * (ans.size()+1)), ans, n);
    }
    
    vector<long long> factorialNumbers(long long n) {
        vector<long long> ans;
        
        recur(1, ans, n);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends