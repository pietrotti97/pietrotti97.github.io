#!/bin/sh
PAFFS=/sys/devices/platform/gpio-leds/leds
while true;
do
	if ping 1.1.1.1 -c 1 -w 1
	then 
	        echo 1 >$PAFFS/AGPF-S0:green:internet/brightness
		echo 0 >$PAFFS/AGPF-S0:red:internet/brightness
	else
		echo 0 >$PAFFS/AGPF-S0:green:internet/brightness
        	echo 1 >$PAFFS/AGPF-S0:red:internet/brightness
	fi
	sleep 1
done
