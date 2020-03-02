
#define peruSetColor(CR,PRGB) cairo_set_source_rgba(CR, PRGB.r, PRGB.g, PRGB.b, PRGB.a)

void peruDrawImage(cairo_t * cr, const char * file){
    cairo_surface_t * image;

    image = cairo_image_surface_create_from_png(file);
    cairo_set_source_surface(cr, image, 10, 10);
    cairo_paint(cr);
}

class pRGB{
public:
    double r,g,b,a;
    pRGB(double _r = 0, double _g = 0, double _b = 0, double _a = 0):r(_r), g(_g), b(_b), a(_a){};
    void A(double _a){ a=_a; }
};
