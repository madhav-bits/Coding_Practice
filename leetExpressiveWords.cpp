/*
*
//***********************************************************809. Expressive Words.****************************************************

Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of adjacent 
letters that are all the same character, and adjacent characters to the group are different.  A group is extended if that group is length 3 or 
more, so "e" and "o" would be extended in the first example, and "i" would be extended in the second example.  As another example, the groups 
of "abbcccaaaa" would be "a", "bb", "ccc", and "aaaa"; and "ccc" and "aaaa" are the extended groups of that string.

For some given string S, a query word is stretchy if it can be made to be equal to S by extending some groups.  Formally, we are allowed to 
repeatedly choose a group (as defined above) of characters c, and add some number of the same character c to it so that the length of the group 
is 3 or more.  Note that we cannot extend a group of size one like "h" to a group of size two like "hh" - all extensions must leave the group 
extended - ie., at least 3 characters long.

Given a list of query words, return the number of words that are stretchy. 

Example:
Input: 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not extended.
Notes:

0 <= len(S) <= 100.
0 <= len(words) <= 100.
0 <= len(words[i]) <= 100.
S and all words in words consist only of lowercase letters




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"heeelllooo"
["hello", "hi", "hello", "heeelllooo"]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm is straightforward calc. of #times a char occurs in sequence. In the list of words, #occurance of char has to match that of target
// string or #occurance < #occurance of that char in target string and #occurance in target string has to be >=3 times. If a doesn't satisfy these
// conditions, then move onto next word in array. 



cclass Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res=0;
        vector<vector<int>>count;
        int index=1, temp_count=1;
        while(index<s.length()){									// Calculates the #times of occurance of chars in target string in order of occur.
            if(s[index]!=s[index-1]){
                count.push_back({s[index-1], temp_count});
                temp_count=1;
                index++;
                continue;
            }
            temp_count++;
            index++;
        }
        count.push_back({s[index-1], temp_count});
        /*
        for(int i=0;i<count.size();i++){
            cout<<"The values are: "<<char(count[i][0])<<" and the count is: "<<count[i][1]<<endl;
        }
        */
        
        for(int i=0;i<words.size();i++){							// Iterating through the all the words in the array.
            //cout<<"****************************New string: "<<words[i]<<endl;
            int index1=1,index2=0, temp_count1=1;
            while(index1<words[i].length()){						// Iterating through a particular word.
                //cout<<"temp1 count for index: "<<index1<<" is: "<<temp_count1<<"curr. char: "<<words[i][index1]<<" and prev. char: "<<words[i][index1-1]<<endl;
                if(words[i][index1]!=words[i][index1-1]){			// Start counting the #occurance of next diff char.
                //count.push_back({s[index1-1], temp_count});
                    //cout<<"Char. changed at index: "<<index1<<endl;
                    if(index2<count.size() && char(count[index2][0])== words[i][index1-1] && (count[index2][1]== temp_count1 || count[index2][1] >=3 && count[index2][1] > temp_count1)){
                        index2++;
                    }
                    else{
                        //cout<<"Break called for string: "<<words[i]<<" at char: "<<words[i][index1-1]<<" and sequence: "<<char(count[index2][0])<<" is: " <<count[index2][1]<<" "<< temp_count1<<endl;
                        break;
                    }
                    temp_count1=1;
                    index1++;
                    //cout<<"Continue called."<<endl;
                    continue;
                }
                
                temp_count1++;										// Inc. the count of #occurances in sequence of a char in a word in array.
                index1++;
            }
            //cout<<"Outside while: "<<count[index2][1]<<" and the temp_count is; "<<temp_count1<<endl;
            if(index2== count.size()-1 && char(count[index2][0])== words[i][index1-1] && (count[index2][1]== temp_count1 || count[index2][1] >=3 && count[index2][1] > temp_count1)){
                //index2++;
                //cout<<"The value increased for string: "<<words[i]<<endl;
                res++;
            }														// If all chars #occurance matched to target string, then inc. the count.
            
        }
        return res;													// #Words are stretchy.
    }
};