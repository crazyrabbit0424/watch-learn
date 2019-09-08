#define MAX(a, b) ((a) > (b)) ? (a) : (b)
int maxSubArray(int* nums, int numsSize){
    int sum = nums[0];
    int result = nums[0];
    int i = 1;
    
    for (int i = 1; i < numsSize; i++) {
        // 我们不需要记录sum数组，只要算出当前的sum，然后和result比较就行了
        sum = MAX(sum + nums[i], nums[i]);
        result = MAX(result, sum);
    }
    return result;
}