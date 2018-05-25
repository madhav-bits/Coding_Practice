/*
*
//******************************************************350. Intersection of Two Arrays II.***********************************************

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,6,7]
[4,2,2,3,5,6,7,1]


[1,2,3,4,5,6,7]
[7,6,5,4,7,3,2,1]


[1,2,3,4,5,6,7]
[7,6,5,4,3,2,1]


[1,1,1,1,1,2,3,3]
[1,1,2,2,3]


[1,1,1,1,1,2,3,3]
[1,1,2,2,3,4]




// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates both the arrays and stores the count of occurances of all nums in a map. We extract the min. of both maps for each int
// and push that int into final res vector min. no. of times.








class Solution {
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        unordered_map<int, int> count1, count2;
        vector<int> res;
        for(auto num:v1) count1[num]++;											// Counting the no. of occuranes of num.
        for(auto num:v2) count2[num]++;											// Counting the no. of occuranes of num.
        
        
        for(auto it=count1.begin();it!=count1.end();it++){
            int len = min(it->second, count2[it->first]);						// Pushing the min. no. of occurances of num into final res.
            for(int j=0;j<len;j++) res.push_back(it->first);
        }
        return res;																// Returning the final res. vector.
    }	
};



// This algorithm is same as above one, except that it improves utilization of maps, thus reducing num. of iterations.



class Solution {
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        unordered_map<int, int> count1;											// Stores the no. of occurances of num in first vector.
        vector<int> res;														// Final result vector.
        for(auto num:v1) count1[num]++;											// Count the no. of occurances of num in first vector.
        
        for(auto num:v2){
            if(count1[num]==0) continue;
            if(count1[num]>0){													// Extracting the min. no. of occurances for a num.
                res.push_back(num);												// Pushing num. into final res. vector.
                count1[num]--;
            }
            
        }
        
        return res;																// Returning the final res. vector.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm sorts the two given vectors. When two iterators show same value, push into final result vector. If not, move the iter. of smaller
// value to next gretaer value and compare the values of two iter.. Thus, we iterate through entire length of two arrays and push common elem.
// into final result vector.







class Solution {
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        vector<int> res;															// Final result vector.
        sort(v1.begin(), v1.end());													// Sorting both vectors.
        sort(v2.begin(), v2.end());
        
        for(int i=0,j=0; i<v1.size() && j<v2.size();i++, j++){
            //cout<<"Currently scanning index i: "<<i<<" and j: "<<j<<endl;
            if(v1[i]==v2[j]) res.push_back(v1[i]);									// Push into final, iff num present in both vectors.
            else if(v2[j]>v1[i]){													// If not equal, move the iter. to next greater elem.
                j--;
                while(i+1<v1.size() && v1[i+1]==v1[i]) i++;
                //cout<<"Renewed i: "<<i<<endl;
            }
            else if(v1[i]>v2[j]){													// If not equal, move the iter. to next greater elem.
                i--;
                while(j+1<v2.size() && v2[j+1]==v2[j]) j++;
                //cout<<"Renewed j: "<<j<<endl;
            }
        }
        
        
        
        return res;																	// Returning the final result vector.
    }
};