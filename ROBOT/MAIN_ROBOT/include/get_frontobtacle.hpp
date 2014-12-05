#ifndef HEAD_GET_FRONTOBTACLE
#define HEAD_GET_FRONTOBTACLE


/*===== FrontObtacle =====*/
class FrontObtacle
{
    public:
        FrontObtacle();
        bool get_front_obtacle();

    private:
        void recive_udp(char* char_front_obtacle);
        bool comv_front_obtacle(char* char_front_obtacle);

        char char_front_obtacle;
};

#endif // HEAD_GET_FRONTOBTACLE
