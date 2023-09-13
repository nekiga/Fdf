/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:34 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/13 14:28:41 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYHANDLER_H
# define KEYHANDLER_H

# define ESC_KEY	65307
# define KEY_SPACE 32
# define EVENT_CLOSE_BTN 17
# define MOUSE_BTN 1
# define MOUSE_BTN2 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_I 105
# define KEY_O 111
# define KEY_PLUS 43
# define KEY_MINUS 45
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define ONE 49
# define TWO 50
# define NINE 57
# define EIGHT 56
# define SEVEN 55

int	key_handler(int key);
int	key_handler_sub(int key);

#endif