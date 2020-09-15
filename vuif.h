#include <stdlib.h>
#include <stdio.h>

#define INVALID_IMG -2
#define INVALID_FILE -3

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} color;

typedef struct {
    unsigned short x;
    unsigned short y;
    color pixel_color;
} pixel;

typedef struct {
    unsigned short width;
    unsigned short height;
    pixel *image_pixels;
} image;

void add_image_info(FILE *fptr, image *img) {
    fputc(img->width, fptr);
    fputc(img->height, fptr);
    fputc(0x0A, fptr);
}

void write_to_file(char *filename, image *img) {
    if (img == NULL) {
        exit(INVALID_IMG);
    }

    FILE *fptr;

    fptr = fopen(filename, "w");

    if (fptr == NULL) {
        exit(INVALID_FILE);
    }

    add_image_info(fptr, img);

    for (size_t i = 0; i < ((img->height) * (img->width)); i++) {
        fputc(img->image_pixels[i].x , fptr);
        fputc(img->image_pixels[i].y , fptr);
        fputc(img->image_pixels[i].pixel_color.r, fptr);
        fputc(img->image_pixels[i].pixel_color.g, fptr);
        fputc(img->image_pixels[i].pixel_color.b, fptr);
    }

    fclose(fptr);
}