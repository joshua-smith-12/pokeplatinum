#!/usr/bin/python3
import os
import sys
import shutil
import subprocess

if len(sys.argv) < 5:
    print("Usage: dump_to_sources.py [knarc path] [nitrogfx path] [source folder] [dest folder]")
    sys.exit(-1)

knarc = sys.argv[1]
nitrogfx = sys.argv[2]
source = sys.argv[3]
dest = sys.argv[4]

if not os.path.exists(dest):
    os.mkdir(dest)

subprocess.run(["./tools/narctools/dump_knarc.py", knarc, source, dest + "/source"])
subprocess.run(["./tools/narctools/decompress_nitrogfx.py", nitrogfx, dest + "/source"])
subprocess.run(["./tools/narctools/rename_nitrogfx.py", dest + "/source", dest + "/named"])
subprocess.run(["./tools/narctools/convert_nitrogfx.py", nitrogfx, dest + "/named", dest])