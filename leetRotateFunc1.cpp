/*
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

//*************************************************THIS IS STRAIGHT FORWARD WAY, WORKS FOR ALL CASES BUT ONE. THAT TOO TIME LIMIT EXECEED*****
//**********************************************WARNING. OPTIMIZATION NEEDED.*************************************************
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& v) {
        int n=v.size();
        if(n==0)
            return 0;
        int arr[n]={0};
        int maxm=INT_MIN;
        for(int i=0;i<n;i++){// For the array values.
            int sum=0;
            //int a=n;
            for(int k=0;k<n;k++){
                sum+=v[(k+n-i)%n]*k;
            }
            //arr[i]=sum;
            maxm=max(maxm,sum);
        }
        return maxm;
    }
};