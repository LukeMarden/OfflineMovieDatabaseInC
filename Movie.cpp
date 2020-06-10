/**
 * File - Movie.cpp
 * Author - Luke Marden
 * Date - 09/04/2020
 * Description - An object to handle a films data
 */
#include <functional>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Movie.h"
/**
 * The constructor
 * @param name - the movies name
 * @param year - the year the movie came out
 * @param certificate - the age certificate of the movie
 * @param genre - the genres of the movie
 * @param duration - the duration of the movie in minutes
 * @param rating - the rating of the movie
 */
Movie::Movie(std::string name, int year, std::string certificate, std::string genre, int duration, int rating) {
    this->name = name;
    this->year = year;
    this->certificate = certificate;
    this->genre = genre;
    this->duration = duration;
    this->rating = rating;
}

/**
 * An overridden operator that checks if a movie is equal to another
 * @param m1 - the first movie
 * @param m2 - the second movie
 * @return true if they are the same, false if they are not
 */
bool operator==(Movie& m1, Movie& m2){
    return (m1.getName() == m2.getName() && m1.getYear() == m2.getYear() &&
        m1.getCertificate() == m2.getCertificate() && m1.getGenre() == m2.getGenre()
        && m1.getDuration() == m2.getDuration() && m1.getRating() == m2.getRating());
}
/**
 * An overridden operator that checks if a movie is not equal to another
 * @param m1 - the first movie
 * @param m2 - the second movie
 * @return true if they are not the same, false if they are the same
 */
bool operator!=(Movie& m1, Movie& m2){
    return !(m1 == m2);
}
/**
     * A method to output the details of a movie
     * @param output - the output stream
     * @param movie - the movie to output
     * @return a series of strings that represent the movies data
     */
std::ostream& operator<<(std::ostream &output, const Movie &movie){
    output << "\"" << movie.name << "\",";
    output << movie.year << ",\"";
    output << movie.certificate << "\",";
    output << "\"" << movie.genre << "\",";
    output << movie.duration << ",";
    output << movie.rating;
    return output;
}

//std::istream &operator>>(std::istream& input, Movie& movie){
//    std::string name, classification, genre;
//    int year, length, rating;
//    std::cout << "What is the name of the film?\n";
//    input >> name;
//    std::cout << "What year was the movie made?\n";
//    input >> year;
//    std::cout << "What's the age rating of the movie?\n";
//    input >> classification;
//    std::cout << "What's the genre of the movie?\n";
//    input >> genre;
//    std::cout << "What's the duration of the movie?\n";
//    input >> length;
//    std::cout << "What's the rating of the movie?\n";
//    input >> rating;
//    movie = Movie(name, year, classification, genre, length, rating);
//    return input;
//}
