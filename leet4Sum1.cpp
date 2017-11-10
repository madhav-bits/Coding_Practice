/*

//*******************************************************18. 4Sum*****************************************************************
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

//*******************************************************THIS IS LEET ACCEPTED CODE.*********************************************
//****************************************Few Changes were inspired by other's logics.*******************************************
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        vector<vector<int>> u;
        if(v.size()<4)
            return u;
        //u.push_back({1,2,3});
        int sum;
        sort(v.begin(), v.end());
        for(int i=0;i<v.size()-3;i++){
            if(i && v[i]==v[i-1])
                continue;
            for(int j=i+1;j<v.size()-2;j++){
                if(j!=(i+1) && v[j]==v[j-1])
                    continue;
                sum=v[i]+v[j];
                int c=j+1, d=v.size()-1;
                //cout<<"sum is: "<<sum<<endl;
                while(c<d){
                    //cout<<" c is: "<< c<<" and d is: "<<d<<endl;
                    if(v[c]+v[d]==(target-sum)){
                        u.push_back({v[i], v[j], v[c], v[d]});
                        c++; d--;// Moving elements out of equal to case.
                        while(c<d && v[c]==v[c-1] )// This will make sure that next scanned val. is not a dupl. of equal case.
                            c++;
                        while(c<d && v[d]==v[d+1] )// This will make sure that next scanned val. is not a dupl. of equal case.
                            d--;// I had a initial thought but that's not satisfying the above commented requirement.
                    }
                    else if(v[c]+v[d]<(target-sum))
                        c++;
                    else
                        d--;
                }
            }
        }
        return u;
    }
};