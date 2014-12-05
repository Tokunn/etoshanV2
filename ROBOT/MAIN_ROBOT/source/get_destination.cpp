#include "get_destination.hpp"


/*----- initialize() -----*/
Destination::Destination() {
    fd = open(SERIAL_PORT, O_RDWR);
}


/*----- get_destination_count() -----*/
int Destination::get_destination_count() {
    // TODO recive serial, comv
}


/*----- get_all_count() -----*/
int Destination::get_all_count() {
}
