/*
*
//****************************************************************3 Sum.*********************************************************

https://www.interviewbit.com/problems/3-sum/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


10 2 1 -9 -7 -8 2 -8 2 3 -8
-1


5 -1 2 2 -4 3
3




// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is Three Pointer based. This algo. is improviation of Two Pointer question. Here, we use/fix third pointer, then move second,
// third pointers in search of target. In the process, we keep on updating the sum of triplets, which are close to target. Thus, at the 
// end of iteration, we get triplets, which are most close to target number.








int Solution::threeSumClosest(vector<int> &v, int target) {
    sort(v.begin(), v.end());												// Sort the given array.		
    int i=0,j=0,k=0;														// Decl. three pointers.
    int res=INT_MAX;														// Init. the result.
    for(int i=0;i<v.size()-2;i++){											// Iter. over all indices.
        j=i+1,k=v.size()-1;													// Init. second, third ptrs.
        while(j<k){															// Until second and third won't intersect.
            int sum=v[i]+v[j]+v[k];											// Calc. sum of three chosen nums.
            if(sum==target) return target;									// If target obtained, return target value.
            if(sum<target){													// If sum<target, we inc. the second index/j.
                if(res==INT_MAX) res=sum; 									// Init. the result value.
                else if((target-sum)<abs(res-target)){						// If curr. sum is closer to target than prev. stored result.
                    // cout<<"1 i: "<<v[i]<<" j: "<<v[j]<<" k: "<<v[k]<<endl;
                    res=sum;												// Update the result value.
                } 
                j++;														// Inc. the second pointer.
            }
            else{
                if(res==INT_MAX) res=sum;
                else if((sum-target)<abs(res-target)){						// If curr. sum is closer to target than prev. stored result.
                    // cout<<"2 i: "<<v[i]<<" j: "<<v[j]<<" k: "<<v[k]<<endl;
                    res=sum;												// Update the result value.
                } 
                k--;														// Dec. the third pointer.
            }
        }
    }
    return res;																// Return the sum closest to target value.
}
