#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>


struct	s_node				{
	int						value;
	struct	s_node			*right;
	struct	s_node			*left;
};


struct	s_node		*create_head(int value)
{
	struct	s_node	*holder = malloc(sizeof(struct s_node));
	
	holder->value = value;
	holder->right = NULL;
	holder->left = NULL;
	return (holder);
}

void				populate(struct	s_node	*head, int left, int right)
{
	struct	s_node		*left_node = create_head(left);
	struct	s_node		*right_node = create_head(right);

	if (left == 0)
		left_node = NULL;
	if (right == 0)
		right_node = NULL;
	head->left = left_node;
	head->right = right_node;
}

void				add_to_the_end(struct s_node **head, struct s_node *node)
{
	struct	s_node		*tmp = *head;

	while (tmp->right)
		tmp = tmp->right;
	tmp->right = node;
}

void				bubble_sort(struct s_node **bst)
{
	struct	s_node	*tmp = *bst;
	int				swaper = 0;

	while(tmp && tmp->right)
	{
		if (tmp->value > tmp->right->value)
		{
			swaper = tmp->right->value;
			tmp->right->value = tmp->value;
			tmp->value = swaper;
			tmp = *bst;
		}
		else
			tmp = tmp->right;
	}
//	*bst = tmp;
}

void				fix_links(struct s_node **bst)
{
	struct	s_node	*tmp = *bst;

	while(tmp && tmp->right)
	{
		tmp->right->left = tmp;
		tmp = tmp->right;
	}
//	*bst = tmp;
}

void				make_it_circular(struct s_node	**bst)
{
	struct	s_node	*tmp = *bst;

	while (tmp->right)
		tmp = tmp->right;
	tmp->right = *bst;
	(*bst)->left = tmp;
}

struct	s_node		*convert_bst(struct	s_node	*bst)
{
	if (!(bst))
		return (NULL);
	
	struct	s_node	*iter = bst;
	struct	s_node	*tmp = NULL;

	while(iter->right)
	{
		if (iter->left)
		{
			tmp = iter->left;
			iter->left = NULL;
			add_to_the_end(&bst, tmp);
			tmp = NULL;
			iter = bst;
		}
		iter = iter->right;
	}
	fix_links(&bst);
	bubble_sort(&bst);
	// make it circular
	make_it_circular(&bst);
	return (bst);
}

/*
void				print_lista(struct s_node *head)
{
	struct	s_node		*tmp;

	tmp = head;
	while (tmp)
	{
		printf("value = %d\n", tmp->value);
		tmp = tmp->right;
	}
}

int					main(void)
{
	struct		s_node		*head = create_head(7);

	struct		s_node		*sorted = NULL;

	// 0's are nullified
	populate(head, 4, 10);
	populate(head->left, 2, 5);
	populate(head->left->right, 0, 6);
	populate(head->left->left, 1, 3);
	populate(head->right, 8, 12);
	populate(head->right->left, 0, 9);
	populate(head->right->right, 11, 0);

	sorted = convert_bst(head);
	print_lista(sorted);
}
*/
