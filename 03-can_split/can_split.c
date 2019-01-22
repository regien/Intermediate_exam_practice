#include <stdio.h>
#include <stdlib.h>

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int			helper(struct s_node *n)
{
	if (!n)
		return (0);

	int		left = helper(n->left);
	int		right = helper(n->right);

	return (left + right + 1);
}

int			can_split(struct s_node *n)
{
	int		n_nodes = 0;

	n_nodes = helper(n);
	return (n_nodes % 2 == 0 ? 1 : 0);
}

// TESTING PART
/*
struct s_node		*create_node(int value)
{
	struct s_node	*holder = malloc(sizeof(struct s_node));

	holder->value = value;
	holder->right = NULL;
	holder->left = NULL;
	return (holder);
}

void				make_childs(struct s_node *head, struct s_node *left, struct s_node *right)
{
	head->left = left;
	head->right = right;
}

int main(void)
{
	struct s_node		*head = create_node(28);

	make_childs(head, create_node(51), NULL);
	make_childs(head->left, create_node(26), create_node(48));
	make_childs(head->left->left, create_node(76), create_node(13));
	printf("can be splitted should be 1 = |%d|\n", can_split(head));
	

	struct s_node		*vaina = NULL;
	printf("can be splitted should be 1 = |%d|\n", can_split(vaina));
}
*/
