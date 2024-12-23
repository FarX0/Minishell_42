/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:27:20 by tfalchi           #+#    #+#             */
/*   Updated: 2024/12/20 14:53:14 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	initialize_data(char **env)
{
	t_data	data;

	data.env = matrix_dup(env);
	data.cube_input = NULL;
	data.input = NULL;
	data.flag1 = 0;
	data.flag2 = 0;
	data.path = NULL;
	data.original_input = 0;
	data.original_output = 1;
	data.fds = (int **)malloc(sizeof(int *) * 2);
	data.fds[0] = (int *)malloc(sizeof(int) * 2);
	data.fds[0][0] = 0;
	data.fds[0][1] = 1;
	data.nbr_cmd = 1;
	data.exit_code = 0;
	
	//data.input = NULL;
	
	return (data);
}

char	**matrix_dup(char **matrix)
{
	char	**new_matrix;
	int		i;

	if (!matrix)
		return (NULL);
	i = 0;
	while (matrix[i] != NULL)
		i++;
	new_matrix = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_matrix)
		return (NULL);
	i = 0;
	while (matrix[i] != NULL)
	{
		new_matrix[i] = ft_strdup(matrix[i]);
		i++;
	}
	new_matrix[i] = NULL;
	return (new_matrix);
}
