#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct	s_node			{
	void				*content;
	struct	s_node		*next;
};

struct	s_queue			{
	struct	s_node		*first;
	struct	s_node		*last;
};

int						isEmpty(struct s_queue *queue)
{
	if (!(queue) || !(queue->first))
		return (1);
	else
		return (0);
}

struct	s_queue			*init(void)
{
	struct	s_queue		*holder = malloc(sizeof(struct s_queue));

	holder->first = NULL;
	holder->last = NULL;
	return (holder);
}

void					enqueue(struct s_queue *queue, void *content)
{
	struct	s_node		*holder = malloc(sizeof(struct s_node));

	holder->content = content;
	holder->next = NULL;
	if (isEmpty(queue) == 1)
	{
		queue->first = holder;
		queue->last = holder;
	}
	else
	{
		queue->last->next = holder;
		queue->last = holder;
	}
}

void					*dequeue(struct s_queue *queue)
{
	void				*ptr = NULL;
	struct	s_node		*holder = NULL;

	if (isEmpty(queue) == 0)
	{
		ptr = queue->first->content;
		holder = queue->first;
		if (queue->first == queue->last)
		{
			queue->first = NULL;
			queue->last = NULL;
		}
		else
			queue->first = queue->first->next;
		free(holder);
	}
	return (ptr);
}

void					*peek(struct s_queue *queue)
{
	void				*ptr = NULL;

	if (isEmpty(queue) == 0)
		ptr = queue->first->content;
	return (ptr);
}


/*
int			main(void)
{
	struct	s_queue	*queue = init();

	printf("Has to be empty - 1 = |%d|\n", isEmpty(queue));
	printf("Should be NULL = |%p|\n", peek(queue));

	enqueue(queue, strdup("something"));
	enqueue(queue, strdup("in"));
	enqueue(queue, strdup("the"));
	enqueue(queue, strdup("way"));
	enqueue(queue, strdup("she"));
	printf("Has to be not empty - 0 = |%d|\n", isEmpty(queue));
	for(int i = 0; i < 5; ++i)
		printf("dequeueing = |%s|\n", dequeue(queue));
	
	printf("Has to be empty - 1 = |%d|\n", isEmpty(queue));
	return (0);
}
*/
