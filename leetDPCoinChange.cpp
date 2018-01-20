/*
*
//*************************************************************322. Coin Change.****************************************************

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

//This is the example on which I had tweaked and worked on.
1) [4,2,1] 19
2) [1] 4

// Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).


class Solution {
public:
    int coinChange(vector<int>& v, int amount) {
        if(amount==0)
            return 0;
        int len=v.size();
        sort(v.begin(), v.end(), greater<int>());
        vector<int>sum(amount+1,amount+1);							//As, we need min. coins,So, we initialize to opt. large no. of coins possible.
        sum[0]=0;
        for(int j=0;j<len;j++){
            for(int i=1;i<=amount;i++){				
                if((i-v[j])>=0 )
                    sum[i]=min(sum[i-v[j]]+1, sum[i]);				//No. of coins to "i" equals min of coins to "i-v[j]" plus 1 and itself.
            }														//Itself also included, cause this sum this might be get in other ways also.			
            
        }
        
		//for(int i=0;i<=amount;i++)
		//	cout<<"for sum: "<<i<<" coins: "<<sum[i]<<endl;
	
        if(sum[amount]<=amount)										//NO. of coins differ from the initialized value, then amount achievable.
            return sum[amount];
        else														//If not possible to get sum, then return -1.
            return -1;
    }
};