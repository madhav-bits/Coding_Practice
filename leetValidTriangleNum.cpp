/*
*
//**************************************************************611. Valid Triangle Number.**************************************************

Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can 
make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].

//These are the examples I had created, tweaked and worked on.
[2,2,6,5,2,4,2,3,3,4,4]
[]
[1,2,5,1,5,3,2,4,8,6,7,8,98]
[4,5,6,7,8,9,10]


// Time Complexity: O(n^2).
// Space Complexity: O(n^2).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(n^2).			
// This algo. takes all possible combinations and checks they form a triangle or not. Sum of two sides> third side or not. This algo. beats
// 25 percent of submissions on leetcode.




class Solution {
public:
    int triangleNumber(vector<int>& v) {
        if(v.size()<3) return 0;
        sort(v.begin(), v.end());
        int side1,side2,side3,count=0;
        for(int i=0;i<v.size()-2;i++){
            side1=v[i];
            for(int j=i+1;j<v.size()-1;j++){
                side2=v[j];
                for(int k=j+1;k<v.size();k++){
                    side3=v[k];
                    //cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<"side1: "<<side1<<"side2: "<<side2<<"side3: "<<side3<<endl;
                    if(side1+side2<=side3)
                        break;
                    count++;
                }
            }
        }
        return count;
    }
};




//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).			
// This algorithm has the same logic as to find all pair of numbers whose exceeds the target number in a sorted array. We move from both ends
// if their sum is < target, then lower index is inc. if sum is > target, then the higher index is dec. by 1, and keep on searching for other
// pairs. This algo. beats 75 percent of submissions on leetcode.




class Solution {
public:
    int triangleNumber(vector<int>& v) {
        if(v.size()<3) return 0;
        sort(v.begin(), v.end());
        int side1,side2,side3,count=0;
        for(int i=v.size()-1;i>1;i--){
            int j=0, k=i-1;
            while(j<k){
                //cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<"side1: "<<side1<<"side2: "<<side2<<"side3: "<<side3<<endl;
                if(v[j]+v[k]>v[i]){						//If the sum > target, then num. with index>j will get sum>target with higher index value.
                    count+=k-j;
                    k--;
                }
                else									// If the sum < target, then lower index is inc. by 1, with a hope to get sum>target.
                    j++;
                
            }
        }
        return count;
    }
};