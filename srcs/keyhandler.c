/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:47:16 by garibeir          #+#    #+#             */
/*   Updated: 2023/05/26 15:45:33 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"

int key_handler(int key)
{
    
    if (key == ESC_KEY)
        exit(0);
    if (key == UP)
        cmap()->elevation++;
    if (key == RIGHT && cmap()->spacing + 10 < WIDTH / 3)
        cmap()->spacing += 10;
    if (key == DOWN)
        cmap()->elevation -= 10;
    if (key == LEFT && cmap()->spacing - 10 > 0  )
        cmap()->spacing -= 10;
    renderer();
    return (0);
}