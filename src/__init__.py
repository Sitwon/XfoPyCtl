#!/usr/bin/python

import os, sys
import ctypes

xfoifc_c = ctypes.cdll.LoadLibrary("libXfoInterface.so");


class XfoObj:
	def __init__(self):
		self.pObj = xfoifc_c.xfo_createXfoObject(None)

	def getFormatterType(self):
		return xfoifc_c.xfo_getFormatterType(self.pObj)

	def setFormatterType(self, xfo_type):
		xfoifc_c.xfo_setFormatterType(self.pObj, xfo_type)

	def setDocumentURI(self, uri):
		xfoifc_c.xfo_setDocumentURI(self.pObj, uri)

	def setStylesheetURI(self, uri):
		xfoifc_c.xfo_setStylesheetURI(self.pObj, uri)

	def addUserStylesheetURI(self, uri):
		xfoifc_c.xfo_addUserStylesheetURI(self.pObj, uri)

	def setOutputFilePath(self, path):
		xfoifc_c.xfo_setOutputFilePath(self.pObj, path)

	def setOptionFileURI(self, uri):
		xfoifc_c.xfo_setOptionFileURI(self.pObj, uri)

	def addOptionFileUri(self, uri):
		xfoifc_c.xfo_addOptionFileURI(self.pObj, uri)

	def getOptionFileCount(self):
		return xfoifc_c.xfo_getOptionFileCount(self.pObj)

	def setOutputFOPath(self, path):
		xfoifc_c.xfo_setOutputFOPath(self.pObj, path)

	def setExternalXSLT(self, command):
		xfoifc_c.xfo_setExternalXSLT(self.pObj, command)

	def setBaseURI(self, base):
		xfoifc_c.xfo_setBaseURI(self.pObj, base)

	def setXSLTParamFormat(self, param_fmt):
		xfoifc_c.xfo_setXSLTParamFormat(self.pObj, param_fmt)

	def getStartPage(self):
		return xfoifc_c.xfo_getStartPage(self.pObj)

	def setStartPage(self, page):
		xfoifc_c.xfo_setStartPage(self.pObj, page)

	def getEndPage(self):
		return xfoifc_c.xfo_getEndPage(self.pObj)

	def setEndPage(self, page):
		xfoifc_c.xfo_setEndPage(self.pObj, page)

	def setPdfMasterPassword(self, passwd):
		xfoifc_c.xfo_setPdfMasterPassword(self.pObj, passwd)

	def setPdfOwnerPassword(self, passwd):
		xfoifc_c.xfo_setPdfOwnerPassword(self.pObj, passwd)

	def setPdfUserPassword(self, passwd):
		xfoifc_c.xfo_setPdfUserPassword(self.pObj, passwd)

	def getExitLevel(self):
		return xfoifc_c.xfo_getExitLevel(self.pObj)

	def setExitLevel(self, level):
		xfoifc_c.xfo_setExitLevel(self.pObj, level)

	def getErrorLevel(self):
		return xfoifc_c.xfo_getErrorLevel(self.pObj)

	def getErrorCode(self):
		return xfoifc_c.xfo_getErrorCode(self.pObj)

	def execute(self):
		return xfoifc_c.xfo_execute(self.pObj)

	def setXSLTParam(self, name, value):
		xfoifc_c.xfo_setXSLTParam(self.pObj, name, value)

	def getErrorStreamType(self):
		return xfoifc_c.xfo_getErrorStreamType(self.pObj)

	def setErrorStreamType(self, stream_type):
		xfoifc_c.xfo_setErrorStreamType(self.pObj, stream_type)

	def setPrinterName(self, printer):
		xfoifc_c.xfo_setPrinterName(self.pObj, printer)

	def getFormattedPages(self):
		return xfoifc_c.xfo_getFormattedPages(self.pObj)

	def getBatchPrint(self):
		return xfoifc_c.xfo_getBatchPrint(self.pObj)

	def setBatchPrint(self, mode):
		xfoifc_c.xfo_setBatchPrint(self.pObj, mode)

	def setDocumentText(self, text):
		xfoifc_c.xfo_setDocumentText(self.pObj, text)

if __name__=="__main__":
	xfo = XfoObj()
	xfo.setExitLevel(4)
	xfo.setDocumentURI(sys.argv[1])
	xfo.setOutputFilePath(sys.argv[2])
	xfo.execute()
	print "Finished."

