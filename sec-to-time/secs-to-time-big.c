// Seconds to weeks, days, hours, minutes, seconds.
// Deadline 17 september 2024 kl 21:00.

// PREREQUISITS:
//   Please turn off inlay hints while veiwing this file. This is to allign code.
//   Please use a monospaced font.
//   I love using allignment to aid readability.


// Exmplanation of how we convert seconds to minutes, hours, etc.
/*
  We get the amount of seconds as input, and want to convert it to minutes.
  For example, lets take 66.

  Math:        || Explanation:
  60s = m      // There are 60 seconds in one minute.
  66s = x m    // We have 66 seconds, and that is equal to some amount of minutes.
  66s = x 60s  // We can replace m with 60s because m = 60s.
  66s/60s = x  // We can divide 60s on both sides of the = sign.
  66/60 = x    // We devide by s on both the bottom and top side of the / symbol.

  The answer is that 66 seconds is 66/60 minutes! :D

  Simply showing minutes and seconds is wrong.
  If we did, the output would be 66 seconds and 1.1 minutes.
  We want to have 6 seconds and 1 minute.
  We remove the seconds by using fmod, because 66%60 is 6.
  We remove the 0.1 in 1.1 minutes by rounding down, which means flooring.
  Easiest way to floor in C is by converting to intiger, by doing (int)1.1, which gives 1.

  Now we have 1 minute and 6 seconds. Same logic applies to hours, days, weeks, etc.
*/


// ┌──────────────────────────────────┐ //
// │ Macro definitions are under here │ //
// └──────────────────────────────────┘ //

#include <stdio.h>
#include <math.h>

#define SECONDS_IN_MINUTE 60.0
#define MINUTES_IN_HOUR   60.0
#define HOURS_IN_DAY      24.0
#define DAYS_IN_WEEK      7.0
#define WEEKS_IN_UNIVERSE INFINITY

#define SECONDS_TO_SECONDS 1.0
#define MINUTES_TO_SECONDS (SECONDS_IN_MINUTE * SECONDS_TO_SECONDS)
#define HOURS_TO_SECONDS   (MINUTES_IN_HOUR   * MINUTES_TO_SECONDS)
#define DAYS_TO_SECONDS    (HOURS_IN_DAY      * HOURS_TO_SECONDS  )
#define WEEKS_TO_SECONDS   (DAYS_IN_WEEK      * DAYS_TO_SECONDS   )


// ┌──────────────────────┐ //
// │ Types are under here │ //
// └──────────────────────┘ //

typedef double Seconds;

typedef struct {
  long unsigned int weeks;
  unsigned char days, hours, minutes;
  double seconds;
} Time;


// ┌──────────────────────────┐ //
// │ Functions are under here │ //
// └──────────────────────────┘ //

// Asks the user to give a valid amount of seconds as input
Seconds AskForSeconds() {
  double x;
  if (1 != scanf("%lf", &x)) {
    x = -1;
  }
  return x;
}

// Converts seconds to the Time type
Time SecondsToTime(Seconds s) {
  Time result = {
  //       ┌─Conversion factor to convert seconds to the time
  //       │
  //       │                   ┌─Using fmod, limit the size of the output.
  //       │                   ├─They need to fit in their respective timeframe.
  //       │                   ├─I.e 7 days would be 0 weeks, not 7 weeks.
    fmod(s/WEEKS_TO_SECONDS  , WEEKS_IN_UNIVERSE), // Weeks
    fmod(s/DAYS_TO_SECONDS   , DAYS_IN_WEEK     ), // Days
    fmod(s/HOURS_TO_SECONDS  , HOURS_IN_DAY     ), // Hours
    fmod(s/MINUTES_TO_SECONDS, MINUTES_IN_HOUR  ), // Minutes
    fmod(s/SECONDS_TO_SECONDS, SECONDS_IN_MINUTE), // Seconds
  };
  return result;
}

// Prints the Time type
void PrintTime(Time t) {
  printf("%lu weeks.\n"  , t.weeks  );
  printf("%d days.\n"    , t.days   );
  printf("%d hours.\n"   , t.hours  );
  printf("%d minutes.\n" , t.minutes);
  printf("%lf seconds.\n", t.seconds);
}


// ┌──────────────────────────┐ //
// │ Main program starts here │ //
// └──────────────────────────┘ //

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
    if (s == -1) {
      printf("ERROR: Invalid number\n");
      return -1;
    }
  }

  // Prints the time after converting seconds to time.
  PrintTime(SecondsToTime(s));

  // End the program successfully
  return 0;
}
