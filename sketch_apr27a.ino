#include <SoftwareSerial.h>   // 引用程式庫
 
// 定義連接藍牙模組的序列埠
SoftwareSerial LoRa(10, 11); // 接收腳, 傳送腳
char val;  // 儲存接收資料的變數
 
void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("LoRa is ready!");
  //Serial.write("AT+DTX=3,'123'");
  Serial.write('\r');
  // 設定LoRa模組的連線速率
  LoRa.begin(9600);
  //LoRa.print("AT+DTX=3,'123'\r");
  //用print 的方式自動下達AT command
  
}
 
void loop() {
 // LoRa.print("AT+DTX=11,\"25.04,121.5\"\r");
  //delay(500);
  // 若收到「序列埠監控視窗」的資料，則送到LoRa模組
  if (Serial.available()) {
    val = Serial.read();
    LoRa.print(val);
    //LoRa.print("AT+DTX=3,\"123\"");
  }
 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  ;
  if (LoRa.available() ) {
    val = LoRa.read();
    Serial.print(val);
  }
}
