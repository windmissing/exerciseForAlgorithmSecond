#include <vector>
using namespace std;

//10.2-8
struct nodeOfOnePointerDoubleLinkedList
{
	int key;//?
	unsigned int pointer;//??,???32??,???????????
	nodeOfOnePointerDoubleLinkedList(int k):key(k),pointer(0){}
	void changePreNode(nodeOfOnePointerDoubleLinkedList *pFromNode, nodeOfOnePointerDoubleLinkedList *pToNode);
	void changeNextNode(nodeOfOnePointerDoubleLinkedList *pFromNode, nodeOfOnePointerDoubleLinkedList *pToNode);
	nodeOfOnePointerDoubleLinkedList *getPreFromNext(nodeOfOnePointerDoubleLinkedList *pNextNode);
	nodeOfOnePointerDoubleLinkedList *getNextFromPre(nodeOfOnePointerDoubleLinkedList *pPreNode);
};
//??
class listOfOnePointerDoubleLink
{
private:
	nodeOfOnePointerDoubleLinkedList *pHeadNode;//???,????,?????????
public:
	listOfOnePointerDoubleLink(){pHeadNode = new nodeOfOnePointerDoubleLinkedList(0);}
	~listOfOnePointerDoubleLink(){delete pHeadNode;}
	void Insert(int key);
	vector<int> Print();
	void Delete(int key);
};

//10.3-4
class CCompactMultipleArray
{
private:
	int *key;
	int *next;
	int *prev;
	int size;
	int head;
	int f;
public:
	CCompactMultipleArray(int n = 100);
	~CCompactMultipleArray();
	void insert(int x);
	void remove(int x);
};
