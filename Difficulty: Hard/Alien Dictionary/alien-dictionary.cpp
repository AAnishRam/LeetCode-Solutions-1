//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> inDegree;
        
        // Step 1: Initialize inDegree for all characters
        for (auto& word : words) {
            for (char ch : word) {
                inDegree[ch] = 0;  // Initialize all characters with 0 in-degree
            }
        }

        // Step 2: Build the adjacency list from word ordering
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i], s2 = words[i + 1];
            int minLen = min(s1.length(), s2.length());
            bool found = false;
            
            for (int j = 0; j < minLen; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j]].push_back(s2[j]);
                    inDegree[s2[j]]++;  // Increase in-degree for dependent character
                    found = true;
                    break;  // Only consider the first mismatch
                }
            }
            
            // Edge case: If s1 is longer but starts with s2, return ""
            if (!found && s1.length() > s2.length()) {
                return "";
            }
        }

        // Step 3: Perform Topological Sort (Kahn's Algorithm)
        queue<char> q;
        string result;

        // Push all characters with in-degree 0
        for (auto it : inDegree) {
            if (it.second == 0) q.push(it.first);
        }

        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            result += ch;

            for (char neighbor : adj[ch]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the result length is not equal to total unique characters, return ""
        return result.length() == inDegree.size() ? result : "";
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