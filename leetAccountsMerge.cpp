/*
*
//**************************************************************721. Accounts Merge.*******************************************************

Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the 
elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both 
accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person 
can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the 
elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com", "john_newyork@mail.com"],["John","johnnybravo@mail.com"]]

[["Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"],["Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"],["Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"],["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"],["Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"]]






// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Union Find based. In the first iteration we make all mails as their parents and also map mails to their owner. In the second
// iteration, we make a user's mails starting from second's parent the first mail. In the third iteration, we push all mails with same root parent
// mail under root parent mail key in a map. In the fourth iteration, we iterate through the root parent mails, we push owner and append all else
// mails to owner's list.


// This question can also be solved by using DFS. Store all mails and their owner's index in first iteration. In the second iter. go through all
// owners and also do DFS through all indices/owners where you find curr. owner's mails.



class Solution {
public:
    
    map<string, string>parent;												// Maps mail to it's parent.
    string findParent(string node){											// Find the root parent of a mail.
        while(parent[node]!=node) node=parent[node];
        return node;
    }
    
    void setParent(string node1, string node2){						// Set node2's root parent node's parent to be node1's root parent node's parent.
        parent[node2]=parent[node1];
        return ;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& v) {
        map<string, string> m;												// Which maps emails to name of person.
        map<string, vector<string>>s;										// Tempo. stores all mails with same root parent mail.
        vector<vector<string>> res;											// Final accounts after merging.
        for(int i=0;i<v.size();i++){
            for(int j=1;j<v[i].size();j++){
                parent[v[i][j]]=v[i][j];									// In the first iteration, set parent nodes of all mails to self.
                m[v[i][j]]=v[i][0];											// Map mails to their owner name.
            }
        }
        for(int i=0;i<v.size();i++){
            for(int j=2;j<v[i].size();j++){									//In the second iter., make the first mail's parent as parent to all
                parent[findParent(v[i][j])]=parent[findParent(v[i][1])];	// else mails of that person.
            }
        }
        
        for(auto it:m){
            s[findParent(it.first)].push_back(it.first);					// Stores all mails with same root parent node under the root node key.
        }
        int i=0;
        for(auto it: s){													// Now, we iterate through all root parent nodes.
            res.push_back({m[it.first]});									// First pushing the Owner of root parent node.
            //cout<<"The key: "<<m[it.first]<<endl;
            for(int j=0;j<it.second.size();j++)
                res[i].push_back(it.second[j]);								// Push all mails to root parent node's owner's list.
            i++;
        }
        return res;															// Returning the accounts after merging.
    }
};