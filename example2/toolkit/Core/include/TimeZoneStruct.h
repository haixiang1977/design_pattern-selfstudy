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

#ifndef __TIMEZONESTRUCT_H_
#define __TIMEZONESTRUCT_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure describing engineering units. */
//lint -sem(TimeZoneStruct::clear, cleanup)
//lint -sem(TimeZoneStruct::clear, initializer)
typedef struct TimeZoneStruct
{
	/*! The offset in minutes from UtcTime . */
	OTInt16 offset;

	/*! If TRUE, then daylight saving time (DST) is in effect and offset
	includes the DST correction. If FALSE then the offset does not
	include DST correction and DST may or may not have been in
	effect.  */
	bool daylightSavingInOffset;

#ifdef OT_COMPILATION
	TimeZoneStruct();
	EnumStatusCode setOffset(OTInt16 offset);
	EnumStatusCode setDaylightSavingInOffset(bool daylightSavingInOffset);

	EnumStatusCode set(const TimeZoneStruct&);
	EnumStatusCode get(TimeZoneStruct&) const;
	EnumStatusCode set(const OpcUa_TimeZoneDataType&);
	EnumStatusCode get(OpcUa_TimeZoneDataType&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;


	const TimeZoneStruct& operator=(const TimeZoneStruct& cp);
	bool operator==(const TimeZoneStruct& toCompare) const;
	bool operator!=(const TimeZoneStruct& toCompare) const;
	bool operator<(const TimeZoneStruct& toCompare) const;
	bool operator>(const TimeZoneStruct& toCompare) const;

	int compare(const TimeZoneStruct* pTarget) const;

	void clear(void);
	~TimeZoneStruct(void);

#endif
}TimeZoneStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
