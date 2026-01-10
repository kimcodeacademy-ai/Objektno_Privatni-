// Да се дефинира класа MovieActor за која ќе се чуваат:
//
// динамички алоцирана низа од карактери за името на актерот
// низа од максимум 40 карактери за државата од која потекнува
// просечна оцена на филмовите во кои глумел актерот годинава (double)
// вкупен број на филмови годинава (int)
// вкупна заработка од тие филмови во милиони долари (double)
// За потребите на класата да се дефинираат:
//
// default конструктор и конструктор со аргументи
// copy constructor и оператор =
// деструктор
// метод rating() кој го враќа рејтингот на актерот пресметан како:
//
// (просечна_оценка * 0.4) + (број_на_филмови * 0.2) + (заработка * 0.4)
//
// метод print() кој ги печати податоците во следниот формат:
//
// [Име] - [држава]
// Average rating: [просечна оцена]
// Movies this year: [вкупен број]
// Total earnings: [вкупна заработка]
// Rating: [рејтинг]
// Од MovieActor да се изведе класа OscarWinner за која дополнително ќе се чуваат:
//
// просечна оцена на филмовите по добиениот Оскар (double)
// број на филмови по добиениот Оскар (int)
// вкупна заработка од тие филмови (double)
// За потребите на класата да се дефинираат:
//
// default конструктор
// конструктор кој прима објект од MovieActor и плус дополнителните информации
// конструктор кој ги прима сите аргументи (видете main)
// copy constructor, оператор =, деструктор
// метод oscarRating() кој го враќа рејтингот од пост-Оскар филмовите:
//
// (пост-оскар_просечна_оценка * 0.6) + (пост-оскар_број_на_филмови * 0.1) + (пост-оскар_заработка * 0.3)
// Да се препокријат методите:
//
// rating() кој враќа просек од основниот и oscar рејтинг
// print() кој покрај основните информации за актерот печати и:
//
// Oscar Rating: [рејтинг]
// New Rating: [просечниот]
//
// nput	Result
// 1
// 5
// Leonardo_DiCaprio USA 8.5 3 150.0
// Tom_Hanks USA 9.0 5 200.0
// Meryl_Streep USA 9.5 4 120.0
// Brad_Pitt USA 8.0 6 180.0
// Jennifer_Lawrence USA 8.7 2 90.0
// MOVIE ACTORS:
// =====================================
// Leonardo_DiCaprio - USA
// Average rating: 8.5
// Movies this year: 3
// Total earnings: 150
// Rating: 64
// -------------------------
// Tom_Hanks - USA
// Average rating: 9
// Movies this year: 5
// Total earnings: 200
// Rating: 84.6
// -------------------------
// Meryl_Streep - USA
// Average rating: 9.5
// Movies this year: 4
// Total earnings: 120
// Rating: 52.6
// -------------------------
// Brad_Pitt - USA
// Average rating: 8
// Movies this year: 6
// Total earnings: 180
// Rating: 76.4
// -------------------------
// Jennifer_Lawrence - USA
// Average rating: 8.7
// Movies this year: 2
// Total earnings: 90
// Rating: 39.88
// -------------------------



#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// динамички алоцирана низа од карактери за името на актерот
// низа од максимум 40 карактери за државата од која потекнува
// просечна оцена на филмовите во кои глумел актерот годинава (double)
// вкупен број на филмови годинава (int)
// вкупна заработка од тие филмови во милиони долари (double)
class MovieActor {
protected:
  char* name;
  char country[41];
  double avg_rating;
  int num_movies;
  double earnings;

    void copy(const MovieActor& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        strcpy(country, other.country);
        this ->avg_rating = other.avg_rating;
        this->num_movies = other.num_movies;
        this->earnings = other.earnings;
    }
public:
    MovieActor() {
        name = new char[1];
        name[0] = '\0';
        strcpy(country, "");
        avg_rating = 0;
        num_movies = 0;
        earnings = 0;
    }

