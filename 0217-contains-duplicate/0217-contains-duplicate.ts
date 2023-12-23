function containsDuplicate(nums: number[]): boolean {
    if (nums.length !== new Set(nums).size) {
        return true;
    }

    return false;
};