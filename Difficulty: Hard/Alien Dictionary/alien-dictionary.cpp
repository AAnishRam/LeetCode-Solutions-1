//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string findOrder(vector<string> &words) {
        
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> inDegree;
        
        for(auto str : words)
        {
            for(auto ch : str)
                inDegree[ch] = 0;
        }

        for(int count=0;count<words.size()-1;count++)
        {
            string s1 = words[count];
            string s2 = words[count+1];
            
            bool found = false;
            
            for(int i=0;i<min(s1.length(),s2.length());i++)
            {
                if(s1[i]!=s2[i])
                {
                    adj[s1[i]].push_back(s2[i]);
                    inDegree[s2[i]]++;
                    found = true;
                    break;
                }
            }
            
            // at any stage if s1.length is < s2.length then we cant form dictionary
            // ex abc -> abcd
            // and also if both the string are same abd -> abc
            
            if(!found && s1.length()>s2.length())
                return "";
        }
        

        
        
        queue<char>q;
        string ans = "";
        for(auto it : inDegree)
        {
            if(it.second == 0)
            {
                q.push(it.first);
            }
        }
        
        while(!q.empty())
        {
            char node = q.front();
            q.pop();
            ans += node;
            
            for(auto adjNode : adj[node])
            {
                inDegree[adjNode]--;
                if(inDegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
        
        
        return ans.length() == inDegree.size() ? ans : "";
        
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends