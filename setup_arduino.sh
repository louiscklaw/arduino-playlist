#!/usr/bin/env bash

set -ex

sudo apt-get install -y aria2

cd /tmp
  aria2c -x 16 -s 99999  https://downloads.arduino.cc/arduino-1.8.13-linux64.tar.xz

  tar -xvf arduino-1.8.13-linux64.tar.xz

  rsync -avh arduino-1.8.13/ /home/logic/.arduino-ide
cd -


cd /home/logic/.arduino-ide
  sudo ./install.sh
cd -