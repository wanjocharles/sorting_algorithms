#include <stddef.h>
#include "sort.h"

void exchange_values(int *a, int *b)
{
int temporary;
temporary = *a;
*a = *b;
*b = temporary;
}

int lomuto_partition(int *array, size_t size, int left, int right)
{
int *pivot, above, below;
pivot = array + right;
for (above = below = left; below < right; below++)
{
if (array[below] < *pivot)
{
if (above < below)
{
exchange_values(array + below, array + above);
print_array(array, size);
}
above++;
}
}

if (array[above] > *pivot)
{
exchange_values(array + above, pivot);
print_array(array, size);
}

return above;
}

void lomuto_sort(int *array, size_t size, int left, int right)
{
int part;
if (right - left > 0)
{
part = lomuto_partition(array, size, left, right);
lomuto_sort(array, size, left, part - 1);
lomuto_sort(array, size, part + 1, right);
}
}

void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
lomuto_sort(array, size, 0, size - 1);
}

