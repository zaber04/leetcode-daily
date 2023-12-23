function minSubArrayLen(target: number, nums: number[]): number {
    let l = 0, r = -1;
    let sum = 0;
    const numLen = nums.length
    let minLength = numLen + 1;

    while (l < numLen) {
        if (r + 1 < numLen && sum < target) {
            sum += nums[++r];
        } else {
            sum -= nums[l++];
        }

        if (sum >= target) {
            minLength = Math.min(minLength, r - l + 1);
        }
    }

    return minLength == nums.length + 1 ? 0 : minLength;
};