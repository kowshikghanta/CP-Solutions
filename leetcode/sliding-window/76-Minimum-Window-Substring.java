class Solution {
    public String minWindow(String s, String t) {
        int[] a = new int[128];
        int[] b = new int[128];
        Set<Character> hs = new HashSet<>();
        for (char c: t.toCharArray()) {
            b[c - 'A']++;
            hs.add(c);
        }
        int n = s.length();
        int l = 0;
        int r = 0;
        String ans = "";

        while (r != n) {
            while (r != n && !check(a, b, hs)) {
                char c = s.charAt(r);
                a[c - 'A']++;
                r++;
            }
            while (check(a, b, hs)) {
                if (ans.equals("") || ans.length() > r - l) {
                    ans = s.substring(l, r);
                }

                a[s.charAt(l) - 'A']--;
                l++;
            }
        }

        return ans;
    }
    public static boolean check(int[] a, int[] b, Set<Character> hs) {
        for (Character c : hs) {
            if (a[c - 'A'] < b[c - 'A']) {
                return false;
            }
        }

        return true;
    }
}