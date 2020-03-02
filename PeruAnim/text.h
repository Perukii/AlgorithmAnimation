
struct text:public object{

     camera * cm;
     string text,fdtext;
     pRGB fdbfcolor;
     bool fading=false, bold=false;

     void set_camera(camera * _cm){ cm=_cm; }
     
     void init_text(string _text, double _x=0, double _y=0, double _w=0, pRGB _color=pRGB(0,0,0,0)){

          x=_x;     tx=_x;
          y=_y;     ty=_y;
          w=_w;     tw=_w;

          text=_text;
          color=_color;tcolor=_color;
     }

     void text_fade(string _fdtext){
          fading = true;
          fdtext = _fdtext;
          fdbfcolor = color;
          tcolor = color; 
          tcolor.A(0);
     }

     void process_fade(){
          if(color.a<0.01){
               fading=false;
               text = fdtext;
               tcolor = fdbfcolor;
          }
     }
     

     void draw_text(cairo_t * _cr){

          peruSetColor(_cr,color);
          adjrect drect = cm->make_object(*this);

          peruSetColor(_cr,color);

          cairo_select_font_face(_cr, "/home/tlllune/Projects/GTK/AlgAnim/quick/Aldrich-Regular.ttf",
               CAIRO_FONT_SLANT_NORMAL,
               bold ? CAIRO_FONT_WEIGHT_BOLD:CAIRO_FONT_WEIGHT_NORMAL);

          cairo_text_extents_t extents;
          cairo_text_extents (_cr, text.c_str(), &extents);

          cairo_set_font_size(_cr, drect.w);
          cairo_move_to(_cr, drect.x-(double)extents.width*3.0*cm->w, drect.y+(double)extents.height*2.0*cm->w);
          cairo_show_text(_cr, text.c_str());
     }


};




