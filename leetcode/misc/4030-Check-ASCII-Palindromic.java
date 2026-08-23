class Solution {
    public boolean isPalindromic(String s) {
        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            StringBuilder bits = new StringBuilder();
            int a = c;

            while (a > 0) {
                bits.append(a % 2);
                a /= 2;
            }

            while (bits.length() < 8) {
                bits.append('0');
            }

            sb.append(bits.reverse());
        }

        return Palindrome(sb);
    }
    public boolean Palindrome(StringBuilder sb) {
        int left = 0;
        int right = sb.length() - 1;
        while (left < right) {
            if (sb.charAt(left++) != sb.charAt(right--)) {
                return false;
            }
        }

        return true;
    }
}

