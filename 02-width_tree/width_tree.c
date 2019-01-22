#include <stdio.h>
#include <stdlib.h>

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	helper(struct s_node *n, int *longest)
{
	if (!n)
		return (0);
	int		longest_local_path = 0;
	int		left = helper(n->left, longest);
	int		right = helper(n->right, longest);

	longest_local_path = (left >= right ? left : right) + 1;
	if (left + right + 1 > *longest)
		*longest = left + right + 1;
	return (longest_local_path);
}

int	width_tree(struct s_node *n)
{
	if (!n)
		return (0);
	int longest = 0;
	helper(n, &longest);
	return (longest);
}

/*
struct s_node		*create_node(int cojudez)
{
	struct s_node	*vaina = malloc(sizeof(struct s_node));

	vaina->value = cojudez;
	vaina->left = NULL;
	vaina->right = NULL;
	return (vaina);
}

void				make_childs(struct s_node *pendejada, struct s_node *left, struct s_node *right)
{
	pendejada->left = left;
	pendejada->right = right;
}

int main(void)
{
	struct s_node	*zona = create_node(1);

	make_childs(zona, create_node(2), create_node(3));
	make_childs(zona->left, create_node(4), create_node(7));
	make_childs(zona->left->left, create_node(5), create_node(6));
	make_childs(zona->left->left->left, NULL, create_node(8));
	make_childs(zona->left->right, create_node(9), create_node(10));
	make_childs(zona->left->right->left, create_node(11), create_node(12));
	make_childs(zona->left->right->right, NULL, create_node(13));

	printf("result %d == 7\n", width_tree(zona));

	struct s_node	*head = create_node(25);

	make_childs(head, create_node(33), NULL);
	make_childs(head->left, create_node(12), create_node(9));
	make_childs(head->left->right, create_node(3), NULL);

	printf("result %d == 4\n", width_tree(head));

	struct s_node	*second = create_node(10);

	make_childs(second, NULL, create_node(12));
	printf("result %d == 2\n", width_tree(second));


}
*/
