class Solution {
    public boolean squareIsWhite(String coordinates) {
        char c1 = coordinates.charAt(0);
        char c2 = coordinates.charAt(1); 
        if (((c1 - 'a') % 2 == 0 && c2 % 2 == 1) || ((c1 - 'a') % 2 == 1 && c2 % 2 == 0)) {
            return false;
        }
        return true;
    }
}