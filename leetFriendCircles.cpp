/*
*
//**************************************************************547. Friend Circles.*****************************************************

There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A 
is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students 
who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are 
direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,1,0,0],[1,1,1,1],[0,1,1,0],[0,1,0,1]]
[[1,1,0,0,1],[1,1,1,0,0],[0,1,1,0,0],[0,0,0,1,0],[1,0,0,0,1]]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).	
// Space Complexity: O(1).	
// This algorithm iterates the array, iterates through the entire friends array. Does, Backtrackig on each of it's friend, and mark them
// as visited. Such, that a node's visited friends aren't visited. In fact, this can be even optimized by avoiding visiting already visited
// nodes. This optimizes by 50% percent. 





class Solution {
public:
    //int count=1;
    void findCircles(vector<vector<int>> &v, int j){
        //v[j][j]=2;
        for(int m=0;m<v.size();m++){
            if(j==m) v[j][m]=2;
            else if(v[j][m] ==1 ){					// Avoiding visiting already visited a node's friends.
                v[j][m]=2;
                //cout<<"Inside fn,Changing value of index i: "<<j<<" and j: "<<m<<" with count: "<<count<<endl;
                findCircles(v,m);					// Calling the friend node.
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& v) {
        int count=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                //if(i==j) v[i][j]=2;
                if(v[i][j]==1){						// From the connection, which has been not yet touched yet.
                    v[i][j]=2;
                    count++;						// Inc. no. of circles accordingly.
                    //cout<<"Changing value of index i: "<<i<<" and j: "<<j<<" with count: "<<count<<endl;
                    findCircles(v,j);
                }
            }
        }
        //cout<<"The answer is: "<<count<<endl;
        return count;								// Returning no. of counts accordingly.
        
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).
// This is the optimized code. Avoids visiting already visited nodes.


class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		visited.resize(M.size(), false);
		int ret = 0;
		for (int i = 0; i < M.size(); ++i) {						//Calling the fn. for all nodes, which are not visited till then.
			if (!visited[i]) {
				visited[i] = true;
				++ret;
				expandCircle(M, i);
			}
		}
		return ret;
	}
private:
	// DFS expand circle
	void expandCircle(const vector<vector<int>>& M, const int i) {
		for (int j = 0; j < M.size(); ++j) {						// Checking the friends of the current node.
			if (M[i][j] && !visited[j]) {
				visited[j] = true;
				// include all j's direct friends in i's circle
				expandCircle(M, j);
			}
		}
	}

	vector<bool> visited;
};













