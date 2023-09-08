love-o-meter: love-o-meter/love-o-meter.ino buildinfo.sh
	sh buildinfo.sh love-o-meter
	arduino-cli compile -p /dev/ttyACM0 --fqbn arduino:avr:uno -u love-o-meter

spaceship: spaceship/spaceship.ino
	arduino-cli compile -p /dev/ttyACM0 --fqbn arduino:avr:uno -u spaceship

monitor:
	stty -F /dev/ttyACM0 9600
	cat /dev/ttyACM0

.PHONY: monitor
