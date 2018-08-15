/*
*
//******************************************************599. Minimum Index Sum of Two Lists.***********************************************

Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them
 with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Shogun","Tapioca Express","Burger King","KFC"]
["Piatti","The Grill at Torrey Pine


	

// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Hash Map based. We first store the indices of first person's favs in a map. We then iterate over second person favs and 
// check whether they had previously occured. If yes, sum their indices, and track the min. sum at every point of iteration. If we found a new 
// min. sum, then update the min. sum value and also update the list with curr. restaurent. If the curr. sum is <min. sum, then update the min.
// sum and update the list with only curr. restaurent. Thus, we stores restaurents with min. sum at every point, at the end of iteration, 
// return the restaurents with min. sum.









class Solution {
public:
    vector<string> findRestaurant(vector<string>& u, vector<string>& v) {
        unordered_map<string,int>m;											// Tracks indices of fav hotels of first person.
        // unordered_map<int,vector<string>>list;
        // vector<vector<string>>list(u.size()+v.size()-1);
        vector<string>s;													// Stores hotels with min. sum.
        for(int i=0;i<u.size();i++){										// Storing indices of hotels of first person.
            m[u[i]]=i;
        }
        int res=INT_MAX;													// Default min. sum.
        for(int i=0;i<v.size();i++){										// Iter. over second person hotels.
            if(m.count(v[i])==1){											// If it's a common hotel.
                // res=min(res,m[v[i]]+i);
                // list[m[v[i]]+i].push_back(v[i]);
                if(res==m[v[i]]+i) s.push_back(v[i]);						// If the sum is repeating min. sum add curr. to hotel list.
                else if(m[v[i]]+i<res){										// If it's a new min. sum.
                    s.clear();												// Clear the prev. list.
                    s.push_back(v[i]);										// Push the curr. hotel.
                    res=m[v[i]]+i;											// Update the min. sum value.
                } 
            }
        }
        return s;															// Return the hotels with min. sum.
    }
};