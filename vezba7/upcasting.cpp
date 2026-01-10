#include <iostream>
using namespace std;

class Instrument {
public:
    void play(int note) const {
        cout << "Instrument playing note " << note << endl;
    }

    void play(int note, float volume) const {
        cout << "Instrument playing note " << note
             << " with volume " << volume << endl;
    }
};

class Flute : public Instrument {
public:
    void play(int note) const {   // redefinement
        cout << "Flute playing note " << note << endl;
    }

    //using Instrument::play; // ← if you add this you will return the versions from the base class
};

void tune(Instrument& inst) {
    inst.play(1); // upcasting + call from base class - safe
}

int main() {
    // Instrument i;
    // i.play(3);
    // i.play(3, 5.5);
    Flute f;

    f.play(1);        // OK → Flute::play(int)
    // f.play(1, 0.5); // ❌ ERROR: hidden version from base class

    tune(f);          // upcasting (Flute -> Instrument)

    return 0;
}
