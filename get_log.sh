avrdude -c avrispv2 -P /dev/ttyACM0 -p t85 -U eeprom:r:log.hex:i
python3 ihex2txt.py log.hex
cat log.txt
