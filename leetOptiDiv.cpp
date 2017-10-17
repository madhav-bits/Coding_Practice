/*
Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations. 
You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. 
Your expression should NOT contain redundant parenthesis.

Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
since they don't influence the operation priority. So you should return "1000/(100/10/2)". 

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
Note:

The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.

//***********************************************************THIS IS LEET ACCEPTED CODE.*************************************
*/
class Solution {
public:
    string optimalDivision(vector<int>& v) {
        string s;
        if(v.size()==1)// The value is maximized by minimalizing the denom. which is possible if we keep on dividing from L->R in denom.
            return to_string(v[0]);
        if(v.size()==2)
            return to_string(v[0])+"/"+to_string(v[1]);
        s=to_string(v[0])+"/("+to_string(v[1]);
        for(int i=2;i<v.size();i++)
            s+="/"+to_string(v[i]);
        s+=")";
        return s;
    }
};