class Solution {
public:
    int maxProduct(int n) {
        int largest = 0, second_largest = 0;

        while (n) {
            int remainder = n % 10;

            if (remainder > largest) {
                second_largest = largest;
                largest = remainder;
            } else if (remainder > second_largest) {
                second_largest = remainder;
            }

            n /= 10;
        }

        return largest * second_largest;
    }
};