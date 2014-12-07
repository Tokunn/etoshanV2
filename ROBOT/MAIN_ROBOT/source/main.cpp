#include <iostream>
#include <stdlib.h>

#include "../include/get_destination.hpp"

#define DEBUG


int main()
{
    Destination destination;

    while (true) {
        int destination_position = destination.get_position();
#ifdef  DEBUG
        std::cout << "Destination Position is: " << destination_position << '\n';
#endif
    }

    return EXIT_SUCCESS;

}
