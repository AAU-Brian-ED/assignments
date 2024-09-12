#include <stdio.h>
#include <math.h>

int main(){
  double s;
  printf("Input amount of seconds to translate to weeks, days, hours, minutes, and seconds:\n");
  scanf("%lf", &s);

  //      text output      type            conversion     max number
  printf("%ld weeks\n"  , (long  ) fmod(s/(1*60*60*24*7), INFINITY));
  printf("%d days\n"    , (int   ) fmod(s/(1*60*60*24  ), 7       ));
  printf("%d hours\n"   , (int   ) fmod(s/(1*60*60     ), 24      ));
  printf("%d minutes\n" , (int   ) fmod(s/(1*60        ), 60      ));
  printf("%lf seconds\n", (double) fmod(s/(1           ), 60      ));

  return 0;
}

