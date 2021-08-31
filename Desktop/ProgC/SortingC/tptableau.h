#ifndef _TABTP_H
#define _TABTP_H

typedef struct _indVal{
	int32_t ind;
	int32_t val;
}indVal;

void init_tab(int32_t tab[], int32_t size, int32_t valmax);

int32_t find_min(int32_t tab[], int32_t size);

indVal find_max(int32_t tab[], int32_t size);

void swap_max_to_last(int32_t tab[], int32_t n);

int32_t search_in_tab(int32_t tab[], int32_t n, int32_t src_n);

double tab_moy(double tab[], int32_t n);

double tab_var(double tab[], int32_t n);

void sort_tab_c(int32_t tab[], int32_t n);

int median_element(int32_t tab[], int32_t n);

void print_tab(int32_t tab[],  int32_t n);

#endif
