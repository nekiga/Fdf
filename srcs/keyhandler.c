/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:16 by garibeir          #+#    #+#             */
/*   Updated: 2023/04/01 16:47:17 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"

int key_handler(int key)
{
    // i need to reconstruct the map if i want the changes to be happening in real time
    if (key == ESC_KEY)
        exit(0);
    if (key == UP)
        cmap()->elevation++;
    if (key == RIGHT)
        cmap()->spacing++;
    if (key == DOWN)
        cmap()->elevation--;
    if (key == DOWN)
        cmap()->elevation--;
    
    
    return (0);
}