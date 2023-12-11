class Solution {
    // 0 < root(x) < x/2
    int binarySearch(int x) {
        if (x < 2) {
            return x;
        }

        long num;
        int pivot, left = 2, right = (x >> 1);

        while (left <= right) {
            pivot = left + ((right - left) >> 1);
            num = (long)(pivot * pivot);

            if (num > x) {
                right = pivot - 1;
            } else if (num < x) {
                left = pivot + 1;
            } else {
                return pivot;
            }
        }

        return  right;
    }

    int newtonRaphson(int x) {
        if (x < 2) {
            return x;
        }

        double x0 = x;
        double x1 = (x0 + x / x0) / 2.0;

        while (abs(x0 - x1) >= 1) {
            x0 = x1;
            x1 = (x0 + x / x0) / 2.0;
        }

        return (int)(x1);
    }
public:
    int mySqrt(int x) {
        // return binarySearch(x);
        return newtonRaphson(x);
    }
};