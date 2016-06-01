/*
** my_ctrl_c.c for 42sh in /home/costa_d/Documents/PSU/42sh/PSU_2015_42sh/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu May 26 18:12:03 2016 Arnaud Costa
** Last update Wed Jun  1 13:51:53 2016 Lucas Villeneuve
*/

#include <signal.h>
#include "42sh.h"

void	sig_finder(int sig)
{
  if (sig == SIGINT)
    {
      my_putstr("\b\b  \n");
      my_putstr("-->");
    }
}
