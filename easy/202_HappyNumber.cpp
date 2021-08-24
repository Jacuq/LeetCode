class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        while(true)
        {
            int next_temp = 0;
            //iterate over number
	    while(n>0)
            {
                int r = n % 10;
                n /= 10;
                next_temp += r*r;
            }
            if(next_temp == 1)
                return true;
	    else
            {
                //look for cycles
                if(nums.find(next_temp) != nums.end())
                    return false;
                nums.insert(next_temp);
            }
            n = next_temp;
        }
        return false;
    }
};