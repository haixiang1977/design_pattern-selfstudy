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

#ifndef SERVERSHELVEDSTATEMACHINEUNSHELVE_H
#define SERVERSHELVEDSTATEMACHINEUNSHELVE_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerMethod.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class MethodCallTransaction;
		class MethodCallRequest;
	}

	namespace Server
	{
		/*! The Unshelve method allows clients to set the alarm condition to the Unshelved state.
		*
		* @see ShelvedStateMachine AlarmCondition */
		class TBC_EXPORT ShelvedStateMachineUnshelve
			: public Method
		{
		public:
			/*! Constructs a new ShelvedStateMachineUnshelve instance */
			static ObjectPointer<ShelvedStateMachineUnshelve> create();

			/*! @deprecated		Please use ShelvedStateMachineUnshelve::create() to construct an instance of this type.
			*					This constructor will be made 'protected' in future versions of this product.
			*
			* Default constructor */
			ShelvedStateMachineUnshelve();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ShelvedStateMachineUnshelve(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			ShelvedStateMachineUnshelve(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ShelvedStateMachineUnshelve();

			/*! Callback method that is called whenever the 'Unshelve' method is executed by a client.
			* This method may be overridden by server applications.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleExecuteRequest(Server::MethodCallTransaction* transaction, Server::MethodCallRequest* request);

		private:
			/*! Forbid use assignment operator */
			ShelvedStateMachineUnshelve& operator=(const ShelvedStateMachineUnshelve&);
			/*! Forbid use of copy constructor */
			ShelvedStateMachineUnshelve(const ShelvedStateMachineUnshelve&);
		};
		typedef ObjectPointer<ShelvedStateMachineUnshelve> ShelvedStateMachineUnshelvePtr;
		typedef ObjectPointer<const ShelvedStateMachineUnshelve> ShelvedStateMachineUnshelveConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERSHELVEDSTATEMACHINEUNSHELVE_H
