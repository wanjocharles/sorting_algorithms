#include "sort.h"
int find_maximum(int *array, int size);
void radix_counting_sort(int *array, size_t size, int significant_digit, int *buffer);
void radix_sort(int *array, size_t size);

int find_maximum(int *array, int size) {
int maximum_value, i;
for (maximum_value = array[0], i = 1; i < size; i++) {
if (array[i] > maximum_value)
maximum_value = array[i];
}
return (maximum_value);
}

void radix_counting_sort(int *array, size_t size, int significant_digit, int *buffer) {
int count[10] = {0};
size_t i;
for (i = 0; i < size; i++)
count[(array[i] / significant_digit) % 10] += 1;
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
for (i = size; i > 0; i--) {
buffer[count[(array[i - 1] / significant_digit) % 10] - 1] = array[i - 1];
count[(array[i - 1] / significant_digit) % 10] -= 1;
}
for (i = 0; i < size; i++)
array[i] = buffer[i];
}

void radix_sort(int *array, size_t size) {
int max_value, significant_digit, *temporary_buffer;
if (array == NULL || size < 2)
return;
temporary_buffer = malloc(sizeof(int) * size);
if (temporary_buffer == NULL)
return;
max_value = find_maximum(array, size);
for (significant_digit = 1; max_value / significant_digit > 0; significant_digit *= 10) {
radix_counting_sort(array, size, significant_digit, temporary_buffer);
print_array(array, size);
}
free(temporary_buffer);
}

