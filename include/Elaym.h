/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elaym.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:48 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/11 05:51:09 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELAYM
#define ELAYM

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include "../mlx_linux/mlx.h"
#include <time.h>
#include <stdbool.h>

typedef struct Wind_s
{
	void	*ml;
	void	*win;
}Wind_t;

typedef struct  Block_s
{
	int		Xmin;
	int		Xmax;
	int		Ymin;
	int		Ymax;
	void	*img;
	void	*imgP;
	struct	Block_s *next;
}Block_t;

typedef	struct	Back_s
{
	void	*img;
	void	*imgP;
	struct 	Back_t *next;
}Back_t;

typedef struct	Map_s
{
	int		id;
	char	**map;
	int		X;
	int		Y;
	struct	Map_s *next;
}Map_t;

typedef	struct	Transparency_s
{
	int		y;
	int		x;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}Transparency_t;

typedef struct	Stat_s
{
	int		hp;
	double	damage;
	int		speed;
	//Inventaire
	//ressources
}Stat_t;

typedef struct  Player_s
{
	int		x;
	int		y;
	int		XminH;
	int		XmaxH;
	int		YmaxH;
	int		YminH;
	int		Up;
	int		Move;
	int		Up_Val;
	int		Zframe;
	int		Yframe;
	int		Xframe;
	void	***imgR;
	void	***imgL;
	Stat_t	*stat;
	struct	Player_s *next;
	struct	Player_s *prev;
}Player_t;

typedef struct  Enemis_s
{
	int		Xmin;
	int		Xmax;
	int		Ymax;
	int		Ymin;
	int		speed;
	int		Zframe;
	int		Yframe;
	int		Xframe;
	void	***imgR;
	void	***imgL;
	struct	Enemis_s *next;
}Enemis_t;

typedef	struct	Coin_s
{
	int		Xmin;
	int		Ymin;
	int		Xmax;
	int		Ymax;
	int		Frame;
	void	**img;
	struct	Coin_s *next;
}Coin_t;

typedef struct	Spell_s
{
	int		Xmin;
	int		Xmax;
	int		Ymin;
	int		Ymax;
	int		Speed;
	void	**img;
}Spell_t;

typedef	struct	Menu_s
{
	void	**background;
	int		FrameBack;
	void	***button;
	int		*FrameButton;
	double	time;
	int		xmouse;
	int		ymouse;
	int 	statement;
}Menu_t;

typedef	struct	Font_s
{
	void	**ImgFont;
	void	**ImgFontN;
}Font_t;

typedef struct  Control_s
{
	int			Statement;
	char		*login;
	char		**save;
	Wind_t		*WS;
	Map_t		*MS;
	Block_t		**BlS;
	Player_t	*PS;
	Enemis_t	**ES;
	Back_t		*BaS;
	Menu_t		*MeS;
	Font_t		*FS;
	Coin_t		*CS;
}Control_t;

#endif