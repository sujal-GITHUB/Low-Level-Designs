#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Signal {
    string color;
    int id;
    int timeInterval;

public:
    Signal(string color, int timeInterval) {
        this->color = color;
        this->timeInterval = timeInterval;

        if (color == "Red") {
            this->id = 1;
        } else if (color == "Yellow") {
            this->id = 2;
        } else if (color == "Green") {
            this->id = 3;
        } else {
            cout << "Invalid signal color!" << endl;
        }
    }

    string getColor() { return this->color; }

    int getTimeInterval() { return this->timeInterval; }

    void updateTimeInterval(int newTimeInterval) {
        this->timeInterval = newTimeInterval;
    }
};

class TrafficSignalSystem {
    Signal* Red;
    Signal* Yellow;
    Signal* Green;
    set<Signal*> signals;
    bool show = false;

public:
    TrafficSignalSystem() {
        Red = new Signal("Red", 60);
        Yellow = new Signal("Yellow", 5);
        Green = new Signal("Green", 50);

        signals.insert(Red);
        signals.insert(Yellow);
        signals.insert(Green);
    }

    void getSignals() {
        for (auto it : signals) {
            cout << it->getColor() << endl;
        }
    }

    int getTimeInterval(int id) {
        if (id == 1) return Red->getTimeInterval();
        else if (id == 2) return Yellow->getTimeInterval();
        else if (id == 3) return Green->getTimeInterval();
        else {
            cout << "Invalid id" << endl;
            return -1;
        }
    }

    int getTimeInterval(string color) {
        if (color == "Red") return Red->getTimeInterval();
        else if (color == "Yellow") return Yellow->getTimeInterval();
        else if (color == "Green") return Green->getTimeInterval();
        else {
            cout << "Invalid color" << endl;
            return -1;
        }
    }

    void updateTimeInterval(int id, int newTimeInterval) {
        if (id == 1) Red->updateTimeInterval(newTimeInterval);
        else if (id == 2) Yellow->updateTimeInterval(newTimeInterval);
        else if (id == 3) Green->updateTimeInterval(newTimeInterval);
        else cout << "Invalid id" << endl;
    }

    void updateTimeInterval(string color, int newTimeInterval) {
        if (color == "Red") Red->updateTimeInterval(newTimeInterval);
        else if (color == "Yellow") Yellow->updateTimeInterval(newTimeInterval);
        else if (color == "Green") Green->updateTimeInterval(newTimeInterval);
        else cout << "Invalid color" << endl;
    }
};

int main() {
    // 1. Create system
    TrafficSignalSystem system;

    cout << "\n--- Default Signals ---\n";
    system.getSignals();

    // 2. Update Yellow's time interval by color
    cout << "\n--- Updating Yellow (color) ---\n";
    system.updateTimeInterval("Yellow", 10);

    // 3. Update Green's time interval by id
    cout << "\n--- Updating Green (id) ---\n";
    system.updateTimeInterval(3, 40);

    // Show updated signals
    cout << "\n--- Updated Signals ---\n";
    system.getSignals();

    // 4. Start signaling for 2 full cycles
    cout << "\n--- Starting signaling for 2 cycles ---\n";
    int cycles = 2;
    while (cycles-- > 0) {
        cout << "Signal: Red | Time: " << system.getTimeInterval(1) << " seconds\n";
        this_thread::sleep_for(seconds(system.getTimeInterval(1)));

        cout << "Signal: Green | Time: " << system.getTimeInterval(3) << " seconds\n";
        this_thread::sleep_for(seconds(system.getTimeInterval(3)));

        cout << "Signal: Yellow | Time: " << system.getTimeInterval(2) << " seconds\n";
        this_thread::sleep_for(seconds(system.getTimeInterval(2)));
    }

    cout << "\n--- Signaling finished ---\n";
    return 0;
}
