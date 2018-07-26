/*
*
//**********************************************************126. Word Ladder II.***************************************************

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, 
such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"hit"
"cog"
["hot","dot","dog","lot","log","cog"]





// Time Complexity: O(n+m).  												// Nodes+Edges.
// Space Complexity: O(n+m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n).
// Space Complexity: O(m+n).	
// This algorithm is BFS+DFS based. We start from the src, and do a BFS search towards desti. At each step, we store the nodes from where the curr.
// node is reachable. On reaching the target, we store all possible nodes that reach to dest. when started from src. In the second iteration,
// DFS, we do a reverse traverasl from dest. to start word. In the traversal, we store the words iterated till now, once on reaching the start
// we reverse the path and push it into final result vector.






class Solution {
public:
     vector<vector<string>> res;											// Final result vector.
    void extractPath(string &target, string &src,unordered_map<string,vector<string>>&prev,vector<string>&tempPath){
        if(src==target){
            // cout<<"src reached."<<endl;
            tempPath.push_back(target);										// Pushing the curr. node into path.
            reverse(tempPath.begin(), tempPath.end());						// Reverse the path.
            // for(auto str: tempPath)
            //     cout<<" "<<str;
            // cout<<endl;
            res.push_back(tempPath);										// Push curr. node into final result vector.
            reverse(tempPath.begin(), tempPath.end());						// Bring it to orig. state.
            tempPath.pop_back();											// Push curr. node into final result vector.
            return ;
        }    
        // cout<<"Curr. source str: "<<src<<endl;
        tempPath.push_back(src);											// Push curr. node into final result vector.
        for(int i=0;i<prev[src].size();i++){
            // cout<<"prev str: "<<prev[src][i]<<endl;
            extractPath(target,prev[src][i],prev,tempPath);					// Traversing in all possible drns from curr. node.
        }
        tempPath.pop_back();// Push curr. node into final result vector.
    }
    
   
    vector<vector<string>> findLadders(string src, string target, vector<string>& v) {
        unordered_map<string,int>dict,visited,dist;							// valid nodes/Tracks all visited nodes/dist. to nodes from src.
        unordered_map<string,vector<string>> prev;							// Stores all prev. nodes to curr. node if start from src.
        dict[src]=v.size();													// Storing the valid nodes.
        for(int i=0;i<v.size();i++)											// Storing the valid nodes.
            dict[v[i]]=0;
        if(dict.count(target)==0) return res;								// If target is not a valid node, return false.
        queue<string>q;														// Stores nodes to be visited.
        q.push(src);														// Start from src and mark as visited.
        visited[src]=1;
        bool found=false;
        int path=-1;
        while(!q.empty()){
            int len=q.size();
            path++;															// Store the dist. from src to curr. node.
            for(int i=0;i<len;i++){											
                string curr=q.front();
                string temp;
                // cout<<"Curr. str: "<<curr<<endl;
                q.pop();
                if(curr==target){											// If target reached.
                    found=true;												// Mark as found.
                    break;
                }
                for(int j=0;j<curr.length();j++){							// Iter. through all chars in a str.
                    temp=curr;
                    for(int k=97;k<=122;k++){								// Creating all possible moves.
                        temp[j]=k;	
                        if(dict.count(temp)==0) continue;					// If new isn't valid nodes, then skip it.
                        if(dist.count(temp)==0) dist[temp]=path;			// Store dist. to curr. from src.
                        if(dist[temp]>=path) prev[temp].push_back(curr);	// If path with same dist. found add prev. node to list.
                        if(visited.count(temp)==0 ){						// If node is not visited.
                            // cout<<"Pushing str into queue."<<temp<<endl;
                            q.push(temp);									// Push into queue and mark as visited.
                            visited[temp]=1;
                        }
                    }
                }
            }
            if(found==true)													// If target found break from while loop.
                break;
        }
        if(found==false) return res;										// If target not found, return empty vector.
        vector<string>tempPath;												// Tracks path from end to start.
        // cout<<"dest found."<<endl;
        extractPath(src,target,prev,tempPath);								// Call fn. to extract all possible paths from src to target.
        return res;															// Reutrn the result vector of vector of strings.
    }
};