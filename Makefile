project := love-o-meter
fqbn := arduino:avr:uno
port := /dev/ttyACM0
baud := 9600

build: buildinfo.sh
	@echo "=== COMPILING" $(project)
	sh buildinfo.sh $(project)
	arduino-cli compile \
		--fqbn $(fqbn) \
		--output-dir $(project)/.build \
		$(project)

upload:
	@echo "=== UPLOADING" $(project)
	arduino-cli upload \
		--fqbn $(fqbn) \
		-p $(port) \
		--input-dir $(project)/.build

clean:
	rm -rf $(project)/.build

monitor:
	stty -F $(port) $(baud)
	cat $(port)

.PHONY: build upload clean monitor
