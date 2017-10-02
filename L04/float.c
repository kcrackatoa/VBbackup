#include <stdio.h>
#include <math.h>

/* define new variable type */
typedef struct {
  float x;
  float y;
  float z;
} point;

point pointCreate(float x, float y, float z){
  point p;
  p.x = x;
  p.y = y;
  p.z = z;
  return p;
}

void pointPrint(point p){
  printf("point: %f,%f,%f\n", p.x,p.y,p.z);
}

void pointZero(point* pt_p){
  //option 1:
  (pt_p).x = 0;
  (pt_p).y = 0;
  (pt_p).z = 0;

  //option 2:
  pt_p->x = 0;
  pt_p->y = 0;
  pt_p->z = 0;

  //option 3:
  pt_p[0].x = 0;
  pt_p[0].y = 0;
  pt_p[0].z = 0;

}

float pointDistanceFromOrigin(point p){
  float d = sqrt(p.x*p.x + p.y*p.y + p.z*p.z);

  return d;
}

int main(){
  point p = pointCreate(1.2, 2.3, 3.1);

  float d = pointDistanceFromOrigin(p);
  
  printf("d = %f\n", d);
  
  pointPrint(p);

  pointZero(p);

  pointPrint(p);

  
  return 0;
}
