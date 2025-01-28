#include <iostream>
#include <vector>
using namespace std;

using Pixel_value = unsigned short;  
using Image = vector<vector<Pixel_value>>;

Image make_image(size_t width, size_t height, unsigned short val = 0) {
    return Image(height, vector<Pixel_value>(width, val));
}

struct Pt {
    int x;
    int y;
    Pt(int init_x, int init_y) : x(init_x), y(init_y) {}
};

using Kernel = vector<Pt>;

Image dilate(Image & input_img, const Kernel & kernel, Pixel_value val) {
    Image img = input_img;
    for(size_t width = 0; width < img.at(0).size(); ++width) {
        for(size_t height = 0; height < img.size(); ++height) {
            Pixel_value max_val = 0;
            for(size_t i = 0; i < kernel.size(); ++i) {
                Pt px(width + kernel.at(i).x, height + kernel.at(i).y);
                Pixel_value evaluated_value = img.at(px.y).at(px.x);
                max_val = max(max_val, evaluated_value);
            }
            img.at(height).at(width) = max_val;
        }
    }
    return img;
}

int main() {
   Pixel_value black = 0;
   Image image = make_image(1920,1080,black);

   for(size_t i = 0; i < 20; ++i)
      image[200 + i][300 - i] = 65535; // dessine une ligne oblique blanche
      
   Kernel kernel { Pt{0,0}, Pt{-1,0}, Pt{1,0}, Pt{0,1}, Pt{0,-1}};
   Image dilated = dilate(image, kernel, black);
}