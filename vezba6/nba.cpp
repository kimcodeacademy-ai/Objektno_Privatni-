// NBAPlayer
// Да се дефинира класа NBAPlayer за која ќе се чуваат:
//
// динамички алоцирана низа од карактери за името на играчот
// низа од максимум 40 карактери за тимот во кој играчот моментално настапува
// просечен број на поени на играчот оваа сезона (double)
// просечен број на асистенции на играчот оваа сезона (double)
// просечен број на скокови на играчот оваа сезона (double)
// За потребите на класата да се дефинираат:
//
// default конструктор и конструктор со аргументи
// copy constructor и оператор =
// деструктор
// метод rating() кој го враќа рејтингот на кошаркарот кој се пресметува како:
//
// 45% од поените + 30% од асистенциите + 25% од скоковите
//
// метод print() кој го печати играчот во следниот формат:
//
// Име - тим
//
// Points: поени
//
// Assists: асистенции
//
// Rebounds: скокови
//
// Rating: рејтинг
//
// AllStarPlayer
// Од претходната класа NBAPlayer да се изведе класата AllStarPlayer за која дополнително ќе се чуваат и:
//
// просечен број на поени на играчот од All Star натпреварите (double)
// просечен број на асистенции на играчот од All Star натпреварите (double)
// просечен број на скокови на играчот од All Star натпреварите (double)
// За потребите на класата да се дефинираат:
//
// default конструктор
// конструктор кој прима објект од NBAPlayer и плус додатните информации (погледни main)
// конструктор кој ги прима сите аргументи (погледни main)
// copy constructor, оператор =, деструктор
// метод allStarRating() кој го враќа рејтингот на кошаркарот од All Star натпреварите и кој се пресметува како:
//
// 30% од поените + 40% од асистенциите + 30% од скоковите
//
// Да се препокријат методите:
//
// rating() кој го враќа просекот од обичниот рејтинг на кошаркарот и неговиот All Star рејтинг
// print() кој покрај основните информации за кошаркарот печати и:
//
// All Star Rating: рејтингот од All Star натпреварите
//
// New Rating: просечниот рејтинг

#include <iostream>
#include <cstring>

using namespace std;

class NBAPlayer {
protected:
  char *name;
  char team[40];
  double points;
  double assists;
  double rebounds;

  void copy(const NBAPlayer &other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    strcpy(team, other.team);
    points = other.points;
    assists = other.assists;
    rebounds = other.rebounds;
  }

public:
  // default
  NBAPlayer() {
    name = new char[1];
    name[0] = '\0';
    strcpy(team, "");
    points = assists = rebounds = 0;
  }

  // constuctor with arguments
  NBAPlayer(const char *n, const char *t, double p, double a, double r) {
     name = new char[strlen(n) + 1];
     strcpy(name, n);
     strcpy(team, t);
     points = p;
     assists = a;
     rebounds = r;
  }

  NBAPlayer(const NBAPlayer &other) {
    copy(other);
  }

  ~NBAPlayer() {
    delete[] name;
  }

  NBAPlayer &operator=(const NBAPlayer &other) {
     if (this != &other) {
       delete [] name;
       copy(other);
     }
      return *this;
  }

  // 45% од поените + 30% од асистенциите + 25% од скоковите
  double rating() {
    return 0.45*points + 0.30*assists + 0.25*rebounds;
  }

  // Име - тим
  // Points: поени
  // Assists: асистенции
  // Rebounds: скокови
  // Rating: рејтинг
  void print() {
    cout << name << "-" << team << endl;
    cout << "Points: " << points << endl;
    cout << "Assists: " << assists << endl;
    cout << "Rebounds: " << rebounds << endl;
    cout << "Rating: " << rating() << endl;
  }
};

class AllStarPlayer : public NBAPlayer {
  double asPoints;
  double asRebounds;
  double asAssits;

public:
  // Default constructor
  AllStarPlayer() {
    asPoints = asRebounds = asAssits = 0;
  }

  // Constructor with nba player
  AllStarPlayer(NBAPlayer &p, double ap, double as, double ar) : NBAPlayer(p) {
    asPoints = ap;
    asAssits = as;
    asRebounds = ar;
  }

  // Constructor with allArguments
  AllStarPlayer(const char *n, const char *t, double p, double a, double r, double ap, double as, double ar) : NBAPlayer(n, t, p, a, r) {
    asPoints = ap;
    asAssits = as;
    asRebounds = ar;
  }

  AllStarPlayer(AllStarPlayer &other) : NBAPlayer(other) {
    asPoints = other.asPoints;
    asAssits = other.asAssits;
    asRebounds = other.asRebounds;
  }

  AllStarPlayer &operator=(const AllStarPlayer &other) {
    if (this != &other) {
      NBAPlayer::operator=(other);
      asPoints = other.asPoints;
      asAssits = other.asAssits;
      asRebounds = other.asRebounds;
    }
    return *this;
  }

  //30% од поените + 40% од асистенциите + 30% од скоковите
  double allStarRating () {
    return 0.30*asPoints + 0.4 *asAssits + 0.3*asRebounds;
  }
  double rating() {
     return(NBAPlayer::rating() + allStarRating()) /2;
  }

  //
  void print() {
    NBAPlayer::print();
    cout << "All Star Rating: " << allStarRating() << endl;
    cout << "New Rating: " << rating() << endl;
  }
};

int main() {

  char name[50];
  char team[40];
  double points;
  double assists;
  double rebounds;
  double allStarPoints;
  double allStarAssists;
  double allStarRebounds;

  NBAPlayer * players = new NBAPlayer[5];
  AllStarPlayer * asPlayers = new AllStarPlayer[5];
  int n;
  cin >> n;

  if (n == 1) {

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < 5; ++i) {
      cin >> name >> team >> points >> assists >> rebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      players[i].print();
    }
  }
  else if (n == 2) {

    for (int i=0; i < 5; ++i){
      cin >> name >> team >> points >> assists >> rebounds;
      cin >> allStarPoints >> allStarAssists >> allStarRebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarRebounds);
    }

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      players[i].print();

    cout << "ALL STAR PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      asPlayers[i].print();

    }
    else if (n == 3) {

      for (int i=0; i < 5; ++i){
        cin >> name >> team >> points >> assists >> rebounds;
        cin >> allStarPoints >> allStarAssists >> allStarRebounds;
        asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                     allStarPoints,allStarAssists,allStarRebounds);
      }
      cout << "ALL STAR PLAYERS:" << endl;
      cout << "=====================================" << endl;
      for (int i=0; i < 5; ++i)
        asPlayers[i].print();

    }

    delete [] players;
    delete [] asPlayers;
}

