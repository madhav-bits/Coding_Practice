/*
*
//******************************************************341. Flatten Nested List Iterator.***********************************************

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1],2,[1,1,[1,2,3,[4,5],6,7]]]
[[2,4,[3]],5]
[]
[[[1,2]]]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, at each step we check whether the curr. index/NestedList contains a list or single integer, if it's a single
// integer, we push the integer directly into global variable-res. If it's a list, then we call a fn. to push the contents of the list to
// res vec. Thus, we push all the contents of the vector of nestedList into a single vector of ints.








/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    
    void extractVal(vector<NestedInteger> &v, vector<int> &res){
        for(int i=0;i<v.size();i++){												// Iterating through the curr. NestedList.
            if(v[i].isInteger()) res.push_back(v[i].getInteger());					// Pushing int. directly into res. vector.
            else extractVal(v[i].getList(), res);									// Extr. contents of the list in that index.
        }
    }
    vector<int> res;
    int i=0;
    NestedIterator(vector<NestedInteger> &v) {
        extractVal(v,res);															// Calling fn. to flatten NestedList vector.
        // for(auto num:res)
        //     cout<<num<<" ";
    }

    int next() {
        return res[i-1];															// Returning curr. index's value.
    }

    bool hasNext() {
        if(i++<res.size()) return true;												// If the iterator haven't reached end of res.
        else return false;															// If end of vector is reached, return false.
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */