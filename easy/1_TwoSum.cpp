class Solution {
public:
    //used to sort vector of numbers with indexes
    static bool greater_val(pair<int, int> p1, pair<int,int> p2)
    {
        return p1.first < p2.first;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        //allocate and fill vector of numbers and indexes
        //basically a map, but with duplicate keys (and more comfrtable than multimap for me)
        vector<pair<int,int>> nums_with_inds;
        for(int i=0; i<nums.size(); ++i)
        {
            nums_with_inds.push_back({nums[i], i});
        }
        
        
        sort(nums_with_inds.begin(), nums_with_inds.end(), greater_val);
        int left = 0;
        int right = nums.size()-1;
        int sum = nums_with_inds[left].first + nums_with_inds[right].first;
        //in a sorted array if the current answer is too big move right bound to the left
        //and if current answer is too small move left bound to right (similar to two pointers method)
        while(sum!=target)
        {
            if(sum > target)
                right--;
            else 
                left++;
            sum = (nums_with_inds[left]).first + (nums_with_inds[right]).first;
        }
        vector<int> answer;
        answer.push_back(nums_with_inds[left].second);
        answer.push_back(nums_with_inds[right].second);
        return answer;
    }
};