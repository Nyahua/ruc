# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import random

def roll_die():
    return random.choice(range(1, 7))

def check_pascal(num_trails):
    num_wins = 0
    for i in range(num_trails):
        d1 = roll_die()
        d2 = roll_die()
        if d1==6 and d2==6:
            num_wins += 1
            break
    print(f"Probality of winning: = {num_wins / num_trails}")

num_trails = 10000
check_pascal(num_trails)