#ifndef BLAH
#define BLAH

typedef struct {
	int red, green, blue;
} Color;

void C_print (Color c);
void C_fprint (FILE *f, Color c);
Color C_new (int red, int green, int blue);
int clamp (int n);
Color C_multiply (Color c, float coef);
Color C_negative (Color c);
Color C_permute (Color c);
int C_intensity (Color c);
Color C_grayScale (Color c);
Color C_grayScaleCoef (Color c);
int C_thershold (Color c, int th);
Color C_th (Color c, int th);
int C_areEqual (Color c1, Color c2);
Color C_replace (Color c);
Color C_addCoef (Color c1, Color c2, float coef);
Color C_gradient (Color c1, Color c2);

#endif
