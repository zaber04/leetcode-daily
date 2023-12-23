class Solution {
    int GCD(int a, int b) {
        if (b==0) return a;
        return GCD(b, a%b);
    }
public:
    string gcdOfStrings(string str1, string str2) {
        
        if (str1[0] != str2[0]) {
            return "";
        }
        
        if ((str1+str2) != (str2+str1)) {
            return "";
        }
        
        int gcd = GCD(str1.length(), str2.length());
        return str1.substr(0, gcd);
    }
};