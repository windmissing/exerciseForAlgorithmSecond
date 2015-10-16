#define MAX_SIZE 100

class CStack
{
public:
	int top;
	int *s;
	CStack(int size = MAX_SIZE);
	~CStack();
	void Print(CStack S);
	bool isEmpty();
	void push(int x);
	int pop();
};
