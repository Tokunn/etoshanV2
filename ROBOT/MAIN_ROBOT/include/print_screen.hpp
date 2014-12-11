#ifndef HEAD_PRINT_SCREEN
#define HEAD_PRINT_SCREEN

#define PMT_ONLINE 0
#define PMT_COUNT 1
#define PMT_STOPLINE 2
#define PMT_ALL_COUNT 3
#define PMT_STOP_NOW 4
#define PMT_VAL 5
#define PMT_COMMAND 6
#define PMT_7 7
#define PMT_8 8
#define PMT_9 9


/*===== PrintScreen =====*/
class PrintScreen
{
    public:
        PrintScreen();
        void set_pmt(int pmt_id, int pmt);
        void print();

    private:
        int pmt[10];
};

#endif // HEAD_PRINT_SCREEN
