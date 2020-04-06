#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        
        for (int i = 0; i < nums.size(); ++i) {
            int c = target - nums[i];
            if (mp.find(c) != mp.end()) {
                return vector<int> {mp.find(c)->second, i};
            }
            mp[nums[i]] = i;
        }
    }
};

int main ()
{
    std::map<int,int> mp;
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = s.twoSum(nums, target);

    for (auto x : ans) {
        cout << x << " ";
    }
}