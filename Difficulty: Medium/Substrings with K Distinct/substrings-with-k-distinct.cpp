//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countSubstr(string& s, int k) {
        
        int count = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            int noOfDistincts = 0;
            string sub = "";
            vector<int> hash(26,0);
            
            for(int j = i; j < s.length(); j++)
            {
                if(hash[s[j]-'a'] == 0)
                {
                    hash[s[j]-'a']++;
                    noOfDistincts++;
                    sub += s[j];
                }
                
                if(noOfDistincts == k)
                {
                    count++;
                }
                
                if(noOfDistincts > k)
                    break;
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends