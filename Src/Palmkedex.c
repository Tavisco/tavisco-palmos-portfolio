#include <PalmOS.h>

#include "Tavisco.h"
#include "Rsc/Tavisco_Rsc.h"


static Boolean PalmkedexFormDoCommand(UInt16 command)
{
	Boolean handled = false;

	switch (command)
	{
		case DexBackButton:
		{
			FrmGotoForm(MainForm);
			handled = true;
			break;
		}
		
		case DexLaunchButton:
		{
			AppLaunchWithCommand(
					dexAppID, 
					sysAppLaunchCmdNormalLaunch, NULL);
		}
	}

	return handled;
}


Boolean PalmkedexFormHandleEvent(EventType * eventP)
{
	Boolean handled = false;
	FormType * frmP;

	switch (eventP->eType) 
	{	
		case ctlSelectEvent:
			return PalmkedexFormDoCommand(eventP->data.menu.itemID);

		case frmOpenEvent:
			frmP = FrmGetActiveForm();
			FrmDrawForm(frmP);
			handled = true;
			break;
	}
    
	return handled;
}
