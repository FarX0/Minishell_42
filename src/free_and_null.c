/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:05:16 by tfalchi           #+#    #+#             */
/*   Updated: 2024/12/20 15:19:34 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array_matrix(t_data *data)
{
	if (data->fds)
	{
		free(data->fds[0]); // while (data->nbr_cmd)
		free(data->fds);
		data->fds = NULL;
	}
}
void	free_all(t_data *data)
{
	free_input(data);
	free_array_matrix(data);
	free_env(data);
	free(data->path);
}

void free_input(t_data *data)
{
	if (data->cube_input)
	{
		int n = 0;
		int i = 0;
		while (data->cube_input[n] != NULL)
		{
			while (data->cube_input[n][i] != NULL)
			{
				//printf("Freeing matrix input:%s\n", data->cube_input[n][i]);
				free(data->cube_input[n][i]);
				data->cube_input[n][i] = NULL;
				i++;
			}
			free(data->cube_input[n]);
			data->cube_input[n] = NULL;
			n++;
		}
		free(data->cube_input);
		data->cube_input = NULL;
	}
	if (data->input)
	{
		//printf("Freeing input:%s\n", data->input);
		free(data->input);
		data->input = NULL;
	}
}

void free_env(t_data *data)
{
	int i;

	i = 0;
	if (data->env == NULL)
		return;
	while (data->env[i] != NULL)
	{
		free(data->env[i]);
		data->env[i] = NULL;
		i++;
	}
	free(data->env);
	data->env = NULL;
}

void    free_matrix(char **matrix)
{
    int i;

    i = 0;
    while (matrix[i] != NULL)
    {
        free(matrix[i]);
        matrix[i] = NULL;
        i++;
    }
    free(matrix);
    matrix = NULL;
}
