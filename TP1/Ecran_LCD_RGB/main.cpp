#include "mbed.h"
I2C lcd(I2C_SDA,I2C_SCL);

const int addrLCD = 0x7C;
const int addrLED = 0xC4;

void init_LCD();
void write_command(char c);
void write_data(char c);
void print_LCD_char(char c);
void print_LCD_String(char *s);
void print_LCD_String_lig2(char *s);
    
int main() {
    init_LCD();
    print_LCD_String("Hello world");
    //print_LCD_String_lig2("Diego");
    //write_command(0x07);
    
}

void init_LCD() {
    wait(0.3);
    write_command(0x3C);    //3C = 2 lignes et LCD allumé
    wait(0.1);
    write_command(0x0F);    //0F = LCD on, cursor on, blink on
    wait(0.1);
    write_command(0x01);    //01 = effacer écran LCD
    wait(0.15);
    write_command(0x06);    //06 = mode incrémental, pas de décalage
    wait(0.1);
    /*char couleur[];
    couleur[0] = 0x80;      //80 = control byte
    couleur[1] = 0xE0;      //A = config de couleur*/
}

void write_command(char c) {
    char cmd[2];
    cmd[0] = 0x80;
    cmd[1] = c;
    lcd.write(addrLCD, cmd, 2, false);
}

void write_data(char c) {
    char cmd[2];
    cmd[0] = 0x40;
    cmd[1] = c;
    lcd.write(addrLCD, cmd, 2, false);
}

void print_LCD_String(char *s) {
    char cmd[17];   //longueur max = 16 car LCD de 16x2
    cmd[0] = 0x40;
    for(int i = 0; i < strlen(s) || i < 16; i++)
        cmd[i+1] = s[i];
        
    lcd.write(addrLCD, cmd, strlen(s)+1, false);
}

/*void print_LCD_String_lig2(char *s) {
    char cmd[36];   //longueur max = 32 car LCD de 16x2
    cmd[0] = 0xC0;
    for(int i = 0; i < strlen(s); i++)
        cmd[i+1] = s[i];
        
    lcd.write(addrLCD, cmd, strlen(s)+1, false);
}*/