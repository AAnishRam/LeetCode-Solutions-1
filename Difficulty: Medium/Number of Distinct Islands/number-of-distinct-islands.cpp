//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  
  private:
    vector<pair<int, int>> dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& visited , int oriR, int oriC)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> temp;
        queue<pair<int, int>> q;
        
        q.push({r, c});
        temp.push_back({oriR-r, oriC-c});
        visited[r][c] = 1;
        
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        
        while(!q.empty())
        {
            int row = q.front().first; 
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !visited[newRow][newCol] && grid[newRow][newCol]==1)
                {
                    q.push({newRow, newCol});
                    temp.push_back({oriR-newRow, oriC-newCol});
                    visited[newRow][newCol] = 1;
                }
            }
        }
        
        return temp;
    }
  
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> islands;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    vector<pair<int, int>> temp = dfs(i, j, grid, visited, i, j);
                    islands.insert(temp);
                }
            }
        }
        
        return islands.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends