/*

//***********************************************************16. 3Sum Closest.***********************************************************

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).



//Time Complexity: O(n^2).
// Space Complexity: O(1).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/

class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        int diff=INT_MAX, sum;
        sort(v.begin(), v.end());
        for(int i=0;i<v.size()-2;i++){
            if(i>0 && v[i]==v[i-1])//Prevents pushing duplicate first elem. into final result.
                continue;
            int req=target-v[i], j=i+1, k=v.size()-1;
            while(j<k){
                //cout<<"curren values of array are: "<<v[j]<<" and: "<<v[k]<<" with req is: "<<req<<endl;
                if(j>i+1 && v[j]==v[j-1] && k<v.size() && v[k]==v[k+1]){
                    j++; k--;// Prevents pushing duplicates sec. and third elem. into final result.
                    continue;
                }    
                if(req==v[j]+v[k])// Whenever there is a match, moving ahead on two sides, as they both form a unique match. Moving on two-
                    return v[i]+v[j]+v[k];//- sides won't remove any unique matching cases. On reaching exact value, directly pushing ans.
                    // as there can't be any combination closer than this.
                if(abs(req-(v[j]+v[k]))<diff){
                    diff=abs(req-(v[j]+v[k]));
                    sum=v[i]+v[j]+v[k];
                    //cout<<"Sum modified: "<<sum<<" with elem. v[i]: "<<v[i]<<" v[j]: "<<v[j]<<" v[k]: "<<v[k]<<endl;
                }
                
                if(v[j]+v[k]<req)
                    j++;
                else if(v[j]+v[k]>req)
                    k--;
            }
        }
        return sum;
    }
};