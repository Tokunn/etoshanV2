#ifndef HEAD_GET_DESTINATION
#define HEAD_GET_DESTINATION


class Destination
{
    public:

        int get_destination_count();
        int get_all_count();
        int get_home_count();

    private:

        Destination();
        void recive_serial(char* char_destination);
        int comv_destination_char2int(char* char_destination);

        int all_count;
        char char_destination[10];

};

#endif // HEAD_GET_DESTINATION
