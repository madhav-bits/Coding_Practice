/*

//*********************************************************198. House Robber.*****************************************************

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only 
constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can 
rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

//This is the example I had worked on.
//[45,6,4,8,8,90,6,3,2,6,23,23,234,15,654,234,24,76,4,3,2,5,2,25,2]

//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/

// Solution 1: 
//Time Complexity: O(n).
// Space Complexity: O(n).

class Solution {
public:
    int rob(vector<int>& v) {
        if(v.size()==0)
            return 0;
        if(v.size()==1)
            return v[0];
        int len=v.size();
        int summ[len]={0}, inc;
        summ[0]=v[0];
        summ[1]=max(summ[0], v[1]);				//When choosing the second elem., finding whether it's bigger or the previous one.
        inc=(summ[0]>v[1])?0:1;
        if(v.size()==2)
            return summ[1];
        for(int i=2;i<len;i++){					//Previous house not included.
            if(inc==0){                         //If the previous value is not included, then we can include the current house.
                summ[i]=summ[i-1]+v[i];			
                inc=1;
            }
            else{                               //Previous house not included.
                if(summ[i-1]<summ[i-2]+v[i])	
                    inc=1;
                summ[i]=max(summ[i-1],summ[i-2]+v[i]);//If the previous house is not included, then the max. sum till here will be 
            }										//either including the "i-1"th house or not.
            //cout<<"Sum after the index: "<<i<<" is: "<<summ[i]<<endl;
        }
        return summ[len-1];
    }
};



//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
//Solution 2:
//Time Complexity: O(n).
// Space Complexity:O(1).



class Solution {
public:
    int rob(vector<int>& v) {
        int incl=0, excl=0;							//Max. Sum till any index if the current house is included/robbed or not.
        for(int i=0;i<v.size();i++){
            int temp=incl;							//Temporarily saved previous index inclusive value.
            incl=v[i]+excl;							// If the curr. index is included, then we add max. sum(if previous index is not included).
            excl=max(excl, temp);					// If the curr. index is excl., then the previous index might be included or not( So-
        }											//- calc. max of the both).
        return max(incl, excl);						//  We need to return the max. of either last elem. is included/excluded.
    }
}; 