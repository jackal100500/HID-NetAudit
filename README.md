# HID-NetAudit

🛡️ HID-NetAudit is a standalone PowerShell HID script running from a USB device (based on ATmega32u4 with SD card) designed for local auditing of network connections, ports and processes on Windows machines **without administrator rights**.

🛡️ HID-NetAudit — это автономный PowerShell HID-скрипт, запускаемый с USB-устройства (на базе ATmega32u4 с SD-картой), предназначенный для локального аудита сетевых соединений, портов и процессов на Windows-машинах **без прав администратора**.

---

## ⚙️ Technical Description

### 🧠 What the script does

- Runs PowerShell via Win+R
- Checks IP addresses of local interfaces
- Analyzes active `Established' TCP connections
  - Identifies external IP addresses
  - Outputs PID, process name
  - Highlights processes by category: trusted / known / unknown
- Scans open `LISTEN` ports
  - Compares with whitelist (80, 443, 135, 139, 445, 3389)
  - Outputs PID + process name
  - Highlights suspicious processes
- Ends execution with a pause

### 🧠 Что делает скрипт

- Запускает PowerShell через Win+R
- Проверяет IP-адреса локальных интерфейсов
- Анализирует активные `Established` TCP-соединения
  - Определяет внешние IP-адреса
  - Выводит PID, имя процесса
  - Подсвечивает процессы по категории: trusted / known / unknown
- Сканирует открытые `LISTEN`-порты
  - Сравнивает с белым списком (80, 443, 135, 139, 445, 3389)
  - Выводит PID + имя процесса
  - Подсвечивает подозрительные процессы
- Завершает выполнение паузой

---

## 🔍 Example output

```plaintext
Local IPs: 192.168.1.10

ESTABLISHED CONNECTIONS
8.8.8.8         443    3120   chrome          ✅
212.45.66.1     445    4444   unknown.exe     ✅

LISTENING PORTS CHECK
445   4      System           Trusted ✅
5555  1111   backdoor         ⚠ Unknown �
