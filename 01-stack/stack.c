#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct					s_node {
	void				*content;
	struct	s_node		*next;
};

struct					s_stack {
	struct	s_node		*top;
};

int					isEmpty(struct s_stack *stack)
{
	if (!(stack) || !(stack->top))
		return (1);
	else
		return (0);
}

struct	s_stack		*init(void)
{
	struct	s_stack	*holder = NULL;

	holder = malloc(sizeof(struct s_stack));
	holder->top = NULL;
	return (holder);
}

void				*pop(struct s_stack *stack)
{
	void			*ptr = NULL;
	struct	s_node	*holder = NULL;

	if (isEmpty(stack) == 0)
	{
		ptr = stack->top->content;
		holder = stack->top;
		stack->top = stack->top->next;
		free(holder);
	}
	return (ptr);
}

void				push(struct s_stack *stack, void *content)
{
	struct	s_node	*holder = NULL;

	if (!(stack))
		return ;
	holder = malloc(sizeof(struct s_node));
	holder->content = content;
	holder->next = stack->top;
	stack->top = holder;
	return ;
}

void				*peek(struct s_stack *stack)
{
	void			*ptr = NULL;
	
	if (isEmpty(stack) == 0)
		ptr = stack->top->content;
	return (ptr);
}


int					main(void)
{
	struct	s_stack *vaina = init();

//	run tests here
	push(vaina, strdup("something"));
	printf("This should print the string = |%s|\n", peek(vaina));
	printf("Should print same string = |%s|\n", (char*)pop(vaina));
	printf("Should be NULL = |%s|\n", pop(vaina));
	printf("should be 1 = |%d|\n", isEmpty(vaina));
	push(vaina, strdup("testing"));
	push(vaina, strdup("the "));
	push(vaina, strdup("queue"));
	push(vaina, strdup("just in case"));
	printf("should be 0 = |%d|\n", isEmpty(vaina));
	push(vaina, strdup("pwd"));
	push(vaina, strdup("ls"));
	for (int i = 0; i < 6; i++)
		printf("Printing the actual stack = |%s|\n", (char*)pop(vaina));
	printf("should be 1 = |%d|\n", isEmpty(vaina));
}
