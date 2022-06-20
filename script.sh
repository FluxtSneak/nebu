#!/bin/bash
mkdir /etc/nebula
mv h1.crt /etc/nebula
mv h1.key /etc/nebula
cd /etc/nebula
wget https://raw.githubusercontent.com/FluxtSneak/nebu/master/config.yaml
wget https://raw.githubusercontent.com/FluxtSneak/nebu/master/nebula
wget https://raw.githubusercontent.com/FluxtSneak/nebu/master/ca.crt
chmod 700 nebula
mkdir /var/log/nebula
touch /var/log/nebula/nebula.log
./nebula -config config.yaml | tee -a /var/log/nebula/nebula.log &