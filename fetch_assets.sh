#!/bin/env bash

mkdir -p assets
wget https://launcher.mojang.com/v1/objects/465378c9dc2f779ae1d6e8046ebc46fb53a57968/client.jar -O /tmp/mc.jar
unzip -j /tmp/mc.jar "textures/blocks/*.png" -d assets/
rm /tmp/mc.jar
