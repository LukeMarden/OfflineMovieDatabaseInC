/**
 * File - MovieDatabase.h
 * Author - Luke Marden
 * Date - 21/04/2020
 * Description - A class to handle a database of movie objects
 */
#include <vector>
#include <fstream>
#include <sstream>
#include <iosfwd>
#include <string>
#include <iostream>
#include <regex>
#include "Movie.h"
#ifndef INC_5015Y_CW2_MOVIEDATABASE_H
#define INC_5015Y_CW2_MOVIEDATABASE_H
enum SortDirection {ASC, DESC};
enum Attribute {NAME, NAMELENGTH, YEAR, CERTIFICATE, GENRE, DURATION, RATING};

class MovieDatabase {
public:

    /**
     * Constructor
     */
    MovieDatabase();
    /**
     * Destructor
     */
    ~MovieDatabase();
    /**
     * Method to add movies to the database
     * @param movie - the movie to add
     */
    void addMovie(Movie *movie){
        this->db.push_back(movie);
    }
    /**
     * Makes a sub database based on an attribute and a value
     * @param attribute - the attribute to build the sub database on
     * @param value - the value to match
     * @return The sub database
     */
    MovieDatabase* subDB(Attribute attribute, std::string value);
    /**
     * Sorts the database based on a movies attribute and a direction
     * @param attribute - Movie name etc
     * @param direction - Ascending/Descending
     */
    void sortDB(Attribute attribute, SortDirection direction);
    /**
     * Method to get the db of the object
     * @return the database vector
     */
    inline std::vector<Movie*> getDB(){
        return this->db;
    }
    /**
     * Gets the size of the database
     * @return the size of the database
     */
    inline int getSize(){
        return db.size();
    }
    /**
     * Gets the movie at the index specified
     * @param index - the index to find the movie at
     * @return the movie at that index
     */
    inline Movie* get(int index) {
        return db[index];
    }
    /**
     * Overidden ostream method to output every movie in the database
     * @param output - the output stream
     * @param db - the database
     * @return a series of strings to the console that display all the movies in the
     *         database
     */
    friend std::ostream &operator<<(std::ostream& output, const MovieDatabase &db);


private:
    /**
     * A vector to store the movie objects
     */
    std::vector<Movie*> db;
    /**
     * Comparator to see which movie is bigger based on a films attributes
     * @param m1 - movie 1
     * @param m2 - the movie to compare movie 1 to
     * @param attribute - the movies attribute to compare
     * @return true if m2 is bigger than m1
     */
    bool sortAscending(Movie* m1, Movie* m2, Attribute attribute);
    /**
     * Comparator to see which movie is bigger based on a films attributes
     * @param m1 - movie 1
     * @param m2 - the movie to compare movie 1 to
     * @param attribute - the movies attribute to compare
     * @return true if m1 is bigger than m2
     */
    bool sortDescending(Movie* m1, Movie* m2, Attribute attribute);
};
/**
 * The method to input the movies into the database from a txt file
 * @param input - the input stream
 * @param db - the database to be populated
 * @return the input stream
 */
std::istream &operator>>(std::istream &input, MovieDatabase &db);


#endif //INC_5015Y_CW2_MOVIEDATABASE_H
