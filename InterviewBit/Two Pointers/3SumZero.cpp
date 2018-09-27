/*
*
//****************************************************************3 Sum Zero.*********************************************************



https://www.interviewbit.com/problems/3-sum-zero/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



2 -2 -1


23 1 -4 0 0 5 -5 1 0 -2 4 -4 1 -1 -4 3 4 -1 -1 -3 -4 -1 1 3



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Two Pointer based. We fix the first num in the triplet, then do a linear search for the other two nums.Once, we found a 
// triplet, we skip those values in the next iter. as we want Unique triplets. While iter. first num in triplet, we also avoid duplicates by 
// skipping duplicates on first nums. Thus, at the end we get all the Unique triplets.








vector<vector<int> > Solution::threeSum(vector<int> &v) {
    vector<vector<int>>res;													// Final result vector.
    if(v.size()<3) return res;												// Base cases.
    sort(v.begin(), v.end());												// Sort the given array.
    for(int i=0;i<v.size()-2;i++){											// Iter. for first num. of triplet.
        if(i>0 && v[i]==v[i-1]) continue;									// Skipping duplicates on first num.
        int l=i+1,r=v.size()-1;												// Init. indices for search for other two nums in triplet.
        int target=-1*v[i];													// Expected sum of two values.
        while(l<r){															// When two values exist to compare the sum.
            if(v[l]+v[r]<target) l++;										// IF sum is less, inc. the value.
            else if(v[l]+v[r]>target) r--;									// If sum is greater dec. the value.
            else{															// If target sum obtained.
                vector<int>temp={v[i], v[l], v[r]};									
                if(res.size()==0 || res.back()!=temp) res.push_back(temp);	// Checking for dupli. in result vector.
                l++;r--;													// Inc. the indices to prevent duplicates.
            }
        }
    }
    return res;																// Returning the final result(vector of triplets).
}
