/*
** my_getnbr.c for mysh2 in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_minishell2
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed Apr  6 15:11:56 2016 Lucas Villeneuve
** Last update Mon May 16 13:57:30 2016 Lucas Villeneuve
*/

int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  if (!(str) || str[i] == 0)
    return (-1);
  while (str[i])
    {
      nb *= 10;
      nb += (str[i] - 48);
      i++;
      if ((str[i] < 48 || str[i] > 57) && str[i] != 0)
      	return (-1);
    }
  return (nb);
}
