/*
*
//**************************************************************969. Pancake Sorting.*******************************************************

Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of 
A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips 
will be judged as correct.

 

Example 1:

Input: [3,2,4,1]
Output: [4,2,4,3]
Explanation: 
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: A = [3, 2, 4, 1]
After 1st flip (k=4): A = [1, 4, 2, 3]
After 2nd flip (k=2): A = [4, 1, 2, 3]
After 3rd flip (k=4): A = [3, 2, 1, 4]
After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 
Example 2:

Input: [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.
 

Note:

1 <= A.length <= 100
A[i] is a permutation of [1, 2, ..., A.length]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[3,2,1]


[1,2,3]



[4,2,1,3]







// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is Greedy/ Iteration based. As, here, we are able to flip starting 'i' indices at every step, we greedily chose greatest 
// unsorted value at each step, find it's index, flip all values till that index to bring to '0' index, now flip it's actual psn #indices to 
// bring it to it's acutal position. This, way we take (2*#elelments) steps to sort the given array. At each step, we take linear #flips, so 
// it becomes O(n^2) time complexity.








class Solution {
public:
    
    void printVec(vector<int>&v){											// Prints the contents of the array.
        for(auto num:v)
            cout<<num<<" ";
        cout<<endl;
    }
    
    vector<int> pancakeSort(vector<int>& v) {
        vector<int>res;														// Final result storing #flips made at each step.
        for(int elem=v.size();elem>0;elem--){								//  Iter. elem. #steps.
            // cout<<"setting elem: "<<elem<<endl;
            int index=find(v.begin(), v.end(), elem)-v.begin();				// Finding index of greatest unsorted value.
            res.push_back(index+1);											// Saving the flips value.
            reverse(v.begin(), v.begin()+index+1);							// Flipping to bring it to '0' index.
            // cout<<"after stage1: "<<endl;
            // printVec(v);
            res.push_back(elem);											// Storing it's actual psn number.
            reverse(v.begin(), v.begin()+elem);								// Flipping it's actual psn indices.
            // cout<<"after stage2: "<<endl;
            // printVec(v);
        }
        return res;															// Returning the vector of length of flips made.
    }
};