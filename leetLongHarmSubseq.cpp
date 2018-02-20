/*
*
//******************************************************594. Longest Harmonious Subsequence.***********************************************

We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,4,2,2,4,2,2,5,2,6,3,2,2,5]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm iterates the array and updates the #occurances of a digit in a hash map, then iterate through the array or hashmap once again,
// to get the max. of the sum of occurances of two consecutive digits.
// This can also be achieved by sorting the given array and counting the #occurances of successive same valued digits.



class Solution {
public:
    
    int findLHS(vector<int>& v) {
        map<int, int> m;
        for(int i=0;i<v.size();i++) m[v[i]]+=1;						// Updating the hashmap count.
        
        int maxm=0;
        /*
        for(int i=0;i<v.size();i++){								//Iterating through the array once again.
            if(m[v[i]] >=1 && m[v[i]+1]>=1 || m[v[i]] >=1 && m[v[i]-1]>=1){
                //cout<<"INside if with index: "<<i<<endl;
                maxm=max(m[v[i]+1] + m[v[i]],maxm);
                maxm=max(m[v[i]-1] + m[v[i]],maxm);
                //m[v[i]+1]=0;
                m[v[i]]=0;
                //cout<<"maxm: "<<maxm<<endl;
            }
            
        }
        */
        
        for(auto it=m.begin();it!=m.end();it++){					// Iterating through the hash map.
            //cout<<"The key is; "<<it->first<<" value is: "<<it->second<<endl;
            if( m.count(it->first+1)>=1)
                maxm=max(maxm,it->second + m[it->first+1]);
        }
        return maxm;
    }
};