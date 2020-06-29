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

    
};


