#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Movie structure
struct Movie {
    string title;
    string genre;
    int year;
    double rating;
};

// Function prototypes
void showMenu();
void listMovies(const vector<Movie>& movies);
void recommendByGenre(const vector<Movie>& movies);
void searchMovie(const vector<Movie>& movies);
void addToWatchlist(const vector<Movie>& movies, vector<Movie>& watchlist);
void viewWatchlist(const vector<Movie>& watchlist);
int getValidatedInput(int min, int max);

int main() {
    vector<Movie> movies = {
        {"Extraction", "Action", 2020, 6.8},
        {"Murder Mystery", "Comedy", 2019, 6.0},
        {"Bird Box", "Horror", 2018, 6.6},
        {"To All the Boys I've Loved Before", "Romance", 2018, 7.1},
        {"The Irishman", "Drama", 2019, 7.8},
        {"Stranger Things", "Sci-Fi", 2016, 8.7}
    };

    vector<Movie> watchlist;
    int choice;

    do {
        showMenu();
        choice = getValidatedInput(1, 6);

        switch (choice) {
            case 1:
                listMovies(movies);
                break;
            case 2:
                recommendByGenre(movies);
                break;
            case 3:
                searchMovie(movies);
                break;
            case 4:
                addToWatchlist(movies, watchlist);
                break;
            case 5:
                viewWatchlist(watchlist);
                break;
            case 6:
                cout << "======= THANK YOU FOR USING NETFLIX MINI SYSTEM. GOODBYE!! ========" << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}

// Display menu
void showMenu() {
    cout << "\n=== WELCOME TO NETFLIX MINI SYSTEM ===" << endl;
    cout << "1. List all movies" << endl;
    cout << "2. Recommend by genre" << endl;
    cout << "3. Search a movie" << endl;
    cout << "4. Add movie to watchlist" << endl;
    cout << "5. View my watchlist" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option (1-6): ";
}

// Input validation
int getValidatedInput(int min, int max) {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else {
            break;
        }
    }
    return choice;
}

// List all movies
void listMovies(const vector<Movie>& movies) {
    cout << "\nAvailable Movies:\n";
    for (size_t i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i].title 
             << " (" << movies[i].year << ") - " 
             << movies[i].genre << " | Rating: " << movies[i].rating << endl;
    }
}

// Recommend by genre
void recommendByGenre(const vector<Movie>& movies) {
    string genre;
    cout << "Enter genre (Action, Comedy, Horror, Romance, Drama, Sci-Fi): ";
    cin.ignore();
    getline(cin, genre);

    cout << "\nRecommended Movies in " << genre << ":\n";
    bool found = false;
    for (const auto& m : movies) {
        if (m.genre == genre) {
            cout << "- " << m.title << " (" << m.year << ") | Rating: " << m.rating << endl;
            found = true;
        }
    }
    if (!found) cout << "No movies found for this genre." << endl;
}

// Search a movie
void searchMovie(const vector<Movie>& movies) {
    string keyword;
    cout << "Enter movie title to search: ";
    cin.ignore();
    getline(cin, keyword);

    cout << "\nSearch Results:\n";
    bool found = false;
    for (const auto& m : movies) {
        if (m.title.find(keyword) != string::npos) {
            cout << "- " << m.title << " (" << m.year << ") | " << m.genre << " | Rating: " << m.rating << endl;
            found = true;
        }
    }
    if (!found) cout << "No movies matched your search." << endl;
}

// Add to watchlist
void addToWatchlist(const vector<Movie>& movies, vector<Movie>& watchlist) {
    int index;
    listMovies(movies);
    cout << "Select a movie number to add to watchlist: ";
    index = getValidatedInput(1, movies.size());

    watchlist.push_back(movies[index - 1]);
    cout << movies[index - 1].title << " added to your watchlist." << endl;
}

// View watchlist
void viewWatchlist(const vector<Movie>& watchlist) {
    if (watchlist.empty()) {
        cout << "Your watchlist is empty." << endl;
    } else {
        cout << "\nYour Watchlist:\n";
        for (size_t i = 0; i < watchlist.size(); i++) {
            cout << i + 1 << ". " << watchlist[i].title 
                 << " (" << watchlist[i].year << ") - " 
                 << watchlist[i].genre << " | Rating: " << watchlist[i].rating << endl;
        }
    }
}
