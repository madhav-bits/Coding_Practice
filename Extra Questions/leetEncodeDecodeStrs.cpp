/*
*
//******************************************************271. Encode and Decode Strings.***********************************************

Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the 
original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on 
any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"a","2bc","3def","","#","efgh"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array. Merge all the strings into one final str. IN the beginning we add a int of length 8(bit form of int)
// indicating how many strings are there in the accumulated string, whose lengths are appended at the end of the string in the second iteration. 
// In the decoding part, we first extract the number of strings in the string from the first 8 chars, then extract lens of all strings from the 
// back, then iterate the string from the front, and extract the strings whose lengths are known to us.


// I made a small mistake while analyzing the problem and come up with this sln, th solution 2 is a neatly thought through one.




class Codec{
public:

	string encode(vector<string>& strs) {
		int len=0;
		string res="";
		for(int i=0;i<strs.size();i++){										// Merging strings into bigger string.
			res+=strs[i];
		}	
		bitset<8>num=strs.size();											// Getting bit form of #strings.
		res=num.to_string()+res;											// Adding bits in the beginning.
		for(int i=0;i<strs.size();i++){
			res+="#"+to_string(strs[i].length());							// Appending all the lengths at the back of the string.
		}
		return res;															// Returning the combined string.
	}

	  // Decodes a single string to a list of strings.
	vector<string> decode(string s) {
	  vector<string>res;
	  int num=stoi(s.substr(0,8));											// Extracing the #strings in the string.
	  int psn=1, len=0;
	  while(num>0){
		  int temp=num%10;
		  len+=temp*psn;
		  psn*=2;
		  num/=10;
	  }
	  cout<<"len: "<<len<<endl;
	  int len2=len;
	  vector<int>lens(len,0);												// Stores lengths of all the strings in the string.
	  int curr,prev=s.length();												// Tracks indices of each string while extraction.
	  while(len>0){															// Extracting lengths of all strings in string.
		  curr=prev-1;
		  while(s[curr]!='#') curr--;										// Reaching upto '#'.
		  int val=stoi(s.substr(curr+1,prev-curr-1));
		  cout<<"Extracted val: "<<val<<endl;
		  lens[len-1]=val;
		  len--;
		  prev=curr;
	  }
	  int count=0, index=8;													// Tracks #strings extracted,curr. index while extracing.
	  while(count<len2){													// Iterates all strings are extracted.
		  string temp=s.substr(index,lens[count]);							// Extract string.
		  res.push_back(temp);
		  index+=lens[count];
		  count++;															// Inc. the count of #strings extracted.
	  }
	  return res;															// Returning the extracted strings vector.
	}
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array. Merge all the strings into one final str. At th beginning of each string, we also add length of that string, 
// followed by '#'. In the decode part, first we extract the length of the string to be extracted, then extract that substr. Thus, we extract all
// substrs.






class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
		string res="";
		for(int i=0;i<strs.size();i++)										// Merging strings into bigger one.
			res+=to_string(strs[i].length())+"#"+strs[i];
		return res;
	}

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
	    vector<string>res;
	    int index=0;
        while(index<s.length()){											// Until all strings are extracted.
            int temp=index;
            while(s[temp]!='#') temp++;										// ITerates until '#' is reached.
            string st=s.substr(index,temp-index);							// Extract the len in string format.
            int len=stoi(st);												// Extract the lengh of string to be extracted.
            res.push_back(s.substr(temp+1,len));							// Extract the string and add it to vector.
            index=temp+1+len;
        }
	    return res;															// Returning the vector of extracted strings.
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));