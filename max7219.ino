#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Xác định loại phần cứng, kích thước và các chân đầu ra:
#define HARDWARE_TYPE MD_MAX72XX :: FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3
#define GENERIC_HW 1
// Tạo một phiên bản mới của lớp MD_Parola với kết nối SPI phần cứng:
MD_Parola myDisplay = MD_Parola (HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Thiết lập SPI phần mềm:
// #define DATA_PIN 2
// #define CLK_PIN 4
// MD_Parola myDisplay = MD_Parola (HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup () {
  // Intialize đối tượng:
  myDisplay.begin ();
  // Đặt cường độ (độ sáng) của màn hình (0-15):
  myDisplay.setIntensity (15);
  // Xóa màn hình:u
  myDisplay.displayClear (); 
  myDisplay.displayText ("YRASEVINNA SRAEY 04 SITTIB BAL EHT", PA_CENTER, 100, 0, PA_SCROLL_RIGHT, PA_SCROLL_RIGHT);
}

void loop () {
  if (myDisplay.displayAnimate ()) {
    myDisplay.displayReset ();
  }
}
