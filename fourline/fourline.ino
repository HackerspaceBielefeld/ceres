// 1 01010101 01010101 01010101 01010101 01010101 01010101 111
//   <temper> <temp2 > <wet   > <wet2  > <light > <light2>

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
const int ADDRC     = 4;

const int STAT_ACT  =  ;
const int STAT_ERR  =  ;

//obsolete
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

long dezeln(arr) {
	int c = sizeof(arr);
	int m = 1;
	long r =0;
	for(int i = 0;i<c;i++) {m = m*2;}
	for(int i = 0;i<c;i++) {
		r = r + (arr[i]*m);
		m = m/2;
	}
	return r;
}

int mitteln(aPin,werte=10) {
  long r = 0;
  for(long i = 0;i<werte;i++) {
    r = r + analogRead(aPin)
  }
  int x = r/werte;
  return x;
}

bool last = LOW;

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
  digitalWrite(DATAP,LOW);
  digitalWrite(OUT_WET,LOW);
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
	//warte auf anfrage
	int timer = 0;
	bool autark = false;
	while(digitalRead(DATAP) == LOW) {
		timer++;
		delay(1);
		if(timer > WAIT) {
			// wenn kein takt autark mode
			autark = true;
			break;
		}
	}
	if(!autark){
		last = digitalRead(CLOCKP);
		// hole adresse
		bool ad[ADDRC];
		for int i = 0; i<ADDRC;i++) {
			while(digitalRead(CLOCKP) == last) {
				;
			}
			last = digitalRead(CLOCKP);
			ad[i] = digitalRead(DATAP);
		}
	}
  
	if(!autark && dezeln(ad) == addr) {
		// daten empfangen
		int n = 48;
		bool raw[n];
		int data[3];
		for(int i = 0;i<n;i++) {
			while(digitalRead(CLOCKP) == last) {
				;
			}
			last = digitalRead(CLOCKP);
			raw[i] = digitalRead(DATAP);
		}
		
		// daten vereinzeln und paitieren
		for(int j = 0;j<3;j++) {
			k = j*16;
			bool tmp[8];
			for(int i = 0; i < 8; i++) {
				if(raw[(k+i)] == raw[(k+i+8)]) {
					// daten korrekt
					tmp[i] = raw[(k+i)];
				}else{
					// daten inkorrekt byte nullen
					for(int l = 0; l<8;l++) {
						tmp[l] = LOW;
					}
					break;
				}
			}
		}
		
		// neue daten speichern 
		//TODO
		
		// prüfen ob handlungsbedarf existiert
		//TODO
		
		// bereite sensor daten vor
		//TODO
		
		// start
		//TODO
		
		// 2x temp
		//TODO
		
		// 2x licht
		//TODO
		
		// 2x wasser
		//TODO
		
		// stop	
		//TODO	
	
	}else{
		// daten prüfen und autark arbeiten TODO
		
	}
  
  
}
