#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Floyds's Cycle-finding algorithm (fastest one)
// you have two pointer, one increasing one by one and the
// other one increasing two each time
// https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

struct	s_node				{
	int					value;
	struct	s_node		*next;
};

int						is_looping(struct s_node *node)
{
	struct	s_node		*slow_p = node;
	struct	s_node		*fast_p = node;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
			return (1);
	}
	return (0);
}

struct	s_node			*new_node(int i)
{
	struct	s_node		*holder;

	holder = malloc(sizeof(struct s_node));
	holder->value = i;
	holder->next = NULL;
	return (holder);
}

void					add_list(struct s_node **head, struct s_node *node)
{
	node->next = (*head);
	(*head) = node;
}

void					printing_list(struct s_node **head)
{
	struct	s_node		*holder = (*head);

	while (holder)
	{
		printf("printing value = |%d|\n", holder->value);
		holder = holder->next;
	}
}

int		main(void)
{
	struct s_node		*head = new_node(14);

	add_list(&head, new_node(1));
	add_list(&head, new_node(4));
	add_list(&head, new_node(31));
	add_list(&head, new_node(16));
	add_list(&head, new_node(20));
	add_list(&head, new_node(25));
	add_list(&head, new_node(48));

	printing_list(&head);
	printf("is looping? |%d|\n", is_looping(head));

	head->next->next->next->next = head;
	printf("is looping? |%d|\n", is_looping(head));
}
