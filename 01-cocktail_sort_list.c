#include "sort.h"

/**
 * swap_forward - Swap two adjacent elements in a linked list in forward direction.
 * @list: Pointer to the head of the linked list.
 * @tail: Pointer to the tail of the linked list.
 * @shaker: Pointer to the current node being considered.
 */
void swap_forward(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shaker)->next;
if ((*shaker)->prev != NULL)
(*shaker)->prev->next = tmp;
else
*list = tmp;
tmp->prev = (*shaker)->prev;
(*shaker)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *shaker;
else
*tail = *shaker;
(*shaker)->prev = tmp;
tmp->next = *shaker;
*shaker = tmp;
}
/**
 * swap_backward - Swap two adjacent elements in a linked list in backward direction.
 * @list: Pointer to the head of the linked list.
 * @tail: Pointer to the tail of the linked list.
 * @shaker: Pointer to the current node being considered.
 */
void swap_backward(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shaker)->prev;
if ((*shaker)->next != NULL)
(*shaker)->next->prev = tmp;
else
*tail = tmp;
tmp->next = (*shaker)->next;
(*shaker)->prev = tmp->prev;
if (tmp->prev != NULL)
tmp->prev->next = *shaker;
else
*list = *shaker;
(*shaker)->next = tmp;
tmp->prev = *shaker;
*shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a doubly linked list in ascending order using Cocktail Shaker Sort.
 * @list: Pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *shaker;
bool shaken_not_stirred = false;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
for (tail = *list; tail->next != NULL;)
tail = tail->next;
while (!shaken_not_stirred)
{
shaken_not_stirred = true;
for (shaker = *list; shaker != tail; shaker = shaker->next)
{
if (shaker->n > shaker->next->n)
{
swap_forward(list, &tail, &shaker);
shaken_not_stirred = false;
}
}
for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
{
if (shaker->n < shaker->prev->n)
{
swap_backward(list, &tail, &shaker);
shaken_not_stirred = false;
}        
}
}
print_list((const listint_t *)*list);
}

