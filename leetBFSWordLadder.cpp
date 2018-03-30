/*
*
//************************************************************127. Word Ladder.*****************************************************

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to 
endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest 
changes.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


// No Test cases, I had created and worked on.




// Time Complexity: O(n*#dict_words).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*#dict_words).	
// Space Complexity: O(n).	
// This algorithm is BFS Oriented. We start from the beginning, extract all the adjacent words(words which differ with curr. string by single char).
// We push into queue only those strings which have not been visited till now. Once, the dest. node is reached, we return the #elem. traversed
// till then.

// This can be optimized by traversing from both the ends. After every step, we chose from one from both the sides, which has less number of nodes
// to travel to.



class Solution {
public:
    int ladderLength(string source, string dest, vector<string>& dict) {
        if(find(dict.begin(), dict.end(), dest)==dict.end()) return 0;
        int len= source.length();
        queue<pair<string, int>>q;										// Forming a pair(curr node and dist from source to that node+1).
        unordered_set<string> path;										// Stores nodes which were traversed till now.
        q.push(make_pair(source,1));									// Pushing the source node into queue.
        path.insert(source);
        int num;
        while(!q.empty()){
            string curr;
            pair<string, int> p=q.front();
            q.pop();
            int num=p.second;											// #Nodes from source to this node+1.
            curr=p.first;												// Curr. node.
            //cout<<"Inside the while with string: "<<p.first<<" with num: "<<num<<endl;
            for(int i=0;i<dict.size();i++){								// Iterating through all the members of the dict.
                int count=0;
                for(int j=0;j<curr.length();j++){						// Finding strings from dict. which differ from curr node by single char.
                    if(curr[j]!=dict[i][j]) count++;
                    if(count>1) break;
                }
                if(count==1 && dict[i]==dest) return num+1;				// If the next node is dest. return #nodes in the path.
                if(count==1 && path.count(dict[i])==0){					// If the next node is not dest. and unvisit till now, then push into queue.
                    q.push(make_pair(dict[i], num+1));
                    path.insert(dict[i]);								// Updating the psth traversed.
                    //dict.erase(dict.begin()+i);
                }
            }
        }
        
        return 0;														// If the dest. nodes is not reachable, then return 0.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*#dict_words).	
// Space Complexity: O(n).	
// This algorithm is BFS Oriented. We start from the beginning, extract all the adjacent words(words which differ with curr. string by single char).
// We push into queue only those strings which have not been visited till now. Once, the dest. node is reached, we return the #elem. traversed
// till then.

// This can be optimized by traversing from both the ends. After every step, we chose from one from both the sides, which has less number of nodes
// to travel to.
// This algorithm is same as the above one, except that few optimizations were made.






class Solution {
public:
    int ladderLength(string source, string dest, vector<string>& dict) {
        if(find(dict.begin(), dict.end(), dest)==dict.end()) return 0;
        queue<string> q1;
        unordered_set<string> path;
        q1.push(source);
        path.insert(source);
        int num=1;
        while(!q1.empty()){
            string curr;
            int len=q1.size();
            //cout<<"The size of queue is: "<<len<<endl;
            for(int k=0;k<len;k++){
                curr=q1.front();
                q1.pop();
                //cout<<"Inside the while with string: "<<curr<<" with num: "<<num<<endl;
                for(int i=0;i<dict.size();i++){
                    int count=0;
                    for(int j=0;j<curr.length();j++){
                        if(curr[j]!=dict[i][j]) count++;
                        if(count>1) break;
                    }
                    if(count==1 && dict[i]==dest) return num+1;
                    if(count==1 && path.count(dict[i])==0){
                        q1.push(dict[i]);
                        path.insert(dict[i]);
                        //dict.erase(dict.begin()+i);
                    }
                }
            }
            num++;
        }
        
        return 0;
    }
};