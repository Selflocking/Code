#!/usr/bin/python3
import glob
import os

files = glob.glob("./**/*.cpp",recursive=True)

for i in files:
    os.system(f"clang-format --style=file -i \"%s\""%i)

print(f"format %d files"%len(files))
