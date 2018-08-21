/*
*
//**************************************************************573. Squirrel Simulation.*******************************************************

There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for 
the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move 
in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.
Example 1:
Input: 
Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12
Explanation:

Note:
All given positions won't overlap.
The squirrel can take at most one nut at one time.
The given positions of nuts have no order.
Height and width are positive integers. 3 <= height * width <= 10,000.
The given positions contain at least one nut, only one tree and one squirrel.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
7
[2,2]
[4,4]
[[3,0], [1,4],[0,5],[4,5]]



6
7
[2,4]
[5,4]
[[3,0], [1,4],[3,5],[5,5]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Math/observation based. Here, so as to bring a nut to the tree, we need to travel from the tree to the nut and bring it back to 
// tree, except the first one. So, we want to choose that nut as first one, which contributes less dist. to total dist. travelled. So, we want to 
// minimize (2*sum of all dists to tree)-2*chosen one's dist to tree + chosen one's dist to tree+it's dist to squirrel. We keep track of min. possi.
// last three terms through the iteration and add it to the 2*sum of all dists to tree to get the result.








class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& sq, vector<vector<int>>& nuts) {
        vector<int>dist(nuts.size(),0),toTree(nuts.size(),0);				// To stores dist. of nuts to Tree and init. psn of squirrel.
        for(int i=0;i<nuts.size();i++){										// Iter. through nuts, calc. dist. to tree, init. psn of squirrel.
            int len=abs(nuts[i][0]-sq[0])+abs(nuts[i][1]-sq[1]);			// Calc. Manhattan distance to squirrel.
            dist[i]=len;
            len=abs(nuts[i][0]-tree[0])+abs(nuts[i][1]-tree[1]);			// Calc. Manhattan distance to Tree.
            toTree[i]=len;
        }
        int minm=-toTree[0]+dist[0];										// Init. the minm var to contribution of first nut.
        int sum=2*toTree[0];												// Adding up first nuts dist. to tree to sum var.
        for(int i=1;i<nuts.size();i++){										// Iter. through rest of nuts.
            sum+=2*toTree[i];												// Adding up all nuts dists. to tree.
            if(-toTree[i]+dist[i]<minm) minm=-toTree[i]+dist[i];			// Tracking min. contribution to final dist.
        }
        // cout<<"sum: "<<sum<<endl;
        // cout<<"index: "<<ind<<"with minm: "<<minm<<endl;
        int ans=sum+minm;													// Calc. ans.
        return ans;															// Returning the min. dist. needed to collect all nuts.
    }
};