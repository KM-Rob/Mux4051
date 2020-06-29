
#define A 5
#define B 6
#define C 7
#define A_in A0
#define MAX_bit 3

int ina, inb, inc;

void set_out(char value);
void czytaj(char value);
void ABC_clear(void);

void setup() {
  // put your setup code here, to run once:
pinMode(A, OUTPUT);
pinMode(B, OUTPUT);
pinMode(C, OUTPUT);

ABC_clear();

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println(analogRead(A_in));
for(int j=0;j<3;j++)
  {
    Serial.print("cyfra: ");
    Serial.print(j);
    Serial.print(":  ");
    set_out(j);
    delay(5);
    czytaj(j);
  }
  Serial.print(ina);
  Serial.print(" ");
  Serial.print(inb);
  Serial.print(" ");
  Serial.println(inc);
  delay(1500);
}

void set_out(char value)
{
ABC_clear();
for(int i=0; i<MAX_bit; i++)
  {
    Serial.print(A+i);
    Serial.print(" ");
    if(bitRead(value,i))
      {
        digitalWrite(A+i,HIGH);
        Serial.print("H  ");
      }
  }
  Serial.println("");

}

void czytaj(char value)
{
  if(value==0) ina = analogRead(A_in);
  if(value==1) inb = analogRead(A_in);
  if(value==2) inc = analogRead(A_in);
}

void ABC_clear(void)
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
}
