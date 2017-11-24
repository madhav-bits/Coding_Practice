/*

//*******************************************************523. Continuous Subarray Sum*****************************************************

Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous 
subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.



//Time Complexity: O(n).
// Space Complexity: O(n).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/



class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int k) {
        map<int,int> m,n;
        m[0]=1; n[0]=-1;//Initialize the case when sum goes to k.
        vector<int>u;
        int sum=0;
        for(const auto& num:v){//Summing up all the elements.
            sum+=num;
            u.push_back(sum);
        }
        sum=0;
        for(int i=0;i<v.size()-1;i++)
            if(v[i]==0 && v[i+1]==0)//Checks for two consecutive occurences of zeroes.
                return true;
        
        
        if(k!=0){
            for(int i=0;i<u.size();i++){
                //cout<<"sum is: "<<u[i]<<endl;
                int b=u[i]%k;
                if(m[b]==1 && i-n[b]>1)// Two occurences of same rem. means the middle elem. sum up to multiple of k.
                    return true;

                else if(m[b]!=1){//Makes sure that the instance of sum going to k won't get modified in case of direct occurence of k.
                    m[b]=1;
                    n[b]=i;
                }
            }
        }
        return false;
    }
};