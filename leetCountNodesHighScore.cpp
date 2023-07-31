/*
*
//******************************************************2049. Count Nodes With the Highest Score.******************************************************

https://leetcode.com/problems/count-nodes-with-the-highest-score/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[-1,2,0,2,0]
[-1,2,0]
[-1, 0,0,1,2,2,3,4,5,8]
[-1,0]
[-1,0,0]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, as we iterate we collect #nodes in both the children of each node, based on them we calc. rem. nodes that are connected to parent, 
// we calc. prod of #nodes in these three subtrees, if this prod >maxProd til now, we update maxProd and rest count to 1 else if currProd=maxProd, we inc. count by 1. We return 
// count at the end of iter.







class Solution {
public:
    
    int iterateTree(vector<vector<int>>&graph, int node, int&res, long long int& maxProd) {
        
        int lt=(graph[node].size()>=1)?iterateTree(graph, graph[node][0], res, maxProd):0;// If left child exists, call DFS to get #nodes in left child.
        int rt=(graph[node].size()==2)?iterateTree(graph, graph[node][1], res, maxProd):0;
        
        long long int currProd=(graph.size()-lt-rt-1==0)?1:graph.size()-lt-rt-1;// We calc. #nodes in the subtree containing the parent node.
        if(lt!=0) currProd*=lt;												// Mult. with #nodes in left child.
        if(rt!=0) currProd*=rt;												// Mult. with #nodes in right child.
        
        // cout<<"node: "<<node<<" and currProd: "<<currProd<<endl;
        if(currProd>maxProd) {												// If currProd>maxProd, we update maxProd and reset res with 1.
            maxProd=currProd;
            res=1;
        } else if(currProd==maxProd) res++;									// If currProd=maxProd, we inc. res by 1.
        
        return lt+rt+1;														// Returning #nodes in curr. subtree.
    
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        vector<vector<int>>graph(parents.size());
        for(int i=1;i<parents.size();i++) {									// Forming Adjacency list.
            graph[parents[i]].push_back(i);
        }
        long long int maxProd=-1;
        int res=0;
        iterateTree(graph, 0, res, maxProd);								// DFS call to iterate the tree.
        return res;															// Returning #nodes with max score.
    }
};

