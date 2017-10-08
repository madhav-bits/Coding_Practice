
// This is leet accepted code.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i;
        cout<<m[4]<<endl;
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]]!= i){
                cout<<target-nums[i]<<endl;
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
                break;
            }
        }
        return v;
    }
};