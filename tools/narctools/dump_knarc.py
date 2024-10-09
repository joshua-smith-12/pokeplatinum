#!/usr/bin/python3
import os
import sys
import shutil
import subprocess

if len(sys.argv) < 4:
    print("Usage: dump_knarc.py [knarc path] [source file] [dest folder]")
    sys.exit(-1)

knarc = sys.argv[1]
source = sys.argv[2]
dest = sys.argv[3]

if not os.path.exists(dest):
    os.mkdir(dest)

if source.endswith(".narc"):
    print(f"Calling knarc for conversion {source}->{dest}")
    subprocess.run([knarc, "-d", dest, "-u", source])
