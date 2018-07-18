/*
*
//**********************************************************444. Sequence Reconstruction.***************************************************

Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers 
from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest 
sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from 
seqs and it is the org sequence.

Example 1:

Input:
org: [1,2,3], seqs: [[1,2],[1,3]]

Output:
false

Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
Example 2:

Input:
org: [1,2,3], seqs: [[1,2]]

Output:
false

Explanation:
The reconstructed sequence can only be [1,2].
Example 3:

Input:
org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]

Output:
true

Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
Example 4:

Input:
org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]

Output:
true
UPDATE (2017/1/8):
The seqs parameter had been changed to a list of list of strings (instead of a 2d array of strings). Please reload the code definition to get 
the latest changes.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3]
[[1,2],[1,3]]


[4,1,5,2,6,3]
[[5,2,6,3],[4,1,5,2]]


[1,2,3]
[[1,2],[1,3],[2,3]]


[4,1,2,3]
[[4,1,2,4],[1,2,3]]


[4,1,2,3,5]
[[4,1,2,3,1],[1,2],[2,3,5]]


[4,1,2,3,5]
[]


[1]
[]


[1]
[[],[]]



[5,3,2,4,1]
[[5,3,2,4],[4,1],[1],[3],[2,4],[1,1000000000]]




// Time Complexity: O(nodes+edges).  
// Space Complexity: O(nodes+edges).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nodes+edges).
// Space Complexity: O(nodes+edges).	
// This algorithm is Topological sort based using BFS. We first iterate over seqs and store the moves/edges in the vector, which says all the nodes 
// connected to curr. node. We also have another vector which tracks how many direct/ point towards curr. node. Here, in BFS we have to have only
// node in the queue as we need only one unique path. We also have to check for out of bound values. If the curr. value in queue during BFS
// doesn't match with char expected acc. to sequence return false. If, no issues arises until end of BFS and whole path is travelled, we return 
// true.



// This qsn's test cases lot of unnecc. test cases(out of bounds values/ empty seqs etc...). That's why it got disliked a lot.




class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        bool res;
        vector<vector<int>>edges(org.size()+1);								// Stores adj. nodes to curr. node.
        vector<int>prev(org.size()+1,0);									// Stores #nodes point towards curr. node.
        unordered_set<int>s;												// Tracks nodes mentioned in the seqs.
        for(int i=0;i<seqs.size();i++){										// Iterating over all seqs.
            for(int j=0;j<seqs[i].size();j++){
                if(seqs[i][j]<1 || seqs[i][j]>org.size()) return false;		// If nodes out of bounds occur. return false.
                s.insert(seqs[i][j]);										// Mark all encountered nodes.
                if(j<seqs[i].size()-1 && (seqs[i][j+1]>=1 && seqs[i][j+1]<=org.size())){
                    if(seqs[i][j]<1 || seqs[i][j]>org.size()) return false;	// Out of bounds values.
                    edges[seqs[i][j]].push_back(seqs[i][j+1]);				// Noting the edge.
                    // cout<<"Next of :"<<seqs[i][j]<<" is: "<<seqs[i][j+1]<<endl;
                    prev[seqs[i][j+1]]++;									// Counting #input edges.
                }
            }
        }
        queue<int>q;
        for(int i=1;i<=org.size();i++){
            if(prev[i]==0 && s.count(i)==1) q.push(i);						// Take nodes with zero input vectors.
        }
        // cout<<"queue size: "<<q.size()<<endl;
        if(q.size()!=1) return false;										// If >1 start nodes exist, then return false.
        int index=0;
        while(!q.empty()){
            int curr=q.front();
            // cout<<"curr. node: "<<curr<<endl;
            if(q.size()!=1 ||org[index]!=curr) return false;				// If nodes !=1 exists to trace path, then return false.
            index++;														// Inc. the iterator tracking curr. node in target path.
            q.pop();
            int len=edges[curr].size();
            for(int i=0;i<len;i++){											// Iterating over all edges of curr. node.
                int next=edges[curr][i];
                prev[next]--;
                if(prev[next]==0){											// Dec. the #input edges of adj. nodes to curr. node.
                    // cout<<"Pushing node: "<<next<<endl;
                    q.push(next);											// If no input edge exist, then push into queue.
                }
            }
        }
        return (index==org.size());											// If entire target path traversed, then return true.
    }
};