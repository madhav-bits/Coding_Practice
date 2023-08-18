/*
*
//******************************************************2284. Sender With Largest Word Count.******************************************************

https://leetcode.com/problems/sender-with-largest-word-count/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"]
["Alice","userTwo","userThree","Alice"]
["How is leetcode for everyone","Leetcode is useful for practice"]
["Bob","Charlie"]



// Time Complexity: O(n).													// n-#messages.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n-#messages.
// Space Complexity: O(n).	
// This algorithm is Map based. We iter. over messages and count #words in each of the message and update the cnt in the map with the corres. sender key. If 
// the new count of #words of sender is>#words by res or #words and res match but sender>res, we update res and max words count. We return res at the end of 
// iteration.







class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        string res="";
        int maxTotal=0;
        unordered_map<string, int>m;
        for(int i=0;i<messages.size();i++) {
            int cnt=0, j=0;
            while(j<messages[i].length()) {									// Counting #' 's as they occur only once b/w words and no trail/lead ' 's.
                if(messages[i][j]==' ') cnt++;								// Inc. cnt by 1, as ' ' would signify completion of a word.
                j++;
            }
            cnt++;															// To account for last word in the message.
            m[senders[i]]+=cnt;												// Update the total words count by this sender in map.
            if(m[senders[i]]>maxTotal || (m[senders[i]]==maxTotal && senders[i]>res)) {// Update the res if curr. sender words count if greater of equal and-
                res=senders[i];												// sender>res.
                maxTotal=m[senders[i]];										// We update res and maxWords.
            }
        }
        return res;															// Returning the sender who sent max words in total.
    }
};

