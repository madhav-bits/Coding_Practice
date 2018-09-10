/*
*
//**************************************************************Word Ladder II.*******************************************************

https://www.interviewbit.com/problems/word-ladder-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


9 hot dot dog lot log pit sot hit cog




// Time Complexity: O(dict_size).  
// Space Complexity: O(n*num1). 											// inv_sigma(dict_size)-> sigma(num1)=dict_size.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(dict_size).
// Space Complexity: O(n*num1).												// inv_sigma(dict_size)-> sigma(num1)=dict_size.
// This algorithm is BFS+DFS based. We first use BFS to reach Target string in the shortest possible dist. and form graph, form nodes b/w curr. 
// string and the strings that can be formed from curr. str. We form graph, as we can't store the path separately to a node in the path in BFS. As,
// at each level(at a dist. from src), lot of nodes would be stored, to stores paths corresponding to each of those nodes would throw Memory Limit
// Exceeded error. Instead, we form graph in the process, such that we can do DFS in the second iteration, starting from target as all edges
// in reverse drn from target would lead to source node. We do DFS, as we will be working/storing path of a single node at a time, instead of all
// nodes at a level in case of BFS.









void extractPath(unordered_map<string,vector<string>>&prev, string &src, vector<string>&path, vector<vector<string>>&res, string curr){
    // cout<<"Path size: "<<path.size()<<endl;
    path.push_back(curr);													// Add curr. path to path.
    if(curr==src){															// On reaching src, we push path into final result str.
        reverse(path.begin(), path.end());									// Reverse path, as we travelled from target to src.
        res.push_back(path);
        reverse(path.begin(), path.end());									// Reverting back to accomodate following DFS traversals.
        path.pop_back();
        return ;
    }
    
    for(int i=0;i<prev[curr].size();i++){									// Iter. over all edges.
        extractPath(prev,src,path,res,prev[curr][i]);						// Call fn. to extract paths on each edge.
    }
    path.pop_back();														// Remove curr. node from path.
    
}

vector<vector<string> > Solution::findLadders(string src, string target, vector<string> &v) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>>res;
    unordered_map<string,int>dict,visited;									// Tracks dict, visited nodes.
    unordered_map<string,vector<string>>prev;								// Graph storing rln b/w curr. and strings formable from it.
    for(auto str:v) dict[str]=1;											// Forming a map from given dict words.
    if(dict.count(src)==0) return res;										// If src isn't in dict, then return empty result.
    queue<string>q;															// Nodes to be visited.
    int dist=0;
    visited[src]=0;
    q.push(src);
    bool found=false;
    while(!q.empty()){														// Until all nodes are visited.
        int len=q.size();
        dist++;																// Updating the dist. from src string.
        for(int i=0;i<len;i++){
            string curr=q.front();
            visited[curr]=1;
            q.pop();
            string temp;
            // cout<<"Curr. "<<curr<<endl;
            for(int j=0;j<curr.length();j++){								// Iter. over all indices of curr. str.
                temp=curr;
                for(int ch=97;ch<=122;ch++){								// Modifying to all possible chars.
                    temp[j]=ch;												// Changing the char.
                    if(dict.count(temp)==0) continue;
                    if(visited.count(temp)==1 && visited[temp]<dist) continue;// If new string is already formed in prev. levels, then ignore it.
                    if(visited.count(temp)==0) q.push(temp);				// If new str never visited, push into queue.
                    visited[temp]=dist;										// Update the dist.
                    prev[temp].push_back(curr);								// Form the edge b/w old and new str.
                    if(temp==target) found=true;							// If target obtained, mark as found.
                }
            }
        }
        if(found) break;													// We stop moving to next level, once target is reached.
    }
    
    if(!found) return res;													// If tagret not found, return empty result vector.
    vector<string>path;														// Stores temp. path from target to curr. node.
    extractPath(prev,src,path,res,target);									// Call fn. to extract all paths from src to target.
    return res;																// Return final result paths vector.
    
}
