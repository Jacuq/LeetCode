class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        /*
        * disclaimer: this is not the solution 'intended'
        * topics related are two pointers, but I didn't manage to find
        * a solution based on two pointers method that would be better than this
        */

        //nums2 is empty, nums1 is already an answer
        if(n < 1)
            return;
        
        //put all nums to nums1
        for(int i = 0; i < n; ++i)
        {
            nums1[m+i] = nums2[i];
        }
        //sort nums1 
        sort(nums1.begin(), nums1.end());
    }
};