import os
import sys
import pathlib
import time
import collections
import itertools
import shutil
import pickle
import inspect
import json
import subprocess
import logging


def check(py_path, cpp_path):
    with open(py_path, "r") as f:
        pytexts = f.readlines()
    with open(cpp_path, "r") as f:
        cpptexts = f.readlines()

    for idx, py_ans in enumerate(pytexts):
        cpp_ans = cpptexts[idx]
        if(py_ans != cpp_ans):
            print(idx, "py=", py_ans, "cpp=", cpp_ans)

def split(in_path):
    with open(in_path, "r") as f:
        pytexts = f.readlines()

    num = 0
    for idx, pytext in enumerate(pytexts):
        if(len(pytext.split())==2):
            num += 1
            print(f" ------ {num} --------")
        print(pytext)

def main():
    py_path = sys.argv[1]
    cpp_path = sys.argv[2]
    check(py_path, cpp_path)
    # check(py_path)
    # split(py_path)


if __name__ == "__main__":
    main()
