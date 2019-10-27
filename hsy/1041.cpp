class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int direction = 0;
        for (char c : instructions) {
            switch (c) {
            default: break;
            case 'L': direction = (direction - 1) & 0x3; break;
            case 'R': direction = (direction + 1) & 0x3; break;
            case 'G':
                if (direction == 0)
                    ++y;
                else if (direction == 1)
                    ++x;
                else if (direction == 2)
                    --y;
                else
                    --x;
                break;
            }
        }
        bool res = true;
        if (direction == 0 && (x != 0 || y != 0))
            res = false;
        return res;
    }
};
