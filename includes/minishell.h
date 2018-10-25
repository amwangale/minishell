/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amwangal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:13:27 by amwangal          #+#    #+#             */
/*   Updated: 2018/10/25 10:15:48 by amwangal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdint.h>
# include <unistd.h>

/*
** stdint is the header holding uint_8 below
*/

# include "../libft/libft.h"

# ifndef PROMPT
# define PROMPT "MwangaleShell$>"
# endif

/*
** a node in our doubly linked list with a void
** pointer to any data type described by size
*/

typedef struct		s_node
{
    size_t          size;
    void            *data;
    struct s_node   *next;
    struct s_node   *prev;
}					t_node;

/*
** a linked list of length with pointers to head
** and tail offering O(1) access with appending
** popping from either side of the list, as well
** as a convenient exit condition during list
** traversal
*/

typedef struct      s_link
{
    size_t          len;
    t_node          *head;
    t_node          *tail;
}                   t_link;

/*
** status flags and our personal errno to update
** state of our shell during runtime
*/

typedef struct      s_status
{
    uint8_t         running :1;
    int             error;
}                   t_status;

/*
** environment variables to use within our
** environment. val is the right hand value of our
** environment variable while var is the left
** hand name of our environment variable
*/

typedef struct      s_var
{
    char            *val;
    char            *var;
}                   t_var;

/*
** environment to maintain shell state, variables
** and other additional information needed during
** runtime
*/

typedef struct      s_env
{
    /*
    ** linked list of variables from t_link
    */

    t_link          *vars;
    t_status        status;
}                   t_env;

/*
** initialize our environment struct, passing the
** environment by reference and mallocing the
** appropriate space. Other default struct values
** can be set here such as our linked list of
** environment variables
*/

int                 init(t_env **env);

/*
** error handler function which sets our status
** values appropriately, such as in the case of
** an error, our status.error will be set to
** custom errno and the minishell will act
** accordingly
*/

void                error(t_env *env);
