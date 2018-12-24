/*
*
//******************************************************535. Encode and Decode TinyURL.***********************************************

TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such 
as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just 
need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"abcdfasdfa"


"fadfadjeofaesfja ejo sae ase;as"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Hash Function and HasmMap based. Here, we take a hash function, which produces hash value if key is given, we update 
// longToShort and shortToLong maps with these values, longUrl is extracted from shortToLong map in decode function.








class Solution {
public:

    unordered_map<string,string>longToShort, shortToLong;
    hash<string>myHash;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string res="";
        if(longToShort.count(longUrl)==0){									// If this longUrl is encountered first time.
            res=to_string(myHash("abcd"));
            longToShort[longUrl]=res;										// Updating both maps with obtained hashValue.
            shortToLong[res]=longUrl;
        }
        else res=longToShort[longUrl];										// If longUrl already encountered, extracted shortUrl from map.
        // cout<<"res: "<<res<<endl;
        return res;															// Returning the shortUrl.
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[shortUrl];										// Returning the longUrl from map.						
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. Here, we create a random string for every given input, until a random string which hadn't been produced till
// now is produced. Once, we get random string, we update longToShort, shortToLong maps with longUrl and random string. On the other side, 
// longUrl is obtained from shortToLong map in decode function.




// We can use the number of test case as unique identifier, and use that as shortUrl and update both maps accordingly.






class Solution {
public:

    unordered_map<string,string>longToShort, shortToLong;					// Two maps to track link b/w long and short utls.
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(longToShort.count(longUrl)==1) return longToShort[longUrl];
        string res="";
        string str="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789zyxwvutsrqponmlkjihgfedcba";
        for(int i=0;i<9;i++) res+=str[rand()%str.length()];					// Creating a random string of length 9.
        while(shortToLong.count(res)==1){									// Creating string until new random string is obtained.
            res="";
            for(int i=0;i<9;i++) res+=str[rand()%str.length()];
        }
        longToShort[longUrl]=res;											// Updating both maps with random string and longUrl.
        shortToLong[res]=longUrl;
        return "http://tinyurl.com/"+res;									// Added tinyUrl.com as mentioned in question.
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl=shortUrl.substr(19);										// Extracting the random string.
        return shortToLong[shortUrl];										// Returning the longUrl from map.
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));