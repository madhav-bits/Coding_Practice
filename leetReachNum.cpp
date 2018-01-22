/*
*
//********************************************************754. Reach a Number.****************************************************

You are standing at position 0 on an infinite number line. There is a goal at position target.

On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

Return the minimum number of steps required to reach the destination.

Example 1:
Input: target = 3
Output: 2
Explanation:
On the first move we step from 0 to 1.
On the second step we step from 1 to 3.
Example 2:
Input: target = 2
Output: 3
Explanation:
On the first move we step from 0 to 1.
On the second move we step  from 1 to -1.
On the third move we step from -1 to 2.
Note:
target will be a non-zero integer in the range [-10^9, 10^9].



// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(1).


class Solution {
public:
    int reachNumber(int target) {
        int n=1;
        target=abs(target);
        while(n*(n+1)/2<target)
            n+=1;
        //cout<<"number is: "<<n<<endl;
        int diff=(n*(n+1)/2)-target;			//How many back is the target compared to the curr. psn.
        //cout<<"diff is: "<<diff<<endl;
        if(diff%2==0)							//If the diff. is even, then it can be reached by taking  a step of value(diff/2) in other drn.
            return n;
        else if( (diff+n+1)%2==0){				//We aim to get to get even diff. which can be reached by moving in other dirn. a step- 
            return n+1;							//of val.(diff+n+1)/2. We add one more step of val. (n+1) here.So, count inc. by one.		
        }
        else									//If the even diff. is not formed in the above two calc. then even. diff will be formed if we
            return n+2;							// include (n+2) steps. A setp of val.(diff+n+1+n+2)/2. in other dirn. balances the distance 
    }
};