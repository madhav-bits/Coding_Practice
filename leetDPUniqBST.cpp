/*
*
//****************************************************96. Unique Binary Search Trees.*********************************************

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

   
//These are the cases I had created and worked on.
1
2
100
4
19


// Time Complexity: O(n*2).
// Space Complexity: O(n*2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n*2).
// Space Complexity: O(n*2).
// This is a recursiv


class Solution {
public:
    
    int numTrees(int n) {
        long long int result;
        vector<long long int>dp(n+1,0);				// Saves no. of possib. of forming a tree for index no. of elements.
        dp[0]=1;dp[1]=1;
        //result=findPossib(dp,n);
        for(int i=2;i<=n;i++){
            int temp=0;
            for(int j=1;j<=i;j++){					//If "i" elements present. If "j"th element is chosen as mid. Two subtrees are formed.
                //int res1=dp[j-1];
                //int res2=dp[i-j];
                //temp+=res1*res2;
				temp+=dp[j-1]*dp[i-j];				// Multi. no. of possi. in left and subtrees resp. and multiplying them to get overall possib.
            }
            dp[i]=temp;								// Saves overall possib. if "i" elem. are there as we iterate and choose all elem. once as node. 
            //cout<<"dp value for i: "<<i<<" is: "<<dp[i]<<endl;
        }
        //result=dp[n];
        //cout<<"The result is: "<<result<<endl;
        return dp[n];								//Returning no. of possib. for "n" elements in a tree.
    }
};




//************************************************************Solution 2:************************************************************
// Time Complexity: O(n*2).
// Space Complexity: O(n*2).
// Optimized the a bit in the for loop(Not Asymptotical level improvement), but still the run time remains the same.

class Solution {
public:
    int numTrees(int n) {
        //long long int result;
        vector<long long int>dp;
        dp.push_back(1);
        dp.push_back(2);
        dp[0]=1;dp[1]=1;
        //result=findPossib(dp,n);
        for(int i=2;i<=n;i++){
            int temp=0;
            for(int j=1;j<=(i+1)/2;j++){
                if((i%2)!=0 && j==(i+1)/2)				//If odd no. of elem. are present the mid elem. have to be chosen once.
                    temp+=dp[j-1]*dp[i-j];
                else									// As no. of possib. are same for pair of elem. whose dist. from their closest end is same.
                    temp+=2*(dp[j-1]*dp[i-j]);
            }
            //dp[i]=temp;
            dp.push_back(temp);							// Pushing the resultant possib. ito the vector.
            //cout<<"dp value for i: "<<i<<" is: "<<dp[i]<<endl;
        }
        //result=dp[n];
        //cout<<"The result is: "<<result<<endl;
        return dp[n];									//Returns the no. of possib. for "n" elements in the tree.
    }
};







//************************************************************Solution 3:************************************************************
// Time Complexity: O(n*2).
// Space Complexity: O(n*2).
// This is a DYNAMIC PROGRAMMING problem solved using recursive functions. Takes each element in the number in a row starts adding their res.
//subtree arrange possibilities. Saving the previous results and using them to calculate the no. of possibilities for large number of elements.



class Solution {
public:
    int findPossib(vector<int>v,int n){
        if(n==1) return 1;
        if(n==0) return 1;
        if(v[n]!=0) return v[n];
        int temp=0;
        for(int i=1;i<=n;i++){								//If "n" elements present. If "i"th element is chosen as mid. Two subtrees are formed.
            int res1=findPossib(v,i-1);						// No. of possibilities of arrangement of left subtree.
            int res2=findPossib(v,n-i);						// No. of possibilities of arrangement of Right subtree.
            temp+=res1*res2;
        }
        v[n]=temp;
        return v[n];
    }
    
    int numTrees(int n) {
        int result;
        vector<int>dp(n+1,0);
        dp[0]=1;dp[1]=1;
        result=findPossib(dp,n);							//Receives the result for "n" no. of elements.
        return result;										// Returning the result.
    }
};




