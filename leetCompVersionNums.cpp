/*
*
//******************************************************165. Compare Version Numbers.***********************************************

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
Credits:
Special thanks to @ts for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

"1.2,3"
"1.10.3.4"


"1.0.001"
"1"

"1.2,3"
"1.2"


"1.1.100"
"1"




// Time Complexity: O(n).  
// Space Complexity: O(n).							//As, I am reshaping the Strings.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).							//As, I am reshaping the Strings.
// This algorithm is that it iterates through the two strings making '.' as delimiters. Comparing the values of ints extracted between them. If
// a ints of same values are extracted, then we look for the next value between next '.'s. If the greater/lesser value is obtained, we return 1/-1.
// In the beginning, it travels from the back and removes all the trailing no-valued zeroes {1.000->1}. Thus, we can safely values iterating
// from the start. The number which gets completed first can be said be of lower version. If two versions complete at same time with same set of 
// ints, then they are same.



class Solution {
public:
    int compareVersion(string s1, string s2) {
        int dig1,dig2, begin1=-1, begin2=-1, i=0,j=0, end1=0, end2=0;
        int temp1=s1.length()-1, temp2=s2.length()-1, last1=s1.length()-1, last2=s2.length()-1;
        while(1){							// Removing trailing zeroes between '.'s.
            while(s1[temp1]=='0') temp1--;
            if(s1[temp1]=='.'){ last1=temp1-1; temp1--;}
            else{							// If non-zero is encountered, this set of values shouldn't be removed.
                //cout<<"Changing s1 with last1: "<<last1<<endl;
                s1=s1.substr(0, last1+1);	//Updating the string.
                break;
            }
        }
        while(1){						// Removing trailing zeroes between '.'s.
            while(s2[temp2]=='0') temp2--;
            if(s2[temp2]=='.') {last2=temp2-1; temp2--;}
            else{
                //cout<<"Changing s1 with last1: "<<last2<<endl;
                s2=s2.substr(0, last2+1);
                break;
            }
        }
        
        //cout<<" Updated string1 is; "<<s1<<endl;
        //cout<<" Updated string2 is: "<<s2<<endl;
        while(end1==0 && end2==0){
            while(i<s1.length() && s1[i]!='.') i++;
            while( j<s2.length() && s2[j]!='.') j++;
            
            if(i==s1.length()) end1=1;								//Marking that this string's end is reached.
            if(j==s2.length())  end2=1;								//Marking that this string's end is reached.
            //cout<<" Curren values of i: "<<i<<" and j: "<<j<<endl;
            dig1=stoi(s1.substr(begin1+1, i-begin1-1));				//Extracting int values b/w two '.'s.
            dig2=stoi(s2.substr(begin2+1, j-begin2-1));
            begin1=i;begin2=j;
            i++; j++;												// Updating params, helpful in extracing values.
            //cout<<"Current dig1 is: "<<dig1<<" and dig2: "<<dig2<<endl;
            if(dig1>dig2) return 1;									// If s1's int> s2's int, then return 1;
            if(dig1<dig2) return -1;
        }
        //cout<<"Outside the while with end1: "<<end1<<" and end2: "<<end2<<endl;
        if(end1==1 && end2==1) return 0;							// If both strings are completed at same time with same values,then they are same.
        else if(end1==1) return -1;									// If s1 has ended, s2 is greater.
        else return 1;												// If s2 has ended, s1 is greater.
    }
};