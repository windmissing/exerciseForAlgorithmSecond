#include <vector>

//一个活动用一个结点表示
struct activity
{
	int id;
	int start;
	int finish;
};

vector<int> Reccursive_Activity_Selector(vector<activity> A);
vector<int> Greedy_Activity_Selector(vector<activity> A);
