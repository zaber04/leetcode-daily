/*
1. Sort the Array ( ascending order )
2. For Each Element traverse the previous element
3. If element is divisible by any previous element it means it can be part of that group by 
we also need to make sure it is part of the group with maximum size, So if we found any bigger 
group we will add it to that group
4. If we update the group size, it means we have added new element I will update my previous 
of the current element with group's maximum till now ( before adding )
5. I will also track the index of the last element added in the biggest group
6. Now I will backtraverse from that maximum index ( defined in previous point ) using my 
previous element array and one by one add into my result list
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> groupSize(len, 1);
        vector<int> previous(len, -1); // -1 means first element of group
        int maxIndex = 0;

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && groupSize[i] < groupSize[j] + 1) {
                    groupSize[i] = groupSize[j] + 1;
                    previous[i] = j;
                }
            }

            if (groupSize[i] > groupSize[maxIndex]) {
                maxIndex = i;
            }
        }

        vector<int> out;

        for (int i = maxIndex; i != -1; i = previous[i]) {
            out.insert(out.begin(), nums[i]);
        }

        return out;
    }
};