/*

//*********************************************************275. H-Index II.*****************************************************

Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?


H-Index Question: 
Given an array of citations (each citation is a non-negative integer) of a researcher, write a 
function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers 
have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each 
of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 
3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

//************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/

//**********************************************THIS SOLUTIN IS BINARY SEARCH PARADIGM BASED.**********************************

class Solution {
public:
    int hIndex(vector<int>& v) {
        int hIndex=0, j=1, mid, begin=0, end=v.size()-1;
        while(begin<=end){
            mid=(begin+end)/2;
            j=v.size()-mid;
            if(v[mid]>=j){
                hIndex=j;
                end=mid-1;
            }
                
            else
                begin=mid+1;
        }
        
        
        return hIndex;
    }
};


//*****************************Solution 2. This is Linear Time Solution.***************************************************
class Solution {
public:
    int hIndex(vector<int>& v) {
        int hIndex=0, j=1;
        
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]>=j)
                hIndex=j;
            j++;
        }
        
        return hIndex;
    }
};