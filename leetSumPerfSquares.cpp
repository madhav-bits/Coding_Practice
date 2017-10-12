/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

//*************************************************THIS IS LEET ACCEPTED CODE.**********************************************

*/

class Solution {
public:
    int sqMin(int num, int sqCount[], int sq[]){
        int minm=INT_MAX;
        //cout<<"Inside function with num is: "<<num<<endl;
        if(sqCount[num]>0)// Says that the the number of perfect squares which sums up to "num"  is already calculated.
          return sqCount[num];
        for(int i=1;sq[i]<num && i<num;i++)
          minm=min(minm,sqMin(sq[i], sqCount, sq)+sqMin(num-sq[i], sqCount, sq));
        return minm;
    }
    
    int numSquares(int n) {
        if(ceil(sqrt(n))==floor(sqrt(n)))
            return 1;
        int sqCount[n+1]={0};//This saves the number of perfect squares which sums up to index "i".
        int sq[n+1]={0};// Stores all the perfect squares.
        for(int i=0;i<=n;i++)
          sq[i]=INT_MAX;
        sq[1]=1;
        int sqNum=1;// Initializing the base case of number 1.
        sqCount[1]=1;// Initializing the base case of number 1.
        for(int i=2;i<=n;i++){
            if(ceil(sqrt(i))==floor(sqrt(i))){// If it's a perf square directly initialized.
                sqCount[i]=1;
                sqNum++;
                sq[sqNum]=i;
            }
            else
                sqCount[i]=sqMin(i, sqCount, sq);
        }
        cout<<sqCount[n]<<endl<<endl;
        //for(int i=0;i<=n;i++)
          //cout<<"i is: "<<i<<"Count is: "<<sqCount[i]<<endl;
        return sqCount[n];
    }
};