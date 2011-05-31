#!/usr/bin/python

import os, sys
import ctypes

xfoifc_c = ctypes.cdll.LoadLibrary("libXfoInterface.so");


class XfoObj:
	def __init__(self):
		self.pObj = xfoifc_c.xfo_createXfoObject(None)

	def setExitLevel(self, level):
		xfoifc_c.xfo_setExitLevel(self.pObj, level)

	def setDocumentURI(self, uri):
		xfoifc_c.xfo_setDocumentURI(self.pObj, uri)

	def setOutputFilePath(self, path):
		xfoifc_c.xfo_setOutputFilePath(self.pObj, path)

	def execute(self):
		return xfoifc_c.xfo_execute(self.pObj)

if __name__=="__main__":
	xfo = XfoObj()
	xfo.setExitLevel(4)
	xfo.setDocumentURI(sys.argv[1])
	xfo.setOutputFilePath(sys.argv[2])
	xfo.execute()
	print "Finished."

