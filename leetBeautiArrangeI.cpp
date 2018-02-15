/*
*
//*************************************************************526. Beautiful Arrangement.****************************************************

Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully 
if one of the following is true for the ith position (1 <= i <= N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

0
1
4
7
12


// Time Complexity: O(n!).
// Space Complexity: O(n!).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(n!).			
// This is dfs, the logic is that we swap values at each level, go ahead iff condition is satisfied. If all the values satisfy the condition, then
// count inc. by one. I am doing only single swap, as I want to maintain the order and reduce redundnat swaps.



class Solution {
public:
    
    void findCombi(vector<int> v, int N, int index, int &count){
        if(index==N){											// If all the satisfy the conditions, then inc. the count by one  and return.
            //for(int i=0;i<N;i++)
            //    cout<<"Vector elem. are: "<<v[i]<<endl;
            //cout<<endl<<endl;
            count++;
            return ;
        }
        
        for(int i=index;i<N;i++){
            if(v[i]%(index+1)==0 || (index+1)%v[i]==0){			// Check whether to be swapped satisfies the condition or not.
                swap(v[i], v[index]);							// If satisfies then only go ahead with the swap and do a recuriseve call.
                //cout<<"i+1 is: "<< i+1<<" and v[i] is: "<<v[i]<<endl;
                findCombi(v,N,index+1,count);
                //swap(v[i], v[index]);							// Re-Swap lets us have a clear flow of swaps. Where as single swap maitains the 
            }													// Order of values- Much useful in case of duplicates values in vector.
        }    
    }
    
    int countArrangement(int N) {
        vector<int> v;
        if(N==1) return 1;
        int count=0;
        for(int i=0;i<N;i++)									// Intitializing the array.
            v.push_back(i+1);
        findCombi(v,N,0,count);
        return count;											// Returns the count satisfying the conditions.
    }
};