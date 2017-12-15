/*

//**********************************************************740. Delete and Earn.*****************************************************

Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element 
equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:
Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].

//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/



// Solution 1: 
// Maintain two vectors one stores the sum of chosen vlaues till then, if elem. at index "i" is chosen, 
// other stores the sum of chosen vlaues till then, if elem. at index "i" is not chosen. At the end returning the max of the two array's last
// values.
// TWO VECTORS take & skip aren't required even as the take[i], skip[i] will depend on only it's previous value. I had maitained an-
// - array just for the sake of clarity.

class Solution {
public:
    int deleteAndEarn(vector<int>& v) {
        int len=10001;								// As given the question the range of elem. in the vector is [1,100000].
        vector<int> count(len,0);					
        for(const auto& num:v)						// As an elem. of a certain value is chosen, all it's occurences will contri. to total sum.
            count[num]+=num;						//So, creating parallel which contains no duplicates, so we can directly on indices.
        vector<int> take(len,0), skip(len,0);		
        take[0]=count[0];							//As the first elem. of take is the sum of all the elem's occurences itself. 
        for(int i=1;i<len;i++){
            take[i]=skip[i-1]+count[i];				
            skip[i]= max(take[i-1], skip[i-1]);
        }
        return max(take[len-1], skip[len-1]);		//Returning the max of two values, as max may be obtained from by choosing/ not choosing-
    }												//- the last value in the count array.
};