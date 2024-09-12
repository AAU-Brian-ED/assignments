// Seconds to weeks, days, hours, minutes, seconds.
// Deadline 17 september 2024 kl 21:00.

#include <stdio.h>
#include <math.h>

#define DAYS_IN_WEEK      7
#define HOURS_IN_DAY      24
#define MINUTES_IN_HOUR   60
#define SECONDS_IN_MINUTE 60

#define WEEKS_TO_SECONDS   (DAYS_IN_WEEK    * DAYS_TO_SECONDS   )
#define DAYS_TO_SECONDS    (HOURS_IN_DAY    * HOURS_TO_SECONDS  )
#define HOURS_TO_SECONDS   (MINUTES_IN_HOUR * MINUTES_TO_SECONDS)
#define MINUTES_TO_SECONDS SECONDS_IN_MINUTE

typedef double Seconds;

typedef struct {
  long int weeks;
  unsigned char days, hours, minutes;
  double seconds;
} Time;

// Asks the user to give a valid amount of seconds as input
Seconds AskForSeconds() {
  double x;
  if (1 != scanf("%lf", &x)) {
    printf("Invalid number, defaulting to 0");
  }
  return x;
}

// Converts seconds to the Time type
Time SecondsToTime(Seconds s) {
  Time result = {
         s/WEEKS_TO_SECONDS                      ,
    fmod(s/DAYS_TO_SECONDS   , DAYS_IN_WEEK     ),
    fmod(s/HOURS_TO_SECONDS  , HOURS_IN_DAY     ),
    fmod(s/MINUTES_TO_SECONDS, MINUTES_IN_HOUR  ),
    fmod(s                   , SECONDS_IN_MINUTE),
  };
  return result;
}

// Prints the Time type
void PrintTime(Time t) {
  printf("%ld weeks.\n"  , t.weeks  );
  printf("%d days.\n"    , t.days   );
  printf("%d hours.\n"   , t.hours  );
  printf("%d minutes.\n" , t.minutes);
  printf("%lf seconds.\n", t.seconds);
}

// |--------------------------| //
// | Main program starts here | //
// |--------------------------| //
int main(int argc, char *argv[]){

  // The only variable we need is s, since we only ask for seconds
  Seconds s;

  // If argc==1, then no argument was given, and so we run the normal program.
  // If argc!=1, then argumen was given, and so we run the tests.
  unsigned char isTesting = argc!=1;

  if (isTesting) {
    // Quick test for program.
    // This is a multiline sum that sums the weeks, days, etc to seconds.
    // The output should just be the numbers in this sum, so 260 weeks, 5 days etc.
    s = 260 * WEEKS_TO_SECONDS   + // Weeks
        5   * DAYS_TO_SECONDS    + // Days
        10  * HOURS_TO_SECONDS   + // Hours
        10  * MINUTES_TO_SECONDS + // Minutes
        59.4;                      // Seconds
  } else {
    // Handling input
    printf("When inputing seconds, give 1 number and press enter. For example:\n");
    printf("-----\n");
    printf("21312\n");
    printf("-----\n");
    printf("Input amount of seconds to translate to weeks, days, hours, minutes, and seconds:\n");
    s = AskForSeconds();
  }

  // Prints the time after converting seconds to time.
  PrintTime(SecondsToTime(s));

  // End the program successfully
  return 0;
}

