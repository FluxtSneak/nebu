#include <stdlib.h>

bool greater_than(int a, int b);
bool lesser_than(int a, int b);
void swap(int32_t* tab, int32_t a, int32_t b);
void sort(int32_t *sorted, const int32_t *const orig, int32_t nitems, bool (*comp)(int32_t, int32_t));
void test_ordre(int size,int array[size], bool (*comp)(int32_t, int32_t));
void print(int size,int tab[size]);
void random_tab(int size,int tab[size],int inf,int sup);
void swap(int* p_a,int* p_b);
int partition(int size,int array[size],int first,int last,bool (*comp)(int32_t, int32_t));
void quicksort(int size,int array[size],int first,int last, bool (*comp)(int32_t, int32_t));

#endif