#!/usr/bin/python

import os, sys
from ctypes import *

xfo = cdll.LoadLibrary("libXfoInterface.so")


class XfoObj:
	def __init__(self):
		self.pObj = xfo.xfo_createXfoObject(None)

	def getFormatterType(self):
		return xfo.xfo_getFormatterType(self.pObj)

	def setFormatterType(self, xfo_type):
		xfo.xfo_setFormatterType(self.pObj, xfo_type)

	def setDocumentURI(self, uri):
		xfo.xfo_setDocumentURI(self.pObj, uri)

	def setStylesheetURI(self, uri):
		xfo.xfo_setStylesheetURI(self.pObj, uri)

	def addUserStylesheetURI(self, uri):
		xfo.xfo_addUserStylesheetURI(self.pObj, uri)

	def setOutputFilePath(self, path):
		xfo.xfo_setOutputFilePath(self.pObj, path)

	def setOptionFileURI(self, uri):
		xfo.xfo_setOptionFileURI(self.pObj, uri)

	def addOptionFileUri(self, uri):
		xfo.xfo_addOptionFileURI(self.pObj, uri)

	def getOptionFileCount(self):
		return xfo.xfo_getOptionFileCount(self.pObj)

	def setOutputFOPath(self, path):
		xfo.xfo_setOutputFOPath(self.pObj, path)

	def setExternalXSLT(self, command):
		xfo.xfo_setExternalXSLT(self.pObj, command)

	def setBaseURI(self, base):
		xfo.xfo_setBaseURI(self.pObj, base)

	def setXSLTParamFormat(self, param_fmt):
		xfo.xfo_setXSLTParamFormat(self.pObj, param_fmt)

	def getStartPage(self):
		return xfo.xfo_getStartPage(self.pObj)

	def setStartPage(self, page):
		xfo.xfo_setStartPage(self.pObj, page)

	def getEndPage(self):
		return xfo.xfo_getEndPage(self.pObj)

	def setEndPage(self, page):
		xfo.xfo_setEndPage(self.pObj, page)

	def setPdfMasterPassword(self, passwd):
		xfo.xfo_setPdfMasterPassword(self.pObj, passwd)

	def setPdfOwnerPassword(self, passwd):
		xfo.xfo_setPdfOwnerPassword(self.pObj, passwd)

	def setPdfUserPassword(self, passwd):
		xfo.xfo_setPdfUserPassword(self.pObj, passwd)

	def getExitLevel(self):
		return xfo.xfo_getExitLevel(self.pObj)

	def setExitLevel(self, level):
		xfo.xfo_setExitLevel(self.pObj, level)

	def getErrorLevel(self):
		return xfo.xfo_getErrorLevel(self.pObj)

	def getErrorCode(self):
		return xfo.xfo_getErrorCode(self.pObj)

	def execute(self):
		return xfo.xfo_execute(self.pObj)

	def setXSLTParam(self, name, value):
		xfo.xfo_setXSLTParam(self.pObj, name, value)

	def getErrorStreamType(self):
		return xfo.xfo_getErrorStreamType(self.pObj)

	def setErrorStreamType(self, stream_type):
		xfo.xfo_setErrorStreamType(self.pObj, stream_type)

	def setPrinterName(self, printer):
		xfo.xfo_setPrinterName(self.pObj, printer)

	def getFormattedPages(self):
		return xfo.xfo_getFormattedPages(self.pObj)

	def getBatchPrint(self):
		return xfo.xfo_getBatchPrint(self.pObj)

	def setBatchPrint(self, mode):
		xfo.xfo_setBatchPrint(self.pObj, mode)

	def setDocumentText(self, text):
		xfo.xfo_setDocumentText(self.pObj, text)

if __name__=="__main__":
	xfoObj = XfoObj()
	xfoObj.setExitLevel(4)
	xfoObj.setDocumentURI(sys.argv[1])
	xfoObj.setOutputFilePath(sys.argv[2])
	xfoObj.execute()
	print "Finished."

