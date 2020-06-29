/*
 * Main functionality:
 *  Read RFID: read the RFID card and find the unique identifier of the card
 *  Registration: a new student must have to be registered. Through register mode a new RFID card can be register
 *  Verification: verify RFID card by checking in the registered list
 */


#include <MFRC522.h>
#include <SPI.h>
#define number_of_student 50 //assume total 50 student can entrol in a course
#define CS 10
#define RST 9
MFRC522 rfid(CS, RST); 

 
class RFID{

  public:
    String uniqueRFID;
    String enroled_student[number_of_student];
    int registered_id=0;
    void registerCard(String id);
    String readRFID();
    void verifyCheckIn();
    void modeSelectorDisplay();

    
};

//function is used for registration
void RFID::registerCard(String id){
  if(registered_id!=0) //if there are some existing registered student
  {
    for(int i=0;i < registered_id;i++){
        if(enroled_student[i]==id){
            Serial.println("Already registered");
            return;
         }  
      
      }
  }
  enroled_student[registered_id]=id;
  registered_id++;
  Serial.println("Register a new student");
  
}


//function for mode selection
void RFID::modeSelectorDisplay(){
  Serial.println("Press 1: to register a new student");
  Serial.println("Press 2: to remove an existing student");
  Serial.println("Press 3: to access into the class");
  
}
