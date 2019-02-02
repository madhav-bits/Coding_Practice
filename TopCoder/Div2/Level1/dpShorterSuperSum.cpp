
/*
//***************************************************************ShorterSuperSum.**********************************************************************

SuperSum is a function defined as:

SuperSum(0 , n) = n, for all positive n.
SuperSum(k , n) = SuperSum(k-1 , 1) + SuperSum(k-1 , 2) + ... + SuperSum(k-1 , n), for all positive k, n.
Given k and n, return the value for SuperSum(k , n).

 
Definition
        
Class:  ShorterSuperSum
Method: calculate
Parameters: int, int
Returns:    int
Method signature:   int calculate(int k, int n)
(be sure your method is public)
    
 
Constraints
-   k will be between 1 and 14, inclusive.
-   n will be between 1 and 14, inclusive.
 
Examples
0)  
        
1
3
Returns: 6
When k = 1, SuperSum is equal to the sum of the first n = 3 numbers: 1 + 2 + 3 = 6.
1)  
        
2
3
Returns: 10
SuperSum(2 , 3) = SuperSum(1 , 1) + SuperSum(1 , 2) + SuperSum(1 , 3) = 1 + 3 + 6 = 10.
2)  
        
4
10
Returns: 2002
3)  
        
10
10
Returns: 167960



// Time Complexity: O(n*k)                                                              
// Space Complexity: O(n)                                                               
*/


//***************************************************************Solution 1.**********************************************************************

// Time Complexity: O(n*k)                                                              
// Space Complexity: O(n)                                                               


#include<vector>
#include<algorithm>
#include<iostream>


using namespace std;


class ShorterSuperSum{

    
public:
    int calculate(int k, int n){
    	vector<vector<int>>dp(2,vector<int>(n+1,0));
        for(int j=1;j<=n;j++) dp[0][j]=j;
        for(int i=1;i<=k;i++){
            int sum=0;
        	for(int j=1;j<=n;j++){
           		sum+=dp[(i-1)%2][j];
                dp[i%2][j]=sum;
            }
        }
        return dp[k%2][n];
    }
};