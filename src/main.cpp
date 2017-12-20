#include <chrono>
#include "sketch.h"
#include <thread>
#include "config.h"

using namespace std;

bool isRunning = true;
const unsigned int LOGIC_UPDATE_RATE_MS = 10;
const unsigned int DRAW_UPDATE_RATE_MS = 32;
Sketch *sketch;
sf::Color bgColor(255,255,255);

void updateFrame() {
    while (isRunning) {
        sketch->update();
        this_thread::sleep_for(chrono::milliseconds(LOGIC_UPDATE_RATE_MS));
    }
}

int main() {
    srand(time(NULL));

    cout << "RoboRregos 2018 Maze Simulation Version= " << myproject_VERSION_MAJOR << '\n';
    cout << "By Alberto Jahuey Moncada\n";
    sketch = new Sketch();
    sketch->setup();
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Maze Simulation " + to_string(myproject_VERSION_MAJOR));
    thread updateThread(updateFrame);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                isRunning = false;
            }
        }

        window.clear(bgColor);
        sketch->draw(window);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(DRAW_UPDATE_RATE_MS));
    }
    updateThread.join();
    delete sketch;

    return 0;
}