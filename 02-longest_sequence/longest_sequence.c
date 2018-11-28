#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct	s_node			{
	int					value;
	struct s_node		*left;
	struct s_node		*right;
};

int		helper(struct s_node *node, int *max)
{
	if (!(node))
		return (0);
	
	int		l = helper(node->left, max);
	int		r = helper(node->right, max);
	int		fromleft = 0;
	int		fromright = 0;

	if (!(node->left))
		fromleft = 1;
	else if (node->left->value - 1 == node->value)
		fromleft = l + 1;
	else
		fromleft = 1;

	if (!(node->right))
		fromright = 1;
	else if (node->right->value -1 == node->value)
		fromright = r + 1;
	else
		fromright = 1;

	*max = (*max > fromleft ? *max : fromleft);
	*max = (*max > fromright ? *max : fromright);
	return (fromleft > fromright ? fromleft : fromright);
}

int		longest_sequence(struct s_node *node)
{
	int		max = 0;

	helper(node, &max);
	return (max);
}

// prototype of answer
// https://www.programcreek.com/2014/04/leetcode-binary-tree-longest-consecutive-sequence-java/

/*
struct	s_node	*make_head(int value)
{
	struct	s_node		*head = malloc(sizeof(struct s_node));

	head->value = value;
	head->left = NULL;
	head->right = NULL;
	return (head);
}

void	polute_nodes(struct s_node *node, int left, int right)
{
	struct	s_node		*izquierda = make_head(left);
	struct	s_node		*derecha = make_head(right);

	node->left = izquierda;
	node->right = derecha;
}

int		main(void)
{
	// run test here
	struct	s_node		*head = make_head(1);

	polute_nodes(head, 2, 15);
	polute_nodes(head->left, 4, 3);
	polute_nodes(head->left->right, 4, 8);
	polute_nodes(head->left->right->left, 5, 6);
	printf("primer_test = |%d|\n", longest_sequence(head));
}
*/
