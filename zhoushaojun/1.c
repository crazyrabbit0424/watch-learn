/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i = 0;
	int *piResult = NULL;
	int *piTmp = NULL;
	int iMin = nums[0];
	int iMax = iMin;
	int iValue = 0;
    
    *returnSize = 2;
	piResult = (int *)malloc(2 * sizeof(int));
	if (NULL == piResult)
	{
		return NULL;
	}
	
	/* find min max */
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > iMax)
		{
			iMax = nums[i];
		}
		if (nums[i] < iMin)
		{
			iMin = nums[i];
		}
	}

	piTmp = (int *)malloc((iMax - iMin + 1) * sizeof(int));
	if (NULL == piTmp)
	{
		if (NULL != piResult)
		{
			free(piResult);
		}
		return NULL;
	}

	memset(piTmp, -1, (iMax - iMin + 1) * sizeof(int));

	for (i = 0; i < numsSize; i++)
	{
		iValue = target - nums[i];
		if ((iValue < iMin) || (iValue > iMax))
		{
			continue;
		}

		if (piTmp[iValue - iMin] != -1)
		{
			if (i < piTmp[iValue - iMin] - 1)
			{
				piResult[0] = i;
				piResult[1] = piTmp[iValue - iMin] - 1;
			}
			else
			{
				piResult[0] = piTmp[iValue - iMin] - 1;
				piResult[1] = i;

			}
			if (NULL != piTmp)
			{
				free(piTmp);
			}
			//printf("result %d, %d\n", nums[piResult[0]], nums[piResult[1]]);

			return piResult;
		}
		else
		{
			piTmp[nums[i] - iMin] = i + 1;
		}
	}

	return NULL;
}