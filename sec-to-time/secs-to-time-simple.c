// seconds to weeks, days, hours, minutes, seconds
// deadline 17 september 2024 kl 21:00

#include <stdio.h>
#include <math.h>

int main(){
  double s;
  printf("When inputing seconds, give 1 number and press enter. For example:\n");
  printf("-----\n");
  printf("21312\n");
  printf("-----\n");
  printf("Input amount of seconds to translate to weeks, days, hours, minutes, and seconds:\n");
  scanf("%lf", &s);

  printf("%ld %d %d %d %lf\n",
    (long)(s/(7*24*60*60)),
  printf("%ld %d %d %d %lf\n",
    (int)fmod(s/(7*24*60*60),7),
  printf("%ld %d %d %d %lf\n",
    (int)fmod(s/(60*60),24),
  printf("%d\n",(int)fmod(s/60,60))
  printf("%lf\n",fmod(s,60));

  return 0;
}

