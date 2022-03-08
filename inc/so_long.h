/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:05:05 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/08 23:30:04 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_h

typedef struct s_map
{
    char    *text;
    int lenght;
    int index;
    struct s_map next;
        
} t_data;

#endif
