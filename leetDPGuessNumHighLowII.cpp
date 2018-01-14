/*

//******************************************************375. Guess Number Higher or Lower II.***************************************************

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

Credits:
Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.



//Time Complexity: O(n^3).
// Space Complexity: O(n^3).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************


class Solution {
public:
    int getMoneyAmount(int n) {
        int result;
        int dp[n+1][n+1]={0};
        
        ///*
        for(int i=1;i<=n;i++){					//This is the length of the subarray.
            for(int j=1;j+i<=n;j++){			//This is the beginning of the subarray.
                int minm=INT_MAX;
                for(int k=j+1;k<j+i;k++){		//When a no. k is chosen, it's value and the max of the subarrays make the worst case.
                    minm=min(minm,k+max(dp[j][k-1],dp[k+1][j+i]));
                }
                dp[j][j+i]=(i==1)?j:minm;		//Choosing the smallest of the worst cases.
            }									//If only two elem. are in subarray, choosing the lowest val. gives the min. cost.
        }
        /*
        for(int i=0;i<=n;i++){					//Iterating through all the elements in the dp array.
            for(int j=0;j<=n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        */
        //cout<<"the result is: "<<dp[1][n]<<endl;
        return dp[1][n];						//Returs the min. worst value for the subarray of numbers 1 to n.
    }
};


//*************************************************************Solution 2: ***************************************************************
//This solution is the same as the above solution, except few included cases as described below.
//This solution contains the cases when the edge numbers(i,j) are chosen when subarray [i,j] under consideration.
//These cases were eliminated in *****Solution 1***** as they won't form the min. value which we are calc. once we exit from the innermost for loop.

class Solution {
public:
    int getMoneyAmount(int n) {
        int result;
        int dp[n+1][n+1]={0};
        
        for(int i=1;i<=n;i++){
            for(int j=1;j+i<=n;j++){
                int minm=INT_MAX;
                for(int k=j;k<=j+i;k++){
                    if(k>j && k<j+i)
                        minm=min(minm,k+max(dp[j][k-1],dp[k+1][j+i]));
                    else if(k==j)
                        minm=min(minm, k+dp[k+1][j+i]);
                    else if(k==j+i)
                        minm=min(minm, k+dp[j][k-1]);
                }
                dp[j][j+i]=(i==1)?j:minm;
            }
        }
		
        /*
        for(int i=0;i<=n;i++){				
            for(int j=0;j<=n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        */
        //cout<<"the result is: "<<dp[1][n]<<endl;
        return dp[1][n];
    }
};