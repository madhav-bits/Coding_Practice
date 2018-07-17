/*
*
//**********************************************************320. Generalized Abbreviation.***************************************************

Write a function to generate the generalized abbreviations of a word. 

Note: The order of the output does not matter.

Example:

Input: "word"
Output:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"words"
"word"
"a"
""
"ab"



// Time Complexity: O(n!).  
// Space Complexity: O(n*2^n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*2^n).
// Space Complexity: O(n*2^n).	
// This algorithm is Binary representation based. As, we need to get abbrevation based on nums from 0 to pow(2,len). At each step, I iterate
// over the number and extract the 1/0 bits at each step and copy the char into final str accordingly. If we have >1 in sequence, we add them
// up and apend the string to temp str. 








class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string>res;
        for(int i=pow(2,word.length())-1;i>=0;i--){							// Iterating over all 2^n combinations.
            // cout<<"Curr. index: "<<i<<endl;
            int num=1<<(word.length()-1), count=0;							// Init. the bit extractor. 
            string temp="";
            for(int j=0;j<word.length();j++){
                while(j<word.length() && (i&num)>0){						// Extracing all bits from curr. num.
                    count++;
                    j++;
                    num/=2;
                } 
                if(j<=word.length()){										// Appending count to result str.
                    if(count>0) temp+=to_string(count);
                    temp+=word[j];											// Appending char after nums into result str.
                    count=0;
                }
                num/=2;														// Dec. the value of bit extractor.
                
            }
            // cout<<"Extracted string temp: "<<temp<<endl;
            res.push_back(temp);											// Appending the resutl str to vector of strings.
        }
        return res;															// Return the vector of strings.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(n*2^n).	
// This algorithm is DFS based. As, we need to get abbrevation based on seq. of 1' conse. ones that can be accomodated, we start from index -0,
//  at each step, we iteratre from curr. and last index and get the count at each step and append it to result str and forward it to next
// DFS call. We append the count value to the string and give DFS call. We start calc. count value, when last char in str is not an int.



class Solution {
public:
    void findAbbre(string&word, int index, vector<string>&res, string &str){
        if(index==word.length()){											// When end reached, append the str to result vector.
            res.push_back(str);
            return ;
        }
        int count=1;														// #ones in sequence starting from index.
        string temp=str;
        str+=word[index];													// Append curr. char and give DFS call.
        // cout<<"Updated to string: "<<str<<endl;
        findAbbre(word,index+1,res,str);	
        str=temp;
        if(str.length()>0 && (str.back()>=48 && str.back()<=57)) return;	// If last char is int, skip calc. count from this index.
        for(int i=index;i<word.length();i++){								// Calc. count at each step, append to it, give DFS call.
            str+=to_string(count);
            findAbbre(word,i+1,res,str);
            count++;													
            str=temp;
        }
        
    }
    
    vector<string> generateAbbreviations(string word) {
        vector<string>res;													// Final result vector of strings.
        string temp="";														// Temp. stores the result through DFS calls.
        findAbbre(word,0,res, temp);										// Give fn. call to get abbreviations
        return res;															// Returning the final result vector of strings.
    }
};