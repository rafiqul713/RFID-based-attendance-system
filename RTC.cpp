//Because of absence of RTC, static time is used here that is set manually
// RTC will be added later
class RealTimeClock{
  private:
    int attendence_hour;
    int attendence_minute;
    
    
  public:

    struct student_access_time{
        int student_access_hour;
        int student_access_minute;  
    };
    
    student_access_time stdAcs;
    //Attendence time is set by the teacher
    void set_attendence_time(int, int);
    void read_RTC();
    void get_student_access_time();
    bool verifyAccessTime(int,int);
};


void RealTimeClock::set_attendence_time(int h, int m){
     attendence_hour=h;
     attendence_minute=m;
     
}


void RealTimeClock::read_RTC(){
     //Read time from the RTC
     //This functionality will be changed after adding the RTC
     //Currently static time are used because missing of RTC   
     //Serial.println("Read RTC");
     stdAcs.student_access_hour=9;
     stdAcs.student_access_minute=0; 
}

void RealTimeClock::get_student_access_time(){
     Serial.print("Your Access Time is ");
     String str= String(stdAcs.student_access_hour) + " : " + String(stdAcs.student_access_minute);
     Serial.println(str);
} 


bool RealTimeClock::verifyAccessTime(int h,int m){
  if(h<=attendence_hour && m<=attendence_minute){
    return true;  
  }

  else{
    return false;  
  }
  
}
