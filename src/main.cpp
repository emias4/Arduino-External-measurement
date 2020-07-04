#include <Arduino.h>
#define ADC_RES_DEF (5.0f / 1024.0f)
#define ADC_LH_DEF (100.0f / 1024.0f)
#define samples 100
#define samplingTime 1000

void PrintResult(double P, double L, double H)
{
  Serial.print(" \t V(5) = ");
  Serial.print(P);
  Serial.print("[V]  ");
  Serial.print(" L(4) = ");
  Serial.print(L);
  Serial.print("%  ");
  Serial.print(" H(3) = ");
  Serial.print(H);
  Serial.println("%  ");
}

void setup()
{
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);
}
void loop()
{
  double sumP = 0, sumL = 0, sumH = 0;
  double avrP = 0, avrL = 0, avrH = 0;
  for (int i = 1; i <= samples; i++)
  {
    sumP += ADC_RES_DEF * analogRead(A5);
    sumL += ADC_LH_DEF * analogRead(A4);
    sumH += ADC_LH_DEF * analogRead(A3);
    delay(10);
  }

  avrP = sumP / samples;
  avrL = sumL / samples;
  avrH = sumH / samples;
  PrintResult(avrP, avrL, avrH);

  delay(samplingTime);
}