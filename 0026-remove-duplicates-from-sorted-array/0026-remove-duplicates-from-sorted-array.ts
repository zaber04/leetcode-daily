function removeDuplicates(nums: number[]): number {
    const len = nums.length;

    if (!len) {
        return 0;
    }

    let unique = 0;

    for (let current = 1; current < len; current++) {
        if (nums[unique] != nums[current]) {
            nums[++unique] = nums[current];
        }
    }

    return unique + 1;
};