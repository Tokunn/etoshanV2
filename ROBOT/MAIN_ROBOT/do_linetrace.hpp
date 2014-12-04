#ifndef HEAD_DO_LINETRACE
#define HEAD_DO_LINETRACE


class LineTrace
{
    public:

        void set_sensor_value(int sensor_value);
        int get_tire_speed_value();

    private:

        LineTrace();
        int comp_linetrace_lib(int sensor_value);

        int sensor_value;
        int linetrace_lib[2][];

};

#endif // HEAD_DO_LINETRACE
