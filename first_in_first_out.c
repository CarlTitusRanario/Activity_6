// Carl Titus Ranario BSCpE 4B

// First In First Out Scheduling

int bt[] = {4, 1, 2, 8, 10, 5}; // Burst time inputs
int p[] = {13, 12, 11, 10, 9, 8}; // Processes pin inputs
int size = 6;
float Averagewaitingtime, wt;

void setup() {
  // LEDs Pin configuration
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void Wt(int waitingTime) {	// function for getting the average waiting time
  wt = wt + waitingTime; 
  Averagewaitingtime = Averagewaitingtime + wt;
}

void Arrive(int task, int burstTime) { //function for arrival of the task
  digitalWrite(task, HIGH); // sets the LED to High state or ON
  delay(burstTime * 1000); //Burst time in milliseconds 
  digitalWrite(task, LOW); // sets the LED to low state or OFF
}

void loop() { //driver function
  for ( int i = 0; i < size; i++) {
    Arrive(p[i], bt[i]); // Arrival of task
    
  	if (i < size - 1) {
      Wt(bt[i]); // Waiting time
  	}
  }
  
  Serial.println("Average Waiting Time : ");
  Serial.println(Averagewaitingtime/size); // Prints Average Waiting Time
  Serial.println("End of process. ");
  delay(10000); 
}



        