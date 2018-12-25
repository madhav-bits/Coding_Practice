/*
*
//************************************************************956. Tallest Billboard.*****************************************************

You are installing a billboard and want it to have the largest height.  The billboard will have two steel supports, one on each side.  Each 
steel support must be an equal height.

You have a collection of rods which can be welded together.  For example, if you have rods of lengths 1, 2, and 3, you can weld them together to 
make a support of length 6.

Return the largest possible height of your billboard installation.  If you cannot support the billboard, return 0.

 

Example 1:

Input: [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.
Example 2:

Input: [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
Example 3:

Input: [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.
 

Note:

0 <= rods.length <= 20
1 <= rods[i] <= 1000
The sum of rods is at most 5000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[1,2,3,4,5,6]


[10,12,32,21,2,6,9,4]


[1,2,4,8,16,32,64,128,256,512,50,50,50,150,150,150,100,100,100,123]


[]


[3,4,3,3,2]



// Time Complexity: O(n*k).													// k= Max. possible value sum of poles lengths.			  
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(3^n).													// Can't be said excatly, as pruning conditions are placed.
// Space Complexity: O(3^n).	
// This algorithm is Recursion/BackTracking based. Here, in each turn of recursion either we take the rod to left/right leg of billboard or 
// we ignore the rod and give recursion call to decide on following rods. The instant we have both legs of equal length, we update the max.
// height var.. We also employ the PRUNING CONDITIONS to terminate the recursions early. We sort the rods in desc. order of lengths, as we 
// might greater res values in eariler recursions, helping PRUNING conditions to terminate the recursions earlier.






class Solution {
public:
    int res=0;
    void findHeight(vector<int>&v, int index, int left, int right, int remLen){	// Takes each rod at a time.
        if(left==right) res=max(res, left);									// If both sides have equal length, update max. height.
        if(index==v.size() || (abs(left-right)>remLen) || (left+right+remLen<=res*2)) return ;// THIS IS WHERE WHOLE MAGIC HAPPENS, PRUNING
											// CONDITIONS DICTATE FLOW.
											// IF DIFF IN BOTH HEIGHTS IS GREATER THAN REM. RODS LENGTH, THEN BOTH SIDES CAN'T BECOME SAME LENGTH.
											// IF SUM OF ALL INVOLVED LENGTHS IS 2*RES, THEN THOSE RODS CAN'T FORM HEIGHTS > RES.
        findHeight(v,index+1, left+v[index], right, remLen-v[index]);		// Rod added to left side of billboard.
        findHeight(v,index+1, left, right+v[index], remLen-v[index]);		// Rod added to right side of billboard.
        findHeight(v,index+1, left, right, remLen-v[index]);				// Rod not involved in both the legs.
        return ;
    }
    
    int tallestBillboard(vector<int>& v) {
        if(v.size()<=1) return 0;
        int total=0;
        sort(v.begin(), v.end(), greater<int>());							// Sorted in Dec. order as greter res values are obtained early,
																			// helping pruning conditions to terminate recursions.
        for(auto num: v) total+=num;										// Sum of lengths of all rods.
        findHeight(v,0,0,0, total);											// Calling fn. to get max. Height of billboard.
        return res;															// Returning the max. height of billboard.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k).													// n= No. of poles, k=possible values of sum of poles lengths.
// Space Complexity: O(n*k).	
// This algorithm is Dynamic Programming based. It is very similar to Weighted Knapsack problem. 
// It is very similar to Weighted Knapsack problem. Here, as we bulid on the smaller test cases to 
// form larger test cases(More number of rods), moreover as different scenarios where same diff. in heights are of same value here. we build DP
// from bottom to top. We track maxm. height possible for each possible height diff. b/w two ends for certain number of poles used. We return 
// max. height possible for all rods considered with diff. being 0(dp[len][5000]).


// We started from 5000, as sum of all rods is<5000, inorder to accomodate negative height diff. in pole selection.
// dp[i][5000+j] indicates max. height that can be achieved after considering first 'i' poles and with a diff. in height at two ends being 'j'.

// Here, we get the max. height from a distribution of rods to both legs from the left leg.





class Solution {
public:
    
    int tallestBillboard(vector<int>& v) {
        if(v.size()<2) return 0;
        int len=v.size();
        vector<vector<int>>dp(v.size()+1, vector<int>(10001, -1));						// Init. DP array.
        dp[0][5000+v[0]]=v[0];															// Taking in the first rod to left leg.
        dp[0][5000-v[0]]=0;																// Taking in the first rod to right leg.
        dp[0][5000]=0;																	// Ignoring the first rod.
        for(int i=1;i<v.size();i++){
            for(int j=0;j<=10000;j++){
                if(dp[i-1][j]<0) continue;
                if(j+v[i]<=10000) dp[i][j+v[i]]=max(dp[i][j+v[i]], dp[i-1][j]+v[i]);    // Adding curr. elem. to group 1.
                if(j-v[i]>=0) dp[i][j-v[i]]=max(dp[i][j-v[i]], dp[i-1][j]);             // Adding curr. elem. to group 2.
                dp[i][j]=max(dp[i][j], dp[i-1][j]);                                     // Ignoring curr. elem.
            }
        }
        return (dp[len-1][5000]>=0)?dp[len-1][5000]:0;
    }
};









//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k).													// n= No. of poles, k=possible values of sum of poles lengths.
// Space Complexity: O(k).			
// This algorithm is Dynamic Programming based. It is very similar to Weighted Knapsack problem. Here, as we bulid on the smaller test cases to 
// form larger test cases(More number of rods), moreover as different scenarios where same diff. in heights are of same value here. we build DP
// from bottom to top. We track maxm. height possible for each possible height diff. b/w two ends for certain number of poles used. We return 
// max. height possible for all rods considered with diff. being 0(dp[len][5000]).


// We started from 5000, as sum of all rods is<5000, inorder to accomodate negative height diff. in pole selection.
// dp[i][5000+j] indicates max. height that can be achieved after considering first 'i' poles and with a diff. in height at two ends being 'j'.



// This is improved version of above one, space complexity wise.




class Solution {
public:
    
    int tallestBillboard(vector<int>& v) {
        if(v.size()<2) return 0;
        int len=v.size();
        vector<vector<int>>dp(2, vector<int>(10001, -1));
        dp[0][5000+v[0]]=v[0];
        dp[0][5000-v[0]]=0;
        dp[0][5000]=0;
        for(int i=1;i<v.size();i++){
            for(int j=0;j<=10000;j++){
                if(dp[(i-1)%2][j]<0) continue;
                if(j+v[i]<=10000) dp[i%2][j+v[i]]=max(dp[i%2][j+v[i]], dp[(i-1)%2][j]+v[i]);    // Adding curr. elem. to group 1.
                if(j-v[i]>=0) dp[i%2][j-v[i]]=max(dp[i%2][j-v[i]], dp[(i-1)%2][j]);             // Adding curr. elem. to group 2.
                dp[i%2][j]=max(dp[i%2][j], dp[(i-1)%2][j]);                                     // Ignoring curr. elem.
            }
        }
        return (dp[(len-1)%2][5000]>=0)?dp[(len-1)%2][5000]:0;
    }
};

