#include "sort.h"

void merge_subarray(int *subarray, int *buffer, size_t front, size_t mid,
size_t back);
void merge_sort_recursive(int *subarray, int *buffer, size_t front, size_t back);
void merge_sort(int *array, size_t size);

void merge_subarray(int *subarray, int *buffer, size_t front, size_t mid,
size_t back)
{
size_t i, j, k = 0;

printf("Merging...\n[Left Subarray]: ");
print_array(subarray + front, mid - front);

printf("[Right Subarray]: ");
print_array(subarray + mid, back - mid);

for (i = front, j = mid; i < mid && j < back; k++)
buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
for (; i < mid; i++)
buffer[k++] = subarray[i];
for (; j < back; j++)
buffer[k++] = subarray[j];
for (i = front, k = 0; i < back; i++)
subarray[i] = buffer[k++];

printf("[Merged Subarray]: ");
print_array(subarray + front, back - front);
}

void merge_sort_recursive(int *subarray, int *buffer, size_t front, size_t back)
{
size_t mid;

if (back - front > 1)
{
mid = front + (back - front) / 2;
merge_sort_recursive(subarray, buffer, front, mid);
merge_sort_recursive(subarray, buffer, mid, back);
merge_subarray(subarray, buffer, front, mid, back);
}
}

void merge_sort(int *array, size_t size)
{
int *buffer;

if (array == NULL || size < 2)
return;

buffer = malloc(sizeof(int) * size);
if (buffer == NULL)
return;

merge_sort_recursive(array, buffer, 0, size);

free(buffer);
}

