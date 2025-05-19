#include <Keypad.h>

const byte columns = 4;
const byte rows = 4;

byte rowPins[rows] = {2,3,4,5};
byte columnPins[columns]={6,7,8,9};

/*char keys[rows][columns]= {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','a','A','c'},
  {'d','e','f','s'},
  };*/

 char keys[rows][columns]={
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'},
  };

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, columnPins, rows, columns);

const int buzzer = 10;
int tones[] = {262, 294, 330, 349, 392, 440, 494, 523, 587, 659, 698, 784, 880, 988, 1046, 1174};




void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  char keyPressed = myKeypad.getKey();

    if(keyPressed){
          Serial.print("Pritisnuti taster: ");
          Serial.println(keyPressed);
          int index = keyPressed - '1';  // Računanje indeksa u nizu tonova
          if (index >= 0 && index < 16) {
            tone(buzzer, tones[index]);  // Reprodukcija tona
            delay(300);                   // Zadržavanje tona
            noTone(buzzer);                // Isključivanje tona
    };
    }

}
