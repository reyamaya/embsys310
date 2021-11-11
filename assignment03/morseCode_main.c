#include <time.h>
#include <string.h>
#include <ctype.h>

#define RCC_BASE    0x40021000
#define GPIOA_BASE  0x48000000

#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER  (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA_MODER_OUTPUT (1 << 11)
#define GPIOA_ODR_OD5 (1 << 5)

void delay(unsigned int);
void dot(void);
void dash(void);
void dotAbsence(void);
void toggleLED1_ON(void);
void toggleLED1_OFF(void);
void morseCodeSingleWord(const char*);

int main()
{
     //Enable the clock for GPIOA
    RCC_AHB2ENR |= 0x1; 
        
    //Set Port A as output
    GPIOA_MODER ^= GPIOA_MODER_OUTPUT;
    
    //Delay prior to Morse Code input for visiblity
    delay(1); 
    
    //Running Morse Code Per Word
    morseCodeSingleWord("ReyNAldo!!3d0");
    
    return 0;
}

void delay (unsigned int secs) 
{
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until the finish time.
}

void dot(void)
{
    //dot will turn LED on for (1) second
    toggleLED1_ON();
    delay(1);
    toggleLED1_OFF();
}

void dash(void)
{
    //dash will turn LED on for (3) second
    toggleLED1_ON();
    delay(3);
    toggleLED1_OFF();
}

void dotAbsence(void)
{
    //dotAbsence will leave LED off for (1) second
    delay(1);
}

void toggleLED1_ON(void)
{
    //Turn LED ON - Set GPIOA Pin 5 to Output Data
    GPIOA_ODR ^= GPIOA_ODR_OD5;       
 }

void toggleLED1_OFF(void)
{
    //Turn LED ON - Set GPIOA Pin 5 to Output Data
    GPIOA_ODR ^= GPIOA_ODR_OD5;    
}

void morseCodeSingleWord(const char* str)
{
    unsigned int strLen = strlen(str);
    unsigned int i;
    unsigned char letter; 
      
    for(i = 0; i < strLen; i++)
    {
        letter = str[i];
        
        if(letter < '0')
        {
            continue;
        }
        if(letter > '9' && letter < 'A')
        {
            continue;
        }
        if(letter > 'Z' && letter < 'a')
        {
            continue;
        }
        if(letter > 'z')
        {
            continue;
        }
        if(letter >= 'a' && letter <= 'z')
        {
            letter = toupper(str[i]);
        }
        
        switch(letter)
        {
            case 'A' :
                dot();
                dotAbsence();
                dash();
                break;
                
            case 'B' :
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                break;
            
            case 'C' :
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dash();
                dotAbsence();
                dot();
                break;

            case 'D' :
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                break;
                
            case 'E' :
                dot();
                break;
            
            case 'F' :
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dash();
                dotAbsence();
                dot();                        
                break;
                
            case 'G' :
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dot();
                break;
                
            case 'H' :
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();                
                break;
            
            case 'I' :
                dot();
                dotAbsence();
                dot();
                break;

            case 'J' :
                dot();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                break;
                
            case 'K' :
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dash();
                break;
            
            case 'L' :
                dot();
                dotAbsence();
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                break;   
                
            case 'M' :
                dash();
                dotAbsence();
                dash();
                break;

            case 'N' :
                dash();
                dotAbsence();
                dot();
                break;
                
            case 'O' :
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                break;
            
            case 'P' :
                dot();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dot();
                break;
                
            case 'Q' :
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dash();
                break;   
                
            case 'R' :
                dot();
                dotAbsence();
                dash();
                dotAbsence();
                dot();
                break;

            case 'S' :
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                break;
                
            case 'T' :
                dash();
                break;
            
            case 'U' :
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dash();
                break;
                
            case 'V' :
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dash();
                break;
                
            case 'X' :
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dash();
                break;
            
            case 'Y' :
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                break;
                           
            case 'Z' :
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                break;
                
            case '1' :
                dot();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                break;
                
            case '2' :
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                break;   
                
            case '3' :
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                break;

            case '4' :
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dash();                
                break;
                
            case '5' :
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();                
                break;
            
            case '6' :
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();    
                break;
                
            case '7' :
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dot();
                dotAbsence();
                dot();    
                break;
                
            case '8' :
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dot();
                dotAbsence();
                dot();    
                break;
            
            case '9' :
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dot();    
                break;
                           
            case '0' :
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dash();
                dotAbsence();
                dash();    
                break;
        }//End switch statement
        
        //exit function if the the end of the string was reached.
        if(str[i + 1] == '\0')
            return;
        
        //Add a three unit absences between letters in word
        dotAbsence();   
        dotAbsence(); 
        dotAbsence(); 
      
    }//end for loop    
}//end function