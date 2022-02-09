#!/bin/bash
#! This script use for open cominication port for
#! ITU AGV robot's Maxon Epos 70/11 motor drivers
#! shell script for linking /dev/ttyUSB0 to dev/ttyS2

chmod a+rw /dev/ttyUSB0
chmod a+rw /dev/ttyUSB1
chmod a+rw /dev/ttyUSB2
 echo "permissions given."
rm /dev/ttyS2
ln -s /dev/ttyUSB0 /dev/ttyS2

echo "Linking succesful: /dev/ttyUSB0 --> /dev/ttyS2"