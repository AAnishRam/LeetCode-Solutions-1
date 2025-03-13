//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
    void recurr(int r, int c, vector<vector<int>> &mat, string &tempWord, vector<string> &ans, string &word, int dr[], int dc[] )
    {
        int n = mat.size();
        if(r == n-1 && c == n-1)
        {
            ans.push_back(tempWord);
            return;
        }
        
        mat[r][c] = 0;
        for(int i=0; i<4; i++)
        {
            int newR = r + dr[i];
            int newC = c + dc[i];
            
            if(newR >= 0 && newR < n && newC >= 0 && newC < n && mat[newR][newC] == 1)
            {
                tempWord.push_back(word[i]);
                
                recurr(newR, newC, mat, tempWord, ans, word, dr, dc);
                
                tempWord.pop_back();
            }
        }
        mat[r][c] = 1;
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        
        string tempWord;
        vector<string> ans;
        string word = "DRLU";
        int dr[4] = {1, 0, 0, -1};
        int dc[4] = {0, 1, -1, 0};
        
        recurr(0, 0, mat, tempWord, ans, word, dr, dc);
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends