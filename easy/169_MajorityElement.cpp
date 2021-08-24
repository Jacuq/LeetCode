class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int votes=1, majority=nums[0];
	//solve using boyer-moore voting algo
        for(int i=1; i<nums.size(); ++i)
        {
            if(nums[i] == majority)
                ++votes;
            else
                --votes;
            if(votes==0)
            {
                majority = nums[i];
                votes = 1;
            }
            
        }
        return majority;
    }
};