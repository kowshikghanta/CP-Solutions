class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length();
        int[] freq = new int[26];
        char[] ans = new char[n];

        for (char c: s.toCharArray()) {
            freq[c - 'a']++;
        }

        int l = 0;
        int r = n - 1;
        for (int idx = 0; idx < 26; idx++) {
            while (freq[idx] >= 2) {
                ans[l++] = (char) ('a' + idx);
                ans[r--] = (char) ('a' + idx);
                freq[idx] -= 2;
            }
            if (freq[idx] == 1) {
                ans[n / 2] = (char) ('a' + idx);
            }
        }
        
        return new String(ans);
    }
}