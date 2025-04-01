# HID-NetAudit

🛡️ HID-NetAudit — это автономный PowerShell HID-скрипт, запускаемый с USB-устройства (на базе ATmega32u4 с SD-картой), предназначенный для локального аудита сетевых соединений, портов и процессов на Windows-машинах **без прав администратора**.

---

## 📦 Состав проекта

| Файл           | Назначение                                    |
|----------------|-----------------------------------------------|
| `HID-NetAudit.ino` | Arduino-скетч для ATmega32u4 с HID и SD |
| `script.txt`       | PowerShell-команды для анализа сети       |
| `README.md`        | Документация                             |

---

## 🧠 Архитектура

USB HID (ATmega32u4) ↓ Keyboard input ↓ Запуск PowerShell ↓ Выполнение script.txt ↓ → IP и порты → Таблица PID/процессы → Проверка RDP и Listen


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

📋 Вывод:

Local IPs: 192.168.1.7

ESTABLISHED CONNECTIONS 8.8.8.8 443 4128 chrome ✅ 185.44.12.11 5555 7732 suspapp.exe ✅

LISTENING PORTS CHECK 445 4 System Trusted ✅ 5555 8890 unknown.exe ⚠ Unknown ⚠


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

---

## 🖼 Иконка проекта

![HID-NetAudit Icon](./docs/icon.png)
