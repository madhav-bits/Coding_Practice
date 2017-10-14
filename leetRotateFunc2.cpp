/*
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

//************************************************THIS IS LEET ACCEPTED CODE.**********************************************************
//************************************************NICE AND SMART SOLUTION.*************************************************************
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& v) {
        int n=v.size();
        if(n==0)
            return 0;
        int total=0;
        int singSum=0;
        for(int i=0;i<n;i++){
            total+=v[i]*i;
            singSum+=v[i];
        }
        int maxm=total;
        //cout<<"Earlier total is: "<<total<<"Single value sum is: "<<singSum<<endl;
        for(int i=1;i<n;i++){
            total+=singSum;// As the array moves to the right by 1 psn each time. This is added corresponding increased index value(+1) each
            //value gets multiplied.
            total-=(n*v[n-i]);//This is corresponding to the value multi. to the last index, which now multiplies with 0 index value.
            //cout<<"Sub value is: "<<v[n-i]<<endl;
            //cout<<"New total is: "<<total<<endl;
            maxm=max(maxm, total);
        }
        return maxm;
    }
};