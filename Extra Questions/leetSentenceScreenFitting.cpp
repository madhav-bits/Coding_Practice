/*
*
//**********************************************************418. Sentence Screen Fitting.***************************************************

Given a rows x cols screen and a sentence represented by a list of non-empty words, find how many times the given sentence can be fitted 
on the screen.

Note:

A word cannot be split into two lines.
The order of words in the sentence must remain unchanged.
Two consecutive words in a line must be separated by a single space.
Total words in the sentence won't exceed 100.
Length of each word is greater than 0 and won't exceed 10.
1 ≤ rows, cols ≤ 20,000.
Example 1:

Input:
rows = 2, cols = 8, sentence = ["hello", "world"]

Output: 
1

Explanation:
hello---
world---

The character '-' signifies an empty space on the screen.
Example 2:

Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]

Output: 
2

Explanation:
a-bcd- 
e-a---
bcd-e-

The character '-' signifies an empty space on the screen.
Example 3:

Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]

Output: 
1

Explanation:
I-had
apple
pie-I
had--

The character '-' signifies an empty space on the screen.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["I", "had", "apple", "pie"]
4
5


["a", "bcd", "e"]
3
6



["hello", "world"]
2
8


["I", "have","a","strawhat","but","lost"]
6
8







// Time Complexity: O(n).  
// Space Complexity: O(k).													// #Words in sentence.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).
// Space Complexity: O(k).													// #Words in sentence.
// This algorithm is iteration based. We start iterating in each row. Iterate through each word of string, and check whether end of clmn is 
// reached or not? If end is reached while adding length of curr. word, we move back to count again that word's len in next row. If end is reached
// after adding ' ' after a word, then that's ok. Whenever index 0 is reacehd we inc. the count(#Times sentence fits in given space).In this way, 
// we iterate over entire rows, keeping track of #times index 0 had been reached. 






class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int>len(sentence.size());
        for(int i=0;i<sentence.size();i++) len[i]=sentence[i].length();		// Storing lens of words in vector.
        int count=0, index=0;												// Tracks #times sentence iterated, curr. scanning word's index.
        int clmn=0, row=0,del=0;											// Tracks curr. row and curr. clmn, to move index iterator back.
        while(row<rows){													// Iterating over all rows.
            clmn=0;del=0;
            // cout<<"Curr. row: "<<row<<endl;
            while(clmn<cols){												// Iterating over clmns.
                // cout<<"clmn: "<<clmn<<" and index: "<<index<<endl;
                clmn+=len[index];											// Adding curr. word's length.
                clmn++;
                index++;
                if(index==len.size()){										// If end of sentence is reached, inc. the count of #sentences.
                    index=0;												// Start iteration from the start.
                    count++;
                }
                // cout<<"Index: "<<index<<" and clmn: "<<clmn<<endl;
                if(clmn>cols+1) del=1;										// If word crosses clmn length, then move back index iterator.
            }
            if(del==1 && index>0) index--;									// Moving back index iterator.
            else if(del==1 && index==0){									// Moving back index iterator and dec. the count.
                index=len.size()-1;
                count--;
            }
            row++;															// Inc. the count num.
            // cout<<endl;
        }
        return count;														// Returning the count.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(k).													// #Words in sentence.
// This algorithm is iteration and DP based. As, we have limited number of words in sentence, as each time a new line starts with a word. We 
// maintain a DP array to track the next row's word index if curr. row starts with this index. This way, we avoid iterating all over clmn. 
// to calculate next row's start index.




class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int len=sentence.size();
        vector<int>dp(len,0);
        for(int i=0, index=0, dist=0;i<len;i++, dist=0){					// Iterating over all words.
            index=i;
            while(dist+sentence[index%len].length()<=cols)					// Till end of clmn is reached.	
                dist+=sentence[index++%len].length()+1;
            
            dp[i]=index-i;													// Extracting #words fits in clmn.
        }
        
        int count=0, index=0;												// Tracks #sentences covered till now, curr. word index.
        for(int i=0;i<rows;i++){
            count+=dp[index];												// Adding #words fitting in this row with index as start word index.
            // index=(count)%len;
            index=(index+dp[index])%len;									// Next row's start word index.
        }
        return count/len;													// Returning #times sentence fits in given space.
    }
};