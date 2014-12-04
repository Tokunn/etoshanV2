#ifndef HEAD_GET_FRONTOBTACLE
#define HEAD_GET_FRONTOBTACLE

class FrontObtacle
{
    public:

        bool get_front_obtacle();

    private:

        FrontObtacle();
        void recive_udp(char* char_front_obtacle);
        bool comv_front_obtacle(char* char_front_obtacle);

        char char_front_obtacle;

};

#endif // HEAD_GET_FRONTOBTACLE
