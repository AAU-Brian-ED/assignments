#include <stdio.h>

int main(){
  int n, cifre;
  scanf("%u", &n);
  scanf("%u", &cifre);

  int found = 0;
  for (int i=n; i>=0; i--){
    for (int t=i; t!=0; t/=10) {
      if (t%10 == cifre) {
        found++;
        break;
      }
    }
  }

  printf("%u\n", found);

  return 0;
}

