class Solution {
public:
    bool isRobotBounded(string instructions) {
        int pos_x = 0;
        int pos_y = 0;
        int dir = 0;/* 顺时针4个方向 0 1 2 3 */
        
        for (auto cmd : instructions)
        {
            switch (cmd)
            {
                case 'R':
                {
                    dir += 1;
                    break;
                }
                case 'L':
                {
                    dir += 3;
                    break;
                }
                case 'G':
                {
                    dir %= 4;
                    if (1 == dir)
                    {
                        pos_x++;
                    }
                    else if (2 == dir)
                    {
                        pos_y--;
                    }
                    else if (3 == dir)
                    {
                        pos_x--;
                    }
                    else
                    {
                        pos_y++;
                    }
                    break;
                }
                default:
                {
                    return false;
                }
            }
        }

        return (pos_x == 0 && pos_y == 0) || ((dir % 4) != 0);
    }
};
