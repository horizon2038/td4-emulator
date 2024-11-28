#include <td4/factory.hpp>

#include <chrono>
#include <iostream>
#include <thread>

int main()
{
    std::cout << R"(
  _______ _____  _____  _______ _______ _______  
 |_     _|     \|  |  ||    ___|   |   |   |   | 
   |   | |  --  |__    |    ___|       |   |   | 
   |___| |_____/   |__||_______|__|_|__|_______| 

                )"
              << std::endl;

    auto core = td4::make_cpu();

    // LED tika-tika (from sample codes)
    auto rom   = std::make_unique<td4::rom>();
    rom->at(0) = 0b10110011;
    rom->at(1) = 0b10110110;
    rom->at(2) = 0b10111100;
    rom->at(3) = 0b10111000;
    rom->at(4) = 0b10111000;
    rom->at(5) = 0b10111100;
    rom->at(6) = 0b10110110;
    rom->at(7) = 0b10110011;
    rom->at(8) = 0b10110001;
    rom->at(9) = 0b11110000;

    core.register_rom(std::move(rom));

    std::cout << std::endl;
    std::cout << "clock late (hz) > ";
    auto hz = 0;
    std::cin >> hz;
    auto late = 1000 / hz;

    for (;;)
    {
        core.clock();
        std::this_thread::sleep_for(std::chrono::milliseconds(late));
    }
}
