/*

//****************************************************6. ZigZag Conversion*******************************************************

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display 
this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


//Time Complexity: O(n).
// Space Complexity: O(n).

//**************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/

class Solution {
public:
    string convert(string s, int num) {
        string t;
        if(num==1)
            return s;
        vector< string> v;
        for(int i=0;i<num;i++)
            v.push_back("");// Initializing the vector with strings, so that we can push_back elements into empty string.
        int a=1;
        for(int i=0;i<s.length();i++){
            if(i%(num-1)==0 && a==1)// This is for top to bottom.
                a=0;
            else if(i%(num-1)==0 && a==0)// This is for bottom to top.
                a=1;
            if(a==0)// Pushing elem. into vector while traversing from top to bottom.
                v[i%(2*num-2)].push_back(s[i]);
            
            if(a==1){// Pushing elem. into vector while traversing from bottom to top.
                int rem=i%(num-1);
                v[num-1-rem].push_back(s[i]);
            }
            
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){// Pushing vector's elements into final result string.
                //cout<<"vector content for i: "<<i<<" and j: "<<j<<" is: "<<v[i][j]<<endl;
                t+=v[i][j];
            }
        }
        //cout<<"t is: "<<t<<endl;
        return t;
    }
};