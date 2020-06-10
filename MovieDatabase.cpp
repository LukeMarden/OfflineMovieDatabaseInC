/**
 * File - MovieDatabase.cpp
 * Author - Luke Marden
 * Date - 21/04/2020
 * Description - A class to handle a database of movie objects
 */
#include <iomanip>
#include <functional>
#include "MovieDatabase.h"

/**
 * Constructor
 */
MovieDatabase::MovieDatabase(){}
/**
 * Destructor
 */
MovieDatabase::~MovieDatabase() {
    for(Movie *movie : this->db) {
        delete movie;
    }
}
/**
 * Makes a sub database based on an attribute and a value
 * @param attribute - the attribute to build the sub database on
 * @param value - the value to match
 * @return The sub database
 */
MovieDatabase* MovieDatabase::subDB(Attribute attribute, std::string value) {
    MovieDatabase* subDB = new MovieDatabase();
    switch (attribute) {
        case NAME:
            for (Movie* movie : this->db) {
                if(movie->getName().find(value) != std::string::npos){
                    subDB->addMovie(movie);
                }
            }
            break;
        case YEAR:
            for (Movie* movie : this->db) {
                if (movie->getYear() == stoi(value)){
                    subDB->addMovie(movie);
                }
            }
            break;
        case CERTIFICATE:
            for (Movie* movie : this->db) {
                if (movie->getCertificate() == value) {
                    subDB->addMovie(movie);
                }
            }
            break;
        case GENRE:
            for (Movie* movie : this->db) {
                if(movie->getGenre().find(value) != std::string::npos){
                    subDB->addMovie(movie);
                }
            }
            break;
        case DURATION:
            for (Movie* movie : this->db) {
                if (movie->getDuration() == stoi(value)){
                    subDB->addMovie(movie);
                }
            }
            break;
        case RATING:
            for (Movie* movie : this->db) {
                if (movie->getRating() == stoi(value)){
                    subDB->addMovie(movie);
                }
            }
            break;
        default: //genre
            for (Movie* movie : this->db) {
                if(movie->getGenre().find(value) != std::string::npos){
                    subDB->addMovie(movie);
                }
            }
    }
    return subDB;
}
/**
 * Sorts the database based on a movies attribute and a direction
 * @param attribute - Movie name etc
 * @param direction - Ascending/Descending
 */
void MovieDatabase::sortDB(Attribute attribute, SortDirection direction) {
    switch(direction){
        case ASC:
            std::sort(db.begin(), db.end(), [&](Movie* m1, Movie* m2){
                return sortAscending(m1, m2, attribute);
            });
            break;
        case DESC:
            std::sort(db.begin(), db.end(), [&](Movie* m1, Movie* m2){
                return sortDescending(m1, m2, attribute);
            });
            break;
        default:
            std::sort(db.begin(), db.end(), [&](Movie* m1, Movie* m2){
                return sortAscending(m1, m2, attribute);
            });
    }

}
/**
     * Overidden ostream method to output every movie in the database
     * @param output - the output stream
     * @param db - the database
     * @return a series of strings to the console that display all the movies in the
     *         database
     */
std::ostream &operator<<(std::ostream& output, const MovieDatabase &db){
    for (Movie *movie : db.db) {
        std::cout << *movie << std::endl;
    }
    return output;
}
/**
     * Comparator to see which movie is bigger based on a films attributes
     * @param m1 - movie 1
     * @param m2 - the movie to compare movie 1 to
     * @param attribute - the movies attribute to compare
     * @return true if m2 is bigger than m1
     */
bool MovieDatabase::sortAscending(Movie *m1, Movie *m2, Attribute attribute) {
    switch(attribute) {
        case NAME:
            return m1->getName() < m2->getName();
        case NAMELENGTH:
            return m1->getName().length() < m2->getName().length();
        case YEAR:
            return m1->getYear() < m2->getYear();
        case CERTIFICATE:
            return m1->getCertificate() < m2->getCertificate();
        case GENRE:
            return m1->getGenre().length() < m2->getGenre().length();
        case DURATION:
            return m1->getDuration() < m2->getDuration();
        case RATING:
            return m1->getRating()<m2->getRating();
        default:
            return m1->getName() < m2->getName();
    }
}
/**
     * Comparator to see which movie is bigger based on a films attributes
     * @param m1 - movie 1
     * @param m2 - the movie to compare movie 1 to
     * @param attribute - the movies attribute to compare
     * @return true if m1 is bigger than m2
     */
bool MovieDatabase::sortDescending(Movie *m1, Movie *m2, Attribute attribute) {
    switch(attribute) {
        case NAME:
            return m1->getName() > m2->getName();
        case NAMELENGTH:
            return m1->getName().length() > m2->getName().length();
        case YEAR:
            return m1->getYear() > m2->getYear();
        case CERTIFICATE:
            return m1->getCertificate() > m2->getCertificate();
        case GENRE:
            return m1->getGenre().length() > m2->getGenre().length();
        case DURATION:
            return m1->getDuration()>m2->getDuration();
        case RATING:
            return m1->getRating() > m2->getRating();
        default:
            return m1->getName() > m2->getName();
    }
}

/**
     * The method to input the movies into the database from a txt file
     * @param input - the input stream
     * @param db - the database to be populated
     * @return the input stream
     */
std::istream &operator>>(std::istream &input, MovieDatabase &db){
    std::string line, data;
    std::ifstream infile("films.txt", std::ifstream::in);
//http://www.cplusplus.com/doc/tutorial/files/  template for error checking
    if (infile.is_open()) {
        while (std::getline(infile, line)) {
                std::vector<std::string> movieData;
//https://stackoverflow.com/questions/1757065/java-splitting-a-comma-separated-string-but-ignoring-commas-in-quotes
//regex
//https://stackoverflow.com/questions/16749069/c-split-string-by-regex
//general method
                std::regex regex(",(?=(?:[^\\\"]*\\\"[^\\\"]*\\\")*[^\\\"]*$)");
                std::sregex_token_iterator iterator(line.begin(),
                                                line.end(),
                                                regex,
                                                -1);
                std::sregex_token_iterator end;
                for ( ; iterator != end; ++iterator) {
                    std::string string = *iterator;
                    string.erase(remove(string.begin(), string.end(), '"'), string.end());
                    movieData.push_back(string);

                }
                Movie* newMovie = new Movie(movieData[0], stoi(movieData[1]),
                                        movieData[2], movieData[3], stoi(movieData[4]),
                                        stoi(movieData[5]));

                db.addMovie(newMovie);
        }
        infile.close();
    }
    else{
        std::cout << "File couldn't be found or accessed." << std::endl;
        exit(0);
    }
    return input;

}



