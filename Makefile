love-o-meter: love-o-meter/love-o-meter.ino buildinfo.sh
	sh buildinfo.sh love-o-meter
	arduino-cli compile \
		-p /dev/ttyACM0 \
		-u \
		--fqbn arduino:avr:uno \
		--output-dir love-o-meter/.build \
		love-o-meter

spaceship: spaceship/spaceship.ino
	arduino-cli compile \
		-p /dev/ttyACM0 \
		-u \
		--fqbn arduino:avr:uno \
		--output-dir spaceship/.build \
		spaceship

monitor:
	stty -F /dev/ttyACM0 9600
	cat /dev/ttyACM0

.PHONY: love-o-meter spaceship monitor
