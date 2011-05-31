#!/usr/bin/python

import os, sys
import ctypes

xfoifc_c = ctypes.cdll.LoadLibrary("libXfoInterface.so");


class XfoObj:
	def __init__(self):
		self.pObj = xfoifc_c.xfo_createXfoObject(None)

	def getErrorCode(self):
		return xfoifc_c.xfo_getErrorCode(self.pObj)

	def setBatchPrint(self, mode):
		xfoifc_c.xfo_setBatchPrint(self.pObj, mode)

	def setPrinterName(self, printer):
		xfoifc_c.xfo_setPrinterName(self.pObj, printer)

	def setErrorStreamType(self, stream_type):
		xfoifc_c.xfo_setErrorStreamType(self.pObj, stream_type)

	def setExitLevel(self, level):
		xfoifc_c.xfo_setExitLevel(self.pObj, level)

	def setDocumentURI(self, uri):
		xfoifc_c.xfo_setDocumentURI(self.pObj, uri)

	def setDocumentText(self, text):
		xfoifc_c.xfo_setDocumentText(self.pObj, text)

	def setStylesheetURI(self, uri):
		xfoifc_c.xfo_setStylesheetURI(self.pObj, uri)

	def setOutputFOPath(self, path):
		xfoifc_c.xfo_setOutputFOPath(self.pObj, path)

	def setOutputFilePath(self, path):
		xfoifc_c.xfo_setOutputFilePath(self.pObj, path)

	def setExternalXSLT(self, command):
		xfoifc_c.xfo_setExternalXSLT(self.pObj, command)

	def setXSLTParamFormat(self, param_fmt):
		xfoifc_c.xfo_setXSLTParamFormat(self.pObj, param_fmt)

	def execute(self):
		return xfoifc_c.xfo_execute(self.pObj)

if __name__=="__main__":
	xfo = XfoObj()
	xfo.setExitLevel(4)
	xfo.setDocumentURI(sys.argv[1])
	xfo.setOutputFilePath(sys.argv[2])
	xfo.execute()
	print "Finished."

