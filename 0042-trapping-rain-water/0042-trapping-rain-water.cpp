class Solution {
public:
    int firstApproach(vector<int>& height) {
        // An element of the array can store water if there are higher bars on the left and the right. 
        // The amount of water to be stored in every position can be found by finding the heights of bars on the left and right sides. 
        int len = height.size();
        int left = 0, right = 0, total = 0;

        // first and last position can't store
        for (int i = 1; i < len - 1; i++) {
            // For every element: 
            // Traverse the array from start to that index and find the 
            // maximum height in left side
            // Traverse the array from the current index to the end, and find the 
            // maximum height in right side
            // The amount of water that will be stored in this column 
            // is min(left, right) – array[i], add this value to the total amount 
            // of water stored
            left = 0;
            for (int j = 0; j < i; j++) {
                if (height[j] > height[left]) {
                    left = j;
                }
            }
            
            right = i;
            for (int j = right + 1; j < len; j++) {
                if (height[j] > height[right]) {
                    right = j;
                }
            }

            if (height[left] >= height[i] && height[right] >= height[i]) {
                total += min(height[left], height[right]) - height[i];
            }
        }

        return total;
    }

    int secondApproach(vector<int>& height) {
        int len  = height.size();

        vector<int> left(len, 0);
        vector<int> right(len, 0);

        left[0] = height[0];
        for (int i = 1; i < len; i++) {
            left[i] = max(left[i-1], height[i]);
        }

        right[len-1] = height[len-1];
        for (int i = len - 2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i]);
        }

        int total = 0;
        for (int i = 1; i < len - 1; i++) {
            int lower = min(left[i], right[i]);

            if (lower > height[i]) {
                total += lower - height[i];
            }
        }

        return total;
    }

    int thirdApproach(vector<int>& height) {
        int len  = height.size();

        stack<int> stk;
        int total = 0;

        stk.push(0);

        for (int i = 1; i < len; i++) {
            while (!stk.empty() && (height[stk.top()] < height[i])) {
                int tub_height = height[stk.top()];
                stk.pop();
                // we popped the top, now next top is our left bound

                // no left bound found, can't create a tub
                if (stk.empty()) {
                    break;
                }

                // how far are we from left bound
                // spots in between lower and upper bound excluding lower and upper
                int width = (i - 1) - stk.top();

                // find lower height between left and right bound 
                // subtract tub's own height
                int vertical = min(height[stk.top()], height[i]) - tub_height;

                total += width * vertical;
            }

            stk.push(i);
        }

        return total;
    }

    int fourthApproach(vector<int>& height) {
        int block_area = 0; 
        int len = height.size(); 
        int max_height = INT_MIN; 
  
        // Find total blocks, max height and length of array 
        for (int i = 0; i < len; i++) {
            block_area += height[i]; // width of block is 1
            max_height = max(max_height, height[i]);
        }


        int total = 0; 
        int left = 0; // left bound
        int right = len - 1; // right bound

        // here i is actually a possible value for height, not array index
        // this calculate area with heigh 1, 2 , 3, ...., max_height
        for (int i = 1; i <= max_height; i++) {
            // Find leftmost point greater than current row (i)
            while (height[left] < i) {
                left++;
            }

            // Find rightmost point greater than current row (i) 
            while (height[right] < i) {
                right--;
            }

            // water & blocks combined area is = right - left  + 1 
            total += (right - left + 1);
        }

        total -= block_area;

        return total;
    }

    int fifthApproach(vector<int>& height) {
        int len = height.size();

        int left = 0, right = len - 1, leftMax = 0, rightMax = 0, total = 0;

        while (left <= right) {
            if (leftMax <= rightMax) {
                total += max(0, leftMax - height[left]);

                leftMax = max(leftMax, height[left]);

                left++;
            } else {
                total += max(0, rightMax - height[right]);

                rightMax = max(rightMax, height[right]);

                right--;
            }
        }

        return total;
    }

    int sixthApproach(vector<int>& height) {
        int len = height.size();
        int total = 0;
        int left = 0;
        int leftHeight = height[0];

        // Store the water until a larger wall is found
        // if there are no larger walls then delete temp value from water
        int temp = 0;

        for (int i = 1; i < len; i++) {
            // If the current wall is taller than the LEFT side wall
            if (height[i] >= leftHeight) { 
                leftHeight = height[i]; 
                left = i; 

                // larger or same height wall is found
                // can't store water
                temp = 0; 
            } else {
                // current wall is shorter than LEFT side wall
                total += leftHeight - height[i];

                // If we don't find any larger wall then we will subtract
                // temp from total (can't store water without right wall)
                temp += leftHeight - height[i];
            }
        }


        // If the last wall was larger than or equal to the previous wall
        if (left < len - 1) {
            total -= temp; 
            leftHeight = height[len-1];
  
            for (int i = len-1; i >= left; i--) { 
                // Right end wall will be definitely 
                // smaller than the 'previous index' wall 
                if (height[i] >= leftHeight) {
                    leftHeight = height[i];
                } else {
                    total += leftHeight - height[i];
                } 
            }
        }



        return total;
    }

    int trap(vector<int>& height) {
        // return firstApproach(height);
        // return secondApproach(height);
        // return thirdApproach(height);
        // return fourthApproach(height);
        // return fifthApproach(height);
        return sixthApproach(height);
    }
};