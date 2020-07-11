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


void RealTimeClock::set_attendence_time(int h, int m){
     attendence_hour=h;
     attendence_minute=m;
     
}


void RealTimeClock::read_RTC(){
     //Read time from the RTC
     //This functionality will be changed after adding the RTC
     //Currently static time are used because missing of RTC   
     Serial.println("Read RTC");
     student_access_hour=9;
     student_access_minute=0; 
}

void RealTimeClock::get_student_access_time(){
     Serial.print("Your Access Time is ");
     String str= String(student_access_hour) + " : " + String(student_access_minute);
     Serial.println(str);
} 
