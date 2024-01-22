#include "sort.h"

/**
 * exchange_values - Exchange the values of two integers in an array.
 * @a: The first integer to exchange.
 * @b: The second integer to exchange.
 */
void exchange_values(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;

if (array == NULL || size < 2)
return;

for (gap = size / 2; gap > 0; gap /= 2)
{
for (i = gap; i < size; i++)
{
int key = array[i];
j = i;

while (j >= gap && array[j - gap] > key)
{
exchange_values(array + j, array + (j - gap));
j -= gap;
}

array[j] = key;
}
print_array(array, size);
}
}

