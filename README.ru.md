# HID-NetAudit 🇷🇺 

🛡️ HID-NetAudit — это автономный PowerShell HID-скрипт, запускаемый с USB-устройства (на базе ATmega32u4 с SD-картой), предназначенный для локального аудита сетевых соединений, портов и процессов на Windows-машинах **без прав администратора**.

---

## 📦 Состав проекта

| Файл           | Назначение                                    |
|----------------|-----------------------------------------------|
| `HID-NetAudit.ino` | Arduino-скетч для ATmega32u4 с HID и SD |
| `script.txt`       | PowerShell-команды для анализа сети       |
| `README.md`        | Документация на английском                        |
| `README.ru.md`      | Документация на русском                          |

---

## 🧰 Используемое оборудование

Для запуска HID-NetAudit использовалась простая и доступная сборка на базе Arduino:

| Компонент             | Описание                                                                              |
|-------------------------|---------------------------------------------------------------------------------------|
| 🔌 **ATmega32u4 HID** | Отладочная плата с чипом ATmega32u4 и встроенной поддержкой USB HID + microSD-слот   |
| 💾 **SD-карта**       | Любая microSD-карта (формат FAT32)                         |

📦 Отладочная плата с чипом ATmega32u4 на Aliexpress:  
[➡️ ATmega32u4 с SD-слотом (AliExpress)](https://www.aliexpress.com/item/1005007171805928.html?spm=a2g0o.order_list.order_list_main.100.53a61802Hqjcdt)

💡 Подключается напрямую к USB и работает без драйверов.  
SD-карта используется для хранения `script.txt`, который HID-устройство вводит как клавиатура.

![HID-NetAudit Icon](./docs/ATmega32u4.png)

---

## 🧠 Архитектура процесса

🖥 USB HID (ATmega32u4)  
⬇️  
⌨️ Keyboard input (эмуляция ввода)  
⬇️  
💻 Запуск PowerShell  
⬇️  
📄 Выполнение `script.txt`  
⬇️  
📡 Получение IP  
📊 Таблица соединений  
🛡 Проверка RDP / портов

---

## 🎮 Arduino-скетч `HID-NetAudit.ino`

Скетч:

- Использует `Keyboard.h`, `SD.h`
- После загрузки автоматически вызывает PowerShell (`Win+R → powershell`)
- Считывает и исполняет `script.txt` с SD-карты
- Эмулирует по-символьный ввод PowerShell-команд
- Не требует привилегий на целевом ПК

📎 Подходит для:
- Arduino Leonardo
- Teensy 2.0++
- Любое устройство с HID и SD

---

## ⚡ PowerShell-скрипт `script.txt`

Основные функции:

- 🌐 Получение локального IP
- 🔗 Анализ активных TCP-соединений (`Established`)
  - PID + имя процесса
  - Внешние IP выделяются
  - Цветовая подсветка: system / known / unknown
- 🔎 Скан `LISTEN` портов
  - Сравнение с белым списком
  - Подсветка подозрительных
- 🔐 Проверка RDP (настраивается)
- 🧩 Не требует PowerShell-модулей

📋 Example Output:

```plaintext
Local IPs: 192.168.1.10

ESTABLISHED CONNECTIONS
8.8.8.8         443    3120   chrome          
212.45.66.1     445    4444   unknown.exe     

LISTENING PORTS CHECK
445   4      System           Trusted 
5555  1111   backdoor         ⚠ Unknown ⚠

```
Example output ESTABLISHED CONNECTIONS:

![HID-NetAudit Icon](./docs/im1.png)

Example output LISTENING PORTS CHECK:

![HID-NetAudit Icon](./docs/im2.png)

---

## 🛡 Назначение

- 💻 Быстрый локальный аудит системы
- 🔐 Безопасная проверка сети без логов
- 🔍 SOC/BlueTeam анализ при инциденте
- 📚 Обучение и демонстрации

---

## 🚨 Юридическое

> Проект разработан **исключительно для целей аудита и обучения**.  
> Использование без разрешения может нарушать локальное законодательство.

---

## 🖼 Иконка проекта

![HID-NetAudit Icon](./docs/icon.png)

🇬🇧 [Read in English](./README.md)
