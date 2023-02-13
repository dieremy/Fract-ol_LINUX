/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:33:38 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/12 13:33:42 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	put_pixel_image(int x, int y, t_fractal *env, int color)
{
	int pos;

	pos = (y * HW) + x;
	env->addr[pos] = color;
}

void    mand_plane(t_fractal *mBrot)
{
    mBrot->max_i = 1000;
    mBrot->i = 0;
    mBrot->cx = (mBrot->x - HW / 2.0) * 4.0 / HW;
    mBrot->cy = (mBrot->y - HW / 2.0) * 4.0 / HW;
    mBrot->zx = 0;
    mBrot->zy = 0;
}

void mandelbrot(t_fractal mBrot)
{
    double      xtemp;

    mBrot.x = 0;
    while (mBrot.x < HW)
    {
        mBrot.y = 0;
        while (mBrot.y < HW)
        {
            mand_plane(&mBrot);
            while (mBrot.zx * mBrot.zx + mBrot.zy * mBrot.zy < 4 && mBrot.i < mBrot.max_i)
            {
                xtemp = mBrot.zx * mBrot.zx - mBrot.zy * mBrot.zy + mBrot.cx;
                mBrot.zy = 2 * mBrot.zx * mBrot.zy + mBrot.cy;
                mBrot.zx = xtemp;
                mBrot.i++;
            }
            mBrot.y++;
            put_pixel_image(mBrot.x, mBrot.y, &mBrot, mBrot.i * VIOLET);
        }
        mBrot.x++;
    }
}

void    julia_plane(t_fractal *julia)
{
    // julia->zx = (x - width / 2.0) * 4.0 / width;
    // julia->zy = (y - height / 2.0) * 4.0 / width;
    // double zoom_x;
    // double zoom_y;
    double x1 = -1;
    double x2 = 1;
    double y1 = -1.2;
    double y2 = 1.2;

    // zoom_x = HW / (x2 - x1);
    // zoom_y = HW / (y2 - y1);
    julia->max_i = 1000;
    julia->i = 0;
    julia->zx = julia->x / (HW / (x2 - x1)) + x1;
    julia->zy = julia->y / (HW / (y2 - y1)) + y1;
    julia->cx = -0.74543;
    julia->cy = 0.11301; 
}

void julia(t_fractal julia)
{
    double      xtemp;

    julia.x = 0;
    while (julia.x < HW)
    {
        julia.y = 0;
        while (julia.y < HW)
        {
            julia_plane(&julia);
            while (julia.zx * julia.zx + julia.zy * julia.zy < 4 && julia.i < julia.max_i)
            {
                xtemp = julia.zx;
                julia.zx = julia.zx * julia.zx - julia.zy * julia.zy + julia.cx;
                julia.zy = 2 * xtemp * julia.zy + julia.cy;
                julia.i++;
            }
            julia.y++;
            put_pixel_image(julia.x, julia.y, &julia, julia.i * VIOLET);
        }
        julia.x++;
    }
}
