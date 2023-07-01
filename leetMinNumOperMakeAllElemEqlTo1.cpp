/*
*
//**************************************2654. Minimum Number of Operations to Make All Array Elements Equal to 1.**************************************

https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,6,3,4]
[2,10,6,14]
[4,40,100,5]



// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, in every step when we calc. gcd we can substitute it in any of the two adj. indices and moreover the order of 
// gcd to be done may or may not be a unidirectional one. But we use an observation that when calc. gcd of group of nums gcd(a,b,c,d)=gcd(gcd(a,b),gcd(c,d))=
// =gcd(a, gcd(b, gcd(c,d)))=.... that is gcd of a group of numbers is associative in nature. 
// We greedily use this property to set one of the nums to 1, since gcd(1,any_num) would be 1 and we can convert every non-1 number to 1 in single step. To find
// the quickest seq. of gcds which brings 1, we perform gcds starting every index and track the least steps to one and we add rem. nums count and return answer.

// We first sweep over array to check for 1s, if present we return non-1s count, as each of the rest nums can be converted to 1 in single step each.

// This solution is from this discussion forum 
// link: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/discuss/3445725/Explained-or-Easy-or-gcd-and-intuition



// gcd(a, b)-gcd of two nums can be observed as returning product of common factors b/w two numbers.
// gcd(a,b,c,d,e) of multiple nums is nothing but product of common factors of all the nums. As factors are common b/w all of them, the order of gcds(x, y) 
// doesn't matter, we eventually get same set of common factors, that is gcd of group of nums is associative in nature.








class Solution {
public:
    int minOperations(vector<int>& v) {
        int ones=0;
        for(int&num:v) if(num==1) ones++;									// Calc. #ones in the array.
        if(ones>0) return v.size()-ones;									// If ones present, we return rem. vals count.
        int res=INT_MAX;
        for(int i=0;i<v.size();i++) {										// Iter. over diff. starting indices of array seq.
            int gcd=v[i];
            for(int j=i+1;j<v.size();j++) {									// gcd of seq. of nums starting 'i' index.
                gcd=__gcd(gcd, v[j]);
                if(gcd==1 && j-i+v.size()-1<res) res=j-i+v.size()-1;		// If gcd is 1, we track min #steps to get gcd=1+#steps for rem. nums to be 1.
            }
        }
        
        return (res==INT_MAX)?-1:res;										// Returing the least #steps needed to convert all array elems to 1.
    }
};

