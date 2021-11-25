/*Program to implement
Cohen-Sutherland
Line-clipping algorithm*/

# include <bits/stdc++.h>
# include <conio.h>
# include <math.h>
# include <graphics.h>
using namespace std;

void window(){
     line(200, 200, 350, 200);
     line(350, 200, 350, 350);
     line(200, 200, 200, 350);
     line(200, 350, 350, 350);
}
void step(char c[4], float x, float y){
     if(x<200)
          c[0] = '1';
     else
          c[0] = '0';
     if(x>350)
          c[1] = '1';
     else
          c[1] = '0';
     if(y<200)
          c[2] = '1';
     else
          c[2] = '0';
     if(y>350)
          c[3] = '1';
     else
          c[3] = '0';
}
void clip(char c[], char d[], float* px, float* py, float m){
     float x = *px, y = *py;
     bool flag = true;
     for(int i=0; i<4; i++){
          if(c[i] != '0' && d[i] != '0'){
               flag = false;
               break;
          }
          if(flag){
               if(c[0] != '0'){
                    y = m*(200-x)+y;
                    x=200;
               }
               else if(c[1] != '0'){
                    y = m*(350-x) + y;
                    x = 350;
               }
               else if(c[2] != '0'){
                    x = ((200-y)/m)+x;
                    y = 200;
               }
               else if(c[3] != '0'){
                    x = ((350-y)/m)+x;
                    y=350;
               }
          }
          if(!flag)
               cout<<"Line lying outside."<<endl;
     }
     *px = x, *py = y;
}
int main(){
     float x1, y1, x2, y2;
     float m;
     char c1[4], c2[4];
     cout<<"Enter initial co-ordinates of line: ";
     cin>>x1>>x2;
     cout<<"Enter final co-ordinates of line: ";
     cin>>x2>>y2;
     int gd = DETECT, gm;
     initgraph(&gd, &gm, "");
     cout<<"Before clipping:"<<endl;
     window();
     line(x1,y1,x2,y2);
     _getch();
     cleardevice();
     m = float((y2-y1)/(x2-x1));
     step(c1, x1, y1);
     step(c2, x2, y2);
     clip(c1,c2,&x1,&y1,m);
     clip(c2,c1,&x2,&y2,m);
     window();
     cout<<"After clipping:"<<endl;
     line(x1,y1,x2,y2);
     _getch();
     closegraph();
     return 0;
}
