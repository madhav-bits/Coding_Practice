/*
*
//******************************************************332. Reconstruct Itinerary.***********************************************

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the 
tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For 
example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




// Time Complexity: O(n*n).  
// Space Complexity: O(n*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n).	
// Space Complexity: O(n*n).	
// This algorithm is DFS oriented. Each each port, we choose the lexically small port and does a Depth First travel in that drn, if it's terminated
// before passing by len+1 stations, then that DFS is terminated. Then travel in the next possible lexically small dest port.




class Solution {
public:
    
    bool calcIter(vector<string> &v, string port, unordered_map<string, vector<string>> &m, map<pair<string, string>, int> &occur, int num, int len){
        //if(m.count(port)==0 && !m.empty()) return false;
        //cout<<"Inside the calcIter with port: "<<port<<endl;
        num++;
        v.push_back(port);													// Inserting the curr. port to the path.
        if(num==len) return true;											// All the ports are travelled.
        for(int i=0;i<m[port].size();i++){
            //if(path.count(make_pair(port, m[port][i]))==1) continue;
            if(occur[make_pair(port, m[port][i])]==0) continue;				// No such edge exists.
            //occur.insert(make_pair(port, m[port][i]));
            occur[make_pair(port, m[port][i])]--;							// Dec. the count of edges(connecting that particular nodes).
            if(calcIter(v,m[port][i], m, occur, num, len)) return true;		// If all nodes visited, then return the answer.
            //occur.erase(make_pair(port, m[port][i]));
            occur[make_pair(port, m[port][i])]++;							// Updating the #edges for another possible path.
        }
        v.pop_back();														// Updating the node for another possible path.
        return false;														// If all nodes are not touched in this path, return false.
    }
    
    vector<string> findItinerary(vector<pair<string, string>> tick) {
        vector<string> v;
        map<pair<string, string>, int> occur;						// Stores the #of edges.
        unordered_map<string, vector<string>> m;					// Used to store the graph.
        for(int i=0;i<tick.size();i++){
            m[tick[i].first].push_back(tick[i].second);				// Forming a graph with the given edges.
            occur[make_pair(tick[i].first, tick[i].second)]++;		// Counting the #similar nodes.
        }                          
        
        for(auto it=m.begin();it!=m.end();it++)						// Sorting the dest ports, as we have to choose the lexically small port.
            sort(it->second.begin(), it->second.end());
        
        
        calcIter(v,"JFK", m, occur, 0, tick.size()+1);				// Calling the DFS fn.
        return v;
    }
};