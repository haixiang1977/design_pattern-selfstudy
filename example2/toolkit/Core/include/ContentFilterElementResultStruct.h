/*****************************************************************************
*                                                                            *
*                     SOFTING Industrial Automation GmbH                     *
*                          Richard-Reitzner-Allee 6                          *
*                                D-85540 Haar                                *
*                        Phone: ++49-89-4 56 56-0                            *
*                          Fax: ++49-89-4 56 56-3 99                         *
*                                                                            *
*                            SOFTING CONFIDENTIAL                            *
*                                                                            *
*                     Copyright (C) SOFTING IA GmbH 2016                     *
*                             All Rights Reserved                            *
*                                                                            *
* NOTICE: All information contained herein is, and remains the property of   *
*   SOFTING Industrial Automation GmbH and its suppliers, if any. The intel- *
*   lectual and technical concepts contained herein are proprietary to       *
*   SOFTING Industrial Automation GmbH and its suppliers and may be covered  *
*   by German and Foreign Patents, patents in process, and are protected by  *
*   trade secret or copyright law. Dissemination of this information or      *
*   reproduction of this material is strictly forbidden unless prior         *
*   written permission is obtained from SOFTING Industrial Automation GmbH.  *
******************************************************************************
******************************************************************************
*                                                                            *
* PROJECT_NAME             OPC UA C++ Toolkit                                *
*                                                                            *
* VERSION                  5.52.0                                            *
*                                                                            *
* DATE                     26.09.2016                                        *
*                                                                            *
*****************************************************************************/

#ifndef _ContentFilterElementResultStruct_H_
#define _ContentFilterElementResultStruct_H_
#if TB5_FILTER

#include "Enums.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

/*! A structure that contains any errors associated with the filter. */
//lint -sem(ContentFilterElementResultStruct::clear, cleanup)
//lint -sem(ContentFilterElementResultStruct::clear, initializer)
typedef struct ContentFilterElementResultStruct
{
	/* The status code for a single element. */
	EnumStatusCode statusCode;

	/*!
	 * A list of status codes for the operands in an element. The size and order
	 * of the list matches the size and order of the operands in the ContentFilterElement.
	 * This list is empty if no operand errors occurred.
	 */
	EnumStatusCode* pOperandStatusCodes;
	OTUInt32 pOperandStatusCodes_count;

	DiagnosticInfoStruct* pOperandDiagnosticInfos;
	unsigned pOperandDiagnosticInfos_count;

#ifdef OT_COMPILATION
	ContentFilterElementResultStruct();
	ContentFilterElementResultStruct(const ContentFilterElementResultStruct&);

	EnumStatusCode set(const ContentFilterElementResultStruct&);
	EnumStatusCode get(ContentFilterElementResultStruct&) const;

	EnumStatusCode set(const OpcUa_ContentFilterElementResult&);
	EnumStatusCode get(OpcUa_ContentFilterElementResult&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;

	const ContentFilterElementResultStruct& operator=(const ContentFilterElementResultStruct& cp);
	bool operator==(const ContentFilterElementResultStruct& toCompare) const;
	bool operator!=(const ContentFilterElementResultStruct& toCompare) const;
	bool operator<(const ContentFilterElementResultStruct& toCompare) const;
	bool operator>(const ContentFilterElementResultStruct& toCompare) const;

	int compare(const ContentFilterElementResultStruct* pTarget) const;

	void clear(void);
	~ContentFilterElementResultStruct(void);
#endif
} ContentFilterElementResultStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
