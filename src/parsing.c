/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:48:19 by tfalchi           #+#    #+#             */
/*   Updated: 2024/12/20 15:55:57 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data parsing(t_data data)
{
	data = del_extra_spaces(data);
	data = split_input(data);
	return (data);
}

t_data del_extra_spaces(t_data data)
{
	int i;
	int j;
	char *strcpy;

	i = 0;
	j = 0;
	data.input = ft_strdup(data.terminal_input);
	if (data.input)
		strcpy = ft_calloc(sizeof(char), ft_strlen(data.input) + 1);
	while (data.input[i] == ' ')
		i++;
	while (data.input[i] != '\0')
	{
		if (data.input[i] == 39 && data.flag1 % 2 == 0)
			data.flag2 += 1;
		if (data.input[i] == 34 && data.flag2 % 2 == 0)
			data.flag1 += 1; 
		while (data.input[i] == ' ' && data.input[i + 1] == ' ' && data.flag1 % 2 == 0 && data.flag2 % 2 == 0)
			i++;
		if (data.input[i] == ' ' && data.flag1 % 2 == 0 && data.flag2 % 2 == 0 && data.input[i + 1] == '\0')
			i++;
		strcpy[j] = data.input[i];
		i++;
		j++;
	}
	free(data.input);
	data.input = strcpy;
	return (data);
}

t_data split_input(t_data data)
{
	int i;
	int j;
	int k;
	int n;

	n = 0;
	i = 0;
	j = 0;
	k = 0;
	while (data.input[i] != '\0')
	{
		if (data.input[i] == '|')
			data.nbr_cmd++;
		i++;
	}
	i = 0;
	if (data.input)
		data.cube_input = cube_alloc(data.input, data.nbr_cmd);
	while (data.input[i] != '\0')
	{
		if (data.input[i] == '|')
		{
			data.cube_input[n][k][j] = '\0';
			n++;
			k = 0;
			j = 0;
			i++;
		}
		if (data.input[i] == 39)
		{
			i++;
			while (data.input[i] != 39 && data.input[i] != '\0')
			{
				data.cube_input[n][k][j] = data.input[i];
				i++;
				k++;
			}
			i++;
		}
		if (data.input[i] == 34)
		{
			i++;
			while (data.input[i] != 34 && data.input[i] != '\0')
			{
				data.cube_input[n][k][j] = data.input[i];
				i++;
				k++;
			}
			i++;
		}
		if (data.input[i] == ' ')
		{
			data.cube_input[n][k][j] = '\0';
			j = 0;
			k++;
			i++;
		}
		if (data.input[i] == '\0')
			break;
		data.cube_input[n][k][j] = data.input[i];
		i++;
		j++;
	}
	return (data);
}

char  ***cube_alloc(char *str, int nbr_cmd)
{
	int i;
	int j;
	int k;
	int n;
	char **cube;

	i = 0;
	j = 0;
	k = 0;
	n = 0;
	cube = ft_calloc(nbr_cmd + 1, sizeof(char **));
	while (i < nbr_cmd)
	{
		while (str[n] != '|')
		{
			if (str[n] == ' ')
				k++;
			n++;
		}
		k = 0;
		cube[i] = ft_calloc(k + 2, sizeof(char *));
		while (j < n)
		{
			while (str[n][j] != ' ')
				k++;
			cube[i][j] = ft_calloc(k + 1, sizeof(char));
			j++;
		}
		i++;
		n = 0;
		j = 0;
		k = 0;
	}
	return (cube);
}
