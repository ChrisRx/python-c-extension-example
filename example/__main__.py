#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

import _modulename


def main():
    try:
        e = _modulename.ExampleObj()
        print(e.something(sys.argv[1]))
    except KeyboardInterrupt:
        sys.exit(1)


if __name__ == '__main__':
    if not len(sys.argv) > 1:
        sys.stderr.write("Missing arguments\n")
        sys.exit(0)
    main()
