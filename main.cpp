#include <iostream>
#include <iterator>
#include <iomanip>
#include "Movie.h"
#include "MovieDatabase.h"
int main() {
    //Populating the database
    MovieDatabase* db = new MovieDatabase();
    std::cin >> *db;

    //Task 1
    std::cout << "Task 1: Films in chronological order." << std::endl;
    db->sortDB(YEAR, ASC);
    std::cout << *db << "\n\n";

    //Task 2
    std::cout << "Task 2: The third longest Film-Noir film." << std::endl;
    MovieDatabase* filmNoirDB = db->subDB(GENRE, "Film-Noir");
    filmNoirDB->sortDB(DURATION, DESC);
    std::cout << *filmNoirDB->get(2) << "\n\n";

    //Task 3
    std::cout << "Task 3: The eighth most recent UNRATED film." << std::endl;
    MovieDatabase* unratedDB = db->subDB(CERTIFICATE, "UNRATED");
    unratedDB->sortDB(YEAR, DESC);
    std::cout << *unratedDB->get(7) << "\n\n";

    //Task 4
    std::cout << "Task 4: The Movie with the longest title." << std::endl;
    db->sortDB(NAMELENGTH, DESC);
    std::cout << *db->get(0) << "\n\n";
    return 0;
}