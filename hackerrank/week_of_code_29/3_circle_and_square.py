#!/bin/python3
import sys
import math

def eucl_dist(xc, yc, x1, y1):
    return math.sqrt((xc-x1)**2 + (yc-y1)**2)

def is_shaded_for_circle(xc, yc, r, x1, y1):
    return eucl_dist(xc, yc, x1, y1) <= r

def is_shaded_for_square():
    return False

def hash_or_dot(xc, yc, r, x1, y1):
    if is_shaded_for_circle(xc, yc, r, x1, y1) or is_shaded_for_square():
        return '#'
    else:
        return '.'

w,h = input().strip().split(' ')
w,h = [int(w),int(h)]
circleX,circleY,r = input().strip().split(' ')
circleX,circleY,r = [int(circleX),int(circleY),int(r)]
x1,y1,x3,y3 = input().strip().split(' ')
x1,y1,x3,y3 = [int(x1),int(y1),int(x3),int(y3)]
output = ""

for x_i in range(w):
    for y_i in range(h):
        if y_i == h-1:
            output += "\n"
        output += hash_or_dot(circleX, circleY, r, x_i, y_i)

print(output)
