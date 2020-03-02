

struct camera:public object{

     const double cursor=0.1,zoom=1.1;

     void init_camera(double _x=0, double _y=0, double _w=1){

          x=_x;     tx=_x;
          y=_y;     ty=_y;
          w=_w;     tw=_w;

     }

     adjrect make_object(object & _obj){
          adjrect res;
          res.x = (_obj.x-x)*window_w*w+window_w*0.5;
          res.y = (_obj.y-y)*window_w*w+window_h*0.5;
          res.w = _obj.w    *window_w*w;
          res.h = _obj.h    *window_w*w;
          return res;
     }

     void get_input(int _input){
          switch (_input){
               case 119: // w
                    ty+=cursor;break;
               case 115: // s
                    ty-=cursor;break;
               case 97 : // a
                    tx+=cursor;break;
               case 100: // d
                    tx-=cursor;break;
               case 113: // q
                    tw*=zoom;break;
               case 101: // e
                    tw*=1.0/zoom;break;

               default:     break;
          }
     }

     void process(double _speed=0.05){
          process_x(_speed);
          process_y(_speed);
          process_w(_speed);
     }

};