#include <PalmOS.h>

#include "Tavisco.h"
#include "Rsc/Tavisco_Rsc.h"

/*
 * FUNCTION: SorgFormDoCommand
 *
 * DESCRIPTION: This routine performs the menu command specified.
 *
 * PARAMETERS:
 *
 * command
 *     menu item id
 */

static Boolean SorgFormDoCommand(UInt16 command)
{
	Boolean handled = false;

	switch (command)
	{
		case SorgBackButton:
		{
			FrmGotoForm(MainForm);
			handled = true;
			break;
		}
		
		case SorgLaunchButton:
		{
			AppLaunchWithCommand(
					sorgAppID, 
					sysAppLaunchCmdNormalLaunch, NULL);
		}
	}

	return handled;
}

/*
 * FUNCTION: SorgFormHandleEvent
 *
 * DESCRIPTION:
 *
 * This routine is the event handler for the "SorgForm" of this 
 * application.
 *
 * PARAMETERS:
 *
 * eventP
 *     a pointer to an EventType structure
 *
 * RETURNED:
 *     true if the event was handled and should not be passed to
 *     FrmHandleEvent
 */

Boolean SorgFormHandleEvent(EventType * eventP)
{
	Boolean handled = false;
	FormType * frmP;

	switch (eventP->eType) 
	{	
		case ctlSelectEvent:
			return SorgFormDoCommand(eventP->data.menu.itemID);

		case frmOpenEvent:
			frmP = FrmGetActiveForm();
			FrmDrawForm(frmP);
			handled = true;
			break;
	}
    
	return handled;
}
