/*
*
//*************************1452. People Whose List of Favorite Companies Is Not a Subset of Another List.***************************

Given the array favoriteCompanies where favoriteCompanies[i] is the list of favorites companies for the ith person (indexed from 0).

Return the indices of people whose list of favorite companies is not a subset of any other list of favorites companies. You must 
return the indices in increasing order.

 

Example 1:

Input: favoriteCompanies = [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
Output: [0,1,4] 
Explanation: 
Person with index=2 has favoriteCompanies[2]=["google","facebook"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"] corresponding to the person with index 0. 
Person with index=3 has favoriteCompanies[3]=["google"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"] and favoriteCompanies[1]=["google","microsoft"]. 
Other lists of favorite companies are not a subset of another list, therefore, the answer is [0,1,4].
Example 2:

Input: favoriteCompanies = [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
Output: [0,1] 
Explanation: In this case favoriteCompanies[2]=["facebook","google"] is a subset of favoriteCompanies[0]=["leetcode","google","facebook"], therefore, the answer is [0,1].
Example 3:

Input: favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
Output: [0,1,2,3]
 

Constraints:

1 <= favoriteCompanies.length <= 100
1 <= favoriteCompanies[i].length <= 500
1 <= favoriteCompanies[i][j].length <= 20
All strings in favoriteCompanies[i] are distinct.
All lists of favorite companies are distinct, that is, If we sort alphabetically each list then favoriteCompanies[i] != favoriteCompanies[j].
All strings consist of lowercase English letters only.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]


[["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]


[["leetcode"],["google"],["facebook"],["amazon"]]


// Time Complexity: O(n*m+n^2).												// m-Avg. number of companies in each list.
// Space Complexity: O(n*m+n*50000)=O(n*m).									// Size of map + (n*50000) bits for bitset array.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n*m+n^2).												// m-Avg. number of companies in each list.
// Space Complexity: O(n*m+n*50000)=O(n*m).									// Size of map + (n*50000) bits for bitset array.
//The algorithm is based on BIT Manipulation based. Here, going by the problem's constraints, we know that there are at max. 50000 
// companies. So, we create a vector of bitset datasets of size 50000 and store the occurance of companies in each list in the corres.
// bitset's index. We assign a between 0 and 50000 to each of the companies using map. In the second iter. we iter. over all bit rep.
// of rest lists and find if curr. list's rep is subset of any other list by using rep[i] & rep[j]==rep[i] notation, here if the AND
// returns rep[i] means that all the companies in curr. list are subset of some other list(j), then we won't include in the final list.
// If at the end of iter. if there aren't any subset scenarios, we add it to final result list.








class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& v) {
        vector<bitset<50000>>rep;											// Stores reps of all lists.
        unordered_map<string,int>st;										// Used to assign indices to companies and track them.
        int index=0;
        for(int i=0;i<v.size();i++){										// Iter. over all lists.
            bitset<50000>bt;
            for(int j=0;j<v[i].size();j++){
                if(st.count(v[i][j])==0) st[v[i][j]]=index++;				// Assigning index to each of the companies.
                bt[st[v[i][j]]]=1;											// Forming rep.of all companies in curr. list.
            }
            rep.push_back(bt);												// Adding. curr. rep to rep array.
        }
        vector<int>res;														// Stores index of non-subset lists.
        for(int i=0;i<v.size();i++){										// Iter. over all lists.
            bool uniq=true;													// Says that curr. list is non-subset.
            for(int j=0;j<v.size() && uniq;j++){							// Iter. over rest of the lists in array.
                if(i==j) continue;											// Avoiding duplicates.
                if((rep[i]&rep[j])==rep[i]) uniq=false;						// If curr. list is subset of some other list.
            }
            if(uniq) res.push_back(i);										// If curr. list is not subset of any other list.
        }
        return res;															// Returning the final list of non-subset lists.
    }
};