    MovieActor(char* name, char* country, double avg_rating, int num_movies, double earnings) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        strcpy(this->country, country);
        this->avg_rating = avg_rating;
        this->num_movies = num_movies;
        this->earnings = earnings;
    }

    MovieActor(const MovieActor& other) {
        copy(other);
    }

    MovieActor& operator=(const MovieActor& other) {
        if (this != &other) {
            delete [] name;
            copy(other);
        }
        return *this;
    }

    ~MovieActor() {
        delete[] name;
    }

    // метод rating() кој го враќа рејтингот на актерот пресметан како:
    //
    // (просечна_оценка * 0.4) + (број_на_филмови * 0.2) + (заработка * 0.4)

    virtual double rating() {
        return avg_rating * 0.4 +
            num_movies * 0.2 +
            earnings * 0.4;
    }
    // метод print() кој ги печати податоците во следниот формат:
    //
    // [Име] - [држава]
    // Average rating: [просечна оцена]
    // Movies this year: [вкупен број]
    // Total earnings: [вкупна заработка]
    // Rating: [рејтинг]

    virtual void print() {
        cout << name << " - " << country << endl;
        cout << "Average rating: " << avg_rating << endl;
        cout << "Movies this year: " << num_movies << endl;
        cout << "Total earnings: " << earnings << endl;
        cout << "Rating: " << rating() << endl;
    }

};

class OscarWinner : public MovieActor {
    // просечна оцена на филмовите по добиениот Оскар (double)
    // број на филмови по добиениот Оскар (int)
    // вкупна заработка од тие филмови (double)
private:
    double post_avg_rating;
    int post_num_movies;
    double post_earnings;

    void copyOscar(const OscarWinner& other) {
        post_avg_rating = other.post_avg_rating;
        post_num_movies = other.post_num_movies;
        post_earnings = other.post_earnings;
    }
public:

    // default конструктор
    // конструктор кој прима објект од MovieActor и плус дополнителните информации
    // конструктор кој ги прима сите аргументи (видете main)
    // copy constructor, оператор =, деструктор
    // метод oscarRating() кој го враќа рејтингот од пост-Оскар филмовите:
    //
    // (пост-оскар_просечна_оценка * 0.6) + (пост-оскар_број_на_филмови * 0.1) + (пост-оскар_заработка * 0.3)
    // Да се препокријат методите:
    //
    // rating() кој враќа просек од основниот и oscar рејтинг
    // print() кој покрај основните информации за актерот печати и:
    //
    // Oscar Rating: [рејтинг]
    // New Rating: [просечниот]

    OscarWinner() : MovieActor() {
        post_avg_rating = 0;
        post_earnings = 0;
        post_num_movies = 0;
    }

    OscarWinner(MovieActor& base, double post_avg_rating, int post_num_movies, double post_earnings) : MovieActor(base) {
        this->post_avg_rating = post_avg_rating;
        this->post_num_movies = post_num_movies;
        this->post_earnings = post_earnings;
    }

    OscarWinner(char* name, char* country, double avg_rating, int num_movies, double earnings, double post_avg_rating, int post_num_movies, double post_earnings)
    : MovieActor(name, country, avg_rating, num_movies, earnings) {
        this->post_avg_rating = post_avg_rating;
        this->post_num_movies = post_num_movies;
        this->post_earnings = post_earnings;
    }

    OscarWinner(const OscarWinner &other) : MovieActor(other) {
        copyOscar(other);
    }

    OscarWinner& operator=(const OscarWinner& other) {
        if (this!=&other) {
            MovieActor::operator=(other);
            copyOscar(other);
        }
        return *this;
    }

    ~OscarWinner() {}


    // метод oscarRating() кој го враќа рејтингот од пост-Оскар филмовите:
    //
    // (пост-оскар_просечна_оценка * 0.6) + (пост-оскар_број_на_филмови * 0.1) + (пост-оскар_заработка * 0.3)
    // Да се препокријат методите:
    //
    // rating() кој враќа просек од основниот и oscar рејтинг
    // print() кој покрај основните информации за актерот печати и:
    //
    // Oscar Rating: [рејтинг]
    // New Rating: [просечниот]

    double oscarRating() {
        return post_avg_rating*0.6 +
            post_num_movies * 0.1 +
                post_earnings * 0.3;
    }

    double rating() {
        return (MovieActor::rating() + oscarRating()) / 2;
    }

    void print() {
        MovieActor::print();
        cout << "Oscar Rating: " <<oscarRating() << endl;
        cout << "New Rating: " << rating() << endl;
    }
};

