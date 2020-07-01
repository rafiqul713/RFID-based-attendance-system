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
    void modeSelectorDisplay();
    bool isRegisteredStudent(String id);
    
};


//function for mode selection
void RFID::modeSelectorDisplay(){
  Serial.println("Press 1: to register a new student");
  Serial.println("Press 2: to remove an existing student");
  Serial.println("Press 3: to access into the class");
  
}

//function is used to register for a new RFID card
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


//Check register student
bool RFID::isRegisteredStudent(String id){
  for(int i=0;i < registered_id;i++){
        if(enroled_student[i]==id){
            return true;
         }  
      
      }
  

    return false;
}


//Read RFID card
String RFID::readRFID() {
  rfid.PICC_ReadCardSerial();
  Serial.println("Unique ID: ");
  uniqueRFID = String(rfid.uid.uidByte[0]) + " " + String(rfid.uid.uidByte[1]) + 
  " " + String(rfid.uid.uidByte[2]) + " " + String(rfid.uid.uidByte[3]);
  Serial.println(uniqueRFID);
  return uniqueRFID;
}

 
void setup() {
  
  // Init Serial port
  Serial.begin(9600);
  
  while(!Serial);
  
  // Init SPI bus
  SPI.begin(); 
  // Init MFRC522 
  rfid.PCD_Init(); 
 
 
 }

RFID obj;
int mode=0; 
void loop() {
  obj.modeSelectorDisplay(); 
  //Check the register mode: applicable for only new student
  mode=Serial.parseInt();   
  while(!Serial.available()){
  }
  delay(1000);
  if(mode==1){
      Serial.print("Register mode is selected");
      String str=obj.readRFID();
      //str.replace(" ","");
      Serial.println(str);
      obj.registerCard(str);
  }
  //attendence mode 
  else if(mode==3){
    Serial.println("Attendence mode is selected");
    if(rfid.PICC_IsNewCardPresent()){
    String str=obj.readRFID();
    //str.replace(" ","");
    bool registeredStudent= obj.isRegisteredStudent(str);
    if(registeredStudent==true){
      Serial.println("You are Welcome "+str);
      }
    else{
        Serial.println("You are not registered "+str);
      }

    }
    
  }
   mode=0;
  

 
}


 

 

 