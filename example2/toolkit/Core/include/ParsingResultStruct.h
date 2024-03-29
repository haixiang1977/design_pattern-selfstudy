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

#ifndef _ParsingResultStruct_H_
#define _ParsingResultStruct_H_

#include "Enums.h"
#include "DiagnosticInfoStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(ParsingResultStruct::clear, cleanup)
//lint -sem(ParsingResultStruct::clear, initializer)
typedef struct ParsingResultStruct
{
	/*!
	 * @brief Parsing result for the requested NodeTypeDescription.
	 */
	EnumStatusCode statusCode;

	/*!
	 * @brief List of results for dataToReturn.
	 *
	 * The size and order of the list matches the size and order of the
	 * dataToReturn request parameter. The vector can be empty if no
	 * errors were encountered.
	 */
	EnumStatusCode* pDataStatusCodes;
	unsigned pDataStatusCodes_count;

	/*! List of diagnostic information for dataToReturn. The size and order of the
	* list matches the size and order of the dataToReturn request parameter. This list
	* is empty if diagnostics information was not requested in the request header or if
	* no diagnostic information was encountered in processing of the query request. */
	DiagnosticInfoStruct* pDataDiagnosticInfos;
	unsigned pDataDiagnosticInfos_count;

#ifdef OT_COMPILATION
	ParsingResultStruct();
	ParsingResultStruct(const ParsingResultStruct&);

	EnumStatusCode set(const ParsingResultStruct&);
	EnumStatusCode get(ParsingResultStruct&) const;

	EnumStatusCode set(const OpcUa_ParsingResult&);
	EnumStatusCode get(OpcUa_ParsingResult&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;

	const ParsingResultStruct& operator=(const ParsingResultStruct& cp);
	bool operator==(const ParsingResultStruct& toCompare) const;
	bool operator!=(const ParsingResultStruct& toCompare) const;
	bool operator<(const ParsingResultStruct& toCompare) const;
	bool operator>(const ParsingResultStruct& toCompare) const;

	int compare(const ParsingResultStruct* pTarget) const;

	void clear(void);
	~ParsingResultStruct(void);
#endif
} ParsingResultStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
