import os
from pathlib import Path

filepath = Path(__file__).parent/"蓝桥杯辅导课.txt"
dirpath = Path(__file__).parent/"touch"
os.mkdir(dirpath)
os.chdir(dirpath)
with open(filepath, "r", encoding="utf-8") as f:
    lines = f.readlines()
    p = dirpath
    for line in lines:
        if line.startswith("AcWing "):
            filename = line.strip() + ".cpp"
            with open(filename, "w"):
                pass
        elif line.startswith("第"):
            p = dirpath
            os.chdir(p)
            p = p/line.strip()
            os.mkdir(p)
            os.chdir(p)
        else:
            os.chdir(p)
            os.mkdir(line.strip())
            os.chdir(line.strip())
