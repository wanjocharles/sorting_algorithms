#include "sort.h"

/**
 * exchangeNodes - Swap two nodes in a doubly linked list.
 * @head: Pointer to the head of the list.
 * @node1: Pointer to the first node to be swapped.
 * @node2: Pointer to the second node to be swapped.
 */
void exchangeNodes(listint_t **head, listint_t **node1, listint_t *node2)
{
    (*node1)->next = node2->next;
    if (node2->next != NULL)
        node2->next->prev = *node1;
    node2->prev = (*node1)->prev;
    node2->next = *node1;
    if ((*node1)->prev != NULL)
        (*node1)->prev->next = node2;
    else
        *head = node2;
    (*node1)->prev = node2;
    *node1 = node2->prev;
}

/**
 * insertion_sort_list - Sort a doubly linked list using the insertion sort algorithm.
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *toInsert, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (current = (*list)->next; current != NULL; current = temp)
    {
        temp = current->next;
        toInsert = current->prev;
        while (toInsert != NULL && current->n < toInsert->n)
        {
            exchangeNodes(list, &toInsert, current);
            print_list((const listint_t *)*list);
        }
    }
}

