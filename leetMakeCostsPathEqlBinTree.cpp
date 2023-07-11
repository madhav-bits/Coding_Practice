/*
*
//*****************************************2673. Make Costs of Paths Equal in a Binary Tree.*****************************************

https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


7
[1,5,2,2,3,3,1]
3
[5,3,3]
15
[5,7,4,3,8,6,5,3,2,6,5,3,8,6,4]



// Time Complexity: O(n).  													// Second solution gives the best Space Complexity.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Greedy based. Here, we try to find the maxPath total and make every path's value equal to it. In the second iter. we try to inc. as much
// value as possible top-down so that #increments would be less. At every node, we calc. diff of maxPathTotal-sum of modified parents Total-curr. node-maxChild
// --Total which gives max #increments at this node, so that lesser #required increments would pass down to children.






class Solution {
public:
    
    int traverseTree(vector<int>&cost, int index, vector<int>&maxTotal) {	// Iter. tree and find maxChildPathTotal for every node.
        if(index>cost.size()) return 0;    
        int maxm=0;
        maxm=max(maxm, traverseTree(cost, 2*index, maxTotal));				// Tracking max. Child path total. 
        maxm=max(maxm, traverseTree(cost, 2*index+1, maxTotal));
        maxTotal[index-1]=maxm;
        return maxTotal[index-1]+cost[index-1];								// Returing maxChidPathTotal+Curr. node value.
    }
    
    void calcIncrements(vector<int>&cost, int index, vector<int>&maxTotal, int parentTotal, int&res) {
        if(index>cost.size()) return ;
        int moves=maxTotal[0]+cost[0]-parentTotal-cost[index-1]-maxTotal[index-1];// Calc. #increments required at curr. step.
        // cout<<"node: "<<index<<" parentTotal: "<<parentTotal<<" maxChildTotal: "<<maxTotal[index-1]<<" and moves: "<<moves<<endl;
        res+=moves;
        calcIncrements(cost, 2*index, maxTotal, parentTotal+moves+cost[index-1], res);// Calling child with updated modified parents total.
        calcIncrements(cost, 2*index+1, maxTotal, parentTotal+moves+cost[index-1], res);
        return ;
    }
    
    int minIncrements(int n, vector<int>& cost) {
        int res=0;
        vector<int>maxTotal(n,0);
        traverseTree(cost, 1, maxTotal);
        
        calcIncrements(cost, 1, maxTotal, 0, res);
        return res;															// Returning min. #increments needed to make all leaf paths of same total.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy based. This solution is simplified version of above algorithm. At every node, we calc. abs. diff b/w maxChildTotal from left, 
// right child and add it to res as we make #increments in a node so that as much common increments would be made in the parent so that children takes lesser
// req. increments, maxChildPathTotal helps in determining max. common increments, which essentially means we are trying make other path total eql. to 
// maxChildTotal, so we get maxChildTotal from both childre, get their abs. diff and add it to res, return res at the end of iter.












class Solution {
public:
    int iterateTree(int n, vector<int>&cost, int&res) {
        if(n>cost.size()) return 0;
        int lt=iterateTree(2*n, cost, res);									// Getting maxChildPathTotal from both children.
        int rt=iterateTree(2*n+1, cost, res);
        res+=abs(lt-rt);													// Adding abs. diff of maxChildPathTotal to res.
        return cost[n-1]+max(lt, rt);										// Returning maxChidPathTotal+curr. node to parent.
    }
    
    int minIncrements(int n, vector<int>& cost) {
        int res=0;
        iterateTree(1, cost, res);											// Calling fn. to calc. minm #increments required.
        return res;
    }
};

