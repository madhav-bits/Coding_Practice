/*
*
//***********************************************************667. Beautiful Arrangement II.*******************************************

Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys 
the following requirement: 
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

Example 1:
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
Example 2:
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
Note:
The n and k are in the range 1 <= k < n <= 104.


//These are the examples I had created, tweaked and worked on.
7
5


7
6

7
1

// Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************DYNAMIC PROGRAMMING PARADIGM.*************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This is observational question, we have to push in few values, in between actual series of values. Like, if we need 5/4 diff values, we need
//2(5/2 or 4/2) flips. I am maintaining that count. I had improvised it with constant memoryO(1), but not coded yet.


class Solution {
public:
    vector<int> constructArray(int n, int k) {
        map<int, int> m;
        vector<int> v;
        int count=k/2;									// These many no.of insertions are needed.
        for(int i=0;i<n;i++){
            if(!m[i+1]){								// Making sure, elem. are not repeated.(Flipped pushed val. are not repeated.)
                //cout<<"Pushing in series val. "<<i+1<<endl;
                v.push_back(i+1);
            }
            if(count>0){
                //cout<<"Pushing swapped val. "<<v.back()+k<<endl;
                m[v.back()+k]=1;						// Pushig into map, to make sure dup. are not allowed.
                //cout<<"newly pushed map content is: "<<m[v.back()+k]<<endl;
                v.push_back(v.back()+k);				// Pushing the flipped values into vector.
                k-=2;
                count--;								//Determines no. of flips. 
            }
        }
        return v;
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************OBSERVATIONAL QUESTION.*************************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// This is even more simplified algorithm, which I had got into to improve my approach. This has better runnning time. It had made all the flips
// allowed first, then added the series following the flips after that.






class Solution {
public:
    vector<int> constructArray(int n, int k) {
        map<int, int> m;
        vector<int> v;
        v.push_back(1);
        int count=k/2;
        for(int i=0;i<k;i++){										//Handling all the flips.
            if(i%2==0) v.push_back(v.back()+k-i);
            else
                v.push_back(v.back()-k+i);
        }	
        for(int i=k+1;i<n;i++)										//Handling the series after the flip elements.
            v.push_back(i+1);
        return v;
    }
};