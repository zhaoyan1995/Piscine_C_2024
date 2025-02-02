/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:57:05 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/04 21:57:06 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

int		ft_find_num(char c);
int		ft_check_nbr(char *str);
int		ft_strlen(char *str);
int		measure_size(int file);
int		ft_count_nb_brkline(char *buffer, int byte_read);
void	ft_stdin(void);
void	ft_option(int argc, char **argv);
void	ft_put_errormsg(char *filename);
void	ft_check_argv(int i, int argc, char **argv, int byte_num);
void	ft_put_title(int argc, char **argv, int file_num, char *str);
void	ft_put_str(int file, int memory_size);
void	ft_put_str2(int file, int byte_num, int memory_size);

#endif
