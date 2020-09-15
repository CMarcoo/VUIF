#include "vuif.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define HEIGHT 1080
#define WIDTH 1080

int main(int argc, char* argv[]) {
    printf("Starting:\n");
    srand(time(NULL));

    image *img;
    img->width = WIDTH;
    img->height = HEIGHT;
    pixel pixels[HEIGHT * WIDTH];
    size_t count = 0;
    for (size_t w = 0; w < WIDTH; w++) {
        for (size_t h = 0; h < HEIGHT; h++) {
            color rand_color = {.r = rand()%256, .g = rand()%256, .b = rand()%256 };
            pixel pxl = {.x = w, .y = h, .pixel_color = rand_color};
            pixels[count] = pxl;
            count++;
        }
    }

    printf("Starting to write data...\n");
    write_to_file("random-img.vuif", img);
    printf("Data written correctly.\n");    

    return EXIT_SUCCESS;
}