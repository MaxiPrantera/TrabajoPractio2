#include "bitmap_image.hpp"

int main(){

   const int width  = 600;
   const int height = 400;
   cartesian_canvas agua(width,height);


      {
       const rgb_t* colormap[9] = {
                                    autumn_colormap,
                                    copper_colormap,
                                      gray_colormap,
                                       hot_colormap,
                                       hsv_colormap,
                                       jet_colormap,
                                     prism_colormap,
                                       vga_colormap,
                                      yarg_colormap
                                  };
      const double x = 0.7;
      const double y = 0.7;
      const double c1 = 0.3;
      const double c2 = 0.3;
      const double c3 = 0.2;
      const double c4 = 0.2;

      ::srand(0xB6BB6BB6);

      plasma(agua.image(), x, y, width, height, c1, c2, c3, c4, 0.9, copper_colormap);
   }

    agua.image().save_image("suelo.bmp");

    return 0;
}
