
struct rect:public object{

     camera * cm;

     void set_camera(camera * _cm){ cm=_cm; }

     void init_rect(double _x=0, double _y=0, double _w=0, double _h=0, pRGB _color=pRGB(0,0,0,0)){

          x=_x;     tx=_x;
          y=_y;     ty=_y;
          w=_w;     tw=_w;
          h=_h;     th=_h;

          color=_color;tcolor=_color;
     }


     void draw_rect(cairo_t * _cr){
          
          peruSetColor(_cr,color);
          adjrect drect = cm->make_object(*this);
          cairo_rectangle(_cr, drect.x-drect.w/2, drect.y-drect.h/2, drect.w, drect.h);
          cairo_fill(_cr);

     }


};
