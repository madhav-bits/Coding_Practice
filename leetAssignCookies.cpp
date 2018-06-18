/*
*
//**************************************************************455. Assign Cookies.*****************************************************

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i 
has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, 
we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and 
output the maximum number.

Note:
You may assume the greed factor is always positive. 
You cannot assign more than one cookie to one child.

Example 1:
Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:
Input: [1,2], [1,2,3]

Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2]
[1,2,3]


[1,2]
[3,2]




// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting based. We sort two greed and biscuit size array. The point is that, the curr. smallest biscuit would be used to
// satisfy the child with least greed, so that all the bigger length biscuits would be used to satisfy else bigger biscuits. Making sure that
// we don't lose any possiblity of satisfying more child.


// Even if we don't sort the greed array and distribute biscuits in increasing size wise, that's ok. But, in that case, it's hard to keep track of 
// satisfied students, finding the child, who can be satisfied(increasing time complexity to O(n^2).





class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& v) {
        sort(g.begin(), g.end());											// Sort both greed and size arrays.
        sort(v.begin(), v.end());
        int count=0;														// Number of satisfied students.
        int index=0;
        for(int j=0;index<g.size() && j<v.size();j++){						// Iterating till end of kids/end of greed array.
            if(g[index]<=v[j]){												// If a child can be satisfied.
                index++;
                count++;
            }
        }
        // cout<<"The result is: "<<count<<endl;
        return count;														// Returning the #satisfied child.
    }
};