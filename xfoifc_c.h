/**
 * @file	xfoifc_c.h
 * @brief	AH Formatter C Interface
 *
 * @author	Antenna House, Inc.
 *
 * Copyright (C) 2002-2006 Antenna House, Inc. All rights reserved.
 */

#ifndef XFOIFC_C_H__
#define XFOIFC_C_H__

#include <stddef.h>

#if !defined(_DOXYGEN) && defined(_MSC_VER) && defined(_WIN32)
	#ifdef XFOINTERFACE_EXPORTS
		#define XFOINTERFACE_API	__declspec( dllexport )
	#else
		#define XFOINTERFACE_API	__declspec( dllimport )
	#endif
#else
	#define XFOINTERFACE_API
#endif

/**
 * Error Code
 */
typedef long XfoIfErrorCode;	/* 0 means no error */

/**
 * Error Level
 */
typedef enum {
	ELVL_NORMAL			= 0,	/* no error */
	ELVL_INFORMATION	= 1,
	ELVL_WARNING		= 2,
	ELVL_RECOVERABLE	= 3,
	ELVL_FATAL			= 4
} XfoIfErrorLevel;

/**
 * Error Stream Type for MessageListener
 */
typedef enum {
	EST_NONE,				/* no output */
	EST_STDOUT,				/* output to stdout */
	EST_STDERR				/* output to stderr */
} XfoErrorStreamType;

/**
 * PDF version
 */
typedef enum  {
	PDF_13,					/* PDF 1.3 */
	PDF_14,					/* PDF 1.4 */
	PDF_15,					/* PDF 1.5 */
	PDF_16,					/* PDF 1.6 */
	PDF_17,					/* PDF 1.7 */
	PDFX_1a_2001= 101,		/* ISO 15930-1:2001 PDF/X-1a-2001 (based on PDF1.3) */
	PDFX_3_2002	= 103,		/* ISO 15930-3:2002 PDF/X-3-2002  (based on PDF1.3) */
	PDFX_1a_2003= 104,		/* ISO 15930-4:2003 PDF/X-1a-2003 (based on PDF1.4) */
	PDFX_2_2003	= 105,		/* ISO 15930-5:2003 PDF/X-2-2003  (based on PDF1.4) */
	PDFX_3_2003	= 106,		/* ISO 15930-6:2003 PDF/X-3-2003  (based on PDF1.4) */
	PDFA_1a_2005= 200,		/* ISO 19005-1:2005 (based on PDF1.4) */
	PDFA_1b_2005= 400		/* ISO 19005-1:2005 (based on PDF1.4) */
} XfoPDFVERSION;

/**
 * PDF encrypt level
 */
typedef enum  {
	ENCLEVEL_40RC4	= 0,	/*  40-bit RC4 */
	ENCLEVEL_128RC4,		/* 128-bit RC4 */
	ENCLEVEL_128AES,		/* 128-bit AES */
	ENCLEVEL_256AES,		/* 256-bit AES */
	ENCLEVEL_40		= ENCLEVEL_40RC4,
	ENCLEVEL_128	= ENCLEVEL_128RC4
} XfoPDFENCRYPTLEVEL;

/**
 * PDF print allow
 */
typedef enum {
	PRALLOW_NONE,			/* not allowed */
	PRALLOW_LOW,			/* low resolution printing */
	PRALLOW_HIGH			/* high resolution printing */
} XfoPDFPRINTALLOW;

/**
 * PDF image compression
 */
typedef enum {
	IMGCMPR_AUTO,			/* auto */
	IMGCMPR_JPEG,			/* JPEG */
	IMGCMPR_ZLIB,			/* ZLIB */
	IMGCMPR_JPEG2K			/* JPEG2000 */
} XfoPDFIMAGECOMPRESSION;

/**
 * PDF RGB conversion
 */
typedef enum {
	RGBCONV_NONE,			/* no conversion */
	RGBCONV_BLACK,			/* black to devicegray */
	RGBCONV_GRAY,			/* gray to devicegray */
	RGBCONV_ALL				/* all rgb to devicegray */
} XfoPDFRGBCONVERSION;

/**
 * Embed font
 */
typedef	enum {
	EMBALLFONT_PART,		/* specified fonts */
	EMBALLFONT_ALL,			/* all fonts except Base14 fonts */
	EMBALLFONT_BASE14		/* all fonts */
} XfoEMBEDALLFONT;

/**
 * Image downsampling
 */
typedef	enum {
	IMGDOWNSAMPLING_NONE,		/* no downsampling */
	IMGDOWNSAMPLING_AVERAGE,	/* average downsampling */
	IMGDOWNSAMPLING_BICUBIC,	/* bicubic downsampling */
	IMGDOWNSAMPLING_SUBSAMPLING	/* subsampling */
} XfoIMAGEDOWNSAMPLING;

/**
 * Monochrome compression
 */
typedef	enum {
	MONOCMPR_CCITT4,		/* CCITTFaxDecode group 4 filter,default value */
	MONOCMPR_CCITT3,		/* CCITTFaxDecode group 3 filter */
	MONOCMPR_RUNLENGTH,		/* RunLengthDecode filter */
	MONOCMPR_ZLIB,			/* FlateDecode filter */
	MONOCMPR_OFF			/* no filter */
} XfoMONOCHROMECOMPRESSION;

/**
 * SVG version
 */
typedef	enum {
	SVG_11,					/* SVG 1.1 */
	SVG_Basic,				/* SVG Basic */
	SVG_Tiny				/* SVG Tiny */
} XfoSVGVERSION;

/**
 * Image processing
 */
typedef	enum {
	IMGPT_EMBED_ALL,		/* embed all */
	IMGPT_COPY_ALL,			/* copy all */
	IMGPT_LINK,				/* link */
	IMGPT_COPY				/* copy */
} XfoIMAGEPROCTYPE;

/**
 * Image conversion
 */
typedef enum {
	IMGCNV_AUTO,			/* auto */
	IMGCNV_JPEG,			/* jpeg conversion except png */
	IMGCNV_PNG,				/* png conversion except jpeg */
	IMGCNV_JPEGALL			/* jpeg-all conversion */
} XfoIMAGECONVERSION;

/**
 * Formatter type
 */
typedef enum {
	FMTTYP_AUTO,			/* auto */
	FMTTYP_HTML,			/* html */
	FMTTYP_XHTML,			/* xhtml */
	FMTTYP_XMLCSS,			/* xml+css */
	FMTTYP_XSLFO			/* xsl-fo */
} XfoFORMATTERTYPE;

/**
 * INX output mode
 */
typedef	enum  {
	INXOM_TEXT,				/* text area output mode */
	INXOM_LINE,				/* line area output */
	INXOM_BLOCK				/* block area output */
} XfoINXOUTPUTMODE;

/**
 * MIF output mode
 */
typedef	enum  {
	MIFOM_TEXT,				/* text area output mode */
	MIFOM_LINE,				/* line area output */
	MIFOM_BLOCK				/* block area output */
} XfoMIFOUTPUTMODE;

/**
 * MIF Image processiong mode
 */
typedef enum {
	MIFIP_EMBED,				/* image embed mode*/
	MIFIP_LINK_R,				/* link image relative path mode */
	MIFIP_LINK_A				/* link image absolute path mode */
} XfoMIFIMAGEPROCMODE;

/***************************************************************
 * for compatibility -- obsolete types
 */
typedef XfoPDFVERSION			PDFVERSION;
typedef XfoPDFENCRYPTLEVEL		PDFENCRYPTLEVEL;
typedef XfoPDFPRINTALLOW		PDFPRINTALLOW;
typedef XfoPDFIMAGECOMPRESSION	PDFIMAGECOMPRESSION;
typedef XfoPDFRGBCONVERSION		PDFRGBCONVERSION;
typedef XfoEMBEDALLFONT			EMBEDALLFONT;
typedef XfoIMAGEDOWNSAMPLING	IMAGEDOWNSAMPLING;
typedef XfoMONOCHROMECOMPRESSION MONOCHROMECOMPRESSION;
typedef XfoSVGVERSION			SVGVERSION;
typedef XfoIMAGEPROCTYPE		IMAGEPROCTYPE;
typedef XfoIMAGECONVERSION		IMAGECONVERSION;
typedef XfoFORMATTERTYPE		FORMATTERTYPE;
typedef XfoINXOUTPUTMODE		INXOUTPUTMODE;
typedef XfoMIFOUTPUTMODE		MIFOUTPUTMODE;
typedef XfoMIFIMAGEPROCMODE		MIFIMAGEPROCMODE;

/***************************************************************
 * format information
 */

