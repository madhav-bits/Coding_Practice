/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your 
product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad 
version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad 
version. You should minimize the number of calls to the API.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


//*******************************************THIS IS LEET ACCEPTED CODE.*************************************************

*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    
    bool badVer(int begin,int end){
        return true;
    }
    
    int firstBadVersion(int n) {
        //bool answer;
        unsigned long long int begin=0;
        unsigned long long int end=n;
        unsigned long long int prev;
        int ver=ceil((begin+end)/2);
        if(n==1)
            return 1;
        cout<<"version is: "<<ver<<endl;
        while(begin<=end){
            if(isBadVersion(ver)){
                prev=ver;
                end=ver-1;
                ver=ceil((begin+end)/2);
            }
            else{
                begin=ver+1;
                ver=ceil((begin+end)/2);
            }
        }
        return prev;
    }
};