// Do not change the main function
int main() {
    char name[100];
    char country[41];
    double avg_rating;
    int num_movies;
    double earnings;
    double post_avg_rating;
    int post_num_movies;
    double post_earnings;

    int n;
    cin >> n;

    if (n == 1) {
        // Test MovieActor basic functionality
        cout << "MOVIE ACTORS:" << endl;
        cout << "=====================================" << endl;
        int numActors;
        cin >> numActors;

        MovieActor* actors = new MovieActor[numActors];

        for (int i = 0; i < numActors; ++i) {
            cin >> name >> country >> avg_rating >> num_movies >> earnings;
            actors[i] = MovieActor(name, country, avg_rating, num_movies, earnings);
            actors[i].print();
            cout << "-------------------------" << endl;
        }

        delete[] actors;
    }
    else if (n == 2) {
        // Test MovieActor and create OscarWinner from it
        int numActors;
        cin >> numActors;

        MovieActor* actors = new MovieActor[numActors];
        OscarWinner* oscarWinners = new OscarWinner[numActors];

        for (int i = 0; i < numActors; ++i) {
            cin >> name >> country >> avg_rating >> num_movies >> earnings;
            cin >> post_avg_rating >> post_num_movies >> post_earnings;

            actors[i] = MovieActor(name, country, avg_rating, num_movies, earnings);
            oscarWinners[i] = OscarWinner(actors[i], post_avg_rating, post_num_movies, post_earnings);
        }

        cout << "MOVIE ACTORS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < numActors; ++i) {
            actors[i].print();
            cout << "-------------------------" << endl;
        }

        cout << "OSCAR WINNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < numActors; ++i) {
            oscarWinners[i].print();
            cout << "-------------------------" << endl;
        }

        delete[] actors;
        delete[] oscarWinners;
    }
    else if (n == 3) {
        // Test OscarWinner with all arguments constructor
        int numWinners;
        cin >> numWinners;

        OscarWinner* oscarWinners = new OscarWinner[numWinners];

        for (int i = 0; i < numWinners; ++i) {
            cin >> name >> country >> avg_rating >> num_movies >> earnings;
            cin >> post_avg_rating >> post_num_movies >> post_earnings;

            oscarWinners[i] = OscarWinner(name, country, avg_rating, num_movies, earnings,
                                          post_avg_rating, post_num_movies, post_earnings);
        }

        cout << "OSCAR WINNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < numWinners; ++i) {
            oscarWinners[i].print();
            cout << "-------------------------" << endl;
        }

        delete[] oscarWinners;
    }
    else if (n == 4) {
        // Test copy constructor and operator= for MovieActor
        MovieActor actor1;
        cin >> name >> country >> avg_rating >> num_movies >> earnings;
        actor1 = MovieActor(name, country, avg_rating, num_movies, earnings);

        MovieActor actor2(actor1); // Using copy constructor
        MovieActor actor3;
        actor3 = actor1;           // Using operator=

        cout << "ORIGINAL:" << endl;
        actor1.print();
        cout << "-------------------------" << endl;

        cout << "COPY CONSTRUCTOR:" << endl;
        actor2.print();
        cout << "-------------------------" << endl;

        cout << "OPERATOR=:" << endl;
        actor3.print();
        cout << "-------------------------" << endl;
    }
    else if (n == 5) {
        // Test copy constructor and operator= for OscarWinner
        OscarWinner winner1;
        cin >> name >> country >> avg_rating >> num_movies >> earnings;
        cin >> post_avg_rating >> post_num_movies >> post_earnings;

        winner1 = OscarWinner(name, country, avg_rating, num_movies, earnings,
                              post_avg_rating, post_num_movies, post_earnings);

        OscarWinner winner2(winner1); // Using copy constructor
        OscarWinner winner3;
        winner3 = winner1;            // Using operator=

        cout << "ORIGINAL:" << endl;
        winner1.print();
        cout << "-------------------------" << endl;

        cout << "COPY CONSTRUCTOR:" << endl;
        winner2.print();
        cout << "-------------------------" << endl;

        cout << "OPERATOR=:" << endl;
        winner3.print();
        cout << "-------------------------" << endl;
    }

    return 0;
}
