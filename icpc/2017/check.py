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


def main():
    py_path = sys.argv[1]
    cpp_path = sys.argv[2]
    check(py_path, cpp_path)


if __name__ == "__main__":
    main()
