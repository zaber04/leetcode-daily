function sortColors(nums: number[]): void {
    let lo = 0; 
    let hi = nums.length - 1;
    let mid = 0;
    let temp = 0;

    while (mid <= hi) {
        if (nums[mid] == 0) {
            // swap with low position
            temp = nums[lo]; 
            nums[lo] = nums[mid]; 
            nums[mid] = temp; 
            lo++; 
            mid++; 
        } else if (nums[mid] == 1) {
            // keep as is
            mid++;
        } else {
            // swap with high position
            temp = nums[hi]; 
            nums[hi] = nums[mid]; 
            nums[mid] = temp; 
            hi--;
        }
    }
};