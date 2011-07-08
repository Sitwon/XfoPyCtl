#!/bin/sh
cat xfoifc_c.h | grep '^XFOINTERFACE_API' | grep -v 'wchar' | sed 's/XFOINTERFACE_API //' | sed 's/const //g' | sed 's/xfo_//' > prototypes
