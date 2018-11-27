#include <stdio.h>
#include <stdlib.h>

struct	s_node {
		int				value;
		struct s_node	**nodes;
};

int				height_tree(struct s_node *root)
{
		int		curr_height;
		int		max_height;

		if (root == NULL)
			return (0);
		max_height = 0;
		for (size_t i = 0; root->nodes[i]; i++)
		{
				curr_height = height_tree(root->nodes[i]) + 1;
				if (curr_height > max_height)
					max_height = curr_height;
		}
		return (max_height);
}
