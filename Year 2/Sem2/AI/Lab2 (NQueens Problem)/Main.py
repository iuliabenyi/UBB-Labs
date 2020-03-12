# -*- coding: utf-8 -*-
"""
Created on Sun Mar  8 11:47:39 2020

@author: Iulia
"""

from Controller import Controller
from UI import UI

n = int(input("n = "))
ctrl = Controller(n)
ui = UI(ctrl)
ui.menu()