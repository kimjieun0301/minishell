/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:45:17 by jkim3             #+#    #+#             */
/*   Updated: 2023/04/02 16:04:54 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../headers/mini_parsing.h"

int	parsing(char *line, t_list **cmd, t_list *env_lst)
{
	t_list	*tk_lst;
	int		cmd_cnt;

	tk_lst = NULL;
	if (tokenizing(&tk_lst, line, env_lst) < 0)
	{
		ft_lstclear(&tk_lst, free);
		return (ERROR);
	}
	cmd_cnt = init_cmd_lst(cmd, tk_lst);
	ft_lstclear(&tk_lst, free);
	return (cmd_cnt);
}

int	init_cmd_lst(t_list **cmd, t_list *tk_lst)
{
	t_list	*tk_p;
	t_cmd	*new_cmd;
	int		cmd_cnt;

	tk_p = tk_lst;
	new_cmd = NULL;
	cmd_cnt = 0;
	while (tk_p)
	{
		if (set_cmd_val(&tk_p, &new_cmd) < 0)
		{
			free_cmd_struct(new_cmd);
			return (ERROR);
		}
		cus_ft_lstadd_back(cmd, new_cmd);
		cmd_cnt++;
		if (tk_p)
			tk_p = tk_p->next;
	}
	return (cmd_cnt);
}
