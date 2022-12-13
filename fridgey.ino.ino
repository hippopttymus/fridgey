#include <Servo.h>
Servo myservo;

// buzzer stuff
#include <Buzzer.h>
Buzzer buzzer(9);


// temperature settings
float temp;
int tempPin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(11);
  myservo.write(0);


}


void loop() {
  // now doing temp sensing portion 
        temp = analogRead(tempPin);
        float voltage = temp * 5.0;
        voltage /= 1024.0; 
        float temperatureC = (voltage - 0.5) * 100 ;
        // read analog volt from sensor and save to variable temp
        //temp = temp * 0.48828125;
        // convert the analog volt to its temperature equivalent
        Serial.print("TEMPERATURE = ");
        Serial.print(temperatureC); // display temperature value
        Serial.print("*C");
        Serial.println();
        delay(1000); // update sensor reading each one second

        if(temperatureC > 24.00){
          buzzstarwars();
          Serial.print("Playing star wars!");
        }

  
  // this is the light sensing portion  
        // put your main code here, to run repeatedly:
        // reads the input on analog pin A0 (value between 0 and 1023)
        int analogValue = analogRead(A0);

        Serial.print("Analog reading: ");
        Serial.print(analogValue);   // the raw analog reading

        // We'll have a few threshholds, qualitatively determined
        if (analogValue < 10) {
          Serial.println(" - Dark");
        } else if (analogValue < 200) {
          Serial.println(" - Dim");
        } else if (analogValue < 500) {
          Serial.println(" - Light");
        } else if (analogValue < 800) {
          Serial.println(" - Bright");
        } else {
          Serial.println(" - Very bright");
        }
        
        while(analogRead(A0) > 200){
          // buzzer play mario 
          buzzdoormario();
          if(analogRead(A0) > 200){
            buzzbells();
          }else{
            break;
          }
          if(analogRead(A0) > 200){
            buzzdist();
          }else{
            break;
          }
          // delay 10 sec
          //delay(10000);
          // check door one last time
          if(analogRead(A0) > 200){
            myservo.write(180);
            delay(5000);
            myservo.write(0);
            delay(2000);
            break;
          }else{
            break;
          }         
        }

      delay(500);

  
  
}


void buzzdoormario(){
  buzzer.begin(100);

  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_C7, 80);
  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_G7, 80);
  buzzer.sound(0, 240);
  buzzer.sound(NOTE_G6, 80);
  buzzer.sound(0, 240);
  buzzer.sound(NOTE_C7, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_G6, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_E6, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_A6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_B6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_AS6, 80);
  buzzer.sound(NOTE_A6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_G6, 100);
  buzzer.sound(NOTE_E7, 100);
  buzzer.sound(NOTE_G7, 100);
  buzzer.sound(NOTE_A7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_F7, 80);
  buzzer.sound(NOTE_G7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_C7, 80);
  buzzer.sound(NOTE_D7, 80);
  buzzer.sound(NOTE_B6, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_C7, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_G6, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_E6, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_A6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_B6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_AS6, 80);
  buzzer.sound(NOTE_A6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_G6, 100);
  buzzer.sound(NOTE_E7, 100);
  buzzer.sound(NOTE_G7, 100);
  buzzer.sound(NOTE_A7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_F7, 80);
  buzzer.sound(NOTE_G7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_C7, 80);
  buzzer.sound(NOTE_D7, 80);
  buzzer.sound(NOTE_B6, 80);
  buzzer.sound(0, 160);

  buzzer.end(2000);
}

