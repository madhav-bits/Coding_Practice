/*
*
//****************************************************************464. Can I Win.*********************************************************

In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to 
reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both 
players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


20
290



5
21


20
300



10
11



20
110


// Time Complexity: O(2^num).  												// If all the possiblities of the nums are used.
// Space Complexity: O(2^num).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^num).
// Space Complexity: O(2^num).												// If all the possiblities of the nums are used.	
// This algorithm is HashMap. Here, we mark the nums taken/used by marking that indexed char in taken string and passing it to the recursive call
// along with updated sum obtained. If the call receives a taken string which had been already visited, then return the value stored on it's name.
// Now, in a call, we iterate over all possible nums, skipping those which had been already used. If a recursive returns false/ sum of nums
// adding that num >=target value, then we return true from this recursive call, we also assign the taken string at this instant to TRUE in visited
// map. If we don't observe any false from inner recursive calls, we return false from curr. recursive call, also set the taken string to FALSE.








class Solution {
public:
    
    bool findWinner(int limit, int target, string&taken, int sum, unordered_map<string, bool>&visited){
        string temp=taken;													// Temp. storing taken string(Not required infact).
        if(visited.count(temp)==1) return visited[temp];					// If this pattern already visited, then return the result.
        bool res=false;														// Stores result of inner recursive call.
		for(int i=1;i<=limit;i++){											// Iter. over all possible nums.
            if(taken[i]=='/') continue;										// Skip already used nums.
            taken[i]='/';													// Marking used nums with '/' in that index in taken string.
            res=findWinner(limit, target, taken, sum+i, visited);			// Give recursive call with updated sum, taken string.
            taken[i]='.';													// Reverting back to not used state.
            if(res==false || sum+i>=target){								// If false observed, then set curr. state to true and return true.
                visited[temp]=true;
                return true;
            }
        }
        visited[temp]=false;												// If no false/loss observed from recursive calls, then return false/lost.
        return false;
    }
    
    
    bool canIWin(int limit, int target) {
        int ach=(limit*(limit+1))/2;										// If sum of all nums is <target, return false.
        if(ach<target) return false;
        string taken="";													// Tracks nums used.
        unordered_map<string, bool>visited;									// Tracks pattern of nums used and their results.
        for(int i=0;i<=limit;i++) taken+='.';   							// Marking with '.' for not used state.
        return findWinner(limit, target, taken, 0, visited);				// Calling fn. to know winner.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^num).
// Space Complexity: O(2^num).	
// This algorithm is HashMap & Bucketing based. Here, we mark the nums taken/used by setting that numbered bit in filled var. We also track
// visited used nums state by setting that filled value index to TRUE(1)/FALSE(0) accordingly in a vector, whose size is chosen according to 
// the question. Rest of the logic is same as the above solution.


// This algo. has better execution speed, as we had used vectors instead of unordered_map to track already visited states, we also used smaller 
// memory integer to keep track of used nums.
// We made many vars to global vars to reduce copying time/improve execution time.







class Solution {
public:
    
    bool findWinner(int sum, long int filled){
        // cout<<"inside fn. with filled; "<<filled<<" and sum: "<<sum<<endl;
        if(dp[filled]!=-1) return (dp[filled]==1);
        bool res=false;
        for(int i=1;i<=limit;i++){
            if((filled&(1<<i))!=0) continue;
            filled=(filled|(1<<i));											// Setting the curr. used numbered bit to 1 in filled var.
            res=findWinner(sum+i, filled);
            filled=(filled&~(1<<i));										// Setting to 0, curr. iterated numbered bit in filled var.
            if(res==false || sum+i>=target){
                dp[filled]=1;
                return true;
            }
        }
        dp[filled]=0;
        return false;
    }
    
    
    bool canIWin(int lt, int tg) {
        int ach=(lt*(lt+1))/2;
        if(ach<tg) return false;
        // dp=vector<int>(1<<(lt+1),-1);
        dp.assign(1<<(lt+1),-1);											// Assigning -1 to all indices in DP array.
        limit=lt;
        target=tg;
        long int filled=0;													// Tracks nums used.
        return findWinner(0, filled);
    }
    int limit, target;
    vector<int>dp;															// Tracks already encountered used nums state.
};