from ctypes import *
dll = cdll.LoadLibrary("./ab.dll")
func = dll.calculateCircleArea

func.argtypes = [c_double]
func.restype= c_double
print(func(1))
