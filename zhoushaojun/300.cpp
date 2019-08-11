/*
 * init sub[]
 *if val > sub[] all elements, then append to sub
 *if sub[i-1] < val < sub[i], find smaller value sub[i] updated by val, the elements stored in
 *sub[] are known subsequences, and other part is elements of other possible new sub, But,the len
 *of the known sub not changed

 array:[8,2,5,1,6,7,9,3]

 i=0, sub[]=[8] len=1
 i=1, sub[]=[2] len=1
 i=2, sub[]=[2, 5] len=2
 i=3, sub[]=[1, 5] len=2 //len not change
 i=4, sub[]=[1, 5, 6]    len=3
 i=5, sub[]=[1, 5, 6, 7] len=4
 i=6, sub[]=[1, 5, 6, 7, 9] len=5
 i=7, sub[]=[1, 3, 6, 7, 9] len=5
*/

class Solution{
    public:
    int lengthOfLIS(vector<int> &nums){
        if (0 == nums.size())
        {
            return 0;
        }

        vector<int> tmpVector(nums.size() + 1, 0);
        tmpVector[1] = nums[0];
        int maxlen = 1;
        int left = 1;
        int right = maxlen;
        int mid = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            left = 1;
            right = maxlen;

            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (tmpVector[mid] < nums[i])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            tmpVector[left] = nums[i];
            if (left > maxlen)
            {
                maxlen = left;
            }
        }
        return maxlen;
    }
}
