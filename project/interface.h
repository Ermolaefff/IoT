//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// можете включить вывод отладочной информации в Serial на 115200
//#define REMOTEXY__DEBUGLOG    

// определение режима соединения и подключение библиотеки RemoteXY 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT


// настройки соединения 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


#include <RemoteXY.h>

// конфигурация интерфейса RemoteXY  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 101 bytes
  { 255,3,0,17,0,94,0,17,0,0,0,31,1,106,200,1,1,5,0,5,
  15,126,72,72,32,2,26,31,10,41,99,20,19,113,4,26,31,83,69,82,
  86,79,0,31,72,35,76,32,32,84,2,26,75,40,0,0,0,0,0,0,
  52,67,0,0,0,0,1,0,0,0,0,0,0,32,65,1,0,0,42,67,
  0,0,52,67,68,5,17,96,50,17,8,2,67,6,2,94,10,5,2,31,
  11 };
  
// структура определяет все переменные и события вашего интерфейса управления 
struct {

    // input variables
  int8_t joystick_x; // oт -100 до 100
  int8_t joystick_y; // oт -100 до 100
  uint8_t servo_switcher; // =1 если включено, иначе =0

    // output variables
  int16_t circular_bar; // oт 0 до 180
  float online_graph;
  char text[11]; // =строка UTF8 оканчивающаяся нулем

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////