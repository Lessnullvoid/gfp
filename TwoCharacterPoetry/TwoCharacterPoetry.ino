int Letra1[] = {2, 3, 4, 5, 6, 7, 8, 9} ;
int Letra2[] = {10, 11, 12, 13, 14, 15, 16, 17};

String s = "Humans are animals";

void setup() {
  for (int p = 0; p < 8; p++) {
    pinMode(Letra1[p], OUTPUT); // declare all pins as output pins
    pinMode(Letra2[p], OUTPUT);
    digitalWrite(Letra1[p], 1); // turn them off initially
    digitalWrite(Letra2[p], 1);
  }
}

void loop() {
  for (int i = 0; i < s.length(); i += 2) {
    // las proximas 2 letras
    int l1 = 0xff ^ s.charAt(i); // flips bits so 1 value turns on relay
    int l2 = 0xff;

    // check if there's a 2nd char
    if ((i + 1) < s.length()) {
      l2 = 0xff ^ s.charAt(i + 1); // flips bits so 1 value turns on relay
    }

    // first encryption
    int a = l1 / 1 % 2; // calculate LSB
    int b = l1 / 2 % 2;
    int c = l1 / 4 % 2;
    int d = l1 / 8 % 2;
    int e = l1 / 16 % 2;
    int f = l1 / 32 % 2;
    int g = l1 / 64 % 2;
    int h = l1 / 128 % 2; //calculate MSB

    digitalWrite(Letra1[0], a); // write LSB
    digitalWrite(Letra1[1], b);
    digitalWrite(Letra1[2], c);
    digitalWrite(Letra1[3], d);
    digitalWrite(Letra1[4], e);
    digitalWrite(Letra1[5], f);
    digitalWrite(Letra1[6], g);
    digitalWrite(Letra1[7], h); // write MSB


    // second encryption
    a = l2 / 1 % 2; // calculate LSB
    b = l2 / 2 % 2;
    c = l2 / 4 % 2;
    d = l2 / 8 % 2;
    e = l2 / 16 % 2;
    f = l2 / 32 % 2;
    g = l2 / 64 % 2;
    h = l2 / 128 % 2; //claculate MSB

    digitalWrite(Letra2[0], a); // write LSB
    digitalWrite(Letra2[1], b);
    digitalWrite(Letra2[2], c);
    digitalWrite(Letra2[3], d);
    digitalWrite(Letra2[4], e);
    digitalWrite(Letra2[5], f);
    digitalWrite(Letra2[6], g);
    digitalWrite(Letra2[7], h); // write MSB

    delay(333);
  }

}

