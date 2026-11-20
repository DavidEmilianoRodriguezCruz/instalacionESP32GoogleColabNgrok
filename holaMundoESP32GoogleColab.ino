#include <WiFi.h>
#include <WebServer.h>

//Aqui deberas poner el nombre TAL CUAL aparece en tu red WIFI. (Ya sea domestica, laptop o telefono).
const char* ssid = "RED_WIFI_PROPIA";

//Aqui colocaras la contrasena de la red wifi que este conectando.
const char* password="CONTRSENA";

WebServer server(80);

void handleHola()
{
  server.send(200, "text/plain", "holaMundo desde IDE Arduino Conexion Casa - Conexion Exitosa");
}

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Conectado");
  Serial.print("IP del ESP32:");
  Serial.print(WiFi.localIP());

  server.on("/hola", handleHola);
  server.begin();
}

void loop()
{
  server.handleClient();
}
