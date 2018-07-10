/*
*
//******************************************************364. Nested List Weight Sum II.***********************************************

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf 
level integers have weight 1, and the root level integers have the largest weight.

Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1],0,[1,1,[1,1],2,3,[3,[4,5]]]]


[[1,1],0,[1,1,[1,1],2,3,[3,[4,5]]],3,5]


[[1,1],0,[1,1,[1,1],2,3,[3,[4,5]]],3,5,[[],8]]



[0,[2],[[[4],[52],25,5,[2,10],[],925152],[5125,[]]]]






// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iterate through entire array, at each step, we keep track of maxDepth travelled till now and add 
// num's contribution to final sum acc. to their depth. If we encounter a list, we call. fn. recursively to extract contribution of it's elements.
// If num is encountered, if it's depth>maxDepth, we update maxDepth, update the contribution of nums encountered till now to total sum wrto
// new improved maxDepth. We also add the contibution of curr. value to total value. We also maintain the sum of values encountered till now.
// Which is useful in updating contribution of nums encountered till now to final sum, when maxDepth is updated. At the end of iteration, we 
// return the sum.








/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int maxDepth=1, sum=0,len=0;											// Max. Depth travelled till now, sum of values.
																			// Simple sum of nums. encountered till now.
    void findSum(vector<NestedInteger>v,int depth){
        for(int i=0;i<v.size();i++){
           if(v[i].isInteger()){											// If, we encountered num.
                if(depth>maxDepth){											// If heigher depth is reached.
                    sum+=len*(depth-maxDepth);								// Updating the contri. of nums. encountered till now to total sum.
                    maxDepth=depth;											// Updating the maxm. depth encountered.
                }
                sum+=(v[i].getInteger())*(maxDepth-depth+1);				// Adding curr. value's contribution to total sum.
                len+=v[i].getInteger();										// Adding curr. value to sum of nums. encountered till now.
            }
            else findSum(v[i].getList(),depth+1);							// If curr. elem. is a list, then call fn. recursively.
            // cout<<"Curr. index: "<<i<<" and sum: "<<sum<<" and len: "<<len<<endl;
        }
        
    }
    
    int depthSumInverse(vector<NestedInteger>& v) {
        findSum(v,1);														// Calling fn. to extract sum.
        return sum;															// Returning the sum.
    }
};