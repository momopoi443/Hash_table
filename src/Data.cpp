
#include "../include/Data.h"

#include <cstdlib>
#include <ctime>


Data::Data() {

    srand(time(nullptr));

    this->songName = (char) (rand() % 123 + 97);
    this->amOfLikes = rand();
    this->durationSec = rand() % MAX_DURATION;
};
