/*
*
//******************************************************2352. Equal Row and Column Pairs.******************************************************

https://leetcode.com/problems/equal-row-and-column-pairs/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[3,2,1],[1,7,6],[2,7,7]]
[[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]



// Time Complexity: O(n*n).													// O(n*n) for insert, search, n-#size of the matrix.
// Space Complexity: O(n*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).													// O(n*n) for insert, search, n-#size of the matrix.
// Space Complexity: O(n*n).	
// This algorithm is Trie based. As we are searching for a array of values in array of array of values similar to searching string in an array of strings, Trie
// would be the best data structure to use in these cases as there would no unneccessary comparisons and there wont be much space wasted in Trie. Here, 
// we first iter. over cols and insert each of the cols in the Trie and we store #cols with same set of values in the tail node of the Trie. While iter. over
// rows, we search for these rows in Trie, if we are find all the nums. in this row in the trie, we add the #cols value from the tail node to res.







class Solution {
public:
    
    struct TrieNode{														// Defining TrieNode structure.
        unordered_map<int, TrieNode*>child;
        int rows;															// Stores #cols with same sequence of values.
        
        TrieNode(){
            child=unordered_map<int, TrieNode*>();
            rows=0;
        }
    };
    
    struct Trie{
        TrieNode* trieNode;
        
        Trie() {
            trieNode = new TrieNode();
        }
        
        void insertTrie(vector<vector<int>>&grid, int col) {				// Insert array into Trie.
            int row=0;
            TrieNode* node=trieNode;
            
            while(row<grid.size()) {
                if(node->child.count(grid[row][col])==0) node->child[grid[row][col]]=new TrieNode();// If child node doesn't exist, create one.
                node=node->child[grid[row++][col]];							// Move to child node and next index in array.
            }
            node->rows++;													// Updating #cols with same sequence of values.
            return ;
        }
        
        int searchTrie(vector<vector<int>>&grid, int row) {
            int col=0;
            TrieNode* node=trieNode;
            
            while(col<grid.size()) {
                if(node->child.count(grid[row][col])==0) return 0;			// If child node not found, that means curr. row's seq. of values doesn't exist.
                node=node->child[grid[row][col++]];							// Move to child node and next index in array.
            }
            return node->rows;												// Returning #cols with same sequence of values.
        }
        
    };
    
    
    int equalPairs(vector<vector<int>>& grid) {
        int res=0;
        Trie* root=new Trie();
        for(int j=0;j<grid.size();j++) {
            root->insertTrie(grid, j);										// Inserting cols into Trie.
        }
        
        for(int i=0;i<grid.size();i++) {
            res+=root->searchTrie(grid, i);    								// Searching for rows in the Trie.
        }
        
        return res;															// Returning the #equal row, col pairs.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n+nlogn).											// O(n*n) to iter. over matrix, O(nlogn+n*n) to insert into map.
// Space Complexity: O(n*n).												// n-size of the matrix.
// This algorithm is Map based. Here, we use map to store the cols in the map, when we iter. over rows later, we try to find the array in the map, if present
// we add it's #occur. to res as curr. row and all the cols that corresponds to #occur are equal.








class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res=0;
        map<vector<int>, int>m;
        for(int j=0;j<grid.size();j++) {
            vector<int>temp;
            for(int i=0;i<grid.size();i++) temp.push_back(grid[i][j]);		// Forming an array with curr. col values.
            m[temp]++;														// Inserting this array into map.
        }
        for(vector<int>&u:grid) {
            if(m.count(u)==1) res+=m[u];									// If curr. row is present in map, count their #occur. to res as they are = curr. row.
        }
        return res;															// Returning the #equal row, col pairs.
    }
};

