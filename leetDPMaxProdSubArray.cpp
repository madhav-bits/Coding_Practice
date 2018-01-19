/*
*
//******************************************************152. Maximum Product Subarray.**********************************************

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

//This is the examples on which I had worked on.
[2,3,-2,4,5,6,-8,-10,4]




// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// The algorithm is that we calc. product of substring from both ends, returning the max. of both. The important factor is that if we have odd
//no. of (-ve) elem. we have to choose b/w them and also consider the effect of zeros in the substring. This scenario is handled in the 53&54
//lines of the code.

class Solution {
public:
    int maxProduct(vector<int>& v) {
        int len=v.size();
        int maxm=INT_MIN;
        int front=1, back=1;
        for(int i=0;i<len;i++){
            front*=v[i];
            back*=v[len-1-i];
            maxm=max(maxm,max(front, back));
            front=(front==0)?1:front;				//If we have zero, then start calc. product of substring elem. from 1. 
            back=(back==0)?1:back;
        }
        
        //cout<<"The maxm product is: "<<maxm<<endl;
        return maxm;
        
    }
};








//************************************************************Solution 2:************************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).
//This is properly functioning O(n^2) complexity Dynamic Programming code.
//Calc. the product of all substring possible, and then clac. it's maximum. But this implementation throws time limit exceeding error for single
//case of the test cases.

class Solution {
public:
    int maxProduct(vector<int>& v) {
        int len=v.size();
        if(len==1)
            return v[0];
        
        vector<vector<int>> u(len,vector<int>(len,0));
        int maxm=INT_MIN;
        for(int i=0;i<len;i++){
            u[i][i]=v[i];
            maxm=max(maxm,u[i][i]);
        }
        
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                u[i][j]=v[j]*u[i][j-1];
                maxm=max(maxm,u[i][j]);
            }
        }
        //cout<<"The maxm product is: "<<maxm<<endl;
        return maxm;
        
    }
};