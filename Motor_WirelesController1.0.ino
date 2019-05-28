/**
 * Bu kod Uzaktan Kumandalı Tank Projesi için uzaktan kumandanın 
 * çalışmasına yöneliktir.
 * 
 * Kullanılan devre modülleri ve aksamlar:
 * 1 Adet Arduino UNO
 * 1 Adet Gamepad shield modül
 * 1 Adet HC-05 Bluetooth Modül (Master)
 * 5V powerbank
 * 
 * Bu kısımda ardunio ile birlikte Tankı yönlendirebilmek için 
 * bir adet gamepad shield modulü ve uzaktan kumanda görevinde
 * kullanılacak arduino ile tankı sürecek olan arduinonun iletişimi
 * için bir adet HC-05 bluetooth modulü kullanılmıştır. 
 * 
 * Arduino bağlı bulunduğu gamepad shield'inden analog olarak joystick
 * X ve Y değerlerini okur. Arduinonun analog çözünürlüğü 10 bittir.
 * Serial ile bağlantılı olarak bluetooth ile 10 bit yerine 8 bitlik 
 * byte yollayabileceğimiz için okunan değerler 4e bölünüp yollanır.
 * Baştaki '$' karakteri iki arduino arasında veri senkronizasyonu
 * için gönderilmektedir. 05.2019
 * 
 * 05160000657 Nurullah EMSEN
 * 05160000784 Elifnaz ÖKLÜ
 * 05160000283 Oğuzhan KATI
 */


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  delay(4000);
  digitalWrite(13,HIGH); 
}

/**
 * loop fonksiyonu içinde devamlı olarak analogdan değer alınır ve
 * 4e bölünup serial üzerinden gönderilir.
 * Baştaki '$' karakteri iki arduino arasında veri senkronizasyonu
 * için gönderilmektedir. Delay ler senkronizasyonun korunması ve
 * alıcı arduinonun işlemini tamamlayabilmesi için süre sağlar.
 */
void loop() {
  Serial.write('$');
  delay(4);
  Serial.write(analogRead(A0)/4); //X-axis
  delay(4);
  Serial.write(analogRead(A1)/4); //Y-axis
  delay(4);

}
