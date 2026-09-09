class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int ans = 0;
        Set<Character> hs = new HashSet<>();

        int i = 0;
        for (int j = 0; j < n; j++) {
            while (hs.contains(s.charAt(j))) {
                hs.remove(s.charAt(i++));
            }
            hs.add(s.charAt(j));
            ans = Math.max(j - i + 1, ans);
        }

        return ans;
    }
}