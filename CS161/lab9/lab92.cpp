
/******************************************************
 * ** Author: Megan Conley
 * ** Date: 11/27/2013
 * ** Description: Lab 9, part 2
 * ** Input: User fills in a database of movies including
 * title, genre, description, rating, and copies. Then
 * user can search by genre and rent a movie.
 * ** Output: All details about a movie, then the copies
 * subtract the number rented.
 * ******************************************************/

#include<iostream>
#include<string>

#define NUM_MOVIES 5

struct movie_record {

public:
	std::string get_title();
	std::string get_desc();
	std::string get_genre();
	int get_rating();
	int get_copies();

	void add_movie();
	void set_title(std::string t);
	void set_rating(int r);
	void set_desc(std::string d);
	void set_copies(int c);
	void set_genre(std::string g);
	void get_movies(movie_record *record);
	void rent_movie();
	void request_genre();
	void get_movie_info();
	
private: /* I wanted to practice this
	    so I made the variables private
	    even though it wasn't required. */
	std::string title, description, genre;
	int copies, rating;
} rental;

// The following are functions to set and access private variables.
std::string movie_record::get_title() {
	return title;
}

std::string movie_record::get_desc() {
	return description;
}

std::string movie_record::get_genre() {
	return genre;
}

int movie_record::get_rating() {
	return rating;
}

int movie_record::get_copies() {
	return copies;
}

void movie_record::set_title(std::string t) {
	title = t;
}

void movie_record::set_rating(int r) {
	rating = r;
}

void movie_record::set_desc(std::string d) {
	description = d;
}

void movie_record::set_copies(int c) {
	copies = c;
}

void movie_record::set_genre(std::string g) {
	genre  = g;
}

/* This function prompts the user for information
 * about movies and sets the variables to the 
 * values input by the user. */
void movie_record::add_movie() {
	std::string title, description, genre;
	int copies, rating;

	std::cout << "What is the movie's title? ";
	std::getline(std::cin, title);
	set_title(title);

	std::cout << "What is the movie's description? ";
	std::getline(std::cin, description);
	set_desc(description);

	std::cout << "What is the movie's genre? ";
	std::getline(std::cin, genre);
	set_genre(genre);

	std::cout << "What is the movie's rating (0-100)? ";
	std::cin >> rating;
	set_rating(rating);

	std::cout << "How many copies are available? ";
	std::cin >> copies;
	set_copies(copies);

}

/* This function prints the information gathered
 * from add_movie() */
void movie_record::get_movie_info() {

	std::cout << "Title: " << title << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "Genre: " << genre << std::endl;
	std::cout << "Rating: " << rating << std::endl;
	std::cout << "Copies: " << copies << std::endl;

}

/* This function asks user to input genre
 * which will be later used to search for
 * and rent a movie. */
void movie_record::request_genre() {

	std::string g;
	std::cout << "What genre of movies would you like to view? ";
	std::getline(std::cin, g);
	set_genre(g);
}

/* This function subtracts 1 from the number
 * of copies of the rented movie. */
void movie_record::rent_movie() {

	int stock = copies;
	stock--;
	std::cout << "Rental of " << title << " processed." << std::endl;
	std::cout << "There are now " << stock << " copies of " << title << " left in stock." << std::endl;
}

/* This function lists all movies matching the user's
 * genre filter. It then copies all information about
 * the movie the user wants to rent to the rental struct,
 * so the details can be printed with get_movie_info() */
void movie_record::get_movies(movie_record *record) {

	std::string r;
	std::cout << "We currently have the following " << genre << " movies:" << std::endl;

	for (int i = 0; i < NUM_MOVIES; i++) {
		if (record[i].genre == genre) {
			std::cout << record[i].title << std::endl;
		}
	}

	std::cout << "Which movie would you like to rent? ";
	std::getline(std::cin,r);

        for (int i = 0; i < NUM_MOVIES; i++) {
                if (record[i].title == r) {
                        set_title(record[i].title);
			set_copies(record[i].copies);
			set_genre(record[i].genre);
			set_rating(record[i].rating);
			set_desc(record[i].description);
			break;
                }
        }
}

int main() {

	// Creates array of movie_record structs
	movie_record *record = new movie_record[NUM_MOVIES];

	// Prompts user to fill in details about movies
	for(int i = 0; i < NUM_MOVIES; i++) {
		record[i].add_movie();
	}

	// Prompts user to search by genre
	rental.request_genre();

	// Displays movies that match the above genre
	rental.get_movies(record);

	// Displays details about the chosen movie
	rental.get_movie_info();

	// Subtracts one from copies of chosen movie to "rent" it
	rental.rent_movie();

	return 0;
}
