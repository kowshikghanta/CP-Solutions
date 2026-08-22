class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        List<Integer> ans = new ArrayList<>();
        ans.add((tomatoSlices - (2 * cheeseSlices)) / 2);
        ans.add(cheeseSlices - ans.get(0));
        if (tomatoSlices % 2 == 1 || ans.get(0) < 0 || ans.get(1) < 0) {
            return new ArrayList<Integer>();
        }
        return ans;
    }
}