#include <stdlib.h>
#include <stdio.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
	if (!root)
		return ;

	struct s_node	*temp = root->left;

	root->left = root->right;
	root->right = temp;
	reverse_tree(root->left);
	reverse_tree(root->right);
}

// TESTING
/*
struct	s_node		*create_node(int value)
{
	struct s_node	*holder = malloc(sizeof(struct s_node));

	holder->value = value;
	holder->left = NULL;
	holder->right = NULL;
	return (holder);
}

void				make_childs(struct s_node *head, struct s_node *left, struct s_node *right)
{
	head->left = left;
	head->right = right;
}

int main(void)
{
	struct	s_node		*head = create_node(94);

	make_childs(head, create_node(34), create_node(52));

	printf("vaina left = |%d| right = |%d|\n", head->left->value, head->right->value);
	reverse_tree(head);
	printf("vaina left = |%d| right = |%d|\n", head->left->value, head->right->value);
	return (0);
}
*/
