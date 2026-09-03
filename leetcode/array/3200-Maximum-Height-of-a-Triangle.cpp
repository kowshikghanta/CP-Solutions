class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        bool is_blue = true;
        int blue2 = blue;
        int red2 = red;
        int cur_row = 1;
        int max = 1;

        while ((is_blue && blue >= cur_row) || (!is_blue && red >= cur_row)) {
            if (is_blue) {
                blue -= cur_row;
            } else {
                red -= cur_row;
            }
            max = std::max(max, cur_row);
            cur_row += 1;
            is_blue = !is_blue;
        }

        bool is_red = true;
        cur_row = 1;
        blue = blue2;
        red = red2;

        while ((is_red && red >= cur_row) || (!is_red && blue >= cur_row)) {
            if (is_red) {
                red -= cur_row;
            } else {
                blue -= cur_row;
            }
            max = std::max(max, cur_row);
            cur_row += 1;
            is_red = !is_red;
        }

        return max;
    }
};