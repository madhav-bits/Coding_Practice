/*
*
//********************************************************769. Max Chunks To Make Sorted.****************************************************

Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number 
of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 10].
arr[i] will be a permutation of [0, 1, ..., arr.length - 1].

//These are the cases I had tweaked and worked on.
[6,0,1,2,4,3,5,8,7,9]
[0,1,3,5,4,2]

// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
//The algorithm is to find the subset whose elem. are jumbled in the subset's indices only. Values in proper psn would from a indi. subset each
// Thus the sum leads to max. no. of subsets needed to sort the given array.

class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int result, len=v.size(), count=0, maxm=-1;
        for(int i=0;i<len;i++){
            if(i==maxm && v[i]<maxm){				//If the mispl. elem. are < curr. index then they can be pushed into subset-
                maxm=-1;							// as our motive is to get max. #subsets.
                count++;
            }
            else if(v[i]!=i)						//In case of mismatched elem. max value of misplaced elem. is saved.
                maxm=max(v[i], maxm);
            else if(v[i]==i && maxm!=-1 && v[i]>maxm){//Separates a subset of misplaced elem. Leading to subsets 1) misplaced ones 2) itself.
                count+=2;
                maxm=-1;								//Intitializing the misplaced value to default case(NONE).
            }
            else if(v[i]==i && maxm ==-1 )				//No mispl. elem. till now. So, this properly placed elem. form a subset.
                count++;
            
            //cout<<"For index i: "<<i<<" v[i] value is: "<<v[i]<<" count is: "<<count<<" maxm is: "<<maxm<<endl;
        }
        
        if(maxm!=-1)									//If last seq. of values after a proper placed value/misp. in range are all mispl.
            count++;
        //cout<<"The result is: "<<count<<endl;
        return count;									//Returning the #subsets formed.
    }
};