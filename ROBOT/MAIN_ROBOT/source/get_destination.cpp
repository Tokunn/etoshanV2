#include "get_destination.hpp"


/*----- initialize() -----*/
Destination::Destination() {
    fd = open(XBEE_SERIAL_PORT, O_RDWR);
    all_count = 8; // TODO count check
}

/*----- get_destination_count() -----*/
int Destination::get_destination_count() {
    recive_serial(char_destination);
    return comv_destination_char2int(char_destination);
}

/*----- get_all_count() -----*/
int Destination::get_all_count() {
    return all_count;
}


/*----- recive_serial() -----*/
void Destination::recive_serial(char* char_destination) {
    char first_char;
    do {
        read(fd, &first_char, 1);
    } while (first_char != '$');
    read(fd, char_destination, 7);
}

/*----- comv_destination_char2int() -----*/
int Destination::comv_destination_char2int(char* char_destination) {
    // TODO comp string
    return -5;
}


// TODO initialize
/*char Destination::pose_char[7][8] = { "NEKO__",
                                     "MAJOKO",
                                     "OBAKE_",
                                     "KAIDAN",
                                     "NEKO__",
                                     "KING__",
                                     "BRUNA_"  };*/
