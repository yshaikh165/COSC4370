/* Sources:
-https://solarianprogrammer.com/2018/11/19/cpp-reading-writing-bmp-images/
-https://www.geeksforgeeks.org/midpoint-ellipse-drawing-algorithm/
-https://www.geeksforgeeks.org/draw-ellipse-c-graphics/?ref=lbp
-https://www.geeksforgeeks.org/basic-graphic-programming-in-c/?ref=lbp
-https://www.cplusplus.com/doc/tutorial/functions/
-https://stackoverflow.com/questions/5886628/effecient-way-to-draw-ellipse-with-opengl-or-d3d
-https://www.codeproject.com/Questions/1239612/Drawing-an-ellipse-using-Cplusplus-with-opengl
*/

#include <iostream>
#include "BMP.h"
#include <cmath>

int main() {
  BMP bmpNew(1500,800,false);  
  bmpNew.fill_region(0, 0, 200, 200, 0, 0, 0, 0);

  double x = 0; 
  double y = 0;
  x = pow(64, 2.0); 
  y = pow(12.0, 2.0);
   
  for(int i=0;i<bmpNew.bmp_info_header.width;i++)
  {
    double z = 0;
    z = pow(i-750,2.0);
    z = z/y;
    z = x-z;
    z = sqrt(z);
    z = 6*z;
    
    bmpNew.set_pixel(i, z, 255, 250, 250, 255); 
  }
  bmpNew.write("output.bmp");
}
