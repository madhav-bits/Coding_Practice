/*

//********************************************************454. 4Sum II.*********************************************************
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 
and the 
result is guaranteed to be at most 231 - 1.

// Time Complexity: O(n^2). In practice takes bit longer.
// Space Complexity: O(1).
//*****************************************************THIS IS NOT LEET ACCPETED CODE.*******************************************
//*************BUT THERE IS NOTHING WRONG WITH THIS CODE. JUST THE FACT THERE IS NOT SPACE COMPROMISED CODE. PERFECTLY WORKS FINE.*********
*/
class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int count=0,sum;
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        int len=a.size();
        vector<int>::iterator it, it1;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                sum=a[i]+b[j];
                int lim1=0, lim2=len-1;
                while(lim1< c.size() && lim2>=0){
                    //cout<<"lim1 is: "<<lim1<<" and lim2 is: "<<lim2<<endl;
                    if(c[lim1]+d[lim2]==(-sum)){
                        //cout<<"Inside equal condition."<<endl;
                        int temp1=1, temp2=1;
                        //lim1++;
                        //lim2--;
                        it=lower_bound(c.begin(),c.end(), c[lim1]);// Finding number of occurences using lower_bound and upper_bound.
                        it1=upper_bound(c.begin(),c.end(), c[lim1]);
                        temp1=it1-it;
                        lim1+=temp1;
                        /*
                        while((lim1)< c.size() && c[lim1]==c[lim1-1] ){// Other way is to scan through dupl. numbers tis way.
                            lim1++;// ******************Counting num. of dupli. of both the num. and product their occurences 
                            temp1++;//and add to count of target occurences.
                        }
                    
                        while((lim2)>=0 && d[lim2]==d[lim2+1]){
                            lim2--;
                            temp2++;
                        }
                        */
                        it=lower_bound(d.begin(),d.end(), d[lim2]);// Finding number of occurences using lower_bound and upper_bound.
                        it1=upper_bound(d.begin(),d.end(), d[lim2]);
                        temp2=it1-it;
                        lim2-=temp2;
                        count=count+(temp1*temp2);
                    }
                    else if(c[lim1]+d[lim2]<(-sum))
                        lim1++;
                    else
                        lim2--;
                }
                //cout<<"The count is: "<<count<<endl;
                //if(lim1<c.size() && lim2>=0)
                //    cout<<"The final values are: "<< a[i]<<" "<<b[j]<<" "<<e[lim1]<<" "<<e[lim2]<<endl;
            }
        }
        //cout<<"The count is: "<<count<<endl;
        return count;
    }
};