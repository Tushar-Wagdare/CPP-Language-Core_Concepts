#include <cstdio>
#include <cstdlib>

struct vector
{
	int* p_array;
	size_t N;
};


struct vector* create_vector(void);
void push_back(struct vector* p_vec, int new_data);
void show(struct vector* p_vec);
void destroy_vector(struct vector* p_vec);


int main(void)
{
	struct vector* p_vec1 = NULL;
	struct vector* p_vec2 = NULL;

	p_vec1 = create_vector();
	p_vec2 = create_vector();

	push_back(p_vec1, 100);
	push_back(p_vec1, 200);
	push_back(p_vec1, 300);
	push_back(p_vec1, 400);

	push_back(p_vec2, 1000);
	push_back(p_vec2, 2000);
	push_back(p_vec2, 3000);
	push_back(p_vec2, 4000);

	show(p_vec1);
	show(p_vec2);

	destroy_vector(p_vec1);
	destroy_vector(p_vec2);

	return(0);
}


struct vector* create_vector(void)
{
	struct vector* p_vec = NULL;

	p_vec = (struct vector*)malloc(sizeof(struct vector));
	if (NULL == p_vec)
	{
		printf("Error allocating memory");
		exit(-1);
	}

	p_vec->p_array = NULL;
	p_vec->N = 0;

	return(p_vec);
}


void push_back(struct vector* p_vec, int new_data)
{
	p_vec->p_array = (int*)realloc(p_vec->p_array, (p_vec->N+1) * sizeof(int));
	if (NULL == p_vec->p_array)
	{
		puts("Error in allocating memory");
		exit(-1);
	}

	p_vec->N++;

	(p_vec->p_array)[p_vec->N - 1] = new_data;
}


void show(struct vector* p_vec)
{
	size_t i = 0;

	for (i = 0; i < p_vec->N; ++i)
	{
		printf("p_vec->p_array[%llu]:%d\n", i, (p_vec->p_array)[i]);
	}
}


void destroy_vector(struct vector* p_vec)
{
	free(p_vec->p_array);
	free(p_vec);
}


