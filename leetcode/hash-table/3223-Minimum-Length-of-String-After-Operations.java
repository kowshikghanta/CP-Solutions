class Solution {
    public int minimumLength(String s) {
        int[] frequency = new int[26];

        for (char c: s.toCharArray()) {
            frequency[c - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            while (frequency[i] > 2) {
                frequency[i] -= 2;
            }
            ans += frequency[i];
        }

        return ans;
    }
}