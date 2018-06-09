/*
*
//**********************************************************284. Peeking Iterator.***************************************************

Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() 
peration -- it essentially peek() at the element that will be returned by the next call to next().

Example:

Assume that the iterator is initialized to the beginning of the list: [1,2,3].

Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2. 
You call next() the final time and it returns 3, the last element. 
Calling hasNext() after that should return false.
Follow up: How would you extend your design to be generic and work with all types, not just integer?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["PeekingIterator","next","peek","next","next","hasNext"]
[[[1,2,3]],[],[],[],[],[]]

["PeekingIterator",,"next", next","peek","next","next","hasNext"]
[[[1,2,3,4]],[],[],[],[],[],[]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Iterator based. As, we can access only through next() fn., which increases the ptr and we need to get the next vlaue as many
// times as possible, without increasing the iterator. We, extract the next value in prior and save it in temp. variable. Which, we can use as 
// many times as possible, without inc. the iterator. We also save the hasNext fn. result and return whenever hasNext fn. is called.




// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int val;																				// Stores temp. next value.
    bool res;																				// Stores temp. hasNext value.
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        res=Iterator::hasNext();															// Temp. storing hasNext result.			
	    if(res)
            val=Iterator::next();															// Temp. storing next result.
	}
    
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return val;																			// Returning the already saved next result.
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ans=val;																		// Temp. storing already stored next value.
        res=Iterator::hasNext();															// We. inc. the iterator and store next value.
        if(res)val=Iterator::next();
	    return ans;																			// Returning the already stored next value.
	}

	bool hasNext() const {
	    return res;																			// Returning the already stored hasNext value.
	}
};