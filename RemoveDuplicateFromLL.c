#include<stdio.h>
#include<malloc.h>


void InsertLast(struct Node **  , int );
void RemoveDuplicate(struct Node ** );
void DeleteAllLinkedList(struct Node **);
void Display(struct Node * );


struct Node
{
	int iData;
	struct Node * pNext;

};


int main()
{

	int iCh;
	int iData;
	struct Node * pFirst  = NULL;

	printf("Choose One Option from below list:- \n\n");
	
	while(1)
	{
		printf("1.Add Element in LinkedList\n2.Remove Duplicate Element from Linkedlist\n3.Display\n4.Delete Linkedlist\n");
		scanf_s("%d", &iCh);

		switch(iCh)
		{

			case 1:
				printf("Enter Data in ypur LinkedList:-\n");
				scanf("%d", &iData);
				InsertLast(&pFirst , iData);
				Display(pFirst);
			break;

			case 2:
				printf("\nBefore Removing Duplicate Element:-\n");
				Display(pFirst);

				RemoveDuplicate(&pFirst);

				printf("\n After Removing Duplicate Element:-\n");
				Display(pFirst);

			break;

			case 3:
				printf("\nYour Linkedlist is :-\n");
				Display(pFirst);
			
			break;

			case 4:
				DeleteAllLinkedList(&pFirst);
				printf("\nAll Nodes are Deleted Successfully...\n");

			break;

			default:
				printf("\n You Enter Wrong Choice\n");

		}

		
	}


}

void InsertLast(struct Node ** ppHead , int iNo)
{

	struct Node * pNewnode = NULL;
	struct Node * pTemp = (*ppHead);


	pNewnode = (struct Node*) malloc(sizeof(struct Node));

	if(NULL == pNewnode)
	{

		printf("Malloc Fails\n");
		return ;

	}

	pNewnode -> iData = iNo;
	pNewnode -> pNext = NULL;

	if(*ppHead == NULL)
	{
		(*ppHead) = pNewnode;
		return;
	}

	while(pTemp -> pNext)
	{
		pTemp = pTemp ->pNext;

	}

	pTemp ->pNext = pNewnode;


}

void Display(struct Node *pHead)
{

	if(pHead == NULL)
	{
		printf("\n Your Linkedlist is Empty\n");
		return;

	}

	while(pHead)
	{
		printf("%d=>\t", pHead -> iData);
		pHead = pHead -> pNext;
	}

}

void RemoveDuplicate(struct Node ** ppHead)
{

	struct Node * pTemp1 = (*ppHead);
	struct Node * pTemp2 = NULL;

	if(NULL == *ppHead)
	{

		printf("\n Your LinkedList is Empty , Are You Insane!!!\n");
		return;

	}

	while(pTemp1)
	{

		pTemp2 = pTemp1 ->pNext;
		while(pTemp2)
		{
			if(pTemp1 -> iData == pTemp2 ->iData)
				pTemp2->iData = 0;

			pTemp2 = pTemp2 ->pNext;

		}
	
		pTemp1 = pTemp1 ->pNext;
	}


}

void DeleteAllLinkedList(struct Node **pHead)
{

	struct Node *pTemp = (*pHead);

	if(pTemp == NULL)
	{
		printf("\n Your Linkedlist is empty\n");
		return;

	}

	while(pTemp)
	{
		
		(*pHead) = pTemp->pNext;
		pTemp -> iData = 0;
		free(pTemp);
		pTemp = (*pHead);
		

	}

}


