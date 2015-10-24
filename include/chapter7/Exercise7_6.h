#include <vector>
using namespace std;

struct section
{
	int start;
	int end;
	bool operator<(const section& b)const
	{
		return end < b.start;
	}
	bool operator==(const section & b)const
	{
		return (end >= b .start) && (start <= b.end);
	}
	bool operator>(const section & b)const
	{
		return start > b.end;
	}
};

//????:0 -> a????,a+1 -> b-1????,b -> length_A????
struct divid
{
	int a;
	int b;
};

#define ARRAY vector<section>

void Exercise7_6(ARRAY & array);
