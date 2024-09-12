
#ifndef printf
  #include <stdio.h>
#endif

#ifndef sqrt
  #include <math.h>
#endif

typedef struct Vector2 {
  double x, y;
} Vector2;

double Vector2Length(Vector2 v){
  return sqrt(v.x*v.x + v.y*v.y);
}

Vector2 Vector2Minus(Vector2 v1, Vector2 v2) {
  Vector2 result = {v1.x-v2.x, v1.y-v2.y};
  return result;
}

Vector2 AskForVector2() {
  int i=0;
  double x,y;
  while (i != 2) {
    x=0; y=0;
    i = scanf("%lf %lf", &x, &y);
  }
  Vector2 result = {x, y};
  return result;
}

int main(int argc, char *argv[]){

  // Defaults, for easier testing
  Vector2 p1 = {0, 0};
  Vector2 p2 = {1, 4};
  Vector2 p3 = {4, 4};

  if (argc==1) {
    printf("When inputing points, give 2 numbers and press enter. example:\n-------\n0.2 3.5\n-------\n");
    printf("First point:\n");
    p1 = AskForVector2();
    printf("Second point:\n");
    p2 = AskForVector2();
    printf("Third point:\n");
    p3 = AskForVector2();
  }

  double len1 = Vector2Length(Vector2Minus(p1,p2));
  double len2 = Vector2Length(Vector2Minus(p1,p3));
  double len3 = Vector2Length(Vector2Minus(p2,p3));
  printf("Lengths: %lf %lf %lf\n", len1, len2, len3);
  return 0;
}
