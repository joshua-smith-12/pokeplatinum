#!/usr/bin/python3
import os
import sys
import shutil

if len(sys.argv) < 3:
    print("Usage: rename_nitrogfx.py [source folder] [dest folder]")
    sys.exit(-1)

source = sys.argv[1]
dest = sys.argv[2]

if not os.path.exists(dest):
    os.mkdir(dest)

all_headers = []
for file in os.listdir(source):
    filename = os.fsdecode(file)
    if filename.endswith(".bin"):
        target = os.path.join(source, filename)
        with open(target, mode="rb") as f:
            header = f.read(4)
        try:
            target_type = header[::-1].decode('utf-8')
            shutil.copyfile(target, os.path.join(dest, filename.replace(".bin", "." + target_type)))
            print(f"Renamed file from {source}->{dest}")
        except:
            print(f"Unknown header type on file {filename}.")
            shutil.copyfile(target, os.path.join(dest, filename))