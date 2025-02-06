//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
    
  private:
    
    void constructTree(Node *&root, int low, int high, int &index, vector<int> &inorder, 
    vector<int> &preorder)
    {
        if(low > high)
        {
            root = nullptr;
            return;
        }
        
        int findIndex = -1;
        int val = preorder[index];
        
        for(int i = low; i<= high; i++)
        {
            if(inorder[i] == val)
            {
                findIndex = i;
                break;
            }
        }
        
        root = new Node(val);
        index++;
        
        constructTree(root->left, low, findIndex - 1, index, inorder, preorder );
        constructTree(root->right, findIndex + 1, high, index, inorder, preorder );
    }
    
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        
        Node *root = nullptr;
        int n = inorder.size();
        int index = 0;
        
        constructTree(root, 0, n-1, index, inorder, preorder);
        
        return root;
        
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends