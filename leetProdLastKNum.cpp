/*
*
//************************************************1352. Product of the Last K Numbers.*****************************************

GImplement the class ProductOfNumbers that supports two methods:

1. add(int num)

Adds the number num to the back of the current list of numbers.
2. getProduct(int k)

Returns the product of the last k numbers in the current list.
You can assume that always the current list has at least k numbers.
At any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

 

Example:

Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
 

Constraints:

There will be at most 40000 operations considering both add and getProduct.
0 <= num <= 100
1 <= k <= 40000



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


worked on test cases where there are zeroes within the window, start of the window, no zeroes at all.


// Time Complexity: O(1).													// Time required for every addition and every query.  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// Time required for every addition and every query.  
// Space Complexity: O(n).	
// This algorithm is Memoization based. Here, we save the cumulative product in an array. Based on queries, we divide the end index of
// window by start-1 index of window to get the product of all elements in the window. There are few cases to be taken into account 
// into- zeroes inside the window, zeroes at the start-1 index of window, no zeroes at all. These are handled at the time of insertion.







class ProductOfNumbers {
public:
    vector<int>prod, zeroes;
    
    int nums;
    ProductOfNumbers() {
        prod=vector<int>(40000+1,0);										// Tracks cumulative product of numbers.
        zeroes=vector<int>();												// Keeps track of zeroes.
        prod[0]=1;															// Base case.
        nums=0;
    }
    
    void add(int num) {
        nums++;
        if(num==0) zeroes.push_back(nums);									// Storing the index of zero.
        if(prod[nums-1]==0) prod[nums]=num;									// If prev. value is zero.
        else prod[nums]=prod[nums-1]*num;									// If prev. isn't zero, multi. cumul. prod. with curr. num.
    }
    
    int getProduct(int k) {
        // cout<<"nums: "<<nums<<" and k: "<<k<<endl;
        // cout<<"nume: "<<prod[nums]<<" and denom:"<<prod[nums-k]<<endl;
        if(zeroes.size()!=0 && zeroes.back()>nums-k) return 0;				// Zeroes within the window.
        else if(zeroes.size()!=0 && zeroes.back()==nums-k) return prod[nums];// Zeroes at start-1 index of window.
        return prod[nums]/prod[nums-k];										// Happy path test case,no zeroes in ind of consideration.
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */