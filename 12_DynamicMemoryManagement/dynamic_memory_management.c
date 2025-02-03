#include<stdio.h>
#include<stdlib.h>


struct Date
{
	int day;
	int month;
	int year;
};


void built_in_type(void);
void user_defined_data_type(void);

void array_of_built_in_data_type(void);
void array_of_user_defined_data_type(void);


int main(void)
{
	built_in_type();
	user_defined_data_type();
	array_of_built_in_data_type();
	array_of_user_defined_data_type();



	return(0);
}




void built_in_type(void)
{
	int* p = NULL; /// s1 : create a integer pointer

	puts("///////////////////////////////////////");

	p = (int*)malloc(sizeof(int)); /// s2
	///s2 : validation check
	if (NULL == p)
	{
		printf("Error in allocating memory");
		exit(-1);
	}

	*p = 500;     /// s4 : write
	int m = *p;   /// s4 : read

	printf("m = %d\n", m);

	free(p);      /// s5 : relese memory
	p = NULL;     /// s6 : if p is not assigned to null then p becomes dangling pointer
}


void user_defined_data_type(void)
{
	struct Date* pDate = NULL; /// s1

	puts("///////////////////////////////////////");

	pDate = (struct Date*)malloc(sizeof(struct Date)); /// s2
	/// s3
	if (NULL == pDate)
	{
		printf("Error in allocating Memory"); 
		exit(-1);
	}


	/// s4
	pDate->day = 26;
	pDate->month = 5;
	pDate->year = 2024;

	printf("TODAY:%d/%d/%d\n", pDate->day, pDate->month, pDate->year);

	free(pDate);  /// s5
	pDate = NULL; /// s6
}



void array_of_built_in_data_type(void)
{
	puts("///////////////////////////////////////");

	size_t N = 5;
	int* p = NULL; /// s1
	size_t i = 0;

	p = (int*)malloc(N * sizeof(int)); /// s2
	/// s3
	if (NULL == p)
	{
		puts("Error in allocating memory");
		exit(-1);
	}

	/// s4 write
	*(p + 0) = 100; 
	*(p + 1) = 200;
	*(p + 2) = 300;
	*(p + 3) = 400;
	*(p + 4) = 500;

	p[0] = 100;
	p[1] = 200;
	p[2] = 300;
	p[3] = 400;
	p[4] = 500;


	for (i = 0; i < N; i++)
	{
		printf("*(p + %llu) : %d\n",i, *(p + i));
	}

	for (i = 0; i < N; i++)
	{
		printf("p[%llu] : %d\n",i,  p[i]);
	}

	free(p);
	p = NULL;
}


void array_of_user_defined_data_type(void)
{
	puts("///////////////////////////////////////");

	size_t N = 5;
	size_t i = 0;
	struct Date* pDate = NULL;  /// s1

	pDate = (struct Date*)malloc(N * sizeof(struct Date));/// s2
	/// s3
	if (NULL == pDate)
	{
		puts("Error in aloocating memory");
		exit(-1);
	}

	/// s4
	for (i = 0; i < N; ++i)
	{
		pDate[i].day = 31;
		pDate[i].month = 3;
		pDate[i].year = 2000;

		printf("(*(pDate+%llu))->day : %d\n", i, pDate[i].day);
		printf("(*(pDate+%llu))->month : %d\n", i, (*(pDate + i)).month);
		printf("(*(pDate+%llu))->year : %d\n", i, (*(pDate + i)).year);
	}


	


}