const int r0 = 16; 
const int r1 = 5;
const int r2 = 4;
const int r3 = 0;
const int r4 = 2;
const int r5 = 14;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  pinMode(r0, INPUT);
  pinMode(r1, INPUT);
  pinMode(r2, INPUT);
  pinMode(r3, INPUT);
  pinMode(r4, INPUT);
  pinMode(r5, INPUT);
}
int s0=0;
int s1=0;
int s2=0;
int s3=0;
int s4=0;
int s5=0;
void loop() {
  // put your main code here, to run repeatedly:
  s0=digitalRead(r0); s1=digitalRead(r1); s2=digitalRead(r2);s3=digitalRead(r3);s4=digitalRead(r4);s5=digitalRead(r5);
  Serial.printf("r0= %d, r1= %d, r2= %d, r3= %d, r4= %d, r5= %d \n",s0,s1,s2,s3,s4,s5);
  delay(100);
}
