#!/usr/bin/python3
import os
import sys
import shutil
import subprocess

if len(sys.argv) < 4:
    print("Usage: convert_nitrogfx.py [nitrogfx path] [source folder] [dest folder]")
    sys.exit(-1)

nitrogfx = sys.argv[1]
source = sys.argv[2]
dest = sys.argv[3]

if not os.path.exists(dest):
    os.mkdir(dest)

SUPPORTED = {
    "NCGR": "png",
    "NCLR": "pal",
    "NCPR": "pal",
    "NCER": "json",
    "NANR": "json",
    "NMAR": "json"
}

for file in os.listdir(source):
    filename = os.fsdecode(file)
    found = False
    for extension in SUPPORTED:
        if filename.endswith("." + extension):
            target = os.path.join(source, filename)
            result = os.path.join(dest, filename.replace("." + extension, "." + SUPPORTED[extension]))
            print(f"Calling nitrogfx for conversion {target}->{result}")
            subprocess.run([nitrogfx, target, result])
            found = True
            break
    if not found:
        print(f"The file {filename} has an unsupported extension type!")