void buzzstarwars(){
  buzzer.begin(10);

  buzzer.sound(NOTE_A3, 500); 
  buzzer.sound(NOTE_A3, 500);
  buzzer.sound(NOTE_A3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_C4, 125);

  buzzer.sound(NOTE_A3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_A3, 1000);

  buzzer.sound(NOTE_E4, 500); 
  buzzer.sound(NOTE_E4, 500);
  buzzer.sound(NOTE_E4, 500);
  buzzer.sound(NOTE_F4, 375);
  buzzer.sound(NOTE_C4, 125);

  buzzer.sound(NOTE_GS3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_A3, 1000);

  buzzer.sound(NOTE_A4, 500);
  buzzer.sound(NOTE_A3, 375);
  buzzer.sound(NOTE_A3, 125);
  buzzer.sound(NOTE_A4, 500);
  buzzer.sound(NOTE_GS4, 375);
  buzzer.sound(NOTE_G4, 125);

  buzzer.sound(NOTE_FS4, 125);
  buzzer.sound(NOTE_E4, 125);
  buzzer.sound(NOTE_F4, 250);
  buzzer.sound(0, 250);
  buzzer.sound(NOTE_AS3, 250);
  buzzer.sound(NOTE_DS4, 500);
  buzzer.sound(NOTE_D4, 375);
  buzzer.sound(NOTE_CS4, 125);

  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_B3, 125);
  buzzer.sound(NOTE_C4, 250);
  buzzer.sound(0, 250);
  buzzer.sound(NOTE_F3, 250);
  buzzer.sound(NOTE_GS3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_A3, 125);

  buzzer.sound(NOTE_C4, 500);
  buzzer.sound(NOTE_A3, 375);
  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_E4, 1000);

  buzzer.sound(NOTE_A4, 500);
  buzzer.sound(NOTE_A3, 375);
  buzzer.sound(NOTE_A3, 125);
  buzzer.sound(NOTE_A4, 500);
  buzzer.sound(NOTE_GS4, 375);
  buzzer.sound(NOTE_G4, 125);

  buzzer.sound(NOTE_FS4, 125);
  buzzer.sound(NOTE_E4, 125);
  buzzer.sound(NOTE_F4, 250);
  buzzer.sound(0, 250);
  buzzer.sound(NOTE_AS3, 250);
  buzzer.sound(NOTE_DS4, 500);
  buzzer.sound(NOTE_D4, 375);
  buzzer.sound(NOTE_CS4, 125);

  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_B3, 125);
  buzzer.sound(NOTE_C4, 250);
  buzzer.sound(0, 250);
  buzzer.sound(NOTE_F3, 250);
  buzzer.sound(NOTE_GS3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_C4, 125);

  buzzer.sound(NOTE_A3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_A3, 1000);

  buzzer.end(2000);
}

void buzzbells(){
  int time = 500;

  buzzer.begin(10);

  buzzer.sound(NOTE_G3, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_C4, time / 2);
  buzzer.sound(NOTE_G3, time * 2);
  
  buzzer.sound(NOTE_G3, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_C4, time / 2);
  buzzer.sound(NOTE_A4, time * 2);

  buzzer.sound(NOTE_A4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_G4, time);
  buzzer.sound(NOTE_G4, time);
  
  buzzer.sound(NOTE_A5, time / 2);
  buzzer.sound(NOTE_G4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_E4, time * 2);
  
  buzzer.sound(NOTE_G3, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_C4, time / 2);
  buzzer.sound(NOTE_G3, time * 2);
  
  buzzer.sound(NOTE_G3, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_C4, time / 2);
  buzzer.sound(NOTE_A4, time * 2);
  
  buzzer.sound(NOTE_A4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_G4, time / 2);
  buzzer.sound(NOTE_G4, time / 2);
  buzzer.sound(NOTE_G4, (time * 3) / 4);
  buzzer.sound(NOTE_G4, time / 4);
  
  buzzer.sound(NOTE_A5, time / 2);
  buzzer.sound(NOTE_G4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_C4, time * 2);

  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time);
  
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_G4, time / 2);
  buzzer.sound(NOTE_C4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_E4, time * 2);
  
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time / 4);
  buzzer.sound(NOTE_E4, time / 4);

  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_D4, time);
  buzzer.sound(NOTE_G4, time);

  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time);
  
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_G4, time / 2);
  buzzer.sound(NOTE_C4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_E4, time * 2);
  
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time / 2);
  buzzer.sound(NOTE_E4, time / 4);
  buzzer.sound(NOTE_E4, time / 4);
  
  buzzer.sound(NOTE_G4, time / 2);
  buzzer.sound(NOTE_G4, time / 2);
  buzzer.sound(NOTE_F4, time / 2);
  buzzer.sound(NOTE_D4, time / 2);
  buzzer.sound(NOTE_C4, time * 2);

  buzzer.end(2000);
}

void buzzdist(){
  // reg distortion
  buzzer.begin(0);

  buzzer.distortion(NOTE_C3, NOTE_C5);
  buzzer.distortion(NOTE_C5, NOTE_C3);

  buzzer.end(1000);
}
