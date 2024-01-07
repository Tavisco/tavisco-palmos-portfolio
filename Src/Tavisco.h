/*
 * Tavisco.h
 *
 * header file for Tavisco
 *
 * This wizard-generated code is based on code adapted from the
 * stationery files distributed as part of the Palm OS SDK 4.0.
 */
 
#ifndef TAVISCO_H_
#define TAVISCO_H_


/*********************************************************************
 * Internal Constants
 *********************************************************************/

#define appFileCreator			'TVCO'
#define appName					"-Tavisco"
#define appVersionNum			0x01
#define appPrefID				0x00
#define appPrefVersionNum		0x01

#define sorgAppID				'UWSC'
#define dexAppID				'PKDX'

#endif /* TAVISCO_H_ */

Boolean MainFormHandleEvent(EventType * eventP);
Boolean SorgFormHandleEvent(EventType * eventP);
Boolean PalmkedexFormHandleEvent(EventType * eventP);
void OpenAboutDialog(void);