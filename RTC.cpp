//Because of absence of RTC, static time is used here that is set manually
// RTC will be added later
class RealTimeClock{
  private:
    int attendence_hour;
    int attendence_minute;
    
    
  public:

    int student_access_hour;
    int student_access_minute;

    //Attendence time is set by the teacher
    void set_attendence_time(int, int);
    void read_RTC();
    void get_student_access_time();
};

