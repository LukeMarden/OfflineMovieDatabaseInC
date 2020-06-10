/**
 * File - Movie.h
 * Author - Luke Marden
 * Date - 09/04/2020
 * Description - An object to handle a films data
 */

#ifndef INC_5015Y_CW2_MOVIE_H
#define INC_5015Y_CW2_MOVIE_H

#include <functional>
#include <iostream>
#include <string>

class Movie {
private:
    /**
     * All the attributes of the movies
     */
    std::string name, certificate, genre;
    int year, duration, rating;
public:
    /**
     * The constructor
     * @param name - the movies name
     * @param year - the year the movie came out
     * @param certificate - the age certificate of the movie
     * @param genre - the genres of the movie
     * @param duration - the duration of the movie in minutes
     * @param rating - the rating of the movie
     */
    Movie(std::string name, int year, std::string certificate, std::string genre, int duration,
            int rating);
    /**
     * A method to get the movies name
     */
    inline std::string getName(){
        return this->name;
    }
    /**
     * A method to get the movies year
     * @return the year
     */
    inline int getYear(){
        return this->year;
    }
    /**
     * A method to get the movies certificate
     * @return the movies certificate
     */
    inline std::string getCertificate(){
        return this->certificate;
    }
    /**
     * A method to get the movies genres
     * @return the movies genres
     */
    inline std::string getGenre(){
        return this->genre;
    }
    /**
     * A method to get the movies duration
     * @return the movies duration
     */
    inline int getDuration(){
        return this->duration;
    }
    /**
     * A method to get the movies rating
     * @return the movies rating
     */
    inline int getRating(){
        return this->rating;
    }
    /**
     * A method to set a movies name
     * @param name - the name to set it as
     */
    inline void setName(std::string name){
        this->name = name;
    }
    /**
     * A method to set the movies year
     * @param year - the year to set it as
     */
    inline void setYear(int year){
        this->year = year;
    }
    /**
     * A method to set the movies certificate
     * @param certificate - the certificate to set it as
     */
    inline void setCertificate(std::string certificate) {
        this->certificate = certificate;
    }
    /**
     * A method to set the movies genres
     * @param genre - the genres to set it as
     */
    inline void setGenre(std::string genre){
        this->genre = genre;
    }
    /**
     * A method to set the movies duration
     * @param duration - the duration to set it as
     */
    inline void setDuration(int duration){
        this->duration = duration;
    }
    /**
     * A method to set the movies rating
     * @param rating - the rating to set it as
     */
    inline void setRating(int rating){
        this->rating = rating;
    }
    /**
     * A method to output the details of a movie
     * @param output - the output stream
     * @param movie - the movie to output
     * @return a series of strings that represent the movies data
     */
    friend std::ostream& operator<<(std::ostream &output, const Movie &movie);


};
/**
 * An overridden operator that checks if a movie is equal to another
 * @param m1 - the first movie
 * @param m2 - the second movie
 * @return true if they are the same, false if they are not
 */
bool operator==(Movie& m1, Movie& m2);
/**
 * An overridden operator that checks if a movie is not equal to another
 * @param m1 - the first movie
 * @param m2 - the second movie
 * @return true if they are not the same, false if they are the same
 */
bool operator!=(Movie& m1, Movie& m2);

#endif //INC_5015Y_CW2_MOVIE_H
