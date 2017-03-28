#!/bin/python3
a_scores = map(int, input().strip().split(' '))
b_scores = map(int, input().strip().split(' '))

a_points = 0
b_points = 0
for a_score, b_score in zip(a_scores, b_scores):
    if a_score > b_score:
        a_points += 1
    elif b_score > a_score:
        b_points += 1
        
print(a_points, b_points)
