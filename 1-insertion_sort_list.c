#include "sort.h"
#include <stdlib.h>

/**
 * swap - Swaps two nodes in a doubly linked list
 * @unsorted: Pointer to a pointer to the unsorted node
 * @sorted: Pointer to a pointer to the sorted node
 * Return: Pointer to the new position of the unsorted node
 */
listint_t *swap(listint_t **unsorted, listint_t **sorted)
{
	listint_t *tmp;

	tmp = (*unsorted)->next;

	if (*sorted != NULL)
		(*sorted)->next = tmp;

	if (tmp != NULL)
		tmp->prev = *sorted;

	if (*unsorted != NULL)
	{
		(*unsorted)->next = *sorted;
		(*unsorted)->prev = (*sorted)->prev;
	}

	if ((*sorted)->prev != NULL)
		(*sorted)->prev->next = *unsorted;

	(*sorted)->prev = *unsorted;

	return (*unsorted);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers using
 *                       the insertion sort algorithm
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted;
	listint_t *sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted = *list;
	unsorted = (*list)->next;

	while (unsorted != NULL)
	{
		if (sorted != NULL && unsorted->n < sorted->n)
		{
			unsorted = swap(&unsorted, &sorted);
			sorted = unsorted->prev;

			if (sorted == NULL)
				*list = unsorted;

			print_list(*list);

			while (sorted != NULL && unsorted->n < sorted->n)
			{
				unsorted = swap(&unsorted, &sorted);
				sorted = unsorted->prev;

				if (sorted == NULL)
					*list = unsorted;

				print_list(*list);
			}
		}
		else
		{
			sorted = unsorted;
			unsorted = sorted->next;
		}
	}
}
