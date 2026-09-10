class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int[] prefix = new int[n]; // B's count before
        int[] suffix = new int[n]; // A's count after
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if (s.charAt(i - 1) == 'b') {
                prefix[i]++;
            }
        }

        for (int i = n - 2; i > -1; i--) {
            suffix[i] = suffix[i + 1];
            if (s.charAt(i + 1) == 'a') {
                suffix[i]++;
            }
        }

        int ans = Math.min(
            suffix[0] + (s.charAt(0) == 'a' ? 1 : 0),
            prefix[n - 1] + (s.charAt(n - 1) == 'b' ? 1 : 0) 
        );
        for (int i = 1; i < n; i++) {
            ans = Math.min(ans, prefix[i] + suffix[i]);
        }

        return ans;
    }
}