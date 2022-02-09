#!/bin/bash
#! This script is used for giving the sensor port permissions for ITU ODV

chmod a+rw /dev/ttyACM1
chmod a+rw /dev/ttyACM2
chmod a+rw /dev/tty/USB0
echo "Perms are given"
