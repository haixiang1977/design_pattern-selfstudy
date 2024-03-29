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

#ifndef ARGUMENTSTRUCT_H
#define ARGUMENTSTRUCT_H

#include "NodeIdStruct.h"
#include "LocalizedTextStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure describing an input or output parameter of a method. */
//lint -sem(ArgumentStruct::clear, cleanup)
//lint -sem(ArgumentStruct::clear, initializer)
typedef struct ArgumentStruct
{
	/*! The DataType of the parameter. */
	NodeIdStruct dataType;

	/*! The parameter's name. */
	TCHAR* pName;

	/*! The value rank of the parameter (means whether it can be an array, is always an array...) */
	OTInt32 valueRank;

	/*! A field of integer values that give the dimensions of an array used by the parameter. */
	OTUInt32 arrayDimensions_count;
	OTUInt32* arrayDimensions;

	/*! The description of the parameter. */
	LocalizedTextStruct description;


#ifdef OT_COMPILATION
	ArgumentStruct();
	EnumStatusCode setName(const TCHAR* pValue);
	EnumStatusCode getArrayDimensions(unsigned* pCount, OTUInt32** ppValues);
	EnumStatusCode setArrayDimensions(OTUInt32 dimensionsCount, const OTUInt32* pArrayDimensions);
	EnumStatusCode setValueRank(OTInt32 valRank);

	EnumStatusCode set(const ArgumentStruct&, bool targetIsMemberOfNode = false);
	EnumStatusCode get(ArgumentStruct&) const;
	EnumStatusCode set(const OpcUa_Argument&);
	EnumStatusCode get(OpcUa_Argument&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;


	const ArgumentStruct& operator=(const ArgumentStruct& cp);
	bool operator==(const ArgumentStruct& toCompare) const;
	bool operator!=(const ArgumentStruct& toCompare) const;
	bool operator<(const ArgumentStruct& toCompare) const;
	bool operator>(const ArgumentStruct& toCompare) const;

	int compare(const ArgumentStruct* pTarget) const;

	void clear(void);
	~ArgumentStruct(void);

#endif
}ArgumentStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// ARGUMENTSTRUCT_H
