class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int pointer1 = 0, pointer2 = 0;
        int len1 = nums1.size(), len2 = nums2.size();

        while (pointer1 < len1 && pointer2 < len2) {
            if (nums1[pointer1] < nums2[pointer2]) {
                pointer1++;
            } else if (nums1[pointer1] > nums2[pointer2]) {
                pointer2++;
            } else {
                return nums1[pointer1];
            }
        }

        return -1;
    }
};