#ifdef __cplusplus
extern "C" {
#endif

/** Pointer to XfoObj instance. */
typedef void*	CXfoObjPtr;

/**
 * Error callback handler
 */
typedef void (XfoOnMessageProc)(XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const char* errMessage);
typedef void (XfoOnMessageProcW)(XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const wchar_t* errMessage);
typedef void (XfoOnFormatPageProc)(long pageNo);

typedef void (XfoOnMessageProcEx)(void* pAnyObj, XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const char* errMessage);
typedef void (XfoOnMessageProcExW)(void* pAnyObj, XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const wchar_t* errMessage);
typedef void (XfoOnFormatPageProcEx)(void* pAnyObj, long pageNo);

/**
 * Create instance of XfoObj
 *
 * @return	Pointer to XfoObj instance.
 */
XFOINTERFACE_API CXfoObjPtr xfo_createXfoObject();

/**
 * Release instance of XfoObj
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 */
XFOINTERFACE_API void xfo_releaseXfoObject(CXfoObjPtr pXfoObj);

/**
 * Get formatter type.
 * only after Formatter 5.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	type of formatter.
 */
XFOINTERFACE_API XfoFORMATTERTYPE xfo_getFormatterType(CXfoObjPtr pXfoObj);

/**
 * Set formatter type.
 * only after Formatter 5.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal type of formatter.
 */
XFOINTERFACE_API void xfo_setFormatterType(CXfoObjPtr pXfoObj, XfoFORMATTERTYPE newVal);


/**
 * Get the URL of XML document you will format.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getDocumentURI(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
 * Get the URL of XML document you will format.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getDocumentURIW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Specifies the URL of XML document you will format.
 * If it is omitted or "\@STDIN" is specified, XML document is loaded from stdin.
 * The document loaded from stdin are supposed to be FO files.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the URL of XSL document.
 */
XFOINTERFACE_API void xfo_setDocumentURI(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Specifies the URL of XML document you will format.
 * If it is omitted or "\@STDIN" is specified, XML document is loaded from stdin.
 * The document loaded from stdin are supposed to be FO files.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the URL of XSL document.
 */
XFOINTERFACE_API void xfo_setDocumentURIW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Get the URI of XSL stylesheet for formatting.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getStylesheetURI(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
 * Get the URI of XSL stylesheet for formatting.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getStylesheetURIW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Specifies the URI of XSL stylesheet for formatting.
 * If the specified XML document is FO, or the XML file contains the processing instruction
 * &lt;?xml-stylesheet ...?&gt; and the XSL stylesheet is specified, this setting is ignored.
 * Otherwise if there is no setting of this property, an error occurs.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the URL of XSL stylesheet.
 */
XFOINTERFACE_API void xfo_setStylesheetURI(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Specifies the URI of XSL stylesheet for formatting.
 * If the specified XML document is FO, or the XML file contains the processing instruction
 * &lt;?xml-stylesheet ...?&gt; and the XSL stylesheet is specified, this setting is ignored.
 * Otherwise if there is no setting of this property, an error occurs.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the URL of XSL stylesheet.
 */
XFOINTERFACE_API void xfo_setStylesheetURIW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Append the path name of user stylesheet file which describes AH Formatter options.
 * @since 5.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of HTML user stylesheet file.
 */
XFOINTERFACE_API void xfo_addUserStylesheetURI(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Append the path name of user stylesheet file which describes AH Formatter options.
 * @since 5.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of HTML user stylesheet file.
 */
XFOINTERFACE_API void xfo_addUserStylesheetURIW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Get the prior stylesheet title.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getStylesheetTitle(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
 * Get the prior stylesheet title.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getStylesheetTitleW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Set the prior stylesheet title.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the title of priority stylesheet.
 */
XFOINTERFACE_API void xfo_setStylesheetTitle(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Set the prior stylesheet title.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the title of priority stylesheet.
 */
XFOINTERFACE_API void xfo_setStylesheetTitleW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Get html default charset.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getHtmlDefaultCharset(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
 * Get html default charset.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getHtmlDefaultCharsetW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Set html default charset.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the html default charset.
 */
XFOINTERFACE_API void xfo_setHtmlDefaultCharset(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Set html default charset.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the html default charset.
 */
XFOINTERFACE_API void xfo_setHtmlDefaultCharsetW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Get the path name of the output file.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getOutputFilePath(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
 * Get the path name of the output file.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getOutputFilePathW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Specifies the path name of the output file. When "\@STDOUT" is specified, it is considered as stdout.
 * If both the printer name and  this property are specified, the formatted result will be stored in
 * the file by the printer driver.
 * When "\@PDF" is specified as output, the PDF is stored in the file specified by this property.
 * If the property is not specified, it is considered as stdout.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of the output file.
 */
XFOINTERFACE_API void xfo_setOutputFilePath(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Specifies the path name of the output file. When "\@STDOUT" is specified, it is considered as stdout.
 * If both the printer name and  this property are specified, the formatted result will be stored in
 * the file by the printer driver.
 * When "\@PDF" is specified as output, the PDF is stored in the file specified by this property.
 * If the property is not specified, it is considered as stdout.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of the output file.
 */
XFOINTERFACE_API void xfo_setOutputFilePathW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Get the path name of XML-format Option setting file which describes AH Formatter options.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @param	n		Specifies to get n-th URI. 0 means first URI.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getOptionFileURI(CXfoObjPtr pXfoObj, char* pVal, int size, int n);
/**
 * Get the path name of XML-format Option setting file which describes AH Formatter options.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @param	n		Specifies to get n-th URI. 0 means first URI.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getOptionFileURIW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size, int n);

/**
 * Specifies the path name of XML-format Option setting file which describes AH Formatter options.
 * The set of former URIs is thrown away.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of XML-format Option setting file.
 */
XFOINTERFACE_API void xfo_setOptionFileURI(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Specifies the path name of XML-format Option setting file which describes AH Formatter options.
 * The set of former URIs is thrown away.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of XML-format Option setting file.
 */
XFOINTERFACE_API void xfo_setOptionFileURIW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Append the path name of XML-format Option setting file which describes AH Formatter options.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of XML-format Option setting file.
 */
XFOINTERFACE_API void xfo_addOptionFileURI(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Append the path name of XML-format Option setting file which describes AH Formatter options.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of XML-format Option setting file.
 */
XFOINTERFACE_API void xfo_addOptionFileURIW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Get the number of URIs of XML-format Option setting file which describes AH Formatter options.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Returns the number of URIs.
 */
XFOINTERFACE_API int xfo_getOptionFileCount(CXfoObjPtr pXfoObj);

/**
 * Get the output FO file as the result of XSLT when the input files are an XML document and XSL stylesheet.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getOutputFOPath(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
 * Get the output FO file as the result of XSLT when the input files are an XML document and XSL stylesheet.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getOutputFOPathW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Specifies the output FO file as the result of XSLT when the input files are an XML document and XSL stylesheet.
 * If the input file is FO, no file is outputted. When "\@STDOUT" is specified, it is considered as stdout.
 * If the setting is omitted, nothing outputs.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of output FO file.
 */
XFOINTERFACE_API void xfo_setOutputFOPath(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Specifies the output FO file as the result of XSLT when the input files are an XML document and XSL stylesheet.
 * If the input file is FO, no file is outputted. When "\@STDOUT" is specified, it is considered as stdout.
 * If the setting is omitted, nothing outputs.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the path name of output FO file.
 */
XFOINTERFACE_API void xfo_setOutputFOPathW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
	 * Get the command line of External XSLT Processor.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getExternalXSLT(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
	 * Get the command line of External XSLT Processor.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getExternalXSLTW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Specifies the command line of External XSLT Processor.
 * If this is omitted, default MSXML3 will be used. For example:
 * <pre>
 *	xslt \%param -o \%3 \%1 \%2</pre>
 *
 * These meanings are as follows.<pre>
 *	\%1 : XML Document
 *	\%2 : XSL Stylesheet
 *	\%3 : XSLT Output File
 *	\%param : xsl:param</pre>
 * \%1 to \%3 are used to express only parameter positions. Do not replace them actual file names.
 * In case you use XSL:param for external XSLT processor, set the parameter in XSLTParamFormat and SetXSLTParam.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the command line of External XSLT Processor.
 */
XFOINTERFACE_API void xfo_setExternalXSLT(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Specifies the command line of External XSLT Processor.
 * If this is omitted, default MSXML3 will be used. For example:
 * <pre>
 *	xslt \%param -o \%3 \%1 \%2</pre>
 *
 * These meanings are as follows.<pre>
 *	\%1 : XML Document
 *	\%2 : XSL Stylesheet
 *	\%3 : XSLT Output File
 *	\%param : xsl:param</pre>
 * \%1 to \%3 are used to express only parameter positions. Do not replace them actual file names.
 * In case you use XSL:param for external XSLT processor, set the parameter in XSLTParamFormat and SetXSLTParam.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the command line of External XSLT Processor.
 */
XFOINTERFACE_API void xfo_setExternalXSLTW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Get the default base URI.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getBaseURI(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
 * Get the default base URI.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getBaseURIW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Specifies the default base URI.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the default base URI.
 */
XFOINTERFACE_API void xfo_setBaseURI(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Specifies the default base URI.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the default base URI.
 */
XFOINTERFACE_API void xfo_setBaseURIW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Get the parameter format of xsl:param when using External XSLT Processor.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getXSLTParamFormat(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
 * Get the parameter format of xsl:param when using External XSLT Processor.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getXSLTParamFormatW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Specifies the parameter format of xsl:param when using External XSLT Processor.  For example:
 * <pre>
 *	 -p \%p \%v</pre>
 *
 * These meanings are as follows.<pre>
 *	\%p : Parameter Name
 *	\%v : Parameter Value</pre>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the parameter format of xsl:param when using External XSLT Processor.
 */
XFOINTERFACE_API void xfo_setXSLTParamFormat(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Specifies the parameter format of xsl:param when using External XSLT Processor.  For example:
 * <pre>
 *	 -p \%p \%v</pre>
 *
 * These meanings are as follows.<pre>
 *	\%p : Parameter Name
 *	\%v : Parameter Value</pre>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the parameter format of xsl:param when using External XSLT Processor.
 */
XFOINTERFACE_API void xfo_setXSLTParamFormatW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Get the start page number of document to output.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	start page number of output.
 */
XFOINTERFACE_API long xfo_getStartPage(CXfoObjPtr pXfoObj);

/**
 * Specifies the start page number of document to output.
 * If the start page is omitted or the specified value is 0 or less, the start page is
 * considered from the first page.
 * If the setting is inconsistent, (for example, StartPage=5 EndPage=3) an error occurs.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	start page number of output.
 */
XFOINTERFACE_API void xfo_setStartPage(CXfoObjPtr pXfoObj, long newVal);

/**
 * Get the end page number of document to output.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	end page number of output.
 */
XFOINTERFACE_API long xfo_getEndPage(CXfoObjPtr pXfoObj);

/**
 * Specifies the end page number of document to output.
 * If the end page is omitted or the specified value exceeds the actual page number, the end page
 * is considered as the last page.
 * If the setting is inconsistent, (for example, StartPage=5 EndPage=3) an error occurs.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	end page number of output.
 */
XFOINTERFACE_API void xfo_setEndPage(CXfoObjPtr pXfoObj, long newVal);

/**
 * @deprecated
 * Effective when outputting to PDF.
 * Specifies the master password for PDF. The password must be within 32 bytes.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the master password.
 */
XFOINTERFACE_API void xfo_setPdfMasterPassword(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * @deprecated
 * Effective when outputting to PDF.
 * Specifies the master password for PDF. The password must be within 32 bytes.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the master password.
 */
XFOINTERFACE_API void xfo_setPdfMasterPasswordW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Specifies the owner password for PDF. The password must be within 32 bytes.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the owner password.
 */
XFOINTERFACE_API void xfo_setPdfOwnerPassword(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Specifies the owner password for PDF. The password must be within 32 bytes.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the owner password.
 */
XFOINTERFACE_API void xfo_setPdfOwnerPasswordW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Specifies the user password for PDF. The password must be within 32 bytes.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the user password.
 */
XFOINTERFACE_API void xfo_setPdfUserPassword(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Specifies the user password for PDF. The password must be within 32 bytes.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the user password.
 */
XFOINTERFACE_API void xfo_setPdfUserPasswordW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Disables printing the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If nonezero is specified, Disables printing the PDF file.
 */
XFOINTERFACE_API void xfo_setPdfNoPrinting(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables printing the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If zero is returned, Enables printing the PDF file.
 * 			If nonezero is returned, Disables printing the PDF file.
 */
XFOINTERFACE_API long xfo_getPdfNoPrinting(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Disables making changes of the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If nonezero is specified, Disables making changes of the PDF file.
 */
XFOINTERFACE_API void xfo_setPdfNoChanging(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables making changes of the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If zero is returned, Enables making changes of the PDF file.
 * 			If nonezero is returned, Disables making changes of the PDF file.
 */
XFOINTERFACE_API long xfo_getPdfNoChanging(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Disables copying the content of the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If nonezero is specified, Disables copying the content of the PDF file.
 */
XFOINTERFACE_API void xfo_setPdfNoContentCopying(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables copying the content of the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If zero is returned, Enables copying the content of the PDF file.
 * 			If nonezero is returned, Disables copying the content of the PDF file.
 */
XFOINTERFACE_API long xfo_getPdfNoContentCopying(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Disables adding comments and form fields to the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If nonezero is specified, Disables adding comments and form fields to the PDF file.
 */
XFOINTERFACE_API void xfo_setPdfNoAddingOrChangingCommnets(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables adding comments and form fields to the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If zero is returned, Enables adding comments and form fields to the PDF file.
 * 			If nonezero is returned, Disables adding comments and form fields to the PDF file.
 */
XFOINTERFACE_API long xfo_getPdfNoAddingOrChangingCommnets(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Disables adding comments and form fields to the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If nonezero is specified, Disables adding comments and form fields to the PDF file.
 */
XFOINTERFACE_API void xfo_setPdfNoAddingOrChangingComments(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables adding comments and form fields to the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If zero is returned, Enables adding comments and form fields to the PDF file.
 * 			If nonezero is returned, Disables adding comments and form fields to the PDF file.
 */
XFOINTERFACE_API long xfo_getPdfNoAddingOrChangingComments(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Enables specifying whether the version of PDF is 1.3, 1.4 or 1.5.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Specifies the version of PDF.
 */
XFOINTERFACE_API void xfo_setPdfVersion(CXfoObjPtr pXfoObj, XfoPDFVERSION newVal);

/**
 * Effective when outputting to PDF.
 * Get the version of PDF.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the version of PDF.
 */
XFOINTERFACE_API XfoPDFVERSION	xfo_getPdfVersion(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Disables filling in of form fields and signing of the PDF file.
 * This parameter is effective only when you specify PDF1.4 or later to PDF version.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If nonezero is specified, Disables filling in of form fields and signing of the PDF file.
 */
XFOINTERFACE_API void xfo_setPdfNoFillForm(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables filling in of form fields and signing of the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If zero is returned, Enables filling in of form fields and signing of the PDF file.
 * 			If nonezero is returned, Disables filling in of form fields and signing of the PDF file.
 */
XFOINTERFACE_API long xfo_getPdfNoFillForm(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Disables text access for screen reader devices of the PDF file.
 * This parameter is effective only when you specify 1.4 or later with PDF version.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If nonezero is specified, Disables text access for screen reader devices of the PDF file.
 */
XFOINTERFACE_API void xfo_setPdfNoAccessibility(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables text access for screen reader devices of the PDF file.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If zero is returned, Enables text access for screen reader devices of the PDF file.
 * 			If nonezero is returned, Disables text access for screen reader devices of the PDF file.
 */
XFOINTERFACE_API long xfo_getPdfNoAccessibility(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Disables inserting, deleting and rotating the PDF pages.
 * This parameter is effective only when you specify 1.4 or later with PDF version
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If nonezero is specified, Disables inserting, deleting and rotating the PDF pages.
 */
XFOINTERFACE_API void xfo_setPdfNoAssembleDoc(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Get disables inserting, deleting and rotating the PDF pages.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If zero is returned, Enables inserting, deleting and rotating the PDF pages.
 * 			If nonezero is returned, Disables inserting, deleting and rotating the PDF pages.
 */
XFOINTERFACE_API long xfo_getPdfNoAssembleDoc(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies the key length when encrypting the PDF file during outputting.
 * The key length can be specified as either 40 or 128 (bit).
 * This parameter is effective only when you specify PDF1.4 or later with PDF version
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Specifies the key length.
 */
XFOINTERFACE_API void xfo_setPdfEncryptLevel(CXfoObjPtr pXfoObj, XfoPDFENCRYPTLEVEL newVal);

/**
 * Effective when outputting to PDF.
 * Get the key length when encrypting the PDF file during outputting.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the key length.
 */
XFOINTERFACE_API XfoPDFENCRYPTLEVEL xfo_getPdfEncryptLevel(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to embed all embeddable fonts in PDF.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to embed all embeddable fonts
 */
XFOINTERFACE_API long xfo_getPdfEmbedAllFonts(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Embeds all embeddable fonts in PDF to create.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is specified, Embeds all embeddable fonts
 */
XFOINTERFACE_API void xfo_setPdfEmbedAllFonts(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the font specified to be embedded in PDF.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the fontnames. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getPdfEmbedFonts(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Gets the font specified to be embedded in PDF.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the fontnames. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getPdfEmbedFontsW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Embeds the specified font in PDF to create. If you want to specify plural fonts, put commas between fonts.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	fonts specified to embed
 */
XFOINTERFACE_API void xfo_setPdfEmbedFonts(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Embeds the specified font in PDF to create. If you want to specify plural fonts, put commas between fonts.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	fonts specified to embed
 */
XFOINTERFACE_API void xfo_setPdfEmbedFontsW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to issues the error when failing to embed fonts.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to issues the error
 */
XFOINTERFACE_API long xfo_getPdfErrorOnEmbedFault(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * An error is issued in case of failing to embed fonts.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is specified, an error is issued.
 */
XFOINTERFACE_API void xfo_setPdfErrorOnEmbedFault(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to issues the error when missing glyph.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to issues the error
 */
XFOINTERFACE_API long xfo_getPdfErrorOnMissingGlyph(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * An error is issued in case of missing glyph.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is specified, an error is issued.
 */
XFOINTERFACE_API void xfo_setPdfErrorOnMissingGlyph(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Subset embedded fonts when percent of characters used is less than.
 * @since 5.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of percent to embeds subset font
 */
XFOINTERFACE_API long xfo_getPdfEmbedSubsetFontPercentage(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Subset embedded fonts when percent of characters used is less than.
 * @since 5.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	percent to embeds subset font
 */
XFOINTERFACE_API void xfo_setPdfEmbedSubsetFontPercentage(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to print the resulting PDF file or not.
 * @since 3.1
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>PRALLOW_NONE	</td><td>= 0 Not Allowed</td></tr>
 *	<tr><td>PRALLOW_LOW		</td><td>= 1 Low Resolution Printing</td></tr>
 *	<tr><td>PRALLOW_HIGH	</td><td>= 2 High Resolution Printing</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of printing allowed
 */
XFOINTERFACE_API XfoPDFPRINTALLOW xfo_getPdfPrintingAllowed(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Spesifies whether to permit printing PDF to create with one of the following values.
 * This parameter is effective only when you specify PDF1.4 or later to PDF version (setPdfVersion).
 * @since 3.1
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>PRALLOW_NONE	</td><td>= 0 Not Allowed</td></tr>
 *	<tr><td>PRALLOW_LOW		</td><td>= 1 Low Resolution Printing</td></tr>
 *	<tr><td>PRALLOW_HIGH	</td><td>= 2 High Resolution Printing</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of printing allowed
 */
XFOINTERFACE_API void xfo_setPdfPrintingAllowed(CXfoObjPtr pXfoObj, XfoPDFPRINTALLOW newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of how to compress the color images embedded in PDF.
 * @since 3.1
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG compression</td></tr>
 *	<tr><td>IMGCMPR_ZLIB	</td><td>= 2 ZLIB compression</td></tr>
 *	<tr><td>IMGCMPR_JPEG2K	</td><td>= 3 JPEG2000 compression</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of how raster graphics are compressed and stored
 */
XFOINTERFACE_API XfoPDFIMAGECOMPRESSION xfo_getPdfImageCompression(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * When the color image format cannot be stored directly in PDF, the image is stored after being transformed into the bit map format which is compatible with PDF. The compression method of the data stored in a PDF file is then specified by one of the following values.<BR>
 * When IMGCMPR_AUTO is selected, the process is automatically done and creates the image data according to the setting of xfo_setPdfJPEGQuality and xfo_setPdfRasterizeResolution. Whichever has the smaller compressed size, JPEG or ZLIB, is selected. <BR>
This is the setting for the color image. Spesify xfo_setPdfGrayscaleImageCompression for the grayscale image, and xfo_setPdfMonochromeImageCompression for the monochrome image.
 * @since 3.1
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG compression</td></tr>
 *	<tr><td>IMGCMPR_ZLIB	</td><td>= 2 ZLIB compression</td></tr>
 *	<tr><td>IMGCMPR_JPEG2K	</td><td>= 3 JPEG2000 compression</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of how raster graphics are compressed and stored
 */
XFOINTERFACE_API void xfo_setPdfImageCompression(CXfoObjPtr pXfoObj, XfoPDFIMAGECOMPRESSION newVal);

/**
 * Gets the value of the quality of JPEG format that is specified by xfo_setPdfImageCompression() stored in PDF.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of the quality of JPEG format
 */
XFOINTERFACE_API int	 xfo_getPdfJPEGQuality(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * For the color image format that can not be stored directly in PDF, specifies the image quality by the numerical value within the range of 1-100 when IMGCMPR_JPEG is specified by setPdfImageCompression. The quality becomes higher in proportion to the increase in the number; however the file size also becomes larger.<BR>
 * CAUTION: 	It is not for changing the quality of a JPEG format image.<BR>
 * This is the setting for the color image. Spesify setPdfGrayscaleJPEGQuality for the grayscale image.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of the quality of JPEG format
 */
XFOINTERFACE_API void xfo_setPdfJPEGQuality(CXfoObjPtr pXfoObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether the text and the line art in PDF are compressed in order to make the size of PDF smaller or not.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether make the size of PDF smaller or not
 */
XFOINTERFACE_API long xfo_getPdfCompressContentStream(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether the text and the line art in PDF are compressed in order to make the size of PDF smaller or not.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is specified, make the PDF compress
 */
XFOINTERFACE_API void xfo_setPdfCompressContentStream(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of how to transform external link specified by the relative address in the PDF link.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of how to transform external link
 */
XFOINTERFACE_API long xfo_getPdfUseLaunchForRelativeURI(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether the external link specified by the relative address is transformed into 'Open the file' or into 'World Wide Web link' in the PDF link properties.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If nonezero is specified, it is transformed to 'Open the file'. If zero is specified, it is transformed to 'World Wide Web link'
 */
XFOINTERFACE_API void xfo_setPdfUseLaunchForRelativeURI(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of how to convert the RGB color space (DebiceRGB) to DeviceGray.
 * @since 3.1
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>RGBCONV_NONE	</td><td>= 0 No Conversion</td></tr>
 *	<tr><td>RGBCONV_BLACK	</td><td>= 1 Black to DeviceGray</td></tr>
 *	<tr><td>RGBCONV_GRAY	</td><td>= 2 Gray to DeviceGray</td></tr>
 *	<tr><td>RGBCONV_ALL		</td><td>= 3 All RGB to DeviceGray</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of how to convert
 */
XFOINTERFACE_API XfoPDFRGBCONVERSION xfo_getPdfRGBConversion(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies how to convert the RGB color space (DeviceRGB) to DeviceGray.
 * @since 3.1
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>RGBCONV_NONE	</td><td>= 0 No Conversion</td></tr>
 *	<tr><td>RGBCONV_BLACK	</td><td>= 1 Black to DeviceGray</td></tr>
 *	<tr><td>RGBCONV_GRAY	</td><td>= 2 Gray to DeviceGray</td></tr>
 *	<tr><td>RGBCONV_ALL		</td><td>= 3 All RGB to DeviceGray</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of how to convert
 */
XFOINTERFACE_API void xfo_setPdfRGBConversion(CXfoObjPtr pXfoObj, XfoPDFRGBCONVERSION newVal);

#if defined(_DOXYGEN) || (defined(_MSC_VER) && defined(_WIN32))

/**
 * Effective when outputting to PDF.
 * Gets the value of the rasterised-resolution of the transformed raster images.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Rasterised-resolution
 */
XFOINTERFACE_API int xfo_getPdfRasterizeResolution(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies the value of the rasterised-resolution of the transformed raster images in the range from 70 to 500(dpi). SVG, EMF and WMF are drawn in PDF as vectors without being transformed to raster images.
 * This setting is effective only with Windows version.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Rasterised-resolution (70 to 500)
 */
XFOINTERFACE_API void xfo_setPdfRasterizeResolution(CXfoObjPtr pXfoObj, int newVal);

#endif

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to output linearize PDF or not.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to output linearize pdf or not.
 */
XFOINTERFACE_API long xfo_getPdfLinearize(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether to output linearize PDF or not.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is specified, output linearlize PDF.
 */
XFOINTERFACE_API void xfo_setPdfLinearize(CXfoObjPtr pXfoObj, long newVal);

#if defined(_DOXYGEN) || (defined(_MSC_VER) && defined(_WIN32))

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to sign a signature to PDF or not.
 * @since 4.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to sign a signature to PDF or not.
 */
XFOINTERFACE_API long xfo_getPdfSignature(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether to sign a signature to PDF or not.
 * @since 4.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is specified, sign a signature to PDF.
 */
XFOINTERFACE_API void xfo_setPdfSignature(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of a signature information name.
 * @since 4.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	the value of a signature information name.
 */
XFOINTERFACE_API char* xfo_getPdfSignatureName(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Gets the value of a signature information name.
 * @since 4.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	the value of a signature information name.
 */
XFOINTERFACE_API wchar_t* xfo_getPdfSignatureNameW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Sets a signature information name.
 * @since 4.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of a signature information name.
 */
XFOINTERFACE_API void xfo_setPdfSignatureName(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Sets a signature information name.
 * @since 4.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of a signature information name.
 */
XFOINTERFACE_API void xfo_setPdfSignatureNameW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of a certificate information name.
 * @since 4.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	the value of a certificate information name.
 */
XFOINTERFACE_API char* xfo_getPdfCertificateName(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Gets the value of a certificate information name.
 * @since 4.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	the value of a certificate information name.
 */
XFOINTERFACE_API wchar_t* xfo_getPdfCertificateNameW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Sets a certificate information name.
 * @since 4.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of a certificate information name.
 */
XFOINTERFACE_API void xfo_setPdfCertificateName(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Sets a certificate information name.
 * @since 4.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of a certificate information name.
 */
XFOINTERFACE_API void xfo_setPdfCertificateNameW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

#endif

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to embed all embeddable fonts
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>EMBALLFONT_PART	</td><td>= 0 Specified fonts </td></tr>
 *	<tr><td>EMBALLFONT_ALL	</td><td>= 1 All fonts except Base14 fonts</td></tr>
 *	<tr><td>EMBALLFONT_BASE14	</td><td>= 2 All fonts</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to embed all embeddable fonts
 */
XFOINTERFACE_API XfoEMBEDALLFONT xfo_getPdfEmbedAllFontsEx(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether to embed the all outline data of fonts in PDF or not with one of the following values, which are True type fonts and Type1 Fonts and are embeddable in the formatted result.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>EMBALLFONT_PART	</td><td>= 0 Specified fonts </td></tr>
 *	<tr><td>EMBALLFONT_ALL	</td><td>= 1 All fonts except Base14 fonts</td></tr>
 *	<tr><td>EMBALLFONT_BASE14	</td><td>= 2 All fonts</td></tr>
 * </table>
 *
 *If the value is EMBALLFONT_PART, only fonts specified in xfo_setPdfEmbedFonts are embedded. If the value is EMBALLFONT_ALL, all fonts that can be embedded except Base 14 fonts will be embedded. If the value is EMBALLFONT_BASE14, all fonts including Base 14 fonts that can be embedded will be embedded.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of whether to embed all embeddable fonts
 */
XFOINTERFACE_API void xfo_setPdfEmbedAllFontsEx(CXfoObjPtr pXfoObj, XfoEMBEDALLFONT newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of method to downsample the color image
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of method to downsample the color image
 */
XFOINTERFACE_API XfoIMAGEDOWNSAMPLING xfo_getPdfImageDownSampling(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies the following either of method to downsample the color image that is put into PDF.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGDOWNSAMPLING_NONE	</td><td>= 0 No downsampling </td></tr>
 *	<tr><td>IMGDOWNSAMPLING_AVERAGE	</td><td>= 1 Average downsamplin</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_BICUBIC	</td><td>= 2 Bicubic downsampling</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_SUBSAMPLING	</td><td>= 3 Subsampling</td></tr>
 * </table>
 *
 * When the value except IMGDOWNSAMPLING_NONE is specified, the image that has the resolution larger than the one specified by xfo_setPdfImageDownSamplingDPI will be downsampled into the resolution specified by xfo_setPdfImageDownSamplingTarget.
This is the setting for the color image. Spesify xfo_setPdfGrayscaleImageDownSampling for the grayscale image, and xfo_setPdfMonochromeImageDownSampling for the monochrome image.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of method to downsample the color image
 */
XFOINTERFACE_API void xfo_setPdfImageDownSampling(CXfoObjPtr pXfoObj, XfoIMAGEDOWNSAMPLING newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution when the color image is downsampled.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of resolution.
 */
XFOINTERFACE_API int xfo_getPdfImageDownSamplingTarget(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Set resolution when the color image is downsampled.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of resolution.
 */
XFOINTERFACE_API void xfo_setPdfImageDownSamplingTarget(CXfoObjPtr pXfoObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution of the color image which performs a downsampling.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of resolution.
 */
XFOINTERFACE_API int xfo_getPdfImageDownSamplingDPI(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Set resolution of the color image which performs a downsampling.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of resolution.
 */
XFOINTERFACE_API void xfo_setPdfImageDownSamplingDPI(CXfoObjPtr pXfoObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets specification whether to embed to PDF the color profile of the color image that will be embedded to PDF.
 * @since 3.3
 *
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If nonezero is specified, it is embedded. If zero is specified, it is not embedded.
 */
XFOINTERFACE_API long xfo_getPdfPutImageColorProfile(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies whether to embed to PDF the color profile of the color image that will be embedded to PDF.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If nonezero is specified, it is embedded. If zero is specified, it is not embedded.
 */
XFOINTERFACE_API void xfo_setPdfPutImageColorProfile(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of how to compress the grayscale images embedded in PDF.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG compression</td></tr>
 *	<tr><td>IMGCMPR_ZLIB	</td><td>= 2 ZLIB compression</td></tr>
 *	<tr><td>IMGCMPR_JPEG2K	</td><td>= 3 JPEG2000 compression</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of how raster graphics are compressed and stored
 */
XFOINTERFACE_API XfoPDFIMAGECOMPRESSION xfo_getPdfGrayscaleImageCompression(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * When the grayscale image format cannot be stored directly in PDF, the image is stored after being transformed into the bit map format which is compatible with PDF. The compression method of the data stored in a PDF file is then specified by one of the following values.<BR>
 * When IMGCMPR_AUTO is selected, the process is automatically done and creates the image data according to the setting of xfo_setPdfGrayscaleJPEGQuality and xfo_setPdfRasterizeResolution. Whichever has the smaller compressed size, JPEG or ZLIB, is selected. <BR>
This is the setting for the grayscale image. Spesify xfo_setPdfImageCompression for the color image, and xfo_setPdfMonochromeImageCompression for the monochrome image.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG compression</td></tr>
 *	<tr><td>IMGCMPR_ZLIB	</td><td>= 2 ZLIB compression</td></tr>
 *	<tr><td>IMGCMPR_JPEG2K	</td><td>= 3 JPEG2000 compression</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of how raster graphics are compressed and stored
 */
XFOINTERFACE_API void xfo_setPdfGrayscaleImageCompression(CXfoObjPtr pXfoObj, XfoPDFIMAGECOMPRESSION newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of the quality of JPEG format that is specified by xfo_setPdfGrayscaleImageCompression stored in PDF.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of the quality of JPEG format
 */
XFOINTERFACE_API int xfo_getPdfGrayscaleJPEGQuality(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * For the grayscale image format that can not be stored directly in PDF, specifies the image quality by the numerical value within the range of 1-100 when IMGCMPR_JPEG is specified by xfo_setPdfGrayscaleImageCompression. The quality becomes higher in proportion to the increase in the number; however the file size also becomes larger.<BR>
 * CAUTION: It is not for changing the quality of a JPEG format image.<BR>
 * This is the setting for the grayscale image. Spesify xfo_setPdfJPEGQuality for the color image.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of the quality of JPEG format
 */
XFOINTERFACE_API void xfo_setPdfGrayscaleJPEGQuality(CXfoObjPtr pXfoObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of method to downsample the grayscale image
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of method to downsample the grayscale image
 */
XFOINTERFACE_API XfoIMAGEDOWNSAMPLING xfo_getPdfGrayscaleImageDownSampling(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal
 */
XFOINTERFACE_API void xfo_setPdfGrayscaleImageDownSampling(CXfoObjPtr pXfoObj, XfoIMAGEDOWNSAMPLING newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution when the grayscale image is downsampled.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of resolution.
 */
XFOINTERFACE_API int xfo_getPdfGrayscaleImageDownSamplingTarget(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies the following either of method to downsample the grayscale image that is put into PDF.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGDOWNSAMPLING_NONE	</td><td>= 0 No downsampling </td></tr>
 *	<tr><td>IMGDOWNSAMPLING_AVERAGE	</td><td>= 1 Average downsamplin</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_BICUBIC	</td><td>= 2 Bicubic downsampling</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_SUBSAMPLING	</td><td>= 3 Subsampling</td></tr>
 * </table>
 *
 * When the value except IMGDOWNSAMPLING_NONE is specified, the image that has the resolution larger than the one specified by xfo_setPdfGrayscaleImageDownSamplingDPI will be downsampled into the resolution specified by xfo_setPdfGrayscaleImageDownSamplingTarget.
This is the setting for the grayscale image. Spesify xfo_setPdfImageDownSampling for the color image, and xfo_setPdfMonochromeImageDownSampling for the monochrome image.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of method to downsample the grayscale image
 */
XFOINTERFACE_API void xfo_setPdfGrayscaleImageDownSamplingTarget(CXfoObjPtr pXfoObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution of the grayscale image which performs a downsampling.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of resolution.
 */
XFOINTERFACE_API int xfo_getPdfGrayscaleImageDownSamplingDPI(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Set resolution of the grayscale image which performs a downsampling.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of resolution.
 */
XFOINTERFACE_API void xfo_setPdfGrayscaleImageDownSamplingDPI(CXfoObjPtr pXfoObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of how to compress the monochrome images embedded in PDF.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>MONOCMPR_CCITT4		</td><td>= 0 CCITTFaxDecode group 4 filter,default value</td></tr>
 *	<tr><td>MONOCMPR_CCITT3		</td><td>= 1 CCITTFaxDecode group 3 filter</td></tr>
 *	<tr><td>MONOCMPR_RUNLENGTH	</td><td>= 2 RunLengthDecode filter</td></tr>
 *	<tr><td>MONOCMPR_ZLIB		</td><td>= 3 FlateDecode filter</td></tr>
 *	<tr><td>MONOCMPR_OFF		</td><td>= 4 no filter</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of how raster graphics are compressed and stored
 */
XFOINTERFACE_API XfoMONOCHROMECOMPRESSION xfo_getPdfMonochromeImageCompression(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * When the monochrome image format cannot be stored directly in PDF, the image is stored after being transformed into the bit map format which is compatible with PDF. The compression method of the data stored in a PDF file is then specified by one of the following values.<BR>
This is the setting for the monochrome image. Spesify xfo_setPdfGrayscaleImageCompression for the grayscale image, and xfo_setPdfImageCompression for the color image.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>MONOCMPR_CCITT4		</td><td>= 0 CCITTFaxDecode group 4 filter,default value</td></tr>
 *	<tr><td>MONOCMPR_CCITT3		</td><td>= 1 CCITTFaxDecode group 3 filter</td></tr>
 *	<tr><td>MONOCMPR_RUNLENGTH	</td><td>= 2 RunLengthDecode filter</td></tr>
 *	<tr><td>MONOCMPR_ZLIB		</td><td>= 3 FlateDecode filter</td></tr>
 *	<tr><td>MONOCMPR_OFF		</td><td>= 4 no filter</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of how raster graphics are compressed and stored
 */
XFOINTERFACE_API void xfo_setPdfMonochromeImageCompression(CXfoObjPtr pXfoObj, XfoMONOCHROMECOMPRESSION newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of method to downsample the monochrome image
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of method to downsample the monochrome image
 */
XFOINTERFACE_API XfoIMAGEDOWNSAMPLING xfo_getPdfMonochromeImageDownSampling(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Specifies the following either of method to downsample the monochrome image that is put into PDF.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGDOWNSAMPLING_NONE	</td><td>= 0 No downsampling </td></tr>
 *	<tr><td>IMGDOWNSAMPLING_AVERAGE	</td><td>= 1 Average downsamplin</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_BICUBIC	</td><td>= 2 Bicubic downsampling</td></tr>
 *	<tr><td>IMGDOWNSAMPLING_SUBSAMPLING	</td><td>= 3 Subsampling</td></tr>
 * </table>
 *
 * When the value except IMGDOWNSAMPLING_NONE is specified, the image that has the resolution larger than the one specified by xfo_setPdfMonochromeImageDownSamplingDPI will be downsampled into the resolution specified by xfo_setPdfMonochromeImageDownSamplingTarget.
This is the setting for the monochrome image. Spesify xfo_setPdfImageDownSampling for the color image, and xfo_setPdfGrayscaleImageDownSampling for the grayscale image.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of method to downsample the monochrome image
 */
XFOINTERFACE_API void xfo_setPdfMonochromeImageDownSampling(CXfoObjPtr pXfoObj, XfoIMAGEDOWNSAMPLING newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution when the monochrome image is downsampled.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of resolution.
 */
XFOINTERFACE_API int xfo_getPdfMonochromeImageDownSamplingTarget(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Set resolution when the monochrome image is downsampled.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of resolution.
 */
XFOINTERFACE_API void xfo_setPdfMonochromeImageDownSamplingTarget(CXfoObjPtr pXfoObj, int newVal);

/**
 * Effective when outputting to PDF.
 * Gets resolution of the monochrome image which performs a downsampling.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of resolution.
 */
XFOINTERFACE_API int xfo_getPdfMonochromeImageDownSamplingDPI(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Set resolution of the monochrome image which performs a downsampling.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of resolution.
 */
XFOINTERFACE_API void xfo_setPdfMonochromeImageDownSamplingDPI(CXfoObjPtr pXfoObj, int newVal);

/**
 * Gets the specification of two pass format.
 * @since 4.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the specification of two pass format.
 */
XFOINTERFACE_API long xfo_getTwoPassFormatting(CXfoObjPtr pXfoObj);

/**
 * Set the specification of two pass format.
 * @since 4.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the specification of two pass format..
 */
XFOINTERFACE_API void xfo_setTwoPassFormatting(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to output Tagged PDF or not.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to output Tagged pdf or not.
 */
XFOINTERFACE_API long xfo_getPdfTag(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Generates Tagged PDF. Ignored if PDF cannot be tagged depending on the PDF versions.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is specified, output Tagged PDF.
 */
XFOINTERFACE_API void xfo_setPdfTag(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Gets the width of PDF to output.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the width of PDF. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getPdfOutputWidth(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Gets the width of PDF to output.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the width of PDF. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getPdfOutputWidthW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Scales the width of PDF to output. A value with a unit or % value can be specified as length.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the width of PDF to output.
 */
XFOINTERFACE_API void xfo_setPdfOutputWidth(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Scales the width of PDF to output. A value with a unit or % value can be specified as length.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the width of PDF to output.
 */
XFOINTERFACE_API void xfo_setPdfOutputWidthW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Gets the height of PDF to output.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the height of PDF. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getPdfOutputHeight(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Gets the height of PDF to output.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the height of PDF. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getPdfOutputHeightW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to PDF.
 * Scales the height of PDF to output. A value with a unit or % value can be specified as length.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the width of PDF to output.
 */
XFOINTERFACE_API void xfo_setPdfOutputHeight(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Effective when outputting to PDF.
 * Scales the height of PDF to output. A value with a unit or % value can be specified as length.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the width of PDF to output.
 */
XFOINTERFACE_API void xfo_setPdfOutputHeightW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Effective when outputting to PDF.
 * Gets the value of whether to issue error or not when PDF/X is generating.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to issue error.
 */
XFOINTERFACE_API long xfo_getPdfErrorOnPDFXFault(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * An error is not issued when PDF/X is generating.
 * @since 4.0
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is specified, no error is issued.
 */
XFOINTERFACE_API void xfo_setPdfErrorOnPDFXFault(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Output reverse page or not.
 * @since 5.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to output reverse page or not.
 */
XFOINTERFACE_API long xfo_getPdfReversePage(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Output reverse page or not.
 * @since 5.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is reverse page.
 */
XFOINTERFACE_API void xfo_setPdfReversePage(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Import 3D annotations or not.
 * @since 5.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to import 3D annotations or not.
 */
XFOINTERFACE_API long xfo_getPdfImport3DAnnotation(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Import 3D annotations or not.
 * @since 5.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is import 3D annotations.
 */
XFOINTERFACE_API void xfo_setPdfImport3DAnnotation(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to PDF.
 * Convert image color space or not.
 * @since 5.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to convert image color space or not.
 */
XFOINTERFACE_API long xfo_getPdfConvertImageColorSpace(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to PDF.
 * Convert image color space or not.
 * @since 5.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is convert image color space.
 */
XFOINTERFACE_API void xfo_setPdfConvertImageColorSpace(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to SVG.
 * Get the version of SVG.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the version of SVG.
 */
XFOINTERFACE_API XfoSVGVERSION	xfo_getSvgVersion(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to SVG.
 * Enables specifying whether the version of SVG is 1.1, Basic or Tiny.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Specifies the version of SVG.
 */
XFOINTERFACE_API void xfo_setSvgVersion(CXfoObjPtr pXfoObj, XfoSVGVERSION newVal);

/**
 * Effective when outputting to SVG.
 * Gets the setting indicating whether to compress the outputted SVG into gzip format or not.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	whether gzip compression or not.
 */
XFOINTERFACE_API long xfo_getSvgGzipCompression(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to SVG.
 * Specifies whether to compress the outputted SVG into gzip format or not.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is specified, enables to compress data into gzip format.
 */
XFOINTERFACE_API void xfo_setSvgGzipCompression(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to SVG.
 * Gets the setting indicating whether to embed fonts in the outputted SVG.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	whether embeds fonts or not.
 */
XFOINTERFACE_API long xfo_getSvgEmbedAllFonts(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to SVG.
 * Specifies whether to embed fonts in the outputted SVG.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is specified, embeds fonts.
 */
XFOINTERFACE_API void xfo_setSvgEmbedAllFonts(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to SVG.
 * Gets the format for naming files when the outputted SVG becomes multiple.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer, the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getSvgFormat(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Gets the format for naming files when the outputted SVG becomes multiple.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer, the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getSvgFormatW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Specifies the format for naming files when the outputted SVG becomes multiple.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the SVG file name format.
 */
XFOINTERFACE_API void xfo_setSvgFormat(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Effective when outputting to SVG.
 * Specifies the format for naming files when the outputted SVG becomes multiple.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the SVG file name format.
 */
XFOINTERFACE_API void xfo_setSvgFormatW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Effective when outputting to SVG.
 * Gets the font specified to be embedded in SVG.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the fontnames. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getSvgEmbedFonts(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Gets the font specified to be embedded in SVG.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the fontnames. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getSvgEmbedFontsW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Embeds the specified font in SVG to create. If you want to specify plural fonts, put commas between fonts.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	fonts specified to embed
 */
XFOINTERFACE_API void xfo_setSvgEmbedFonts(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Effective when outputting to SVG.
 * Embeds the specified font in SVG to create. If you want to specify plural fonts, put commas between fonts.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	fonts specified to embed
 */
XFOINTERFACE_API void xfo_setSvgEmbedFontsW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Effective when outputting to SVG.
 * Gets the value of whether to issues the error when failing to embed fonts.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of whether to issues the error
 */
XFOINTERFACE_API long xfo_getSvgErrorOnEmbedFault(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to SVG.
 * An error is issued in case of failing to embed fonts.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If the value is 'true' is specified, an error is issued.
 */
XFOINTERFACE_API void xfo_setSvgErrorOnEmbedFault(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to SVG.
 * Gets the value of how to compress the images embedded in SVG.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto conversion</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG conversion</td></tr>
 *	<tr><td>IMGCMPR_PNG		</td><td>= 2 PNG conversion</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of how raster graphics are compressed and stored
 */
XFOINTERFACE_API XfoIMAGECONVERSION xfo_getSvgImageConversion(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to SVG.
 * Selects how to compress the images embedded in SVG to create from the following.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGCMPR_AUTO	</td><td>= 0 Auto conversion</td></tr>
 *	<tr><td>IMGCMPR_JPEG	</td><td>= 1 JPEG conversion</td></tr>
 *	<tr><td>IMGCMPR_PNG		</td><td>= 2 PNG conversion</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the value of how raster graphics are compressed and stored
 */
XFOINTERFACE_API void xfo_setSvgImageConversion(CXfoObjPtr pXfoObj, XfoIMAGECONVERSION newVal);

/**
 * Gets the value of the quality of JPEG format that is specified by xfo_setSvgImageConversion() stored in SVG.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	the value of the quality
 */
XFOINTERFACE_API int xfo_getSvgJPEGQuality(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to SVG.
 * Specifies the quality of the Raster graphics when stored in JPEG format using the range of 1-100.
 * The quality becomes higher in proportion to the increase in the number; however the file size also becomes larger.
 * The initial value is 80.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	JPEG quality (1 to 100)
 */
XFOINTERFACE_API void xfo_setSvgJPEGQuality(CXfoObjPtr pXfoObj, int newVal);

/**
 * Effective when outputting to SVG.
 * Gets specification how to treat the referred image.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGPT_EMBED_ALL	</td><td>= 0 Embeds all images to SVG.</td></tr>
 *	<tr><td>IMGPT_COPY_ALL	</td><td>= 1 Copies all image files to the destination that is specified by setSvgImageCopyPath, and then links.</td></tr>
 *	<tr><td>IMGPT_LINK		</td><td>= 2 Links images that have been linked, and embeds the embedded image. However, the raster images other than JPEG and PNG are always embedded.</td></tr>
 *	<tr><td>IMGPT_COPY		</td><td>= 3 Copies images that have been linked to the destination that is specified by setSvgImageCopyPath, and links. The embedded image are embedded.</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	specification how to treat the referred image.
 */
XFOINTERFACE_API XfoIMAGEPROCTYPE xfo_getSvgImageProcessingType(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to SVG.
 * Specifies how to treat the referred image.
 * @since 3.3
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>IMGPT_EMBED_ALL	</td><td>= 0 Embeds all images to SVG.</td></tr>
 *	<tr><td>IMGPT_COPY_ALL	</td><td>= 1 Copies all image files to the destination that is specified by setSvgImageCopyPath, and then links.</td></tr>
 *	<tr><td>IMGPT_LINK		</td><td>= 2 Links images that have been linked, and embeds the embedded image. However, the raster images other than JPEG and PNG are always embedded.</td></tr>
 *	<tr><td>IMGPT_COPY		</td><td>= 3 Copies images that have been linked to the destination that is specified by setSvgImageCopyPath, and links. The embedded image are embedded.</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	specification how to treat the referred image.
 */
XFOINTERFACE_API void xfo_setSvgImageProcessingType(CXfoObjPtr pXfoObj, XfoIMAGEPROCTYPE newVal);

/**
 * Effective when outputting to SVG.
 * Gets the copy destination of image as specifying IMGPT_COPY_ALL or IMGPT_COPY by xfo_setSvgImageProcessingType.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the image copy path. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getSvgImageCopyPath(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Specifies the copy destination of image as specifying IMGPT_COPY_ALL or IMGPT_COPY by xfo_setSvgImageProcessingType.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as image copy path
 */
XFOINTERFACE_API void xfo_setSvgImageCopyPath(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Effective when outputting to SVG.
 * Gets the copy destination of image as specifying IMGPT_COPY_ALL or IMGPT_COPY by xfo_setSvgImageProcessingType.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the image copy path. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getSvgImageCopyPathW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to SVG.
 * Specifies the copy destination of image as specifying IMGPT_COPY_ALL or IMGPT_COPY by xfo_setSvgImageProcessingType.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as image copy path
 */
XFOINTERFACE_API void xfo_setSvgImageCopyPathW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Effective when outputting to SVG.
 * Gets specification whether to divide into multiple SVG or to output as one SVG when the formatted result extends to multiple pages. <BR>
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	specification whether to divide into multiple SVG or to output as one SVG when the formatted result extends to multiple pages.
 */
XFOINTERFACE_API long xfo_getSvgSingleFile(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to SVG.
 * Specifies whether to divide into multiple SVG or to output as one SVG when the formatted result extends to multiple pages. <BR>
 * If the value is true, outputs one SVG. If the value is false, outputs multiple SVG. When multiple SVG is output, the file name is modified by specifying format. <BR>
 * Effective only when outputting to the file. It is invalid in the output without the file name like the stream etc.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	specification whether to divide into multiple SVG or to output as one SVG when the formatted result extends to multiple pages.
 */
XFOINTERFACE_API void xfo_setSvgSingleFile(CXfoObjPtr pXfoObj, long newVal);

#if !defined(_DOXYGEN)
/**
 * @deprecated
 */
XFOINTERFACE_API char* xfo_getSvgSingleFileMaxHeight(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * @deprecated
 */
XFOINTERFACE_API wchar_t* xfo_getSvgSingleFileMaxHeightW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * @deprecated
 */
XFOINTERFACE_API void xfo_setSvgSingleFileMaxHeight(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * @deprecated
 */
XFOINTERFACE_API void xfo_setSvgSingleFileMaxHeightW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * @deprecated
 */
XFOINTERFACE_API int xfo_getSvgSingleFileMaxPages(CXfoObjPtr pXfoObj);

/**
 * @deprecated
 */
XFOINTERFACE_API void xfo_setSvgSingleFileMaxPages(CXfoObjPtr pXfoObj, int newVal);

/**
 * @deprecated
 */
XFOINTERFACE_API int xfo_getSvgImageDownsamplingDPI(CXfoObjPtr pXfoObj);

/**
 * @deprecated
 */
XFOINTERFACE_API void xfo_setSvgImageDownsamplingDPI(CXfoObjPtr pXfoObj, int dpi);

/**
 * @deprecated
 */
XFOINTERFACE_API int xfo_getSvgImageDownsamplingMethod(CXfoObjPtr pXfoObj);

/**
 * @deprecated
 */
XFOINTERFACE_API void xfo_setSvgImageDownsamplingMethod(CXfoObjPtr pXfoObj, int type);
#endif

/**
 * Effective when outputting to SVG.
 * Gets specification whether to rename all file name to prefix specified by xfo_setSvgImagePrefix, or use original name.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	specification whether to rename all file name to prefix specified by xfo_setSvgImagePrefix, or use original name.
 */
XFOINTERFACE_API long xfo_getSvgImageRename(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to SVG.
 * When images are copied to the directory specified by xfo_setSvgImageCopyPath etc. and processed, specifies whether to rename all file name to prefix specified by xfo_setSvgImagePrefix, or use original name. When the file name overlaps, sequential number is added. When true is specified, all files are renamed.
 *
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	specification whether to rename all file name to prefix specified by xfo_setSvgImagePrefix, or use original name.
 */
XFOINTERFACE_API void xfo_setSvgImageRename(CXfoObjPtr pXfoObj, long newVal);

/**
 * Effective when outputting to SVG.
 * Gets the prefix of the file name when images are copied to the directory specified by xfo_setSvgImageCopyPath and processed.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the prefix. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getSvgImagePrefix(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * Effective when outputting to SVG.
 * When images are copied to the directory specified by xfo_setSvgImageCopyPath and processed, specifies the prefix of the file name. The file name will be prefix with sequence numbers. Default is empty character string with only sequential numbers.
 *
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the prefix of the file name.
 */
XFOINTERFACE_API void xfo_setSvgImagePrefix(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * Effective when outputting to SVG.
 * Gets the prefix of the file name when images are copied to the directory specified by xfo_setSvgImageCopyPath and processed.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the prefix. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getSvgImagePrefixW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Effective when outputting to SVG.
 * When images are copied to the directory specified by xfo_setSvgImageCopyPath and processed, specifies the prefix of the file name. The file name will be prefix with sequence numbers. Default is empty character string with only sequential numbers.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the prefix of the file name.
 */
XFOINTERFACE_API void xfo_setSvgImagePrefixW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Effective when outputting to SVG.
 * Gets specification whether to add sequential number to the output SVG even if it has only one-page.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	specification whether to add sequential number to the output SVG even if it has only one-page.
 */
XFOINTERFACE_API long xfo_getSvgSinglePageNumber(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to SVG.
 * When xfo_setSvgSingleFile = 0 is specified, specifies whether to add sequential number to the output SVG even if it has only one-page. It is not added in case of false.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	specification whether to add sequential number to the output SVG even if it has only one-page.
 */
XFOINTERFACE_API void xfo_setSvgSinglePageNumber(CXfoObjPtr pXfoObj, long newVal);

#if defined(_DOXYGEN) || (defined(_MSC_VER) && defined(_WIN32))
/**
 * Effective when outputting to SVG.
 * Gets the value of the rasterised-resolution of the transformed raster images.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Rasterised-resolution
 */
XFOINTERFACE_API int xfo_getSvgRasterizeResolution(CXfoObjPtr pXfoObj);

/**
 * Effective when outputting to SVG.
 * Specifies the value of the rasterised-resolution of the transformed raster images in the range from 70 to 500(dpi). SVG, EMF and WMF are drawn in SVG as vectors without being transformed to raster images.
 * This setting is effective only with Windows version.
 * @since 3.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Rasterised-resolution (70 to 500)
 */
XFOINTERFACE_API void xfo_setSvgRasterizeResolution(CXfoObjPtr pXfoObj, int newVal);
#endif

/**
 * Get the start volume of document to output.
 * @since 3.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	start volume of output.
 */
XFOINTERFACE_API long xfo_getStartVolume(CXfoObjPtr pXfoObj);

/**
 * Specifies the start volume of document to output.
 * If the start volume is omitted or the specified value is 0 or less, the start volume is
 * considered from the first volume.
 * If the setting is inconsistent, (for example, StartVolume=5 EndVolume=3) an error occurs.
 * @since 3.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	start volume of output.
 */
XFOINTERFACE_API void xfo_setStartVolume(CXfoObjPtr pXfoObj, long newVal);

/**
 * Get the end volume of document to output.
 * @since 3.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	end volume of output.
 */
XFOINTERFACE_API long xfo_getEndVolume(CXfoObjPtr pXfoObj);

/**
 * Specifies the end volume of document to output.
 * If the end volume is omitted or the specified value exceeds the actual volume number, the end volume
 * is considered as the last volume.
 * If the setting is inconsistent, (for example, StartVolume=5 EndVolume=3) an error occurs.
 * @since 3.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	end volume of output.
 */
XFOINTERFACE_API void xfo_setEndVolume(CXfoObjPtr pXfoObj, long newVal);

/**
 * Get multiple volume  of PDF output.
 * @since 3.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If zero is returned, multiple volume don't specified.
 * 			  If nonezero is returned, multiple volume specified.
 */
XFOINTERFACE_API long xfo_getMultiVolume(CXfoObjPtr pXfoObj);

/**
 * Gets the number of all the separate volumes when outputting PDF to multiple separate volumes.
 * @since 3.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Returns total volume count.
 */
XFOINTERFACE_API long xfo_getTotalVolumeCount(CXfoObjPtr pXfoObj);

/**
 * Gets the number of the actual separate volumes when outputting PDF to multiple separate volumes.
 * @since 3.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Returns output volume count.
 */
XFOINTERFACE_API long xfo_getOutputVolumeCount(CXfoObjPtr pXfoObj);


/**
 * Specifies multiple volume of PDF output.
 * @since 3.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Zpecifies zero or nonzero.
 */
XFOINTERFACE_API void xfo_setMultiVolume(CXfoObjPtr pXfoObj, long newVal);

/**
 * Get the error level to abort formatting process.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Returns the error level.
 */
XFOINTERFACE_API XfoIfErrorLevel xfo_getExitLevel(CXfoObjPtr pXfoObj);

/**
 * Error level to abort formatting process. AH Formatter will stop formatting when the detected
 * error level is equal to ExitLevel property or higher. The default value is 2 (Warning).
 * Thus if an error occurred and error level is 2 (Warning) or higher, formatting process will be
 * aborted. Please use the value from 1 to 4. When the value of 5 or more specified, it is considered
 * to be the value of 4. If a error-level:4 (fatal error) occurs, the formatting process will be
 * aborted unconditionally.
 * BTW : An error is not displayed no matter what value may be specified to be this property.
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>ELVL_INFORMATION	</td><td>= 1 Information</td></tr>
 *	<tr><td>ELVL_WARNING		</td><td>= 2 Warning</td></tr>
 *	<tr><td>ELVL_RECOVERABLE	</td><td>= 3 Recoveable Error</td></tr>
 *	<tr><td>ELVL_FATAL			</td><td>= 4 Fatal Error</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	error level to abort formatting process.
 */
XFOINTERFACE_API void xfo_setExitLevel(CXfoObjPtr pXfoObj, XfoIfErrorLevel newVal);

/**
 * Returns the error level of the error that occurred during the formatting process.
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>ELVL_INFORMATION	</td><td>= 1 Information</td></tr>
 *	<tr><td>ELVL_WARNING		</td><td>= 2 Warning</td></tr>
 *	<tr><td>ELVL_RECOVERABLE	</td><td>= 3 Recoveable Error</td></tr>
 *	<tr><td>ELVL_FATAL			</td><td>= 4 Fatal Error</td></tr>
 * </table>
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Returns the error level.
 */
XFOINTERFACE_API XfoIfErrorLevel xfo_getErrorLevel(CXfoObjPtr pXfoObj);

/**
 * Returns the error code of the error that occurred during the formatting process.
 * Zero means no error. Non-zero indicates any error occurred.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Returns the error code.
 */
XFOINTERFACE_API XfoIfErrorCode xfo_getErrorCode(CXfoObjPtr pXfoObj);

/**
 * Returns the error message of the error that occurred during the formatting process.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getErrorMessage(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
 * Returns the error message of the error that occurred during the formatting process.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getErrorMessageW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Sets the substitution of font name. This substitution acts on the font names existing in FO.
 * The font name 'fontName' is replaced to 'aliasName'.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	src		Specifies the font name which is replaced.
 * @param	dst		Specifies the aliasName.
 */
XFOINTERFACE_API void xfo_setFontAlias(CXfoObjPtr pXfoObj, const char* src, const char* dst);
/**
 * Sets the substitution of font name. This substitution acts on the font names existing in FO.
 * The font name 'fontName' is replaced to 'aliasName'.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	src		Specifies the font name which is replaced.
 * @param	dst		Specifies the aliasName.
 */
XFOINTERFACE_API void xfo_setFontAliasW(CXfoObjPtr pXfoObj, const wchar_t* src, const wchar_t* dst);

/**
 * Clear all substitutions of font name.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 */
XFOINTERFACE_API void xfo_clearFontAlias(CXfoObjPtr pXfoObj);
/**
 * Clear all substitutions of font name.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 */

/**
 * Erase the substitution of font name 'fontName'.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	src	Specifies the font name which is replaced.
 */
XFOINTERFACE_API void xfo_eraseFontAlias(CXfoObjPtr pXfoObj, const char* src);
XFOINTERFACE_API void xfo_eraseFontAliasW(CXfoObjPtr pXfoObj, const wchar_t* src);

/**
 * Execute formatting and output to a PDF specified in OutputFilePath or printer specified in PrinterName.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Returns the error code. Zero means no error. Non-zero indicates any error occurred.
 */
XFOINTERFACE_API XfoIfErrorCode xfo_execute(CXfoObjPtr pXfoObj);

/**
 * Initialize formatting engine.
 *
 * @param	pXfoObj Pointer to XfoObj instance.
 */
XFOINTERFACE_API void xfo_clear(CXfoObjPtr pXfoObj);

/**
 * Specifies the callback fucntion.
 * The error that occurred during the formatting process can be received.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	proc		Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void XfoOnMessageProc(XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const char* errMessage);
 * void XfoOnMessageProcW(XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const wchar_t* errMessage);</pre>
 */
XFOINTERFACE_API void xfo_setOnMessageProc(CXfoObjPtr pXfoObj, XfoOnMessageProc* proc);

/**
 * Specifies the callback fucntion.
 * The error that occurred during the formatting process can be received.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	proc		Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void XfoOnMessageProc(XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const char* errMessage);
 * void XfoOnMessageProcW(XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const wchar_t* errMessage);</pre>
 */
XFOINTERFACE_API void xfo_setOnMessageProcW(CXfoObjPtr pXfoObj, XfoOnMessageProcW* proc);

/**
 * Specifies the callback fucntion.
 * The page number in the formatting process can be received.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	proc	Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void XfoOnFormatPageProc(long pageNo);</pre>
 */
XFOINTERFACE_API void xfo_setOnFormatPageProc(CXfoObjPtr pXfoObj, XfoOnFormatPageProc* proc);

/**
 * Specifies the callback fucntion.
 * The error that occurred during the formatting process can be received.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	proc		Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void XfoOnMessageProc(XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const char* errMessage);
 * void XfoOnMessageProcW(XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const wchar_t* errMessage);</pre>
 * @param	pAnyObj		Address of an any object.
 */
XFOINTERFACE_API void xfo_setOnMessageProcEx(CXfoObjPtr pXfoObj, XfoOnMessageProcEx* proc, void* pAnyObj);

/**
 * Specifies the callback fucntion.
 * The error that occurred during the formatting process can be received.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	proc		Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void XfoOnMessageProc(XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const char* errMessage);
 * void XfoOnMessageProcW(XfoIfErrorLevel errLevel, XfoIfErrorCode errCode, const wchar_t* errMessage);</pre>
 * @param	pAnyObj		Address of an any object.
 */
XFOINTERFACE_API void xfo_setOnMessageProcExW(CXfoObjPtr pXfoObj, XfoOnMessageProcExW* proc, void* pAnyObj);

/**
 * Specifies the callback fucntion.
 * The page number in the formatting process can be received.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	proc	Address of the callback function.
 *	<br>Callback function has the following form:<pre>
 * void XfoOnFormatPageProc(long pageNo);</pre>
 * @param	pAnyObj		Address of an any object.
 */
XFOINTERFACE_API void xfo_setOnFormatPageProcEx(CXfoObjPtr pXfoObj, XfoOnFormatPageProcEx* proc, void* pAnyObj);

/**
 * Set parameter name and value for xsl:param.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	paramName name.
 * @param	value	parameter value.
 */
XFOINTERFACE_API void xfo_setXSLTParam(CXfoObjPtr pXfoObj, const char* paramName, const char* value);
/**
 * Set parameter name and value for xsl:param.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	paramName name.
 * @param	value	parameter value.
 */
XFOINTERFACE_API void xfo_setXSLTParamW(CXfoObjPtr pXfoObj, const wchar_t* paramName, const wchar_t* value);

/**
 * Clear all parameter name and value for xsl:param.
 *
 * @param	pXfoObj Pointer to XfoObj instance.
 */
XFOINTERFACE_API void xfo_clearXSLTParam(CXfoObjPtr pXfoObj);

/**
 * Get the error output type.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Error output type.
 */
XFOINTERFACE_API XfoErrorStreamType xfo_getErrorStreamType(CXfoObjPtr pXfoObj);

/**
 * Set the error output type.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	type		Error output type.
 * 	<table border="0" cellspacing="0" cellpadding="0">
 *	<tr><td>OST_NONE	</td><td>: No error output</td></tr>
 *	<tr><td>OST_STDOUT	</td><td>: Error output to stdout</td></tr>
 *	<tr><td>OST_STDERR	</td><td>: Error output to stderr</td></tr>
 *	</table>
 */
XFOINTERFACE_API void xfo_setErrorStreamType(CXfoObjPtr pXfoObj, XfoErrorStreamType type);

/* Print Interface */
/**
 * Get the printer name where the formatted result is outputted.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getPrinterName(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
 * Get the printer name where the formatted result is outputted.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getPrinterNameW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Specifies the output format or the printer name to output.
 * When a printer name is specified, the formatted result is outputted to that printer.
 * When "\@STDPRN" is specified, the formatted result is outputted to the currently used printer.
 * When "\@PDF" is specified, the formatted result is outputted to PDF.
 * When "\@SVG" is specified, the formatted result is outputted to SVG.
 * When "\@PS" is specified, the formatted result is outputted to PostScript.
 * When "\@INX" is specified, the formatted result is outputted to INX.
 * When "\@MIF" is specified, the formatted result is outputted to MIF.
 * When "\@TEXT" is specified, the formatted result is outputted to a text format file.
 * When "\@AreaTree" is specified, the AreaTree will be outputted.
 * When omitted, it is considered as "\@PDF" was specified.
 * It's impossible to output to the printer with any OS's other than Windows.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the printer name.
 */
XFOINTERFACE_API void xfo_setPrinterName(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Specifies the output format or the printer name to output.
 * When a printer name is specified, the formatted result is outputted to that printer.
 * When "\@STDPRN" is specified, the formatted result is outputted to the currently used printer.
 * When "\@PDF" is specified, the formatted result is outputted to PDF.
 * When "\@SVG" is specified, the formatted result is outputted to SVG.
 * When "\@PS" is specified, the formatted result is outputted to PostScript.
 * When "\@INX" is specified, the formatted result is outputted to INX.
 * When "\@MIF" is specified, the formatted result is outputted to MIF.
 * When "\@TEXT" is specified, the formatted result is outputted to a text format file.
 * When "\@AreaTree" is specified, the AreaTree will be outputted.
 * When omitted, it is considered as "\@PDF" was specified.
 * It's impossible to output to the printer with any OS's other than Windows.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the printer name.
 */
XFOINTERFACE_API void xfo_setPrinterNameW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Get formatted total pages.
 *
 * @return	the value of formatted total pages.
 */
XFOINTERFACE_API long xfo_getFormattedPages(CXfoObjPtr pXfoObj);

#if defined(_DOXYGEN) || (defined(_MSC_VER) && defined(_WIN32))

/**
 * Get the printer setting file URI.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getPrinterSettingURI(CXfoObjPtr pXfoObj, char* pVal, int size);
/**
 * Get the printer setting file URI.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getPrinterSettingURIW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);


/**
 * Specifies the printer setting file URI.
 * This setting is effective only with Windows version.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the printer name.
 */
XFOINTERFACE_API void xfo_setPrinterSettingURI(CXfoObjPtr pXfoObj, const char* newVal);
/**
 * Specifies the printer setting file URI.
 * This setting is effective only with Windows version.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the printer name.
 */
XFOINTERFACE_API void xfo_setPrinterSettingURIW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * Get the number of copies. Effective when outputting to printer.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Returns the number of copies.
 */
XFOINTERFACE_API long xfo_getPrnCopies(CXfoObjPtr pXfoObj);

/**
 * Specifies the number of copies. Effective when outputting to printer.
 * If nothing is specified, the value is considered as 1.
 * This setting is effective only with Windows version.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	the number of copies.
 */
XFOINTERFACE_API void xfo_setPrnCopies(CXfoObjPtr pXfoObj, long newVal);

/**
 * Get collation of multiple copies.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If zero is returned, the same page is multi-copied continuously.
 * 			  If nonezero is returned, the pages specified from start to end are printed repeatedly.
 */
XFOINTERFACE_API long xfo_getPrnCollate(CXfoObjPtr pXfoObj);

/**
 * Specifies collation of multiple copies. Effective when outputting to printer and the number of
 * copies is plural. If it is not specified or the value zero is specified, the same page is
 * multi-copied continuously.
 * If nonezero is specified, the pages specified from start to end are printed repeatedly.
 * This setting is effective only with Windows version.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Specifies zero or nonzero.
 */
XFOINTERFACE_API void xfo_setPrnCollate(CXfoObjPtr pXfoObj, long newVal);

/**
 * Get the setting of whether print dialog box is displayed or not when printing
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	If zero, the print dialog box is displayed. If nonezero, the print dialog box is not displayed.
 */
XFOINTERFACE_API long xfo_getBatchPrint(CXfoObjPtr pXfoObj);

/**
 * When the value 'false' is specified, the print dialog box is displayed when printing.
 * If the setting is omitted or the value 'true' is specified, the print dialog is not displayed.
 * This setting is effective only with Windows version.
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	If zero, the print dialog box is displayed. If nonezero, the print dialog box is not displayed.
 */
XFOINTERFACE_API void xfo_setBatchPrint(CXfoObjPtr pXfoObj, long newVal);

#if !defined(_DOXYGEN)
/**
 * @deprecated
 * Get the text of XML document you will format.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getDocumentText(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * @deprecated
 * Get the text of XML document you will format.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getDocumentTextW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);
#endif

/**
 * @deprecated
 * Specifies the XML document you will format.
 * MSXML3/MSXML4 is required when formatting.
 * This setting is effective only with Windows version.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the text of XML document.
 */
XFOINTERFACE_API void xfo_setDocumentText(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * @deprecated
 * Specifies the XML document you will format.
 * MSXML3/MSXML4 is required when formatting.
 * This setting is effective only with Windows version.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the text of XML document.
 */
XFOINTERFACE_API void xfo_setDocumentTextW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

/**
 * @deprecated
 * Get the text of XSL stylesheet for formatting.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getStylesheetText(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * @deprecated
 * Get the text of XSL stylesheet for formatting.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getStylesheetTextW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * @deprecated
 * Specifies the text of XSL stylesheet for formatting.
 * If the specified XML document is FO, or the XML file contains the processing instruction
 * &lt;?xml-stylesheet ...?&gt; and the XSL stylesheet is specified, this setting is ignored.
 * Otherwise if there is no setting of this property, an error occurs.
 * MSXML3/MSXML4 is required when formatting.
 * This setting is effective only with Windows version.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the text of XSL stylesheet.
 */
XFOINTERFACE_API void xfo_setStylesheetText(CXfoObjPtr pXfoObj, const char* newVal);

/**
 * @deprecated
 * Specifies the text of XSL stylesheet for formatting.
 * If the specified XML document is FO, or the XML file contains the processing instruction
 * &lt;?xml-stylesheet ...?&gt; and the XSL stylesheet is specified, this setting is ignored.
 * Otherwise if there is no setting of this property, an error occurs.
 * MSXML3/MSXML4 is required when formatting.
 * This setting is effective only with Windows version.
 * @since 3.1
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Pointer to a null-terminated string to be used as the text of XSL stylesheet.
 */
XFOINTERFACE_API void xfo_setStylesheetTextW(CXfoObjPtr pXfoObj, const wchar_t* newVal);

#endif	/* _WIN32 */

/**
 * Get the version string of AH Formatter.
 * @since 4.0MR4
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API char* xfo_getVersion(CXfoObjPtr pXfoObj, char* pVal, int size);

/**
 * Get the version string of AH Formatter.
 * @since 4.0MR4
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	pVal		Pointer to the buffer that will receive the text. If the string is as long or longer than the buffer,
 *			  the string is truncated and terminated with a NULL character.
 * @param	size		Specifies the number of the 'pVal' buffer, including the NULL character. If the text exceeds this limit, it is truncated.
 * @return	Returns the 'pVal'.
 */
XFOINTERFACE_API wchar_t* xfo_getVersionW(CXfoObjPtr pXfoObj, wchar_t* pVal, int size);

/**
 * Get INX output mode.
 * @since 4.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	output mode of INX.
 */
XFOINTERFACE_API XfoINXOUTPUTMODE xfo_getInxOutputMode(CXfoObjPtr pXfoObj);

/**
 * Set INX output mode.
 * @since 4.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Output mode of INX.
 */
XFOINTERFACE_API void xfo_setInxOutputMode(CXfoObjPtr pXfoObj, XfoINXOUTPUTMODE newVal);

/**
 * Get MIF output mode.
 * @since 4.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Output mode of MIF.
 */
XFOINTERFACE_API XfoMIFOUTPUTMODE xfo_getMifOutputMode(CXfoObjPtr pXfoObj);

/**
 * Set MIF output mode.
 * @since 4.3
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	newVal	Output mode of MIF.
 */
XFOINTERFACE_API void xfo_setMifOutputMode(CXfoObjPtr pXfoObj, XfoMIFOUTPUTMODE newVal);

/**
 * Get MIF image processing mode
 * @since 5.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @return	Image processing mode.
 */
XFOINTERFACE_API XfoMIFIMAGEPROCMODE xfo_getMifIpMode(CXfoObjPtr pXfoObj);

/**
 * Set MIF image processing mode
 * @since 5.2
 *
 * @param	pXfoObj	Pointer to XfoObj instance.
 * @param	mode	Image processing mode.
 */
XFOINTERFACE_API void xfo_setMifIpMode(CXfoObjPtr pXfoObj, XfoMIFIMAGEPROCMODE mode);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif	/* XFOIFC_C_H__ */
