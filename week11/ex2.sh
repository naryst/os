#!/usr/bin/bash
sudo mkdir -p lofsdisk/bin
sudo mkdir -p lofsdisk/lib64
sudo mkdir -p lofsdisk/usr/lib
sudo mkdir -p lofsdisk/usr/lib64

sudo cp /bin/bash lofsdisk/bin
sudo cp /bin/ls lofsdisk/bin
sudo cp /bin/cat lofsdisk/bin
sudo cp /bin/echo lofsdisk/bin

sudo ldd /bin/bash | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
sudo ldd /bin/ls | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
sudo ldd /bin/cat | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
sudo ldd /bin/echo | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}

sudo cp lofsdisk/usr/lib64/* lofsdisk/lib64

echo Nikita > lofsdisk/file1
echo Sergeev > lofsdisk/file2

gcc ex2.c -o ex2.out
sudo cp ex2.out lofsdisk
sudo chroot lofsdisk /ex2.out > ex2.txt
./ex2.out >> ex2.txt
