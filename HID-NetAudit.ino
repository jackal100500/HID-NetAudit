// === ATmega32u4 HID-скрипт с SD-картой для запуска PowerShell и проверки IP/портов ===
// УСТОЙЧИВЫЙ, НАДЁЖНЫЙ, С ПОСИМВОЛЬНОЙ ПЕЧАТЬЮ

#include <SPI.h>
#include <SD.h>
#include <Keyboard.h>

File myFile;
const int chipSelect = 4;
const char* DEFAULT_FILE_NAME = "script.txt";

// === Символьный ввод с паузой ===
void typeSlow(const String& txt, int delayMs = 20) {
  for (size_t i = 0; i < txt.length(); ++i) {
    Keyboard.print(txt[i]);
    delay(delayMs);
  }
}

// === Обработка одной строки ===
void executeLine(String l) {
  l.trim();
  if (l.length() == 0) return;

  int spaceIndex = l.indexOf(' ');
  String command = spaceIndex == -1 ? l : l.substring(0, spaceIndex);
  String argument = spaceIndex == -1 ? "" : l.substring(spaceIndex + 1);
  command.toUpperCase();

  if (command == "STRING") {
    typeSlow(argument);
  } else if (command == "DELAY") {
    delay(argument.toInt());
  } else if (command == "ENTER") {
    Keyboard.write(KEY_RETURN);
  } else if (command == "REM") {
    // комментарий
  } else {
    // Нажатие спец-кнопки (расширяемость)
    Keyboard.press(command[0]);
    delay(100);
    Keyboard.releaseAll();
  }
  Keyboard.releaseAll();
  delay(200);
}

void setup() {
  Keyboard.begin();
  delay(500);

  // Запускаем окно "Выполнить" через Win+R
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(500);

  // Печатаем "powershell" и жмём Enter
  typeSlow("powershell");
  Keyboard.write(KEY_RETURN);
  delay(800);

  if (!SD.begin(chipSelect)) return;
  myFile = SD.open(DEFAULT_FILE_NAME);
  if (!myFile) return;

  String line = "";
  while (myFile.available()) {
    char c = myFile.read();
    if (c == '\n') {
      executeLine(line);
      line = "";
    } else if ((int)c != 13) {
      line += c;
    }
  }
  executeLine(line);
  myFile.close();
  Keyboard.end();
}

void loop() {
  // пусто
}
