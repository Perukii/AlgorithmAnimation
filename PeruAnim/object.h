
struct object{

     double  x, y, w, h;
     double tx,ty,tw,th;

     pRGB color,tcolor;
     int wait;

     bool process_x(double _speed=0.05){
          if(wait){ wait--;return false; }
          x+=(tx-x)*_speed;
          return abs(tx-x)<0.001;
     }

     bool process_y(double _speed=0.05){
          if(wait){ wait--;return false; }
          y+=(ty-y)*_speed;
          return abs(ty-y)<0.001;
     }

     bool process_w(double _speed=0.05){
          if(wait){ wait--;return false; }
          w+=(tw-w)*_speed;
          return abs(tw-w)<0.001;
     }

     bool process_h(double _speed=0.05){
          if(wait){ wait--;return false; }
          h+=(th-h)*_speed;
          return abs(th-h)<0.001;
     }

     void process_color(double _speed=0.05){
          if(wait){ wait--;return; }
          color.r+=(tcolor.r-color.r)*_speed;
          color.g+=(tcolor.g-color.g)*_speed;
          color.b+=(tcolor.b-color.b)*_speed;
          color.a+=(tcolor.a-color.a)*_speed;
     }

};

struct adjrect{
     double  x, y, w, h;
};




