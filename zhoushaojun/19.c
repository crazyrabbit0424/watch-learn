	struct ListNode *pstHead = head;
	struct ListNode *pstNode = head;
	struct ListNode *pstPreHead = head;
	struct ListNode *pstPreTail = head;
	struct ListNode *pstCurHead = head;
	struct ListNode *pstCurTail = head;
	struct ListNode *pstTmpNode = NULL;

	int index = n;

	while (NULL != pstNode)
	{
		pstPreHead = pstCurHead;
		pstCurHead = pstNode;
		index = n;

		while ((NULL != pstNode) && (index > 0))
		{
			if (NULL == pstNode->next)
			{
				if (1 == index)
				{
					pstTmpNode = pstCurHead->next;
					pstCurTail->next = pstTmpNode;
					if (head == pstCurHead)
					{
						pstHead = pstTmpNode;
					}
					free(pstCurHead);
					return pstHead;
				}
				else
				{
					pstTmpNode = pstPreHead;
					index = n - index + 1;
					while (index > 0)
					{
						if (1 == index)
						{
							struct ListNode *pstNode = pstTmpNode->next;
							pstTmpNode->next = pstNode->next;
							free(pstNode);
							return pstHead;
						}
						pstTmpNode = pstTmpNode->next;
						index--;
					}
				}
			}
			else
			{
				if (1 == index)
				{
					pstPreTail = pstCurTail;
					pstCurTail = pstNode;
				}
			}
			pstNode = pstNode->next;
			index--;
		}
	}

	return pstHead;
