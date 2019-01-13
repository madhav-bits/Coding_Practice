/*
*
//**************************************************************975. Odd Even Jump.*******************************************************

You are given an integer array A.  From some starting index, you can make a series of jumps.  The (1st, 3rd, 5th, ...) jumps in the series are 
called odd numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even numbered jumps.

You may from index i jump forward to index j (with i < j) in the following way:

During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index j such that A[i] <= A[j] and A[j] is the smallest possible value.  If 
there are multiple such indexes j, you can only jump to the smallest such index j.
During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index j such that A[i] >= A[j] and A[j] is the largest possible value.  If 
there are multiple such indexes j, you can only jump to the smallest such index j.
(It may be the case that for some index i, there are no legal jumps.)
A starting index is good if, starting from that index, you can reach the end of the array (index A.length - 1) by jumping some number of times 
(possibly 0 or more than once.)

Return the number of good starting indexes.

 

Example 1:

Input: [10,13,12,14,15]
Output: 2
Explanation: 
From starting index i = 0, we can jump to i = 2 (since A[2] is the smallest among A[1], A[2], A[3], A[4] that is greater or equal to A[0]), then 
we can't jump any more.
From starting index i = 1 and i = 2, we can jump to i = 3, then we can't jump any more.
From starting index i = 3, we can jump to i = 4, so we've reached the end.
From starting index i = 4, we've reached the end already.
In total, there are 2 different starting indexes (i = 3, i = 4) where we can reach the end with some number of jumps.
Example 2:

Input: [2,3,1,1,4]
Output: 3
Explanation: 
From starting index i = 0, we make jumps to i = 1, i = 2, i = 3:

During our 1st jump (odd numbered), we first jump to i = 1 because A[1] is the smallest value in (A[1], A[2], A[3], A[4]) that is greater than 
or equal to A[0].

During our 2nd jump (even numbered), we jump from i = 1 to i = 2 because A[2] is the largest value in (A[2], A[3], A[4]) that is less than or 
equal to A[1].  A[3] is also the largest value, but 2 is a smaller index, so we can only jump to i = 2 and not i = 3.

During our 3rd jump (odd numbered), we jump from i = 2 to i = 3 because A[3] is the smallest value in (A[3], A[4]) that is greater than or equal 
to A[2].

We can't jump from i = 3 to i = 4, so the starting index i = 0 is not good.

In a similar manner, we can deduce that:
From starting index i = 1, we jump to i = 4, so we reach the end.
From starting index i = 2, we jump to i = 3, and then we can't jump anymore.
From starting index i = 3, we jump to i = 4, so we reach the end.
From starting index i = 4, we are already at the end.
In total, there are 3 different starting indexes (i = 1, i = 3, i = 4) where we can reach the end with some number of jumps.
Example 3:

Input: [5,1,3,4,2]
Output: 3
Explanation: 
We can reach the end from starting indexes 1, 2, and 4.
 

Note:

1) 1 <= A.length <= 20000
2) 0 <= A[i] < 100000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[14,15,13,12,14,15]



[10,13,12,14,15]



[1]



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Set based. Here, we need smallest possible greater value with greater index, largest possible smallest value with greater
// index for each index, which can be obtained through lower_bound fn in set. We calc. next steps for even, odd steps for each index. In the
// second iter. we iter. over indices, at each step we calc. #ways to reach next step(if exists) from curr. index, if curr. index is reachable in
// case of following step being a even step.For even step we inc. the count of next step by #possi. to reach curr. index with even next step+1.
// At the end of iteration, we return #ways to reach last step either through even/odd last step.






class Solution {
public:

    int oddEvenJumps(vector<int>& v) {
        vector<vector<int>>dist(2,vector<int>(v.size()+1, -1));				// Stores the index of next step we can take from curr. index.
        vector<vector<int>>steps(2,vector<int>(v.size()+1, 0));				// Stores #ways to reach curr. index from the start.
        set<pair<int,int>>s, st;											// Stores the value, index pair.
        for(int i=v.size()-1;i>=0;i--){										// Iter. over all indices.
            // cout<<"i: "<<i<<endl;
            auto it=s.lower_bound({v[i],i});								// Finding the smallest greater value(Odd steps).
            auto it2=st.lower_bound({-v[i], i});							// Finding the largest smaller value(Even steps). 
            if(it!=s.end()){												// If next step found.
                // cout<<"found first: "<<it->first<<" and second: "<<it->second<<endl;
                dist[1][i]=it->second;                         				// Make it the next step(odd) of curr. step.
            }        
            
            if(it2!=st.end()){												// If next step found.
                dist[0][i]=it2->second;    									// Make it the next step(even) of curr. step.
            }

            s.insert({v[i],i});												// Inserting curr. value and index into set.
            st.insert({-v[i],i});											// We reverse signs to get smallest greater instead of largest smaller.
        }
        
//         for(int i=0;i<v.size();i++)										// Printing out dist.(Next step) arrays for debugging.
//             cout<<dist[0][i]<<" ";
//         cout<<endl;
        
//         for(int i=0;i<v.size();i++)
//             cout<<dist[1][i]<<" ";
//         cout<<endl;
        
        
        for(int i=0;i<v.size()-1;i++){										// Iter. over all indices.
            int dist1=dist[1][i];											// Get next step index for odd jump.
            if(dist1!=-1)													// If next step for odd jump is valid.
                steps[0][dist1]+=steps[1][i]+1;
            
            if(steps[0][i]>0){												// If this index is reachable for even jump.
                int dist2=dist[0][i];										// Get next step index for even jump
                if(dist2!=-1) steps[1][dist2]+=steps[0][i];					// If next step is valid, update #ways to reach next step's index.
            }
            
        }
        return steps[0][v.size()-1]+steps[1][v.size()-1]+1;					// Returning #ways to reach last index through even/odd jump+1(As we-  
																			// - can start first jump(odd) from last index. 
    }
};