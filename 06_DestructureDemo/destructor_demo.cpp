#include <iostream>

class Test
{
	int test1;

public:
	Test()
	{
		puts("in Test()");
		printf("in Test() This:%llu\n", (unsigned long long)this);
	}

	~Test()
	{
		puts("in ~Test()");
		printf("in ~Test() This:%llu\n", (unsigned long long)this);
	}
};


int main(void)
{
	Test* test = NULL;

	test = new Test;
	printf("in main This:%llu\n", (unsigned long long)test);

	delete test;
	test = NULL;


	return(0);
}

