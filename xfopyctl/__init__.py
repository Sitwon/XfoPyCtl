import os, os.path
import subprocess

def _mostRecentHome():
	home = 'AHF53_64_HOME'
	if os.environ.has_key(home):
		return os.environ[home]
	home = 'AHF53_HOME'
	if os.environ.has_key(home):
		return os.environ[home]
	home = 'AHF52_64_HOME'
	if os.environ.has_key(home):
		return os.environ[home]
	home = 'AHF52_HOME'
	if os.environ.has_key(home):
		return os.environ[home]
	home = 'AHF51_64_HOME'
	if os.environ.has_key(home):
		return os.environ[home]
	home = 'AHF51_HOME'
	if os.environ.has_key(home):
		return os.environ[home]
	home = 'AHF50_64_HOME'
	if os.environ.has_key(home):
		return os.environ[home]
	home = 'AHF50_HOME'
	if os.environ.has_key(home):
		return os.environ[home]
	home = 'AXF43_64_HOME'
	if os.environ.has_key(home):
		return os.environ[home]
	home = 'AXF43_HOME'
	if os.environ.has_key(home):
		return os.environ[home]
	return ''

class XfoObj:
	def __init__(self, path=None):
		self.executable = None
		if path == None:
			if os.name == "nt":
				self.executable = "AHFCmd.exe"
			else:
				self.executable = os.path.join(_mostRecentHome(), "run.sh")
		else:
			self.executable = path
		self.clear()

	def releaseXfoObject(self):
		pass

	def getFormatterType(self):
		flag = '-f'
		try:
			index = self.args.index(flag)
			return self.args[index + 1]
		except:
			return None

	def setFormatterType(self, newVal):
		flag = '-f'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def getDocumentURI(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getDocumentURI.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getDocumentURI.restype = c_char_p
		return self.xfoifc_c.xfo_getDocumentURI(self.pXfoObj, cstr, 1024)

	def setDocumentURI(self, newVal):
		flag = '-d'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def getStylesheetURI(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getStylesheetURI.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getStylesheetURI.restype = c_char_p
		return self.xfoifc_c.xfo_getStylesheetURI(self.pXfoObj, cstr, 1024)

	def setStylesheetURI(self, newVal):
		flag = '-s'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def addUserStylesheetURI(self, newVal):
		self.xfoifc_c.xfo_addUserStylesheetURI(self.pXfoObj, newVal)

	def getStylesheetTitle(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getStylesheetTitle.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getStylesheetTitle.restype = c_char_p
		return self.xfoifc_c.xfo_getStylesheetTitle(self.pXfoObj, cstr, 1024)

	def setStylesheetTitle(self, newVal):
		self.xfoifc_c.xfo_setStylesheetTitle(self.pXfoObj, newVal)

	def getHtmlDefaultCharset(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getHtmlDefaultCharset.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getHtmlDefaultCharset.restype = c_char_p
		return self.xfoifc_c.xfo_getHtmlDefaultCharset(self.pXfoObj, cstr, 1024)

	def setHtmlDefaultCharset(self, newVal):
		flag = '-htmlcs'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def getOutputFilePath(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getOutputFilePath.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getOutputFilePath.restype = c_char_p
		return self.xfoifc_c.xfo_getOutputFilePath(self.pXfoObj, cstr, 1024)

	def setOutputFilePath(self, newVal):
		flag = '-o'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def getOptionFileURI(self, n):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getOptionFileURI.argtypes = [c_void_p, c_char_p, c_int, c_int]
		self.xfoifc_c.xfo_getOptionFileURI.restype = c_char_p
		return self.xfoifc_c.xfo_getOptionFileURI(self.pXfoObj, cstr, 1024, n)

	def setOptionFileURI(self, newVal):
		flag = '-i'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def addOptionFileURI(self, newVal):
		self.xfoifc_c.xfo_addOptionFileURI(self.pXfoObj, newVal)

	def getOptionFileCount(self):
		return self.xfoifc_c.xfo_getOptionFileCount(self.pXfoObj)

	def getOutputFOPath(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getOutputFOPath.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getOutputFOPath.restype = c_char_p
		return self.xfoifc_c.xfo_getOutputFOPath(self.pXfoObj, cstr, 1024)

	def setOutputFOPath(self, newVal):
		self.xfoifc_c.xfo_setOutputFOPath(self.pXfoObj, newVal)

	def getExternalXSLT(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getExternalXSLT.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getExternalXSLT.restype = c_char_p
		return self.xfoifc_c.xfo_getExternalXSLT(self.pXfoObj, cstr, 1024)

	def setExternalXSLT(self, newVal):
		self.xfoifc_c.xfo_setExternalXSLT(self.pXfoObj, newVal)

	def getBaseURI(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getBaseURI.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getBaseURI.restype = c_char_p
		return self.xfoifc_c.xfo_getBaseURI(self.pXfoObj, cstr, 1024)

	def setBaseURI(self, newVal):
		flag = '-base'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def getXSLTParamFormat(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getXSLTParamFormat.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getXSLTParamFormat.restype = c_char_p
		return self.xfoifc_c.xfo_getXSLTParamFormat(self.pXfoObj, cstr, 1024)

	def setXSLTParamFormat(self, newVal):
		self.xfoifc_c.xfo_setXSLTParamFormat(self.pXfoObj, newVal)

	def getStartPage(self):
		return self.xfoifc_c.xfo_getStartPage(self.pXfoObj)

	def setStartPage(self, newVal):
		flag = '-start'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def getEndPage(self):
		return self.xfoifc_c.xfo_getEndPage(self.pXfoObj)

	def setEndPage(self, newVal):
		flag = '-end'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def setPdfMasterPassword(self, newVal):
		flag = '-ownerpwd'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def setPdfOwnerPassword(self, newVal):
		flag = '-ownerpwd'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def setPdfUserPassword(self, newVal):
		flag = '-userpwd'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def setPdfNoPrinting(self, newVal):
		self.xfoifc_c.xfo_setPdfNoPrinting(self.pXfoObj, newVal)

	def getPdfNoPrinting(self):
		return self.xfoifc_c.xfo_getPdfNoPrinting(self.pXfoObj)

	def setPdfNoChanging(self, newVal):
		self.xfoifc_c.xfo_setPdfNoChanging(self.pXfoObj, newVal)

	def getPdfNoChanging(self):
		return self.xfoifc_c.xfo_getPdfNoChanging(self.pXfoObj)

	def setPdfNoContentCopying(self, newVal):
		self.xfoifc_c.xfo_setPdfNoContentCopying(self.pXfoObj, newVal)

	def getPdfNoContentCopying(self):
		return self.xfoifc_c.xfo_getPdfNoContentCopying(self.pXfoObj)

	def setPdfNoAddingOrChangingCommnets(self, newVal):
		self.xfoifc_c.xfo_setPdfNoAddingOrChangingCommnets(self.pXfoObj, newVal)

	def getPdfNoAddingOrChangingCommnets(self):
		return self.xfoifc_c.xfo_getPdfNoAddingOrChangingCommnets(self.pXfoObj)

	def setPdfNoAddingOrChangingComments(self, newVal):
		self.xfoifc_c.xfo_setPdfNoAddingOrChangingComments(self.pXfoObj, newVal)

	def getPdfNoAddingOrChangingComments(self):
		return self.xfoifc_c.xfo_getPdfNoAddingOrChangingComments(self.pXfoObj)

	def setPdfVersion(self, newVal):
		flag = '-pdfver'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def getPdfVersion(self):
		return self.xfoifc_c.xfo_getPdfVersion(self.pXfoObj)

	def setPdfNoFillForm(self, newVal):
		self.xfoifc_c.xfo_setPdfNoFillForm(self.pXfoObj, newVal)

	def getPdfNoFillForm(self):
		return self.xfoifc_c.xfo_getPdfNoFillForm(self.pXfoObj)

	def setPdfNoAccessibility(self, newVal):
		self.xfoifc_c.xfo_setPdfNoAccessibility(self.pXfoObj, newVal)

	def getPdfNoAccessibility(self):
		return self.xfoifc_c.xfo_getPdfNoAccessibility(self.pXfoObj)

	def setPdfNoAssembleDoc(self, newVal):
		self.xfoifc_c.xfo_setPdfNoAssembleDoc(self.pXfoObj, newVal)

	def getPdfNoAssembleDoc(self):
		return self.xfoifc_c.xfo_getPdfNoAssembleDoc(self.pXfoObj)

	def setPdfEncryptLevel(self, newVal):
		self.xfoifc_c.xfo_setPdfEncryptLevel(self.pXfoObj, newVal)

	def getPdfEncryptLevel(self):
		return self.xfoifc_c.xfo_getPdfEncryptLevel(self.pXfoObj)

	def getPdfEmbedAllFonts(self):
		return self.xfoifc_c.xfo_getPdfEmbedAllFonts(self.pXfoObj)

	def setPdfEmbedAllFonts(self, newVal):
		flag = '-peb'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def getPdfEmbedFonts(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getPdfEmbedFonts.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getPdfEmbedFonts.restype = c_char_p
		return self.xfoifc_c.xfo_getPdfEmbedFonts(self.pXfoObj, cstr, 1024)

	def setPdfEmbedFonts(self, newVal):
		flag = '-peb'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def getPdfErrorOnEmbedFault(self):
		return self.xfoifc_c.xfo_getPdfErrorOnEmbedFault(self.pXfoObj)

	def setPdfErrorOnEmbedFault(self, newVal):
		self.xfoifc_c.xfo_setPdfErrorOnEmbedFault(self.pXfoObj, newVal)

	def getPdfErrorOnMissingGlyph(self):
		return self.xfoifc_c.xfo_getPdfErrorOnMissingGlyph(self.pXfoObj)

	def setPdfErrorOnMissingGlyph(self, newVal):
		self.xfoifc_c.xfo_setPdfErrorOnMissingGlyph(self.pXfoObj, newVal)

	def getPdfEmbedSubsetFontPercentage(self):
		return self.xfoifc_c.xfo_getPdfEmbedSubsetFontPercentage(self.pXfoObj)

	def setPdfEmbedSubsetFontPercentage(self, newVal):
		self.xfoifc_c.xfo_setPdfEmbedSubsetFontPercentage(self.pXfoObj, newVal)

	def getPdfPrintingAllowed(self):
		return self.xfoifc_c.xfo_getPdfPrintingAllowed(self.pXfoObj)

	def setPdfPrintingAllowed(self, newVal):
		self.xfoifc_c.xfo_setPdfPrintingAllowed(self.pXfoObj, newVal)

	def getPdfImageCompression(self):
		return self.xfoifc_c.xfo_getPdfImageCompression(self.pXfoObj)

	def setPdfImageCompression(self, newVal):
		self.xfoifc_c.xfo_setPdfImageCompression(self.pXfoObj, newVal)

	def getPdfJPEGQuality(self):
		return self.xfoifc_c.xfo_getPdfJPEGQuality(self.pXfoObj)

	def setPdfJPEGQuality(self, newVal):
		self.xfoifc_c.xfo_setPdfJPEGQuality(self.pXfoObj, newVal)

	def getPdfCompressContentStream(self):
		return self.xfoifc_c.xfo_getPdfCompressContentStream(self.pXfoObj)

	def setPdfCompressContentStream(self, newVal):
		self.xfoifc_c.xfo_setPdfCompressContentStream(self.pXfoObj, newVal)

	def getPdfUseLaunchForRelativeURI(self):
		return self.xfoifc_c.xfo_getPdfUseLaunchForRelativeURI(self.pXfoObj)

	def setPdfUseLaunchForRelativeURI(self, newVal):
		self.xfoifc_c.xfo_setPdfUseLaunchForRelativeURI(self.pXfoObj, newVal)

	def getPdfRGBConversion(self):
		return self.xfoifc_c.xfo_getPdfRGBConversion(self.pXfoObj)

	def setPdfRGBConversion(self, newVal):
		self.xfoifc_c.xfo_setPdfRGBConversion(self.pXfoObj, newVal)

	def getPdfRasterizeResolution(self):
		return self.xfoifc_c.xfo_getPdfRasterizeResolution(self.pXfoObj)

	def setPdfRasterizeResolution(self, newVal):
		self.xfoifc_c.xfo_setPdfRasterizeResolution(self.pXfoObj, newVal)

	def getPdfLinearize(self):
		return self.xfoifc_c.xfo_getPdfLinearize(self.pXfoObj)

	def setPdfLinearize(self, newVal):
		self.xfoifc_c.xfo_setPdfLinearize(self.pXfoObj, newVal)

	def getPdfSignature(self):
		return self.xfoifc_c.xfo_getPdfSignature(self.pXfoObj)

	def setPdfSignature(self, newVal):
		self.xfoifc_c.xfo_setPdfSignature(self.pXfoObj, newVal)

	def getPdfSignatureName(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getPdfSignatureName.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getPdfSignatureName.restype = c_char_p
		return self.xfoifc_c.xfo_getPdfSignatureName(self.pXfoObj, cstr, 1024)

	def setPdfSignatureName(self, newVal):
		self.xfoifc_c.xfo_setPdfSignatureName(self.pXfoObj, newVal)

	def getPdfCertificateName(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getPdfCertificateName.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getPdfCertificateName.restype = c_char_p
		return self.xfoifc_c.xfo_getPdfCertificateName(self.pXfoObj, cstr, 1024)

	def setPdfCertificateName(self, newVal):
		self.xfoifc_c.xfo_setPdfCertificateName(self.pXfoObj, newVal)

	def getPdfEmbedAllFontsEx(self):
		return self.xfoifc_c.xfo_getPdfEmbedAllFontsEx(self.pXfoObj)

	def setPdfEmbedAllFontsEx(self, newVal):
		self.xfoifc_c.xfo_setPdfEmbedAllFontsEx(self.pXfoObj, newVal)

	def getPdfImageDownSampling(self):
		return self.xfoifc_c.xfo_getPdfImageDownSampling(self.pXfoObj)

	def setPdfImageDownSampling(self, newVal):
		self.xfoifc_c.xfo_setPdfImageDownSampling(self.pXfoObj, newVal)

	def getPdfImageDownSamplingTarget(self):
		return self.xfoifc_c.xfo_getPdfImageDownSamplingTarget(self.pXfoObj)

	def setPdfImageDownSamplingTarget(self, newVal):
		self.xfoifc_c.xfo_setPdfImageDownSamplingTarget(self.pXfoObj, newVal)

	def getPdfImageDownSamplingDPI(self):
		return self.xfoifc_c.xfo_getPdfImageDownSamplingDPI(self.pXfoObj)

	def setPdfImageDownSamplingDPI(self, newVal):
		self.xfoifc_c.xfo_setPdfImageDownSamplingDPI(self.pXfoObj, newVal)

	def getPdfPutImageColorProfile(self):
		return self.xfoifc_c.xfo_getPdfPutImageColorProfile(self.pXfoObj)

	def setPdfPutImageColorProfile(self, newVal):
		self.xfoifc_c.xfo_setPdfPutImageColorProfile(self.pXfoObj, newVal)

	def getPdfGrayscaleImageCompression(self):
		return self.xfoifc_c.xfo_getPdfGrayscaleImageCompression(self.pXfoObj)

	def setPdfGrayscaleImageCompression(self, newVal):
		self.xfoifc_c.xfo_setPdfGrayscaleImageCompression(self.pXfoObj, newVal)

	def getPdfGrayscaleJPEGQuality(self):
		return self.xfoifc_c.xfo_getPdfGrayscaleJPEGQuality(self.pXfoObj)

	def setPdfGrayscaleJPEGQuality(self, newVal):
		self.xfoifc_c.xfo_setPdfGrayscaleJPEGQuality(self.pXfoObj, newVal)

	def getPdfGrayscaleImageDownSampling(self):
		return self.xfoifc_c.xfo_getPdfGrayscaleImageDownSampling(self.pXfoObj)

	def setPdfGrayscaleImageDownSampling(self, newVal):
		self.xfoifc_c.xfo_setPdfGrayscaleImageDownSampling(self.pXfoObj, newVal)

	def getPdfGrayscaleImageDownSamplingTarget(self):
		return self.xfoifc_c.xfo_getPdfGrayscaleImageDownSamplingTarget(self.pXfoObj)

	def setPdfGrayscaleImageDownSamplingTarget(self, newVal):
		self.xfoifc_c.xfo_setPdfGrayscaleImageDownSamplingTarget(self.pXfoObj, newVal)

	def getPdfGrayscaleImageDownSamplingDPI(self):
		return self.xfoifc_c.xfo_getPdfGrayscaleImageDownSamplingDPI(self.pXfoObj)

	def setPdfGrayscaleImageDownSamplingDPI(self, newVal):
		self.xfoifc_c.xfo_setPdfGrayscaleImageDownSamplingDPI(self.pXfoObj, newVal)

	def getPdfMonochromeImageCompression(self):
		return self.xfoifc_c.xfo_getPdfMonochromeImageCompression(self.pXfoObj)

	def setPdfMonochromeImageCompression(self, newVal):
		self.xfoifc_c.xfo_setPdfMonochromeImageCompression(self.pXfoObj, newVal)

	def getPdfMonochromeImageDownSampling(self):
		return self.xfoifc_c.xfo_getPdfMonochromeImageDownSampling(self.pXfoObj)

	def setPdfMonochromeImageDownSampling(self, newVal):
		self.xfoifc_c.xfo_setPdfMonochromeImageDownSampling(self.pXfoObj, newVal)

	def getPdfMonochromeImageDownSamplingTarget(self):
		return self.xfoifc_c.xfo_getPdfMonochromeImageDownSamplingTarget(self.pXfoObj)

	def setPdfMonochromeImageDownSamplingTarget(self, newVal):
		self.xfoifc_c.xfo_setPdfMonochromeImageDownSamplingTarget(self.pXfoObj, newVal)

	def getPdfMonochromeImageDownSamplingDPI(self):
		return self.xfoifc_c.xfo_getPdfMonochromeImageDownSamplingDPI(self.pXfoObj)

	def setPdfMonochromeImageDownSamplingDPI(self, newVal):
		self.xfoifc_c.xfo_setPdfMonochromeImageDownSamplingDPI(self.pXfoObj, newVal)

	def getTwoPassFormatting(self):
		return self.xfoifc_c.xfo_getTwoPassFormatting(self.pXfoObj)

	def setTwoPassFormatting(self, newVal):
		self.xfoifc_c.xfo_setTwoPassFormatting(self.pXfoObj, newVal)

	def getPdfTag(self):
		return self.xfoifc_c.xfo_getPdfTag(self.pXfoObj)

	def setPdfTag(self, newVal):
		self.xfoifc_c.xfo_setPdfTag(self.pXfoObj, newVal)

	def getPdfOutputWidth(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getPdfOutputWidth.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getPdfOutputWidth.restype = c_char_p
		return self.xfoifc_c.xfo_getPdfOutputWidth(self.pXfoObj, cstr, 1024)

	def setPdfOutputWidth(self, newVal):
		self.xfoifc_c.xfo_setPdfOutputWidth(self.pXfoObj, newVal)

	def getPdfOutputHeight(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getPdfOutputHeight.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getPdfOutputHeight.restype = c_char_p
		return self.xfoifc_c.xfo_getPdfOutputHeight(self.pXfoObj, cstr, 1024)

	def setPdfOutputHeight(self, newVal):
		self.xfoifc_c.xfo_setPdfOutputHeight(self.pXfoObj, newVal)

	def getPdfErrorOnPDFXFault(self):
		return self.xfoifc_c.xfo_getPdfErrorOnPDFXFault(self.pXfoObj)

	def setPdfErrorOnPDFXFault(self, newVal):
		self.xfoifc_c.xfo_setPdfErrorOnPDFXFault(self.pXfoObj, newVal)

	def getPdfReversePage(self):
		return self.xfoifc_c.xfo_getPdfReversePage(self.pXfoObj)

	def setPdfReversePage(self, newVal):
		self.xfoifc_c.xfo_setPdfReversePage(self.pXfoObj, newVal)

	def getPdfImport3DAnnotation(self):
		return self.xfoifc_c.xfo_getPdfImport3DAnnotation(self.pXfoObj)

	def setPdfImport3DAnnotation(self, newVal):
		self.xfoifc_c.xfo_setPdfImport3DAnnotation(self.pXfoObj, newVal)

	def getPdfConvertImageColorSpace(self):
		return self.xfoifc_c.xfo_getPdfConvertImageColorSpace(self.pXfoObj)

	def setPdfConvertImageColorSpace(self, newVal):
		self.xfoifc_c.xfo_setPdfConvertImageColorSpace(self.pXfoObj, newVal)

	def getSvgVersion(self):
		return self.xfoifc_c.xfo_getSvgVersion(self.pXfoObj)

	def setSvgVersion(self, newVal):
		self.xfoifc_c.xfo_setSvgVersion(self.pXfoObj, newVal)

	def getSvgGzipCompression(self):
		return self.xfoifc_c.xfo_getSvgGzipCompression(self.pXfoObj)

	def setSvgGzipCompression(self, newVal):
		self.xfoifc_c.xfo_setSvgGzipCompression(self.pXfoObj, newVal)

	def getSvgEmbedAllFonts(self):
		return self.xfoifc_c.xfo_getSvgEmbedAllFonts(self.pXfoObj)

	def setSvgEmbedAllFonts(self, newVal):
		self.xfoifc_c.xfo_setSvgEmbedAllFonts(self.pXfoObj, newVal)

	def getSvgFormat(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getSvgFormat.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getSvgFormat.restype = c_char_p
		return self.xfoifc_c.xfo_getSvgFormat(self.pXfoObj, cstr, 1024)

	def setSvgFormat(self, newVal):
		self.xfoifc_c.xfo_setSvgFormat(self.pXfoObj, newVal)

	def getSvgEmbedFonts(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getSvgEmbedFonts.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getSvgEmbedFonts.restype = c_char_p
		return self.xfoifc_c.xfo_getSvgEmbedFonts(self.pXfoObj, cstr, 1024)

	def setSvgEmbedFonts(self, newVal):
		self.xfoifc_c.xfo_setSvgEmbedFonts(self.pXfoObj, newVal)

	def getSvgErrorOnEmbedFault(self):
		return self.xfoifc_c.xfo_getSvgErrorOnEmbedFault(self.pXfoObj)

	def setSvgErrorOnEmbedFault(self, newVal):
		self.xfoifc_c.xfo_setSvgErrorOnEmbedFault(self.pXfoObj, newVal)

	def getSvgImageConversion(self):
		return self.xfoifc_c.xfo_getSvgImageConversion(self.pXfoObj)

	def setSvgImageConversion(self, newVal):
		self.xfoifc_c.xfo_setSvgImageConversion(self.pXfoObj, newVal)

	def getSvgJPEGQuality(self):
		return self.xfoifc_c.xfo_getSvgJPEGQuality(self.pXfoObj)

	def setSvgJPEGQuality(self, newVal):
		self.xfoifc_c.xfo_setSvgJPEGQuality(self.pXfoObj, newVal)

	def getSvgImageProcessingType(self):
		return self.xfoifc_c.xfo_getSvgImageProcessingType(self.pXfoObj)

	def setSvgImageProcessingType(self, newVal):
		self.xfoifc_c.xfo_setSvgImageProcessingType(self.pXfoObj, newVal)

	def getSvgImageCopyPath(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getSvgImageCopyPath.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getSvgImageCopyPath.restype = c_char_p
		return self.xfoifc_c.xfo_getSvgImageCopyPath(self.pXfoObj, cstr, 1024)

	def setSvgImageCopyPath(self, newVal):
		self.xfoifc_c.xfo_setSvgImageCopyPath(self.pXfoObj, newVal)

	def getSvgSingleFile(self):
		return self.xfoifc_c.xfo_getSvgSingleFile(self.pXfoObj)

	def setSvgSingleFile(self, newVal):
		self.xfoifc_c.xfo_setSvgSingleFile(self.pXfoObj, newVal)

	def getSvgSingleFileMaxHeight(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getSvgSingleFileMaxHeight.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getSvgSingleFileMaxHeight.restype = c_char_p
		return self.xfoifc_c.xfo_getSvgSingleFileMaxHeight(self.pXfoObj, cstr, 1024)

	def setSvgSingleFileMaxHeight(self, newVal):
		self.xfoifc_c.xfo_setSvgSingleFileMaxHeight(self.pXfoObj, newVal)

	def getSvgSingleFileMaxPages(self):
		return self.xfoifc_c.xfo_getSvgSingleFileMaxPages(self.pXfoObj)

	def setSvgSingleFileMaxPages(self, newVal):
		self.xfoifc_c.xfo_setSvgSingleFileMaxPages(self.pXfoObj, newVal)

	def getSvgImageDownsamplingDPI(self):
		return self.xfoifc_c.xfo_getSvgImageDownsamplingDPI(self.pXfoObj)

	def setSvgImageDownsamplingDPI(self, dpi):
		self.xfoifc_c.xfo_setSvgImageDownsamplingDPI(self.pXfoObj, dpi)

	def getSvgImageDownsamplingMethod(self):
		return self.xfoifc_c.xfo_getSvgImageDownsamplingMethod(self.pXfoObj)

	def setSvgImageDownsamplingMethod(self, type):
		self.xfoifc_c.xfo_setSvgImageDownsamplingMethod(self.pXfoObj, type)

	def getSvgImageRename(self):
		return self.xfoifc_c.xfo_getSvgImageRename(self.pXfoObj)

	def setSvgImageRename(self, newVal):
		self.xfoifc_c.xfo_setSvgImageRename(self.pXfoObj, newVal)

	def getSvgImagePrefix(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getSvgImagePrefix.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getSvgImagePrefix.restype = c_char_p
		return self.xfoifc_c.xfo_getSvgImagePrefix(self.pXfoObj, cstr, 1024)

	def setSvgImagePrefix(self, newVal):
		self.xfoifc_c.xfo_setSvgImagePrefix(self.pXfoObj, newVal)

	def getSvgSinglePageNumber(self):
		return self.xfoifc_c.xfo_getSvgSinglePageNumber(self.pXfoObj)

	def setSvgSinglePageNumber(self, newVal):
		self.xfoifc_c.xfo_setSvgSinglePageNumber(self.pXfoObj, newVal)

	def getSvgRasterizeResolution(self):
		return self.xfoifc_c.xfo_getSvgRasterizeResolution(self.pXfoObj)

	def setSvgRasterizeResolution(self, newVal):
		self.xfoifc_c.xfo_setSvgRasterizeResolution(self.pXfoObj, newVal)

	def getStartVolume(self):
		return self.xfoifc_c.xfo_getStartVolume(self.pXfoObj)

	def setStartVolume(self, newVal):
		self.xfoifc_c.xfo_setStartVolume(self.pXfoObj, newVal)

	def getEndVolume(self):
		return self.xfoifc_c.xfo_getEndVolume(self.pXfoObj)

	def setEndVolume(self, newVal):
		self.xfoifc_c.xfo_setEndVolume(self.pXfoObj, newVal)

	def getMultiVolume(self):
		return self.xfoifc_c.xfo_getMultiVolume(self.pXfoObj)

	def getTotalVolumeCount(self):
		return self.xfoifc_c.xfo_getTotalVolumeCount(self.pXfoObj)

	def getOutputVolumeCount(self):
		return self.xfoifc_c.xfo_getOutputVolumeCount(self.pXfoObj)

	def setMultiVolume(self, newVal):
		self.xfoifc_c.xfo_setMultiVolume(self.pXfoObj, newVal)

	def getExitLevel(self):
		return self.xfoifc_c.xfo_getExitLevel(self.pXfoObj)

	def setExitLevel(self, newVal):
		flag = '-extlevel'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def getErrorLevel(self):
		return self.xfoifc_c.xfo_getErrorLevel(self.pXfoObj)

	def getErrorCode(self):
		return self.xfoifc_c.xfo_getErrorCode(self.pXfoObj)

	def getErrorMessage(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getErrorMessage.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getErrorMessage.restype = c_char_p
		return self.xfoifc_c.xfo_getErrorMessage(self.pXfoObj, cstr, 1024)

	def setFontAlias(self, src, dst):
		self.xfoifc_c.xfo_setFontAlias(self.pXfoObj, src, dst)

	def clearFontAlias(self):
		self.xfoifc_c.xfo_clearFontAlias(self.pXfoObj)

	def eraseFontAlias(self):
		self.xfoifc_c.xfo_eraseFontAlias(self.pXfoObj, src)

	def execute(self):
		p = subprocess.Popen(self.args, executable=self.executable, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
		if (self.on_message_proc):
			self._handleErrorMessages(p)
		else:
			p.wait()
		return p.returncode

	def _handleErrorMessages(self, p):
		stdout, stderr = p.communicate()
		self._parseErrorString(stderr)

	def _parseErrorString(self, errors):
		lvl = None
		code = None
		msg = None
		self.errors = [ x.strip() for x in stderr.split('\n') ]
		pos = 0
		while (pos < len(self.errors)):
			pos = self._parseErrorLine(pos)

	def _parseErrorLine(self, pos):
		if ((self.errors[pos].startswith("XSLCmd :") or self.errors[pos].startswith("AHFCmd :")) and (self.errors[pos].find("Error Level") >= 0)):
			return self._parseError(pos)
		elif (self.errors[pos].startswith("Invalid license.")):
			return self._invalidLicense(pos)
		return pos + 1

	def _parseError(self, pos):
		ErrorLevel = int(self.errors[pos][-1:])
		pos += 1
		if (pos >= len(self.errors)):
			return pos
		ErrorCode = int(self.errors[pos][-1:])
		pos += 1
		if (pos >= len(self.errors)):
			return pos
		ErrorMessage = self.errors[pos].split(" ", 2)[2]
		pos += 1
		if ((pos < len(self.errors)) and (self.errors[pos].startswith("XSLCmd :") or self.errors[pos].startswith("AHFCmd :"))):
			ErrorMessage += "\n" + self.errors[pos].split(" ", 2)[2]
			pos += 1
		if (this.on_message_proc):
			self.on_message_proc(ErrorLevel, ErrorCode, ErrorMessage)
		return pos


	def clear(self):
		self.on_message_proc = None
		self.args = [os.path.basename(self.executable)]

	def setOnMessageProc(self, proc):
		self.on_message_proc = proc

	def setOnFormatPageProc(self, proc):
		self.onFormatPageProc_CALLBACK = CFUNCTYPE(None, c_long)
		self.onFormatPageProc_callback = self.onFormatPageProc_CALLBACK(proc)
		self.xfoifc_c.xfo_setOnFormatPageProc(self.pXfoObj, self.onFormatPageProc_callback)

	def setXSLTParam(self, paramName, value):
		self.xfoifc_c.xfo_setXSLTParam(self.pXfoObj, paramName, value)

	def clearXSLTParam(self):
		self.xfoifc_c.xfo_clearXSLTParam(self.pXfoObj)

	def getErrorStreamType(self):
		return self.xfoifc_c.xfo_getErrorStreamType(self.pXfoObj)

	def setErrorStreamType(self, type):
		self.xfoifc_c.xfo_setErrorStreamType(self.pXfoObj, type)

	def getPrinterName(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getPrinterName.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getPrinterName.restype = c_char_p
		return self.xfoifc_c.xfo_getPrinterName(self.pXfoObj, cstr, 1024)

	def setPrinterName(self, newVal):
		flag = '-p'
		try:
			index = self.args.index(flag)
			if (newVal != None):
				self.args[index + 1] = newVal
			else:
				self.args.pop(index)
				self.args.pop(index)
		except:
			self.args.append(flag)
			self.args.append(str(newVal))

	def getFormattedPages(self):
		return self.xfoifc_c.xfo_getFormattedPages(self.pXfoObj)

	def getPrinterSettingURI(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getPrinterSettingURI.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getPrinterSettingURI.restype = c_char_p
		return self.xfoifc_c.xfo_getPrinterSettingURI(self.pXfoObj, cstr, 1024)

	def setPrinterSettingURI(self, newVal):
		self.xfoifc_c.xfo_setPrinterSettingURI(self.pXfoObj, newVal)

	def getPrnCopies(self):
		return self.xfoifc_c.xfo_getPrnCopies(self.pXfoObj)

	def setPrnCopies(self, newVal):
		self.xfoifc_c.xfo_setPrnCopies(self.pXfoObj, newVal)

	def getPrnCollate(self):
		return self.xfoifc_c.xfo_getPrnCollate(self.pXfoObj)

	def setPrnCollate(self, newVal):
		self.xfoifc_c.xfo_setPrnCollate(self.pXfoObj, newVal)

	def getBatchPrint(self):
		return self.xfoifc_c.xfo_getBatchPrint(self.pXfoObj)

	def setBatchPrint(self, newVal):
		self.xfoifc_c.xfo_setBatchPrint(self.pXfoObj, newVal)

	def getDocumentText(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getDocumentText.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getDocumentText.restype = c_char_p
		return self.xfoifc_c.xfo_getDocumentText(self.pXfoObj, cstr, 1024)

	def setDocumentText(self, newVal):
		self.xfoifc_c.xfo_setDocumentText(self.pXfoObj, newVal)

	def getStylesheetText(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getStylesheetText.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getStylesheetText.restype = c_char_p
		return self.xfoifc_c.xfo_getStylesheetText(self.pXfoObj, cstr, 1024)

	def setStylesheetText(self, newVal):
		self.xfoifc_c.xfo_setStylesheetText(self.pXfoObj, newVal)

	def getVersion(self):
		cstr = create_string_buffer(1024)
		self.xfoifc_c.xfo_getVersion.argtypes = [c_void_p, c_char_p, c_int]
		self.xfoifc_c.xfo_getVersion.restype = c_char_p
		return self.xfoifc_c.xfo_getVersion(self.pXfoObj, cstr, 1024)

	def getInxOutputMode(self):
		return self.xfoifc_c.xfo_getInxOutputMode(self.pXfoObj)

	def setInxOutputMode(self, newVal):
		self.xfoifc_c.xfo_setInxOutputMode(self.pXfoObj, newVal)

	def getMifOutputMode(self):
		return self.xfoifc_c.xfo_getMifOutputMode(self.pXfoObj)

	def setMifOutputMode(self, newVal):
		self.xfoifc_c.xfo_setMifOutputMode(self.pXfoObj, newVal)

	def getMifIpMode(self):
		return self.xfoifc_c.xfo_getMifIpMode(self.pXfoObj)

	def setMifIpMode(self, mode):
		self.xfoifc_c.xfo_setMifIpMode(self.pXfoObj, mode)


def onMessage(level, code, message):
	print "Level:", level
	print "Code:", code
	print "Message:", message
	print
	return None

if __name__=="__main__":
	import sys
	xfoObj = XfoObj()
	xfoObj.setExitLevel(4)
	xfoObj.setDocumentURI(sys.argv[1])
	xfoObj.setOutputFilePath(sys.argv[2])
	xfoObj.setOnMessageProc(onMessage)
	xfoObj.execute()

