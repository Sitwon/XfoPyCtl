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
		xfo.xfo_setFormatterType.argtypes = [c_void_p, c_int]
		xfo.xfo_setFormatterType(self.pObj, xfo_type)

	def getDocumentURI(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getDocumentURI.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getDocumentURI.restype = c_char_p
		return xfo.xfo_getDocumentURI(self.pObj, cstr, 1024)

	def setDocumentURI(self, uri):
		xfo.xfo_setDocumentURI.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setDocumentURI(self.pObj, uri)

	def getStylesheetURI(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getStylesheetURI.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getStylesheetURI.restype = c_char_p
		return xfo.xfo_getStylesheetURI(self.pObj, cstr, 1024)

	def setStylesheetURI(self, uri):
		xfo.xfo_setStylesheetURI.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setStylesheetURI(self.pObj, uri)

	def addUserStylesheetURI(self, uri):
		xfo.xfo_adduserStylesheetURI.argtypes = [c_void_p, c_char_p]
		xfo.xfo_addUserStylesheetURI(self.pObj, uri)

	def getStylesheetTitle(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getStylesheetTitle.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getStylesheetTitle.restype = c_char_p
		return xfo.xfo_getStylesheetTitle(self.pObj, cstr, 1024)

	def setStylesheetTitle(self, title):
		xfo.xfo_setStylesheetTitle.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setStylesheetTitle(self.pObj, title)

	def getOutputFilePath(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getOutputFilePath.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getOutputFilePath.restype = c_char_p
		return xfo.xfo_getOutputFilePath(self.pObj, cstr, 1024)

	def setOutputFilePath(self, path):
		xfo.xfo_setOutputFilePath.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setOutputFilePath(self.pObj, path)

	def getOptionFileURI(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getOptionFileURI.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getOptionFileURI.restype = c_char_p
		return xfo.xfo_getOptionFileURI(self.pObj, cstr, 1024)

	def setOptionFileURI(self, uri):
		xfo.xfo_.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setOptionFileURI(self.pObj, uri)

	def addOptionFileURI(self, uri):
		xfo.xfo_addOptionFileURI.argtypes = [c_void_p, c_char_p]
		xfo.xfo_addOptionFileURI(self.pObj, uri)

	def getOptionFileCount(self):
		xfo.xfo_getOptionFileCount.restype = c_int
		return xfo.xfo_getOptionFileCount(self.pObj)

	def getOuptutFOPath(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getOuptutFOPath.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getOuptutFOPath.restype = c_char_p
		return xfo.xfo_getOuptutFOPath(self.pObj, cstr, 1024)

	def setOutputFOPath(self, path):
		xfo.xfo_setOutputFOPath.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setOutputFOPath(self.pObj, path)

	def getExternalXSLT(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getExternalXSLT.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getExternalXSLT.restype = c_char_p
		return xfo.xfo_getExternalXSLT(self.pObj, cstr, 1024)

	def setExternalXSLT(self, command):
		xfo.xfo_setExternalXSLT.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setExternalXSLT(self.pObj, command)

	def getBaseURI(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getBaseURI.argtypes = [c_void_p, getBaseURIc_char_p, c_int]
		xfo.xfo_.restype = c_char_p
		return xfogetBaseURI.xfo_(self.pObj, cstr, 1024)

	def setBaseURI(self, base):
		xfo.xfo_setBaseURI.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setBaseURI(self.pObj, base)

	def getXSLTParamFormat(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getXSLTParamFormat.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getXSLTParamFormat.restype = c_char_p
		return xfo.xfo_getXSLTParamFormat(self.pObj, cstr, 1024)

	def setXSLTParamFormat(self, param_fmt):
		xfo.xfo_setXSLTParamFormat.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setXSLTParamFormat(self.pObj, param_fmt)

	def getStartPage(self):
		xfo.xfo_getStartPage.restype = c_long
		return xfo.xfo_getStartPage(self.pObj)

	def setStartPage(self, page):
		xfo.xfo_setStartPage.argtypes = [c_void_p, c_long]
		xfo.xfo_setStartPage(self.pObj, page)

	def getEndPage(self):
		xfo.xfo_getEndPage.restype = c_long
		return xfo.xfo_getEndPage(self.pObj)

	def setEndPage(self, page):
		xfo.xfo_setEndPage.argtypes = [c_void_p, c_long]
		xfo.xfo_setEndPage(self.pObj, page)

	def setPdfMasterPassword(self, passwd):
		xfo.xfo_setPdfMasterPassword.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setPdfMasterPassword(self.pObj, passwd)

	def setPdfOwnerPassword(self, passwd):
		xfo.xfo_setPdfOwnerPassword.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setPdfOwnerPassword(self.pObj, passwd)

	def setPdfUserPassword(self, passwd):
		xfo.xfo_setPdfUserPassword.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setPdfUserPassword(self.pObj, passwd)

	def getExitLevel(self):
		return xfo.xfo_getExitLevel(self.pObj)

	def setExitLevel(self, level):
		xfo.xfo_setExitLevel.argtypes = [c_void_p, c_int]
		xfo.xfo_setExitLevel(self.pObj, level)

	def getErrorLevel(self):
		return xfo.xfo_getErrorLevel(self.pObj)

	def getErrorCode(self):
		return xfo.xfo_getErrorCode(self.pObj)

	def getErrorMessage(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getErrorMessage.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getErrorMessage.restype = c_char_p
		return xfo.xfo_getErrorMessage(self.pObj, cstr, 1024)

	def execute(self):
		return xfo.xfo_execute(self.pObj)

	def clear(self):
		xfo.xfo_clear(self.pObj)

	def setOnMessageProc(self, callback):
		self.onMessageProc_CALLBACK = CFUNCTYPE(None, c_int, c_long, c_char_p)
		self.onMessageProc_callback = self.onMessageProc_CALLBACK(callback)
		xfo.xfo_setOnMessageProc(self.pObj, self.onMessageProc_callback)

	def setOnFormatPageProc(self, callback):
		self.onFormatPageProc_CALLBACK = CFUNCTYPE(None, c_long)
		self.onFormatPageProc_callback = self.onFormatPageProc_CALLBACK(callback)
		xfo.xfo_setOnFormatPageProc(self.pObj, self.onFormatPageProc_callback)

	def setXSLTParam(self, name, value):
		xfo.xfo_setXSLTParam.argtypes = [c_void_p, c_char_p, c_char_p]
		xfo.xfo_setXSLTParam(self.pObj, name, value)

	def clearXSLTParam(self):
		xfo.xfo_clearXSLTParam(self.pObj)

	def getErrorStreamType(self):
		return xfo.xfo_getErrorStreamType(self.pObj)

	def setErrorStreamType(self, stream_type):
		xfo.xfo_setErrorStreamType.argtypes = [c_void_p, c_int]
		xfo.xfo_setErrorStreamType(self.pObj, stream_type)

	def getPrinterName(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getPrinterName.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getPrinterName.restype = c_char_p
		return xfo.xfo_getPrinterName(self.pObj, cstr, 1024)

	def setPrinterName(self, printer):
		xfo.xfo_setPrinterName.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setPrinterName(self.pObj, printer)

	def getFormattedPages(self):
		return xfo.xfo_getFormattedPages(self.pObj)

	def getBatchPrint(self):
		return xfo.xfo_getBatchPrint(self.pObj)

	def setBatchPrint(self, mode):
		xfo.xfo_setBatchPrint.argtypes = [c_void_p, c_long]
		xfo.xfo_setBatchPrint(self.pObj, mode)

	def getDocumentText(self):
		BUFF_SIZE = 100000000
		cstr = create_string_buffer(BUFF_SIZE)
		xfo.xfo_getDocumentText.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getDocumentText.restype = c_char_p
		return xfo.xfo_getDocumentText(self.pObj, cstr, BUFF_SIZE)

	def setDocumentText(self, text):
		xfo.xfo_setDocumentText.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setDocumentText(self.pObj, text)

	def getStylesheetText(self):
		BUFF_SIZE = 100000000
		cstr = create_string_buffer(BUFF_SIZE)
		xfo.xfo_getStylesheetText.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getStylesheetText.restype = c_char_p
		return xfo.xfo_getStylesheetText(self.pObj, cstr, BUFF_SIZE)

	def setStylesheetText(self, text):
		xfo.xfo_setStylesheetText.argtypes = [c_void_p, c_char_p]
		xfo.xfo_setStylesheetText(self.pObj, text)

	def getVersion(self):
		cstr = create_string_buffer(1024)
		xfo.xfo_getVersion.argtypes = [c_void_p, c_char_p, c_int]
		xfo.xfo_getVersion.restype = c_char_p
		return xfo.xfo_getVersion(self.pObj, cstr, 1024)

def onMessage(level, code, message):
	print "Level:", level
	print "Code:", code
	print "Message:", message
	print
	return None

if __name__=="__main__":
	xfoObj = XfoObj()
	xfoObj.setExitLevel(4)
	xfoObj.setDocumentURI(sys.argv[1])
	xfoObj.setOutputFilePath(sys.argv[2])
	xfoObj.setOnMessageProc(onMessage)
	xfoObj.execute()
	print "Finished."

