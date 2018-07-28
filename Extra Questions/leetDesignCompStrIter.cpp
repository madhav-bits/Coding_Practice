/*
*
//******************************************************604. Design Compressed String Iterator.***********************************************

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an 
increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing 
in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. 
Please see here for more details.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"L1e2t1C1o1d1e1"															// Not curr. format to give as input though.


"L1e2t1C1o2d1e12"

"L1"


"a1c3b1"



// Time Complexity: O(n).  													// Each call would only take O(1).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// Each call would only take O(1).
// Space Complexity: O(n).	
// This algorithm is iteraton based. We iterate once, and store the count of each char and char itself in two vectors sequentially in the order 
// of extraction. While receiving queries, we maintain three vars, one to store the curr. char other to store the #remaining curr. chars to 
// be print, and the other to track the curr. char in the list of chars. When we don't have any more curr. chars to be returned, we inc. the 
// index and update the curr. char and #rem. curr. char count. If the curr. char's index is valid(<v.size()), then return true, else return 
// false.






class StringIterator {
public:
    int count=0,index=0,rem=0;												// Track curr. returning char, #curr. retur. chars remaining to print.
    string str,finalStr;
    vector<char>v1;															// Stores the extracted Chars.
    vector<int>v2;															// Stores the extracted Chars count.
    char ch;																// Temp. stores the char.
    StringIterator(string v) {	
        int temp=0;
        char prev='0';
        for(int i=0;i<v.size();i++){										// Iterating through the given string.
            if(v[i]>=48 && v[i]<=57) temp=temp*10+v[i]-48;					// Calc. the count(#occur).
            
            else if(isalpha(v[i])){											// If char found.
                if(temp>0){													// If #occur. is >0.
                    v1.push_back(prev);										// Push the char in v1.
                    v2.push_back(temp);										// Push the char in v2.
                }
                temp=0;														// Resetting the count=0.
                prev=v[i];													// Setting the char. for next count.
            }
        }
		
        if(temp>0){															// If the last char #occur>0.
            v1.push_back(prev);												// Push the count, char into resp. vectors.
            v2.push_back(temp);
        }
        // cout<<"v1 size: "<<v1.size()<<endl;
        if(index<v1.size()){												// Init. values for extracting during calls.
            ch=v1[0];														// Setting the first char. to access.
            index=0;														// Index. rep. the curr. char.
            rem=v2[0];														// Setting #curr. chars remaining.
        }
    }
    
    char next(){
        if(index>=v2.size()) return ' ';									// If no more chars left, return ' '.
        char temp=ch;														// Temp. storing the curr. char.
        rem--;																// Dec. the count of curr. char.
        if(rem==0){															// If no curr. chars left, move to next char.
            index++;
            if(index<v2.size()){											// If next char valid, assign the #remaining count and char.
                rem=v2[index];
                ch=v1[index];
            }
            
        }
        return temp; 														// Returning the curr. char.
    }
    
    bool hasNext() {														
        if(index<(int)v1.size()) return true;								// If curr. char is valid, return true.
        return false;														// If not, return false.
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */