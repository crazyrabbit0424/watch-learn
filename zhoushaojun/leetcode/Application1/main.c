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
#include <string.h>
#include <stdbool.h>

/* quit sort */
void quickSort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int iTemp = arr[left];//base
	
	if (left >= right)
	{
		return;
	}

	while (i < j)
	{
		/* from right to left */
		while ((i < j) && (arr[j] >= iTemp))
		{
			j--;
		}

		/* the right NUM is less the base */
		if (i < j)
		{
			arr[i] = arr[j];//switch
		}

		/* from left to right */
		while ((i < j) && (arr[i] <= iTemp))
		{
			i++;
		}

		/* the left NUM is great the base */
		if ((i < j))
		{
			arr[j] = arr[i];//switch
		}
	}

	arr[i] = iTemp;

	quickSort(arr, left, i - 1); /* left recursion */
	quickSort(arr, i + 1, right);/* right recursion */

	return;
}

int * findElementSolution1(int aNums[], int iLen, int iTarget)
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

int * findElementSolution2(int aNums[], int iLen, int iTarget)
{
	int i = 0;
	int *piResult = NULL;
	int *piTmp = NULL;
	int iBegin = 0;
	int iEnd = iLen - 1;
	bool bFlag = false;

	piResult = (int *)malloc(2 * sizeof(int));
	if (NULL == piResult)
	{
		return NULL;
	}
	
	/* sort */
	piTmp = (int *)malloc(iLen * sizeof(int));
	if (NULL == piTmp)
	{
		if (NULL != piResult)
		{
			free(piResult);
		}
		return NULL;
	}
	memcpy(piTmp, aNums, iLen * sizeof(int));
	quickSort(piTmp, iBegin, iEnd);

	while (iBegin < iEnd)
	{
		if ((piTmp[iBegin] + piTmp[iEnd]) == iTarget)
		{
			break;
		}
		else if ((piTmp[iBegin] + piTmp[iEnd]) > iTarget)
		{
			iEnd--;
		}
		else
		{
			iBegin++;
		}
	}
	//printf("result %d, %d\n", piTmp[iBegin], piTmp[iEnd]);

	/* find index */
	for (i = 0; i < iLen; i++)
	{
		if (((piTmp[iBegin] == aNums[i]) || (piTmp[iEnd] == aNums[i])) && (false == bFlag))
		{
			piResult[0] = i;
			bFlag = true;
			continue;
		}

		if ((true == bFlag) && (aNums[i] == (iTarget - aNums[piResult[0]])))
		{
			if (i < piResult[0])
			{
				piResult[1] = piResult[0];
				piResult[0] = i;
			}
			else
			{
				piResult[1] = i;
			}

			if (NULL != piTmp)
			{
				free(piTmp);
			}
			return piResult;
		}
	}

	return NULL;
}
int main()
{
	int aNums[] = { -5, 19, 8, -1, 2, 7, 11, 16 };
	int *piNums = NULL;

	//piNums = findElementSolution1(aNums, sizeof(aNums) / sizeof(int), 10);
	piNums = findElementSolution2(aNums, sizeof(aNums) / sizeof(int), 10);
	if (NULL == piNums)
	{
		printf("No result\n");
		getchar();
		return 0;
	}

	printf("the result [%u] [%u]", piNums[0], piNums[1]);

	getchar();

	return 0;
}