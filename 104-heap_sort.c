#include "sort.h"

void swap_elements(int *a, int *b);
void maintain_max_heap(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

void swap_elements(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

void maintain_max_heap(int *array, size_t size, size_t base, size_t root)
{
size_t left, right, largest;

left = 2 * root + 1;
right = 2 * root + 2;
largest = root;

if (left < base && array[left] > array[largest])
largest = left;
if (right < base && array[right] > array[largest])
largest = right;

if (largest != root)
{
swap_elements(array + root, array + largest);
maintain_max_heap(array, size, base, largest);
}
}

void heap_sort(int *array, size_t size)
{
int i;

if (array == NULL || size < 2)
return;

for (i = (size / 2) - 1; i >= 0; i--)
maintain_max_heap(array, size, size, i);

for (i = size - 1; i > 0; i--)
{
swap_elements(array, array + i);
maintain_max_heap(array, size, i, 0);
}
}

