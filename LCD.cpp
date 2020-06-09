#include <LiquidCrystal.h>



//Responsible for LCD display
class LCD_Module{
   public:
      int RS_pin, enable_pin, d4_pin, d5_pin, d6_pin, d7_pin;
      int num_of_col, num_of_row;
      int cursor_col, cursor_line;
      
      LCD_Module(int RS, int enable, int d4, int d5, int d6, int d7,int col, int row,int cur_col,int cur_line);
      
      void set_col_row(int col, int row);
      void set_cursor(int col, int line);

};


//Configure
LCD_Module::LCD_Module(int RS, int enable, int d4, int d5, int d6, int d7, int col, int row, int cursor_col, int cursor_line){
    RS_pin=RS;
    enable_pin=enable;
    d4_pin=d4;
    d5_pin=d5;
    d6_pin=d6;
    d7_pin=d7;
    this->set_col_row(col,row);
    this->set_cursor(cursor_col,cursor_line);
}

void LCD_Module::set_col_row(int col, int row){
    num_of_col=col;
    num_of_row=row;

}

void LCD_Module::set_cursor(int col, int line){
  cursor_col=col;
  cursor_line=line;

}

//Pin configuration and attribute initialization
LCD_Module obj(12,11,5,4,3,2,16,2,0,0); //RS_pin, enable_pin, d4_pin, d5_pin, d6_pin, d7_pin,num_of_col, num_of_row, cursor_row, cursor_line
LiquidCrystal lcd(obj.RS_pin,obj.enable_pin,obj.d4_pin,obj.d5_pin,obj.d6_pin,obj.d7_pin);

