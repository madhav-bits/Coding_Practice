/*
Count the number of prime numbers less than a non-negative number, n.

//*******************************************THIS IS LEET ACCEPTED CODE.********************************************
// This question looks for optimization at each and every step.
*/
class Solution {
public:
    
    int countPrimes(int n) {
        int count=1;
        if(n==1 || n==0 ||n==2)
            return 0;
        for(int i=3;i<n;i++){
            int fac=2;
            int a=0;
            if(i%2!=0){//Checks whether even or not, if even no need of further calculations.
                int upper=sqrt(i);// After including the above condition, came out of Time Limit Exceeded warning. 
                while(fac<=upper){
                    if(i%fac==0){
                        a=1;
                        break;
                    }
                    fac++;
                }

                if(a==0)
                    count++;
            }
        }
        return count;
    }
};