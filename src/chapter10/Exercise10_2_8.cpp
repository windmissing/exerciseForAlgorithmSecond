#include <iostream>
#include <string>
using namespace std;

#include "Chapter10.h"
#if 1
unsigned int node2Addr(nodeOfOnePointerDoubleLinkedList *pNode);
nodeOfOnePointerDoubleLinkedList * addr2Node(unsigned int addr);

void nodeOfOnePointerDoubleLinkedList::changePreNode(nodeOfOnePointerDoubleLinkedList *pFromNode, nodeOfOnePointerDoubleLinkedList *pToNode)
{
	pointer = pointer ^ node2Addr(pFromNode) ^ node2Addr(pToNode);
}

void nodeOfOnePointerDoubleLinkedList::changeNextNode(nodeOfOnePointerDoubleLinkedList *pFromNode, nodeOfOnePointerDoubleLinkedList *pToNode)
{
	pointer = pointer ^ node2Addr(pFromNode) ^ node2Addr(pToNode);
}

nodeOfOnePointerDoubleLinkedList* nodeOfOnePointerDoubleLinkedList::getPreFromNext(nodeOfOnePointerDoubleLinkedList *pNextNode)
{
	unsigned int addrNext = node2Addr(pNextNode);
	unsigned int addrPre = pointer ^ addrNext;

	return addr2Node(addrPre);
}

nodeOfOnePointerDoubleLinkedList* nodeOfOnePointerDoubleLinkedList::getNextFromPre(nodeOfOnePointerDoubleLinkedList *pPreNode)
{
	unsigned int addrPre = node2Addr(pPreNode);
	unsigned int addrNext = pointer ^ addrPre;

	return addr2Node(addrNext);
}

void listOfOnePointerDoubleLink::Insert(int key)
{
	nodeOfOnePointerDoubleLinkedList *pNewNode = new nodeOfOnePointerDoubleLinkedList(key);
	nodeOfOnePointerDoubleLinkedList *pHeadNext = pHeadNode->getNextFromPre(NULL);

	pNewNode->changePreNode(NULL, pHeadNode);
	pNewNode->changeNextNode(NULL, pHeadNext);

	if(pHeadNext != NULL)
	{
		pHeadNext->changePreNode(pHeadNode, pNewNode);
	}
	pHeadNode->changeNextNode(pHeadNext, pNewNode);
}

vector<int> listOfOnePointerDoubleLink::Print()
{
	vector<int> retVec;
	nodeOfOnePointerDoubleLinkedList *pCurrentNode = pHeadNode->getNextFromPre(NULL);
	nodeOfOnePointerDoubleLinkedList *pPreNode = pHeadNode;
	nodeOfOnePointerDoubleLinkedList *pNextNode = NULL;
	while(pCurrentNode != NULL)
	{
		retVec.push_back(pCurrentNode->key);

		pNextNode = pCurrentNode->getNextFromPre(pPreNode);
		pPreNode = pCurrentNode;
		pCurrentNode = pNextNode;

	}
	return retVec;
}

void listOfOnePointerDoubleLink::Delete(int key)
{
	nodeOfOnePointerDoubleLinkedList *pCurrentNode = addr2Node(pHeadNode->pointer);
	nodeOfOnePointerDoubleLinkedList *pPreNode = pHeadNode;
	nodeOfOnePointerDoubleLinkedList *pNextNode = NULL;

	while(pCurrentNode != NULL)
	{
		pNextNode = pCurrentNode->getNextFromPre(pPreNode);

		if(pCurrentNode->key == key)
			break;
		pPreNode = pCurrentNode;
		pCurrentNode = pNextNode;
	}

	if(pCurrentNode == NULL)
		return ;
	pPreNode->changeNextNode(pCurrentNode, pNextNode);
	if(pNextNode != NULL)
		pNextNode->changePreNode(pCurrentNode, pPreNode);
	delete pCurrentNode;
}

unsigned int node2Addr(nodeOfOnePointerDoubleLinkedList *pNode)
{
	return *(unsigned int *)&pNode;
}

nodeOfOnePointerDoubleLinkedList * addr2Node(unsigned int addr)
{
	return (nodeOfOnePointerDoubleLinkedList*)addr;
}
#endif
