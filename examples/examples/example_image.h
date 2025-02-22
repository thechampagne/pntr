#include "../../pntr.h"

pntr_image* image;
pntr_image* resized;

void example_image_init() {
    // Load an image
    image = pntr_load_image("resources/logo-128x128.png");
    if (image == NULL) {
        return;
    }

    // Resize the image
    pntr_image* newImage = pntr_image_resize(image, image->width / 2, image->height / 2, PNTR_FILTER_NEARESTNEIGHBOR);
    resized = pntr_image_rotate(newImage, 0.75f);
    pntr_unload_image(newImage);
}

const char* example_image_update(pntr_image* canvas) {
    if (image == NULL) {
        return "Failed to load resources/logo-128x128.png";
    }

    // Draw an image on the canvas
    pntr_draw_image(canvas, image, 50, 50);

    // Draw a section of an image
    pntr_rectangle rect;
    rect.x = 25;
    rect.y = 16;
    rect.width = 65;
    rect.height = 58;
    pntr_draw_image_rec(canvas, image, rect, 200, 50);

    // Get a pixel color from an image
    pntr_color faceColor = pntr_image_get_color(canvas, 150, 80);
    pntr_draw_rectangle(canvas, 290, 50, 65, 58, faceColor);

    // Draw the resized image
    pntr_draw_image(canvas, resized, 200, 130);

    return "Image";
}

void example_image_unload() {
    pntr_unload_image(image);
    pntr_unload_image(resized);
}
