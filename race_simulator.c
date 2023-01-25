#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Structures section
struct Race{
  // uninitialized member variables
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};

struct RaceCar{
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};
// Print functions section
void printIntro(){
  printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n\n");
}
void printCountDown(){
  printf("Racer Ready! In...\n");
  for (int i = 5; i > 0; i--){
    printf("%d\n", i);
  }
  printf("Race!\n\n");
}
void printCongratulation(struct Race race){
  printf("Let's all congrulate %s in the %s race car for an amazing performace. It truly was a great race and everybody have a goodnight!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printFirstPlaceAfterLap(struct Race race){
printf("After lap number %d\n First Place Is: %s in the %s race car!\n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

// Logic functions section
int calculateTimeToCompleteLap(){
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar){
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}
 
void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2){

    if (raceCar1->totalLapTime <= raceCar2->totalLapTime)
    {
      //assign raceCar1 mem var color name to firstPlaceDrivername/RaceCarColor
      race->firstPlaceDriverName = raceCar1->driverName;
      race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
    }
    else
    {
       //assign raceCar2 mem var color name to firstPlaceDrivername/RaceCarColor
      race->firstPlaceDriverName = raceCar2->driverName;
      race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
    }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2){
  struct Race race = {5,1,"",""};
  for (int i = 0; i <= race.numberOfLaps;i++){
    updateRaceCar(raceCar1); 
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.currentLap++;
  }
  printCongratulation(race);
}

int main() {

  struct RaceCar Car1 = {"Alanso", "blue", 0};
  struct RaceCar Car2 = {"Lewis", "black", 0};
	srand(time(0));
  printIntro();
  printCountDown();
  startRace(&Car1, &Car2);

};