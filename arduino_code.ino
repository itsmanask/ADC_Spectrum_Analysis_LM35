#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C LCD address, adjust to your module's
LiquidCrystal_I2C lcd(0x27, 16, 2);


const int lm35Pin = A0;
const float referenceVoltage = 5.0;
const int adcResolution = 1024;

unsigned long prevSampleTime = 0;
const int samplingIntervalMs = 100;  // 10 Hz → 100ms
float samplingFreq = 1000.0 / samplingIntervalMs;

byte degreeSymbol[8] = {
  0b00111,
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.createChar(0, degreeSymbol);  // create custom char at location 0
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Fs:");
  lcd.setCursor(0, 1);
  lcd.print("Temp:");
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - prevSampleTime >= samplingIntervalMs) {
    prevSampleTime = currentMillis;

    int rawADC = analogRead(lm35Pin); // 10-bit ADC value (0–1023)
    float mV = (rawADC * referenceVoltage * 1000.0) / adcResolution;
    float temperature = mV / 10.0; // LM35 gives 10mV/°C

    // 8-bit quantization (0–255)
    int digital8bit = map(rawADC, 0, 1023, 0, 255);

    // Show on LCD
    
    lcd.setCursor(3, 0);
    lcd.print("   ");
    lcd.setCursor(3, 0);
    lcd.print(samplingFreq, 0);
    lcd.print("Hz");

    lcd.setCursor(6, 1);
    lcd.print("      ");
    lcd.setCursor(6, 1);
    lcd.print(temperature, 1);
    lcd.write(byte(0));     // write custom degree symbol
    lcd.print("C");

    // Serial Monitor Output (CSV format)
    Serial.print(mV, 2);          // mV
    Serial.print(",");
    Serial.println(digital8bit);  // Digital (8-bit)

    // Serial Plotter Output (for graphing purposes)
    Serial.print(mV);            // analog signal (in mV)
    Serial.print(",");
    Serial.println(digital8bit); // digital signal
  }
}
