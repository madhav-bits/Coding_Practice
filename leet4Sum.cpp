

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that
 a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 ***Got the idea from geeksforgeeks, converted to sort of finding target from two integers in an array by some techniques.
 ***The unsatisfied part is that unable to get all 4 combinations for the target.
 
 ////////////NOT SOLVED IT COMPLETELY, STILL NEED TO SOLVE IT COMPLETELY.//////////////////////////////////////
 ////////////////////************3 Sum is also almost similar. Can solve using the same below used technique./////////////////
*/

class Solution {
public:
    struct auxi{
        int sum;
        int first;
        int second;
    };
    
    static bool repetition(auxi a, auxi b){
        if(a.first== b.first || a.first== b.second || a.second== b.first || a.second== b.second)
            return false;
        else
            return true;
    }
    static bool myfunction (int i,int j) { return (i<j); }
    static bool auxicompare(auxi a, auxi b){ return a.sum<b.sum? true: false;}// Aids in sorting a new struct.
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int d=nums.size();
        int num=d*(d-1)/2;
        vector<vector<int>> u;
        //cout<<"Target is: "<<target<<endl;
        if (num==0)
            return u;
        struct auxi pairs[num];
        vector<int> v;int k=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                pairs[k].sum=nums[i]+nums[j];
                pairs[k].first=i;
                pairs[k].second=j;
                k++;
            }
        }
        sort(pairs, pairs+num, auxicompare);// Sorts the auxilary space. Extra function is required whenever a new struct is sorted.
        for(int e=0;e<num;e++)
        cout<<"xxxxx: "<<pairs[e].sum<<endl;
        int i=0;int j=num-1;
        while(i<j){
            if(repetition(pairs[i], pairs[j]) && pairs[i].sum+pairs[j].sum == target){
                //cout<<"ssss: "<< pairs[i].first<< pairs[i].second<<pairs[j].first<< pairs[j].second<<endl;
                cout<< "Pairs are: "<<pairs[i].sum<< "and "<<pairs[j].sum<<endl;
                cout<< "Pairs are: "<<nums[pairs[i].first]<< "and "<<nums[pairs[i].second]<<"and "<<nums[pairs[j].first]<<"and "<<nums[pairs[j].second]<<endl;
                
                v.clear();
             v.push_back(nums[pairs[i].first]);v.push_back(nums[pairs[i].second]);v.push_back(nums[pairs[j].first]);v.push_back(nums[pairs[j].second]);
                
                int size1=v.size();
                sort(v.begin(), v.end());
                //if(!binary_search(u.begin(), u.end(), v))// Alternate way to check the presence of an element in an vector.
                //  u.push_back()
                //while()
                u.push_back(v);
                i++;j--;
            }
            else if(pairs[i].sum+pairs[j].sum > target )
                j--;
            else
                i++;
        }
        sort(u.begin(), u.end());
        //unique(u.begin(), u.end());
        u.erase( unique( u.begin(), u.end() ), u.end() );// Removes the duplicates in the vector.
        //cout<<u[0][0]<<endl;
        return u;
    }
};