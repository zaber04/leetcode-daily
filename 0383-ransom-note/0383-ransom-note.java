class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int ransomLen = ransomNote.length();
        int magazineLen = magazine.length();

        if (ransomLen > magazineLen) {
            return false;
        }

        int[] fre_map = new int[26];
        Arrays.fill(fre_map, 0);

        // magazine is character supplier
        for (int i = 0; i < magazineLen; i++) {
            fre_map[magazine.charAt(i) - 'a']++;  // 'f' - 'a' means 102 - 97 = 5
        }

        // ransomNote is character consumer
        for (int i = 0; i < ransomLen; i++) {
            if (--fre_map[ransomNote.charAt(i) - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
}