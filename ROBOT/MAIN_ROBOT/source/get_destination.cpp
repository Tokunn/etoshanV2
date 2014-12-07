#include "../include/get_destination.hpp"

#include <string.h>
#include <iostream> // #=# DEBUG #=#


/*----- initialize() -----*/
Destination::Destination() {
    std::string temp_pose_string[] = { "$NEKO__",
                                       "$MAJOKO",
                                       "$OBAKE_",
                                       "$KAIDAN",
                                       "$NEKO__",
                                       "$KING__",
                                       "$BRUNA_"  };
    all_count = 8; // TODO count check
    fd = open(XBEE_SERIAL_PORT, O_RDWR);

    unsigned int size = sizeof(temp_pose_string) / sizeof(int);
    for (unsigned int i = 0; i < size; i++) {
        pose_string[i] = temp_pose_string[i];
    }
}

/*----- get_position() -----*/
int Destination::get_position() {
    recive_serial(&string_destination);
    return comv_destination_string2int(pose_string, &string_destination);
}

/*----- get_all_count() -----*/
int Destination::get_all_count() {
    return all_count;
}


/*----- recive_serial() -----*/
void Destination::recive_serial(std::string* string_destination) {
    char char_destination[10];
    read(fd, char_destination, 7);
    *string_destination = char_destination;
}

/*----- comv_destination_string2int() -----*/
int Destination::comv_destination_string2int(
        const std::string* pose_string, const std::string* string_destination) {
    std::cout << ">'" << *string_destination << "'<" << '\n';     // #=# DEBUG #=#
    for (unsigned int i = 0; i < 7; i++) {
        if (string_destination[0][3] == pose_string[i][3]) {
            std::cout << "\t\t[[Find]]: " << pose_string[i] << " Char is: " << string_destination[0][3] << " and: " << pose_string[i][3] << '\n';
        }
    }
    // TODO comp string
    return -5;
}
