#include <PalmOS.h>

#include "Tavisco.h"
#include "Rsc/Tavisco_Rsc.h"

/*
 * FUNCTION: MainFormDoCommand
 *
 * DESCRIPTION: This routine performs the menu command specified.
 *
 * PARAMETERS:
 *
 * command
 *     menu item id
 */

static Boolean MainFormDoCommand(UInt16 command)
{
	Boolean handled = false;

	switch (command)
	{
		case OptionsAboutTavisco:
		{
			OpenAboutDialog();
			handled = true;
			break;
		}
		
		case MainSORGButton:
		{
			FrmGotoForm(SORGForm);
			handled = true;
			break;
		}
		
		case MainAboutButton:
		{
			OpenAboutDialog();
			handled = true;
			break;
		}

	}

	return handled;
}

void OpenAboutDialog()
{
	FormType * frmP;

	/* Clear the menu status from the display */
	MenuEraseStatus(0);
	
	/* Display the About Box. */
	frmP = FrmInitForm (AboutForm);
	FrmDoDialog (frmP);                    
	FrmDeleteForm (frmP);
}

/*
 * FUNCTION: MainFormHandleEvent
 *
 * DESCRIPTION:
 *
 * This routine is the event handler for the "MainForm" of this 
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

Boolean MainFormHandleEvent(EventType * eventP)
{
	Boolean handled = false;
	FormType * frmP;

	switch (eventP->eType) 
	{
		case menuEvent:
			return MainFormDoCommand(eventP->data.menu.itemID);
		
		case ctlSelectEvent:
			return MainFormDoCommand(eventP->data.menu.itemID);

		case frmOpenEvent:
			frmP = FrmGetActiveForm();
			FrmDrawForm(frmP);
			handled = true;
			break;
            
        case frmUpdateEvent:
			/* 
			 * To do any custom drawing here, first call
			 * FrmDrawForm(), then do your drawing, and
			 * then set handled to true. 
			 */
			break;
			
	}
    
	return handled;
}
