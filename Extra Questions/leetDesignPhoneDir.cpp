/*
*
//**********************************************************379. Design Phone Directory.***************************************************

Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["PhoneDirectory","check","get","check","get"]
[[1],[0],[],[0],[]]


["PhoneDirectory","release","get"]
[[1],[0],[]]

["PhoneDirectory","get","get","check","get","check","get","check","get","get","get","release","check","get","check"]
[[5],[],[],[3],[],[3],[],[3],[],[],[],[3],[3],[],[3]]



// Time Complexity: O(1).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is HashMap/Set based. We create a set with given numbers. If asked, we extract first value in it and erase it form the set.
// when checked, we check in set for presence of that num. While inserting, we insert the number into set direclty.




class PhoneDirectory {
public:
    /*
	* Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    
    unordered_set<int>s;													// Init. set.
    PhoneDirectory(int len) {
        for(int i=0;i<len;i++){												// Pushing all values into set.
            s.insert(i);
        }
    }
    
    /*
	* Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(s.empty()) return -1;											// If set empty, return -1.
        int res=*s.begin();													// Extract and return first value from set.
        s.erase(res);														// Erase this num from set.
        return res;	
    }
    
    /*
	* Check if a number is available or not. */
    bool check(int number) {
        return s.count(number);												// Check for presence of num in set.
    }
    
    /*
	* Recycle or release a number. */
    void release(int number) {
        s.insert(number);													// Insert num. into set.
    }
};

/*
*
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is HashMap/Set/Vector based. We create a vector with given numbers, and other vector tracking the availability of nums. Var
// index indicates the starting index of all available nums. When requested we return num at curr. index value and inc. the index value to index+1.
// When new elem. inserted, we assign it at index-1 and update index to index-1. We can check presence of nums in vector by direclty checking num 
// index in pres vector. 


 
 
 
 
class PhoneDirectory {
public:
    /*
	* Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    
    vector<int>val;															// Tracks available nums.
    vector<bool>pres;														// Tracks prsence of nums.
    int index=0, len;
    PhoneDirectory(int nums) {
        len=nums;
        val=vector<int>(len);												// Init. val and pres vectors.
        pres=vector<bool>(len,true);
        for(int i=0;i<len;i++)
            val[i]=i;
    }
    
    /*
	* Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(index==len) return -1;											// If no. num remaining, return -1.
        int res;
        if(index<len){
            res=val[index++];												// Extract curr. value.
            // cout<<"The realsed num: "<<res<<endl;	
            pres[res]=false;												// Make it unavailable.
        }
        return res;															// Return the extracted value.
    }
    
    /*
	* Check if a number is available or not. */
    bool check(int number) {
        return pres[number];												// Check for presence of num.
    }
    
    /*
	* Recycle or release a number. */
    void release(int number) {
        if(pres[number]==true) return ;			
        // cout<<"Added num: "<<number<<endl;
        val[--index]=number;												// Add curr. num to list.
        pres[number]=true;													// Make it available.
    }
};

/*
*
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */