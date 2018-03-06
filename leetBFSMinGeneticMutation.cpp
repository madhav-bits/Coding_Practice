/*
*
//******************************************************433. Minimum Genetic Mutation.***********************************************

A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character 
changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" 
to "end". If there is no such a mutation, return -1.

Note:

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.
Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1
Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2
Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

"CGA"
"AGC"
["CTA", "ATA", "ATC","AGC"]




// Time Complexity: O(n^n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^n).	
// Space Complexity: O(n).	
// This algorithm is BFS. It extracts, all possible next moves(strings) from the current string, and push into map which are in the bank and not 
// visited till now. We stop, the instant, we got the target string or we don't have any unvisited strings in queue. As a improvement, if the target
// gene is not their bank, we return -1 prior starting the iteration.
// As an improvement, we can also pass to extrMoves fn. visited map to dec. #strings returned from fn.

class Solution {
public:
    
    vector<string> extrMoves(map<string, int> m, string curr){
        string temp;
        vector<string> v;
        for(int i=0;i<8;i++){									//Extracing all possible single mutations form curr. gene string.
            temp=curr;
            if(curr[i]!='C') temp[i]='C';						// If curr. gene's index doesn't have 'C', then we change it to 'C'.
            if(m[temp]==1) v.push_back(temp);					// If mutation is in bank, then only push it to vector.

            if(curr[i]!='A') temp[i]='A';
            if(m[temp]==1) v.push_back(temp);

            if(curr[i]!='G') temp[i]='G';
            if(m[temp]==1) v.push_back(temp);

            if(curr[i]!='T') temp[i]='T';
            if(m[temp]==1) v.push_back(temp);
        }
        return v;												// Returning all possible legal mutations.
    }
    
    int minMutation(string start, string end, vector<string>& u) {
        int count=0;
        //string temp=start;									// visit- marks those genes which are scanned/visited.
        map<string, int> bank,dist, visit;						// dist- stores #moves from start gene to any curr. gene
        queue<string> q;										// To store unvisited adj. mutations.
        for(int i=0;i<u.size();i++) bank[u[i]]=1;               // Storing the possible moves-bank.
        if(bank[end]==0) return -1;								// If the target gene is not in bank, then we can't form that gene from mutations.
        q.push(start);											// Pushing the start gene into queue.
        visit[start]=1;											// Marking the start as visited.
        dist[start]=0;											// As, the dist.=0
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            vector<string>v;
            v=extrMoves(bank, curr);							// Contains all possible single mutations from curr. gene.
            //cout<<"Extracted adj. strings for: "<<curr<<" are: "<<v.size()<<endl;
            for(int i=0;i<v.size();i++){						//Iterating through all possible sigle mutation moves from curr. gene.
                //cout<<" Curr. string is: "<<curr<<" and the modified string is: "<<v[i]<<endl;
                if(v[i]==end) return dist[curr]+1;				// If target gene is found, returning #mutations.
                if(visit[v[i]]==0){								// Pushing into queue, those strings which are unvisited.
                    dist[v[i]]=dist[curr]+1;					// Updating the dist. to them.
                    visit[v[i]]=1;								// Marking as visited.
                    q.push(v[i]);								// Pushing into queue for scanning.
                }
            }
        }
        return -1;												// If, not found after all iterations, then there is no way reaching target gene.
    }
};