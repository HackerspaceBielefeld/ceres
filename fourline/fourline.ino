// 1111111111 0101010101 0101010101 0101010101 0101010101 0101010101 0101010101 0000000000
// <start   > <temper  > <temper2 > <wet     > <wet2    > <light   > <light2  > <stop    >

// zeit zwischen 2 daten paketen default:60sekunden
const unsigned long WAIT    = 60000;

// pin eingang für den takt: maximum muss noch getestet werden ich sag mal 
const int CLOCKP    =  ;

const int DATAP     =  ;
const int OUT_WET   =  ;

const int IN_TEMP   =  ;
const int IN_WET    =  ;
const int IN_LIGHT  =  ;
//const int WET     =  ;

const int ADDR_0    =  ;
const int ADDR_1    =  ;
const int ADDR_2    =  ;
const int ADDR_3    =  ;

const int STAT_SEND =  ;
const int STAT_ERR  =  ;

bool send(addr,temp,wet,light) {
  int bitcount = 80;
  bool data[bitcount]
  // daten vorbereiten
  int j = 0;
  // start byte
  for(i<10;i++) {
    data[j] = true;
    j++;
  }
  
  // temperatur
  bool d[] = biteln(temp);
  for(int i = 0;i<10;i++) {
    data[j] = d[i];
    j++;
  }
  for(int i = 0;i<10;i++) {
    data[j] = d[i];
    j++;
  }
  
  // naesse
  bool d[] = biteln(wet);
  for(int i = 0;i<10;i++) {
    data[j] = d[i];
    j++;
  }
  for(int i = 0;i<10;i++) {
    data[j] = d[i];
    j++;
  }
  
  // licht
  bool d[] = biteln(light);
  for(int i = 0;i<10;i++) {
    data[j] = d[i];
    j++;
  }
  for(int i = 0;i<10;i++) {
    data[j] = d[i];
    j++;
  }
  bool clocktime = digitalRead(CLOCKP); 
}

bool biteln(zahl) {
  int bitwert = 512;
  rcount = 10
  bool ret[rcount];
  for (int i = 0;i < rcount;i++( {
    if(zahl > bitwert) {
      zahl = zahl - bitwert;
      ret[i] = true;
    }else{
      ret[i] = false;
    }
    bitwert = bitwert / 2;
  }
  return ret;
}

int mitteln(aPin,werte=10) {
  long r = 0;
  for(long i = 0;i<werte;i++) {
    r = r + analogRead(aPin)
  }
  int x = r/werte;
  return x;
}

int addr = 0;
int temperatur = 0;
int naesse = 0;
int licht = 0;

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println("INIT...");
  pinMode(DATAP, OUTPUT);
  pinMode(OUT_WET, OUTPUT);
  Serial.println("Output Initialisiert ...");
  
  
  pinMode(CLOCKP, INPUT);
  pinMode(ADDR_0, INPUT_PULLUP);
  pinMode(ADDR_1, INPUT_PULLUP);
  pinMode(ADDR_2, INPUT_PULLUP);
  pinMode(ADDR_3, INPUT_PULLUP);
  Serial.println("Input initialisiert ...");
  
  addr = (digitalRead(ADDR_0)*1) + (digitalRead(ADDR_1)*2) + (digitalRead(ADDR_2)*4) + (digitalRead(ADDR_3)*8);
  Serial.print("ID: ");
  Serial.println(addr);
}

void loop() {
  // warte WAIT ms ab um neuen test zu machen
  // prüfe werte
  // reagiere auf werte
  // es sei denn du empfängst start byte plus eigene adresse
}
