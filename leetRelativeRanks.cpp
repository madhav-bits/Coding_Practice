/*
*
//**********************************************************506. Relative Ranks.***************************************************

Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", 
"Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[]
[1]
[2,1]
[2,3,1]
[2,10,9,1,6]



// Time Complexity: O(nlogn).  
// Space Complexity: O().

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is HashMap based. In the first iteration, we push all values and their indices into map. In the second iteration, we start iter.
// the sorted array from the first index, we get it's orig. index from map, we push the rank into that index in final result vector.




class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size(),"");											// Creating a vector of size same as nums.
        if(nums.size()==0) return res;												// If it's a empty string, return empty string.
        unordered_map<int, int> m;													// Stores values and their indices.
        vector<int> v=nums;															// Duplicate the given vector.
        sort(v.begin(), v.end());													// Sort the given values.
        for(int i=0;i<v.size();i++) m[v[i]]=i;										// Storing the val. with the index in map.
            
        for(int i=0;i<nums.size();i++){												// Iterating through the array.
            int len=v.size();
            //cout<<"Curr. rank is: "<<m[nums[i]]<<" rank: "<<len-3<<endl;
            if(m[nums[i]]<len-3) res[i]=to_string(v.size()-m[nums[i]]);				// If it's not top three, assign the rank.
            else if(m[nums[i]]==v.size()-1) res[i]="Gold Medal";					// If it's top, assign "Gold Medal".
            else if(m[nums[i]]==v.size()-2) res[i]="Silver Medal";
            else if(m[nums[i]]==v.size()-3) res[i]="Bronze Medal";
            // else 
            //     res[i]=to_string(v.size()-m[nums[i]]);
        }
        
        return res;      															// Returning the result vector.
    }
};


//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// We push the values and indices into map. We sort the given vector in descending order. In the second iteration, since they are already sorted,
// we get their orig. idices from map, and push Corres. ranks in that index in final result.

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size(),"");
        if(nums.size()==0) return res;
        unordered_map<int, int> m;
        //vector<int> v=nums;
        
        for(int i=0;i<nums.size();i++) m[nums[i]]=i;
        sort(nums.begin(), nums.end(), greater<>());
        
        
        for(int i=0;i<nums.size();i++){													// We travel from greatest to smallest value.
            //cout<<"Curr. score is: "<<nums[i]<<" and index is: "<<m[nums[i]]<<endl;
            if(i==0) res[m[nums[i]]]="Gold Medal";										// As the first value is greatest.
            else if(i==1) res[m[nums[i]]]="Silver Medal";								// This is the second value.
            else if(i==2) res[m[nums[i]]]="Bronze Medal";
            else res[m[nums[i]]]=to_string(i+1);										// If not in top three, assign the rank directly into res.
            
        }
        
        return res;      																// Returning the final res. vector.
    }
};