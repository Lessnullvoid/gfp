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
  for (int c = 0; c < s.length(); c += 2) {
    // las proximas 2 letras
    int l1 = 0xff ^ s.charAt(c); // flips bits because of relay board
    int l2 = 0xff;

    // check if there's a 2nd letra
    if ((c + 1) < s.length()) {
      l2 = 0xff ^ s.charAt(c + 1); // flips bits because of relay board
    }

    for (int b = 0; b < 8; b++) {
      // first letra encryption
      int v1 = (l1 >> b) & 0x1;
      digitalWrite(Letra1[7-b], v1);
      // second letra encryption
      int v2 = (l2 >> b) & 0x1;
      digitalWrite(Letra2[7-b], v2);
    }
    delay(333);
  }

}

