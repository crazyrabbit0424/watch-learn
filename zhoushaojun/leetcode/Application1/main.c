/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may asssume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + num[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <stdio.h>
#include <stdlib.h>

int * findElementSolution1
(
	int aNums[],
	int iLen,
	int iTarget
)
{
	int *piResult = NULL;
	int i = 0;
	int j = 0;
	
	piResult = (int *)malloc(2 * sizeof(int));
	if (NULL == piResult)
	{
		return NULL;
	}

	for (i = 0; i < iLen; i++)
	{
		for (j = i + 1; j < iLen; j++)
		{
			if ((aNums[i] + aNums[j]) == iTarget)
			{
				piResult[0] = i;
				piResult[1] = j;
			}
		}
	}
	return piResult;
}

int * findElementSolution2
(
int aNums[],
int iLen,
int iTarget
)
{
	int *piResult = NULL;
	int iBegin = 0;
	int iEnd = iLen - 1;

	piResult = (int *)malloc(2 * sizeof(int));
	if (NULL == piResult)
	{
		return NULL;
	}
    
	while (iBegin < iEnd)
	{
		if ((aNums[iBegin] + aNums[iEnd]) == iTarget)
		{
			piResult[0] = iBegin;
			piResult[1] = iEnd;

			return piResult;
		}
		else if ((aNums[iBegin] + aNums[iEnd]) > iTarget)
		{
			iEnd--;
		}
		else
		{
			iBegin++;
		}
	}

	return NULL;
}
int main()
{
	int aNums[] = { -1, 2, 7, 11, 16 };
	int *piNums = NULL;

	//piNums = findElementSolution1(aNums, sizeof(aNums) / sizeof(int), 10);
	piNums = findElementSolution2(aNums, sizeof(aNums) / sizeof(int), 10);
	if (NULL == piNums)
	{
		printf("No result\n");
		return 0;
	}

	printf("the result [%u] [%u]", piNums[0], piNums[1]);

	getchar();

	return 0;
}