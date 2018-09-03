/*====================================================*\
  Vendredi 8 novembre 2013
  Arash HABIBI
  Image.h
\*====================================================*/

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>

#include "Ppm.h"
#include "Complex.h"
#include "Mandelbrot.h"

//-----------------------------------------------------

typedef struct
{
	unsigned char _red, _green, _blue;
} Color;

Color C_new(unsigned char red, unsigned char green, unsigned char blue);
void C_check(Color c, char *message);
Color C_blend(Color c1, Color c2, double blend_coef);
double C_intensity(Color c);

//-----------------------------------------------------

typedef struct
{
	int _width, _height;
	int _xzoom, _yzoom;
	int _xoffset, _yoffset;
	double _zoom;
	Color _current_color;
	Color **_buffer;
	double _min, _max;
} Image;

Image* I_new(int _width, int _height);
Image* I_read(char *ppmfilename);

void I_check(Image *img, char *message);

void I_fill       (Image *img, Color c);
void I_checker    (Image *img, Color c1, Color c2, int step);

void I_changeColor(Image *img, Color c);
void I_plot       (Image *img, int x, int y);
void I_plotColor  (Image *img, int x, int y, Color c);

void I_focusPoint (Image *img, int x, int y);
void I_zoomInit   (Image *img);
void I_zoom       (Image *img, double zoom_coef);
void I_move       (Image *img, int x, int y);

void I_mandelbrot (Image *img, Mandelbrot *mb);
void I_colorize   (Image *img, Color max_color, Color min_color);
void I_draw       (Image *img);

#endif
