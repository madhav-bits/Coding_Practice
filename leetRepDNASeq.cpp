/*

//**************************************************187. Repeated DNA Sequences***********************************************

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it 
is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].


//Time Complexity: O(n).
// Space Complexity: O(n).

//**************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //cout<<"The length is: "<<s.length()<<endl;
        vector<string> v;
        if(s.length()<10)
            return v;
        unordered_map<string,int> m;// Allows search operation to be O(1).
        for(int i=0;i<s.length()-9;i++){
            ///*// This indicated uncommented part is one way to solve. 
            auto it=m.find(s.substr(i,10));
            if(it!=m.end() &&it->second==1)// Whenever a string sequence is already present(once), then only pushes into vector.
                v.push_back(s.substr(i,10));//Making sure that same string sequence is not pushed ">" once.
            //*/
                m[s.substr(i,10)]+=1;
            
        }
        /*// This indicated commented part is another way to solve.
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>1)
                v.push_back(it->first);
        }
        */
        return v;
    }
};