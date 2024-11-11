#include "minishell.h"

size_t			size_env(t_env *lst)
{
	size_t	lst_len;

	lst_len = 0;
	while (lst && lst->next != NULL)
	{
		if (lst->value != NULL)
		{
			lst_len += ft_strlen(lst->value);
			lst_len++;
		}
		lst = lst->next;
	}
	return (lst_len);
}

char			*env_to_str(t_env *lst)
{
	char	*env;
	int		i;
	int		j;

	if (!(env = malloc(sizeof(char) * size_env(lst) + 1)))
		return (NULL);
	i = 0;
	while (lst && lst->next != NULL)
	{
		if (lst->value != NULL)
		{
			j = 0;
			while (lst->value[j])
			{
				env[i] = lst->value[j];
				i++;
				j++;
			}
		}
		if (lst->next->next != NULL)
			env[i++] = '\n';
		lst = lst->next;
	}
	env[i] = '\0';
	return (env);
}


int				secret_env_init(t_mini *mini, char **env)
{
	t_env	*env_lst;
	t_env	*tmp;
	int		i;

	if (!(env_lst = malloc(sizeof(t_env))))
		return (1);
	env_lst->value = ft_strdup(env[0]);
	env_lst->next = NULL;
	mini->secret_env = env_lst;
	i = 1;
	while (env && env[0] && env[i])
	{
		if (!(tmp = malloc(sizeof(t_env))))
			return (1);
		tmp->value = ft_strdup(env[i]);
		tmp->next = NULL;
		env_lst->next = tmp;
		env_lst = tmp;
		i++;
	}
	return (0);
}

int				env_init(t_mini *mini, char **env)
{
	t_env	*env_lst;
	t_env	*tmp;
	int		i;

	if (!(env_lst = malloc(sizeof(t_env))))
		return (1);
	env_lst->value = ft_strdup(env[0]);
	env_lst->next = NULL;
	mini->env = env;
	i = 1;
	while (env && env[0] && env[i])
	{
		if (!(tmp = malloc(sizeof(t_env))))
			return (1);
		tmp->value = ft_strdup(env[i]);
		tmp->next = NULL;
		env_lst->next = tmp;
		env_lst = tmp;
		i++;
	}
	return (0);
}