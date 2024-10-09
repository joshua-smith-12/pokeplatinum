#!/usr/bin/python3
import os
import sys
import shutil
import subprocess

if len(sys.argv) < 3:
    print("Usage: decompress_nitrogfx.py [nitrogfx path] [target folder]")
    sys.exit(-1)

nitrogfx = sys.argv[1]
source = sys.argv[2]

SUPPORTED = ["NCGR", "NCLR", "NCPR", "NCER", "NANR", "NMAR"]

for file in os.listdir(source):
    filename = os.fsdecode(file)
    if filename.endswith(".bin"):
        target = os.path.join(source, filename)
        with open(target, mode="rb") as f:
            header = f.read(4)
        try:
            target_type = header[::-1].decode('utf-8')
            if not target_type in SUPPORTED:
                raise Exception("this will get caught")
        except:
            lz_target = os.path.join(source, filename.replace(".bin", ".lz"))
            try:
                os.rename(target, lz_target)
                subprocess.run([nitrogfx, lz_target, target])
                os.remove(lz_target)
                print(f"Successfully decompressed {filename} with LZMA decompression.")
            except:
                print(f"LZMA decompression not effective for target {filename}, other compressions not yet supported.")
                os.rename(lz_target, target)
