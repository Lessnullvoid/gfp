int Letra1[] = {2, 3, 4, 5, 6, 7, 8, 9} ;
int Letra2[] = {10, 11, 12, 13, 14, 15, 16, 17};
long randNumber;

String s = " humans: aren't real, are animals, are free, are underrated, are among us, are cthulhu, like a virus. humans: need air, need love, need water, need to belong. human: services, rights, feelings, thoughts, process, dreams. human: sense of smell, sense of time, sent to mars, produce methane, protostomes or deuterostomes, protecting the environment destroying everything. human genes: BRCA2, CFTR, MTCYB, DMD, GAPDH, HBB, HIST1H1A, TTN, 00, 01, 11, 01, 10, 11 ";

void setup() {
  for (int p = 0; p < 8; p++) {
    pinMode(Letra1[p], OUTPUT); // declare all pins as output pins
    pinMode(Letra2[p], OUTPUT);
    // cambiar 1 por 0 si estan invertidos los valores para prender/apagar the board
    digitalWrite(Letra1[p], 1); // turn them off initially
    digitalWrite(Letra2[p], 1); // 1 is off for the relay board
    randomSeed(analogRead(5));
  }
}

void loop() {
   for (int i = 0; i < 8; i++){
  digitalWrite(Letra1[i], 0);
  digitalWrite(Letra2[i], 0);
  
  randNumber = random(40, 210);
  
  for (int c = 0; c < s.length(); c += 2) {
    // las proximas 2 letras
    // cambiar 0xff para 0x00 si estan invertidos los valores para prender/apagar the board
    int l1 = 0xff ^ s.charAt(c);
    int l2 = 0xff;

    // check if there's a 2nd letra
    if ((c + 1) < s.length()) {
      // cambiar 0xff para 0x00 si estan invertidos los valores para prender/apagar the board
      l2 = 0xff ^ s.charAt(c + 1);
    }

    // get bit values for 1st letter
    //    equivalent of: vi = (l1 >> (7-i)) & 0x1
    int v7 = l1 / 1 % 2;
    int v6 = l1 / 2 % 2;
    int v5 = l1 / 4 % 2;
    int v4 = l1 / 8 % 2;
    int v3 = l1 / 16 % 2;
    int v2 = l1 / 32 % 2;
    int v1 = l1 / 64 % 2;
    int v0 = l1 / 128 % 2;

    // wite to lights
    digitalWrite(Letra1[0], v0);
    digitalWrite(Letra1[1], v1);
    digitalWrite(Letra1[2], v2);
    digitalWrite(Letra1[3], v3);
    digitalWrite(Letra1[4], v4);
    digitalWrite(Letra1[5], v5);
    digitalWrite(Letra1[6], v6);
    digitalWrite(Letra1[7], v7);

    // get bit values for 2nd letter
    v7 = l2 / 1 % 2;
    v6 = l2 / 2 % 2;
    v5 = l2 / 4 % 2;
    v4 = l2 / 8 % 2;
    v3 = l2 / 16 % 2;
    v2 = l2 / 32 % 2;
    v1 = l2 / 64 % 2;
    v0 = l2 / 128 % 2;

    // wite to lights
    digitalWrite(Letra2[0], v0);
    digitalWrite(Letra2[1], v1);
    digitalWrite(Letra2[2], v2);
    digitalWrite(Letra2[3], v3);
    digitalWrite(Letra2[4], v4);
    digitalWrite(Letra2[5], v5);
    digitalWrite(Letra2[6], v6);
    digitalWrite(Letra2[7], v7);

    delay(randNumber);
   }
  }

}

