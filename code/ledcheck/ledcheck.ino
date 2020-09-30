#define count 16
int arr[]={4,5,14,15,16,17,18,19,21,22,23,25,26,27,32,33};
void setup() {
  // put your setup code here, to run once:
  int i;
  for (i = 0; i < count; i++) {
    pinMode(arr[i], OUTPUT);
    //pinMode(i, OUTPUT);
  }


}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for (i = 0; i < count; i++) {
    digitalWrite(arr[i], HIGH);
  }
  delay(100);
  int k;
  for (k = 0; k < count; k++) {
    digitalWrite(arr[k], LOW);
  }
  delay(100);
}
