/*
*
//****************************************************************Word Ladder I.*********************************************************

https://www.interviewbit.com/problems/word-ladder-i/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


7 
hot dot dog lot log hit hit


8 
hot dot dog lot pot log hit pot



// Time Complexity: O(n*n*26).
// Space Complexity: O(Size of dict).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n*26).
// Space Complexity: O(Size of dict).	
// This algorithm is BFS based. We start from the start word, we make changes on each char. and if the new word is in dict and it's not visited
// till now, we push it into queue, to further get various combination of words from this. As, we are making sure, duplicate words are not pushed
// into queue, we are avoiding making cycles. The first time we encounter target word is the min. edit dist from the source word.








int Solution::ladderLength(string start, string target, vector<string> &dictV) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    unordered_map<string,int>visited,dict;									// Tracks visited words till now, store dict. words.
    for(auto str:dictV) dict[str]=1;										// Form a dict. in Maps.
    if(dict.count(start)==0) return 0;										// If start isn't in dict. return 0.
    if(start.length()!=target.length()) return 0;							// If start and target's length doesn't match return 0.
    visited[start]=1;														// Mark start word as visited before BFS.
    queue<string>q;															// Stores Words to be checked and used to form further combi. of words.
    q.push(start);															// Push start into queue.
    int dist=-1;															// Tracks Dist. of words from start word.
    while(!q.empty()){														// Till no more words to check on.
        dist++;																// Inc. the dist var.
        int len=q.size();													
        for(int i=0;i<len;i++){												// Iter. over all words at same dist. from source word.
            string curr=q.front();											// Store curr. word.
            string temp=curr;												// Temp. store the curr. word.
            // cout<<"curr. str: "<<curr<<endl;
            if(curr==target) return dist+1;									// If curr. word is target, return dist+1.
            q.pop();														// Remove curr. word from Queue.
            for(int j=0;j<curr.length();j++){								// Change all indices in curr. word(One index at a time).
                temp=curr;													// Update the temp. word.
                for(int ch=97;ch<=122;ch++){								// Iter. over all possible chars for every index.
                    temp[j]=ch;												// Update the curr. index with curr. char.
                    if(dict.count(temp)==1 && visited.count(temp)==0){		// New word is unvisited, present in Map.
                        // cout<<"new: "<<temp<<" ";
                        q.push(temp);										// Push new word into Queue.
                        visited[temp]=1;									// Mark new word as visited.
                    }
                }
                
            }
        }
        
        
    }
    return 0;																// If target word isn't reachable, return 0.
}
