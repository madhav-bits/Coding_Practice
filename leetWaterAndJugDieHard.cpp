/*

//*******************************************************365. Water and Jug Problem.*****************************************************
//*******************************************************THE FAMOUS DIE HARD PROBLEM.****************************************************
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to 
determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False
Credits:
Special thanks to @vinod23 for adding this problem and creating all test cases.



//Time Complexity: O(1).
// Space Complexity: O(1).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/
//Done using Mathematical Derivations/ Observations.
//******************************************************************************************T*********************************************
//All the shifts between the cans, and the remaining volume in each of the cans are actually multiples of GCD of two volumes. If the required-
//- volume is multiple of GCD and less than (x+y), then the volume is acheivable.
//******************************************************************************************T*********************************************

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==x || z==y || z==0)
            return true;
        if(z<=(long long )x+y && z%__gcd(x,y)==0)
            return true;
        return false;
    }
};