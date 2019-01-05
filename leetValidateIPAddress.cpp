/*
*
//**********************************************************4468. Validate IP Address.***************************************************

Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated 
by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons 
(":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four 
hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 
address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. 
For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"172.16.255.1"


"172.16.255.01"



"172.16.256.01"



"2001:0db8:85a3:0:0:8A2E:0370:7334"




"2001:0db8:85a3:0:0:8A2E:0370:7334:"



"1.1.1.1."



"12..33.4"




"0.0.0.-0"


"1.1..1"





// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we diff. checking for IPv4/IPv6 based on occurance of '.' or ':'s. In checking for IPv4, we extract
// nums at each every call, while making sure that we don't get chars other than [0,9], also not to get empty nums. If nums is formed is more than
// 4, then return false.We also make sure that last char isn't '.' by placing specific conditions for it.
// For IPv6, at every call, we iterate until we reach ':', we make sure that we don't get notallowed chars. We also check for empty num/nums with
// length>4, we also check for  getting >8 nums formed, then we return false.
// If we don't give calls to these both functions, then that's not IPv4/IPv6, so we return false.








class Solution {
public:
    
    bool isIpv4(string &s, int index, int num){								// Extracting curr. num from string.
        if(index==s.length()) return false;									// Last char is '.', so return false.
        if(index>s.length()){												// Iter. till end of string.
            return (num==4)?true:false;										// If 4 nums extracted return true.
        }    
        if(num==4) return false;											// If 4 nums already formed, return false(As 5th num will be formed now).
        // cout<<"index: "<<index<<" and num: "<<num<<endl;
        int i=index;														// Storing start of curr. num.
        int temp=0;															// Tracking curr. extracted num.
        while(i<s.length() && s[i]!='.'){									// Iter. curr. num.
            if( s[i]==':' || s[i]<'0' || s[i]>'9') return false;			// Not allowed chars encountered, return false.
            if(temp==0 && i-index>0) return false;							// '0' as prefix char.
            temp=temp*10+(s[i]-'0');										// Updating curr. formed num.
            // cout<<"i: "<<i<<" and val: "<<temp<<endl;
            if(temp>255) return false;										// Curr. num out of range.
            i++;															// INc. the iterator value.
        }	
        if(i==index) return false;											// If empty num is given, return false.
        return isIpv4(s,i+1, num+1);										// Call to extract following num. 
    }
    
    
    bool notAllowed(char ch){												// Checking not allowed chars for IPv6.
        if(ch>='0' && ch<='9') return false;
        if(ch>='a' && ch<='f') return false;
        if(ch>='A' && ch<='F') return false;
        return true;
    }
    
    bool isIpv6(string s, int index, int num){								// Extracts curr. num from string.
        if(index==s.length()) return false;									// IF last char is ':'.
        if(index>s.length()){												// Iter. till end of string extracting num.
            return (num==8)?true:false;										// If 8 nums extracted, return true else return false.
        }
        if(num==8) return false;											// If 8 nums already extracted, return false.
        // cout<<"index: "<<index<<" and num: "<<num<<endl;
        int i=index, temp=0;												// Tracks curr. index.
        while(i<s.length() && s[i]!=':'){									// Extracting curr. num.
            if(s[i]=='.' || notAllowed(s[i])) return false; 				// If not allowed chars encountered, return false.
            i++;															// INc. the iterator value.
        }
        if(i==index || (i-index)>4) return false;							// If empty num/oversize num found, return false.
        return isIpv6(s,i+1, num+1);										// Give call to extract next num.
    }
    
    string validIPAddress(string s) {
        for(int i=0;i<s.length();i++){										// Search for '.'/':'.
            if(s[i]==':') return isIpv6(s,0,0)?"IPv6":"Neither";			// If ':' found, check for IPv6 possiblility.
            else if(s[i]=='.') return isIpv4(s,0,0)?"IPv4":"Neither";		// If '.' found, check for IPv4 possiblility.
        }
        return "Neither";													// If it's neither of IPv4/IPv6, then return Neither.
    }
};