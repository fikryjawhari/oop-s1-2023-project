#include <iostream>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

int main()
{
    int width, height, channels;   
    unsigned char *img = stbi_load("t0img1.PNG", &width, &height, &channels, 0); 
    // sets width, height and channels to "<file>"s values by loading it (read)

    if (img == nullptr) {
        std::cout << "Error in loading the image\n";
        return 1;
    }

    std::cout << "Loaded image with a width of " << width << "px, a height of " << height << "px, and " << channels << " channels\n";
    stbi_write_png("t0img2.PNG", width, height, channels, img, width * channels);
    // writes a new png "<name>" from img
    stbi_write_jpg("t0img3.jpg", width, height, channels, img, 1);
    // writes a new jpg "<name>" from img
    // int at the end is level of quality (1-100)

    stbi_image_free(img);
    // deletes pointer
}