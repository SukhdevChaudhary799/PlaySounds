#include <SFML/Audio.hpp>
#include <thread>
#include <vector>
#include <chrono>

void playAudio(const std::string& filePath) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filePath)) return;

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    std::this_thread::sleep_for(std::chrono::seconds(3)); // Adjust as needed
}

int main() {
    std::vector<std::string> audioFiles = {"Sound1.wav", "Sound2.wav", "Sound3.wav","Sound4.wav", "Sound5.wav", "Sound6.wav", "Sound7.wav" ,"Sound8.wav","Sound1.wav", "Sound2.wav", "Sound3.wav","Sound4.wav", "Sound5.wav", "Sound6.wav", "Sound7.wav" ,"Sound8.wav"};

    for (const auto& file : audioFiles) {
        std::thread(playAudio, file).detach();
        std::this_thread::sleep_for(std::chrono::seconds(2));  // Pattern delay
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));  // Prevent main from exiting early
    return 0;
}
