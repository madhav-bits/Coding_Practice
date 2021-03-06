/*
*
//******************************************************1268. Search Suggestions System.******************************************************

https://leetcode.com/problems/search-suggestions-system/


Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products 
after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products 
with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
Example 4:

Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]
 

Constraints:

1 <= products.length <= 1000
There are no repeated elements in products.
1 <= Σ products[i].length <= 2 * 10^4
All characters of products[i] are lower-case English letters.
1 <= searchWord.length <= 1000
All characters of searchWord are lower-case English letters.


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


["mobile","mouse","moneypot","monitor","mousepad"]
"mouse"
["ab","ac","cd","cecd","cf"]
"cd"




// Initial Sorting.
// Time Complexity: O(nlogn).												// n- length of the given array.
// Space Complexity: O(1).	

// Query: 
// Time Complexity: O(logn)
// Space complexity: O(m*l)													// m-#query length, l-#length of the words.


//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Initial Sorting.
// Time Complexity: O(nlogn).												// n- length of the given array.
// Space Complexity: O(1).	

// Query: 
// Time Complexity: O(logn)
// Space complexity: O(m*l)													// m-#query length, l-#length of the words.
// This algorithm is Binary Search based. Here, for every substring of query, we search for first index which is >=substring, we check the next 3 indices
// and check whether substring can be found at the beginnning of each of indices and push them into final result array.



// This link has good explanation of the below approach.
// https://leetcode.com/problems/search-suggestions-system/discuss/436674/C%2B%2BJavaPython-Sort-and-Binary-Search-the-Prefix






class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& v, string searchWord) {
        vector<vector<string>>res;
        sort(v.begin(), v.end());											// Sorting the given array.
        string temp="";
        for(char ch:searchWord){
            temp+=ch;														// Forming substring starting from 0-index.
            // cout<<"search word: "<<temp<<endl;
            vector<string>u;
            auto it=lower_bound(v.begin(), v.end(), temp);					// Searching for first index which is >=substring.
            for(int i=0;i<3 && (it+i)!=v.end();i++){
                string &s=*(it+i);
                // cout<<" word to check: "<<s<<endl;
                if(s.find(temp)!=0) break;									// If substring is not found at 0-index, we break from checking words.
                u.push_back(s);
            }
            res.push_back(u);												// Pushing prefix matched words into final result array.
        }
        return res;															// Returning the prefix matched words for all the substrings of the query.
    }
};

