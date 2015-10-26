/*************************************************************************
    > File Name: fibHeap.cpp
    > Author: yinahe
    > Mail: yina.he@nokia.com 
    > Created Time: Sun 25 Oct 2015 10:15:52 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include <cmath>
#include "FibHeap.h"

#define MIN_KEY -0x7fffffff

errorType CFibHeap::insert(node *pNode)
{
	if(pNode == NULL)
		return POINTER_NULL;

	addNodeToRootList(pNode);
	dataCount++;
	return SUCCESS;
}

int CFibHeap::getDataCount()
{
	return dataCount;
}

errorType CFibHeap::merge(CFibHeap *H2)
{
	if(H2 == NULL )
		return POINTER_NULL;
	if( H2->getDataCount() == 0)
		return SUCCESS;
	if(pMinNode == NULL)
	{
		pMinNode = H2->pMinNode;
		dataCount = H2->dataCount;
		return SUCCESS;
	}

	addListToRootList(H2->pMinNode);
	dataCount += H2->dataCount;  
	return SUCCESS;
}

node* CFibHeap::extract()
{
	if(pMinNode == NULL)
		return NULL;

	node *pChildOfMin = pMinNode->pChild;
	if(pChildOfMin != NULL)
	{
		while(pChildOfMin != NULL && pChildOfMin->pParent == pMinNode)
		{
			pChildOfMin->pParent = NULL;
			pChildOfMin = pChildOfMin->pRight;
		}
		pMinNode->pChild = NULL;
		addListToRootList(pChildOfMin);
	}

	node *pRetNode = pMinNode;
	removeNodeFromRootList(pRetNode);
	if(pMinNode != NULL)
		consolidate();
	dataCount--;
	return pRetNode;
}

errorType CFibHeap::decreaseKey(node *pNodeToDecrease, int newKey)
{
	if(pNodeToDecrease == NULL)
		return POINTER_NULL;
	if(pNodeToDecrease->key < newKey)
		return PARAM_ERROR;
	if(isNodeInHeap(pNodeToDecrease) == false)
		return PARAM_ERROR;

	pNodeToDecrease->key = newKey;
	node *pParent = pNodeToDecrease->pParent;
	if(pParent != NULL && pNodeToDecrease->key < pParent->key)
		moveNodeToRootList(pNodeToDecrease);
	if(pNodeToDecrease->key < pMinNode->key)
		pMinNode = pNodeToDecrease;
	return SUCCESS;
}

errorType CFibHeap::deleteNode(node *pNode)
{
	if(pNode == NULL)
		return POINTER_NULL;
	if(isNodeInHeap(pNode) == false)
		return PARAM_ERROR;

	decreaseKey(pNode, MIN_KEY);
	extract();
	return SUCCESS;
}

void CFibHeap::consolidate()
{
	int degreeOfHeap = log(dataCount*1.0) / log(2.0), i;
	node **A = new node*[degreeOfHeap+1];
	for(int i = 0; i <= degreeOfHeap; i++)
		A[i] = NULL;

	node *pNodeOfList = pMinNode;
	node *pCurrentNode = pNodeOfList;
	do 
	{
		pCurrentNode->isHandled = false;
		pCurrentNode = pCurrentNode->pRight;
	} while (pCurrentNode != pMinNode);
	
	
	while(pNodeOfList->isHandled == false) 
	{
		pNodeOfList->isHandled = true;
		pCurrentNode = pNodeOfList;
		pNodeOfList = pNodeOfList->pRight;
		int degreeOfCurrentNode = pCurrentNode->degree;
		while(A[degreeOfCurrentNode] != NULL)
		{
			node *pNodeInA = A[degreeOfCurrentNode];
			if(pNodeInA->key < pCurrentNode->key)
				swap(*pNodeInA, *pCurrentNode);
			link(pNodeInA, pCurrentNode);
			A[degreeOfCurrentNode] = NULL;
			degreeOfCurrentNode++;
		}
		A[degreeOfCurrentNode] = pCurrentNode;
	}
	
	pMinNode = NULL;
	for(int i = 0; i <= degreeOfHeap; i++)
		if(A[i] != NULL)
			addNodeToRootList(A[i]);

	delete []A;
}

void CFibHeap::link(node *y, node *x)
{
	removeNodeFromRootList(y);
	addChildToParent(y, x);
	y->isOneChildDeleted = false;
}

void CFibHeap::moveNodeToRootList(node *pNode)
{
	node *pParent = pNode->pParent;
	deleteChildFromParent(pNode);
	addNodeToRootList(pNode);
	pNode->isOneChildDeleted = false;

	if(pParent->isOneChildDeleted == false)
		pParent->isOneChildDeleted = true;
	else if(pParent->pParent != NULL)
		moveNodeToRootList(pParent);
}

bool CFibHeap::isNodeInHeap(node *pNode)
{
	node *pRootOfNode = pNode;
	while(pRootOfNode->pParent != NULL)
		pRootOfNode = pRootOfNode->pParent;
	node *pCurrentNode = pRootOfNode;
	do 
	{
		if(pCurrentNode == pMinNode)
			break;
		else
			pCurrentNode = pCurrentNode->pRight;
	} while (pCurrentNode != pRootOfNode);
	if(pCurrentNode != pMinNode)
		return false;
	else
		return true;
}
void CFibHeap::addNodeToRootList(node *pNode)
{
	pNode->pParent = NULL;
	if(pMinNode != NULL)
	{
		pNode->pRight = pMinNode->pRight;
		pNode->pLeft = pMinNode;
		pMinNode->pRight->pLeft = pNode;
		pMinNode->pRight = pNode;
	}
	if(pMinNode == NULL || pNode->key < pMinNode->key)
	{
		pMinNode = pNode;
	}
}

void CFibHeap::addListToRootList(node *pNodeOfList)
{
	node *t = pMinNode->pRight;  
	pMinNode->pRight = pNodeOfList;  
	pNodeOfList->pLeft->pRight = t;  
	t->pLeft = pNodeOfList->pLeft;  
	pNodeOfList->pLeft = pMinNode;  
	if(pMinNode->key > pNodeOfList->key)
		pMinNode = pNodeOfList;
}

void CFibHeap::removeNodeFromRootList(node *pRootNode)
{
	if(pRootNode->pRight == pRootNode)
		pMinNode = NULL;
	else
	{
		if(pMinNode == pRootNode)
			pMinNode = pRootNode->pRight;
		pRootNode->pRight->pLeft = pRootNode->pLeft;
		pRootNode->pLeft->pRight = pRootNode->pRight;
	}
}

void CFibHeap::addChildToParent(node *pChild, node *pParent)
{
	if(pParent->pChild == NULL)
	{
		pParent->pChild = pChild;
		pChild->pRight = pChild;
		pChild->pLeft = pChild;
	}
	else
	{
		node *pOriginChildOfParent = pParent->pChild;
		pChild->pRight = pOriginChildOfParent->pRight;
		pChild->pLeft = pOriginChildOfParent;
		pOriginChildOfParent->pRight->pLeft = pChild;
		pOriginChildOfParent->pRight = pChild;
	}
	pChild->pParent = pParent;
	pParent->degree++;
}

void CFibHeap::deleteChildFromParent(node *pNode)
{
	node *pParent = pNode->pParent;
	if(pNode->pRight == pNode)
		pParent->pChild = NULL;
	else
	{
		if(pParent->pChild == pNode)
			pParent->pChild = pNode->pRight;
		pNode->pRight->pLeft = pNode->pLeft;
		pNode->pLeft->pRight = pNode->pRight;
	}
	pParent->degree--;
}
