#ifndef HEAD_DO_LINETRACE
#define HEAD_DO_LINETRACE


/*===== LineTrace =====*/
class LineTrace
{
    public:
        LineTrace();
        void set_sensor_value(int sensor_value);
        int get_tire_speed_value();

    private:
        int comp_linetrace_lib(int sensor_value);

        int sensor_value;
        int linetrace_lib[2][10];
};

#endif // HEAD_DO_LINETRACE
