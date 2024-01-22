#include "sort.h"

void swap_elements(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

void swap_elements(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;
}

int hoare_partition(int *array, size_t size, int left, int right)
{
int pivot, above, below;

pivot = array[right];
for (above = left - 1, below = right + 1; above < below;)
{
do {
above++;
} while (array[above] < pivot);
do {
below--;
} while (array[below] > pivot);

if (above < below)
{
swap_elements(array + above, array + below);
print_array(array, size);
}
}

return above;
}

void hoare_sort(int *array, size_t size, int left, int right)
{
int partition;

if (right - left > 0)
{
partition = hoare_partition(array, size, left, right);
hoare_sort(array, size, left, partition - 1);
hoare_sort(array, size, partition, right);
}
}

void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

hoare_sort(array, size, 0, size - 1);
}

