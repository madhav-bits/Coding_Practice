/*
*
//**********************************************************474. Ones and Zeroes.******************************************************

In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".



//Time Complexity: O(n^3).
// Space Complexity: O(n^3).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//This problem is similar to (0/1)-Kanpsack, 2 Partition Subset Sum Problem(Near Similar to Problem No. 416). 


class Solution {
public:
    int findMaxForm(vector<string>& v, int m, int n) {
        vector<vector<int>> u(m+1, vector<int>(n+1,0));			//Stores max no. of strings can be "i"-zeros and "j"-ones, init. all val. to 0.
        for(auto str:v){
            int zeros=0, ones=0;
            for(auto s:str){									//Counting the #zeroes in a string.
                if(s=='0')
                    zeros++;
                if(s=='1')
                    ones++;
            }
            
            for(int i=m;i>=0;i--){
                for(int j=n;j>=0;j--){
                    if((i-zeros)>=0 && (j-ones)>=0)				// Accessing only legitimate values of #zeros and #ones.
                        u[i][j]=max(u[i][j], u[i-zeros][j-ones]+1);//If i-zeros and j-ones form "x" no. of strings then i, j would "x+1" strings.
                }													//Saving the maxm of the two values.
            }
        }
        //cout<<"The answer is: "<<u[m][n]<<endl;
        return u[m][n];											//Returning the max # strings can be formed with m-zeros and n-ones.
    }
};