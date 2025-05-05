#include "c_img.h"
#include <stdio.h>
#include <math.h>

void adjust_brightness(struct rgb_img *im, struct rgb_img **new_im, float adjust){
    create_img(new_im, im->height, im->width);
    for(int y = 0; y < im->height; y++){
        for(int x = 0; x < im->width; x++){
            int r = get_pixel(im, y, x, 0) * adjust;
            int g = get_pixel(im, y, x, 1) * adjust;
            int b = get_pixel(im, y, x, 2) * adjust;
            
            if(r>255){
                r=255;
            }
            if (g>255){
                g=255;
            }
            if (b>255){
                b=255;
            }
            set_pixel(*new_im, y, x, r, g, b);
        }
    }
}
int main(){
    struct rgb_img *im;
    read_in_img(&im, "image.bin");
    struct rgb_img *new_im;
    float adj = 10;
    char filename[20];
    adjust_brightness(im, &new_im, adj);
    sprintf(filename, "bright4.bin");
    write_img(new_im, filename);
    destroy_image(new_im);
    destroy_image(im);
}