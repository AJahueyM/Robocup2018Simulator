#include <chrono>
#include "sketch.h"
#include <thread>
#include "config.h"
#include "spdlog/spdlog.h"

using namespace std;
namespace spd = spdlog;

bool isRunning = true;
const unsigned int LOGIC_UPDATE_RATE_MS = 10;
const unsigned int DRAW_UPDATE_RATE_MS = 32;
Sketch *sketch;
sf::Color bgColor(255, 255, 255);

void updateFrame() {
    while (isRunning) {
        sketch->update();
        this_thread::sleep_for(chrono::milliseconds(LOGIC_UPDATE_RATE_MS));
    }
}

int main() {
    srand(time(NULL));
    spd::set_level(spd::level::trace);

    cout << "RoboRregos 2018 Maze Simulation Version= " << myproject_VERSION_MAJOR << '\n';
    cout << "By Alberto Jahuey Moncada\n";
    sketch = new Sketch();
    sketch->setup();
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Maze Simulation " + to_string(myproject_VERSION_MAJOR));
    sf::View view(window.getDefaultView());
    thread updateThread(updateFrame);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                isRunning = false;
            }
            if (event.type == sf::Event::Resized)
                window.setView(view = sf::View(sf::FloatRect(0.f, 0.f,
                                                          static_cast<float>(window.getSize().x),
                                                          static_cast<float>(window.getSize().y))));
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