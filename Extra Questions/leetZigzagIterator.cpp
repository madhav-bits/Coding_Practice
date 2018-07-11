/*
*
//************************************************************281. Zigzag Iterator.*****************************************************

Given two 1d vectors, implement an iterator to return their elements alternately.

Example:

Input:
v1 = [1,2]
v2 = [3,4,5,6] 

Output: [1,3,2,4,5,6]

Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,3,2,4,5,6].
Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question:
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with 
"Cyclic". For example:

Input:
[1,2,3]
[4,5,6,7]
[8,9]

Output: [1,4,8,2,5,9,3,6,7].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[]
[]

[1]
[]

[]
[1]


[1,2,3]
[4,5,6]


[1,2,3]
[4,5]



[1,2]
[4,5,6]


[]
[4,5,6]


[1,2,3]
[]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We form a 2D vector with the given 2 vectors. I maintain another vector whose contents are indices of 
// two array's to be returned values. We skip those arrays, which have been completely iterated. As, I have generalized this solution to work for 
// "K" arrays, I had stored the combined length of all arrays, so that we can answer the hasNext in O(1) time. 



// THIS ALGO. IS GENERALIZED TO WORK FOR ITERATING "K" VECTORS.




class ZigzagIterator {
public:
    int vec=0;																// Tracks array from which value has to returned now.
    vector<vector<int>>v;													// Stores given 2 vectors as 2D vector.
    vector<int>ind;
    int len=0, count=0;														// Stores total #elem and #elem. returned till now.
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        ind=vector<int>(2,0);												// Init. index vector.
        len+=v1.size();														// Adding #elem. in two vectors.
        len+=v2.size();
        v.push_back(v1);													// Adding vectors to temp. vector forming a 2D vector.
        v.push_back(v2);
    }

    int next() {
        int res=0;															// Stores to be returned value.
        while(ind[vec%2]>=v[arr%2].size())									// Skipping completely iterated arrays.
            vec++;
        
        res=v[arr%2][ind[vec%2]];											// Extracting the to be returned vlaue.
        ind[vec%2]++;														// Inc. the iterator for that array.
        vec++;																// Inc. the array iterator.
        count++;															// Inc. the #elem. returned count.
        return res;															// Returning the extracted value.
    }

    bool hasNext() {
        // if(ind[vec%2]<v[arr%2].size()) return true;
        // return false;
        return (count<len);													// Says, whether all elem. are iterated or not?
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */