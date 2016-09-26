#!/bin/python3
import math

lines = int(input())
for i in range(lines):
    cuts = int(input())
    cuts_horizontal = math.floor(cuts/2)
    cuts_vertical = math.ceil(cuts/2)
    print(cuts_horizontal * cuts_vertical)
